smart_ptr.h
```c++
#include <functional>

// 模仿shared_ptr实现一个智能指针
// 首先，share_ptr是不推荐指向数组的，所以默认delete
template <typename T>
class smart_ptr
{
public:
	smart_ptr();
	explicit smart_ptr(T*);
	smart_ptr(const smart_ptr&);
	smart_ptr& operator=(const smart_ptr&);
	T& operator*() const;
	T* operator->() const;

	~smart_ptr();

	bool unique();
	void reset();
	void reset(T*);
	T* release();
	T* get() const;

private:
	unsigned* m_p_use_count = nullptr;
	T* m_pobject = nullptr;
};

// make系列函数也很灵性，将裸指针的构造和智能指针的构造绑定在一块，这样就不会造成内存泄漏的问题，更加安全
// 其实是一个完美转发
template <typename T, typename... Args> 
smart_ptr<T> make_smart(Args&&... args)
{
	smart_ptr<T> sp(new T(std::forward<Args>(args)...));
	return sp;
}

// 默认构造和裸指针构造的use_count都是1，很灵性
template <typename T>
smart_ptr<T>::smart_ptr()
	:m_pobject(nullptr), m_p_use_count(new unsigned(1)) 
{
}

template <typename T>
smart_ptr<T>::smart_ptr(T *p)
	:m_pobject(p), m_p_use_count(new unsigned(1))
{
}

template <typename T>
smart_ptr<T>::smart_ptr(const smart_ptr& rhs)
	:m_pobject(rhs.m_pobject), m_p_use_count(rhs.m_p_use_count)
{
	(*m_p_use_count)++;
}

// 赋值函数和拷贝构造函数是不一样的逻辑，拷贝构造是初始化，必定没有引用其他的智能指针，所以use_count使用拷贝构造的m_use_count，然后加1；
// 而赋值函数之前应该有
template <typename T>
smart_ptr<T>& smart_ptr<T>::operator =(const smart_ptr &rhs)
{
	// 递增右侧运算对象的引用计数
	++(*rhs.m_p_use_count);
	// 递减本对象的引用计数
	if (--(*m_p_use_count) == 0)
	{
		// 如果管理的对象没有其他用户了，则释放对象分配的成员
		delete m_pobject;
		delete m_p_use_count;
		m_pobject = nullptr;
		m_p_use_count = nullptr;
	}

	m_p_use_count = rhs.m_p_use_count;
	m_pobject = rhs.m_pobject;

	return *this; // 返回本对象	
}

template <typename T>
T& smart_ptr<T>::operator*() const
{
	return *m_pobject;
}

template <typename T>
T* smart_ptr<T>::operator->() const
{
	return &this->operator*();
}

//析构函数也是智能指针的重要函数
template <typename T>
smart_ptr<T>::~smart_ptr()
{
	if (--(*m_p_use_count) == 0)
	{
		delete m_pobject;
		m_pobject = nullptr;

		delete m_p_use_count;
		m_p_use_count = nullptr;
	}
}

template <typename T>
bool smart_ptr<T>::unique() //判断智能指针的共享个数是否为1
{
	return *m_p_use_count == 1;
}

template <typename T>
void smart_ptr<T>::reset() //此指针将原来引用的对象释放掉，此时原来对象指针引用计数减一，此指针的m_pobject归为null,use_count归为1
{
	(*m_p_use_count)--;

	if (*m_p_use_count == 0)
	{
		delete m_pobject;
	}

	m_pobject = nullptr;
	*m_p_use_count = 1;
}

template <typename T>
void smart_ptr<T>::reset(T* p) //此指针将原来引用的对象释放掉，此时原来对象指针引用计数减一，此指针的m_pobject指向新的裸指针,use_count归为1
{
	(*m_p_use_count)--;

	if (*m_p_use_count == 0)
	{
		delete m_pobject;
	}

	m_pobject = p;
	*m_p_use_count = 1;
}

template <typename T>
T* smart_ptr<T>::release() //释放自己对原来的指针的共享权，并把原来的指针m_pobject返回
{
	(*m_p_use_count)--;

	if (*m_p_use_count == 0)
	{
		*m_p_use_count = 1;
	}

	auto p = m_pobject;
	m_pobject = nullptr;

	return p;
}

template <typename T>
T* smart_ptr<T>::get() const
{
	return m_pobject;
}
```

test.cpp
```c++
#include "smart_ptr.h"
#include <iostream>
using std::cout;
using std::endl;

struct MyStruct
{
	MyStruct() = default;
	MyStruct(int a, int b) :a(a), b(b) {}
	int a;
	int b;
};

int main()
{
	MyStruct *s = new MyStruct();
	s->a = 10;
	s->b = 20;

	smart_ptr<MyStruct> sp(s);

	cout << sp->a << endl;
	cout << sp->b << endl;
	cout << (*sp).a << endl;

	// smart_ptr<MyStruct> sp2 = make_smart<MyStruct>(100, 200)
	auto sp2 = make_smart<MyStruct>(100, 200);
	cout << sp2->a << endl;
	cout << sp2->b << endl;

	auto p = sp2.release();
	cout << p->a << endl;
	cout << p->b << endl;
	delete p;

	return 0;
}
```
