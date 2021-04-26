

```c++
template<typename T>
class MyUniquePtr
{
public:
   explicit MyUniquePtr(T* ptr = nullptr)
        :mPtr(ptr)
    {}

    ~MyUniquePtr()
    {
        if(mPtr)
            delete mPtr;
    }

    MyUniquePtr(MyUniquePtr &&p) noexcept;
    MyUniquePtr& operator=(MyUniquePtr &&p) noexcept;

    MyUniquePtr(const MyUniquePtr &p) = delete;
    MyUniquePtr& operator=(const MyUniquePtr &p) = delete;

    T* operator*() const noexcept {return mPtr;}
    T& operator->()const noexcept {return *mPtr;}
    explicit operator bool() const noexcept{return mPtr;}

    void reset(T* q = nullptr) noexcept
    {
        if(q != mPtr){
            if(mPtr)
                delete mPtr;
            mPtr = q;
        }
    }

    T* release() noexcept
    {
        T* res = mPtr;
        mPtr = nullptr;
        return res;
    }
    T* get() const noexcept {return mPtr;}
    void swap(MyUniquePtr &p) noexcept
    {
        using std::swap;
        swap(mPtr, p.mPtr);
    }
private:
    T* mPtr;
};

template<typename T>
MyUniquePtr<T>& MyUniquePtr<T>::operator=(MyUniquePtr &&p) noexcept
{
    swap(*this, p);
    return *this;
}

template<typename T>
MyUniquePtr<T> :: MyUniquePtr(MyUniquePtr &&p) noexcept : mPtr(p.mPtr)
{
    p.mPtr == NULL;
}
```



---

#### 为什么实现上禁止左值拷贝构造和左值拷贝赋值函数呢？

因为unique_ptr的使用上本身禁止左值拷贝构造和左值拷贝赋值！

```c++
int main() 
{
    // 创建一个unique_ptr实例
    unique_ptr<int> pInt(new int(5));
    unique_ptr<int> pInt2(pInt);    // 报错
    unique_ptr<int> pInt3 = pInt;   // 报错
}
```

正确的使用：

```c++
int main() 
{
    unique_ptr<int> pInt(new int(5));
    unique_ptr<int> pInt2 = std::move(pInt);    // 转移所有权
    //cout << *pInt << endl; // 出错，pInt为空
    cout << *pInt2 << endl;
    unique_ptr<int> pInt3(std::move(pInt2));
}
```

