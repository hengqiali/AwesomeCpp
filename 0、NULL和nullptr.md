### C++ 空指针  NULL、0 和 nullptr

#### 小点子：free(nullptr)不会发生任何问题，nullptr可以转换成任意类型的指针，但是！void\* 不能隐式的转换成其他类型的指针

  1. 以往我们使用NULL表示空指针。它实际上是个为0的int、long类整型值。下面的代码会产生岐义：

    void f(int i) {} // chose this one
    void f(const char* s) {}
    
    f(NULL);
  2. 为此C++ 11新增类型nullptr_t，它只有一个值nullptr, 可以避免整型和指针的误用。上面的调用代码可以写成: 

    void f(int i) {}
    void f(const char* s) {} // chose this one
    
    f(nullptr);

例子：


```c++
#include <iostream>

using namespace std;

//当没有f(int a)时，都会调用f(int*),0和NULL都会被解释成空指针
//但当有f(int a)时，会发生参数int和int*的函数重载，0和NULL此时会被识别调用f(int)，而nullptr会调用f(int *)
// 上面的情况在没有模板时的确是那样，0和NULL都有可能被解释成空指针，但是模板时，0和NULL只会被编译器解释成整型，而不能转换成指针***

void f(int a)
{
	cout << "f_int" << endl;
}

void f(int *a)
{
	cout << "f_int*" << endl;
}

int main()
{
	f(0);
	f(NULL);
	f(nullptr);  //nullptr其实是nullptr_t，其不能被视为整型，其可以隐形的转换成所有的原始指针类型，即可以指向任意类型的指针

	return 0;
}
```
