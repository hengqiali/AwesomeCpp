#include <iostream>
using namespace std;


/****************************************

            C++ 命名空间
在 C++ 应用程序中。例如，您可能会写一个名为 xyz() 的函数，在另一个可用的库中也存在一个相同的函数 xyz()。这样，编译器就无法判断您所使用的是哪一个 xyz() 函数。
因此，引入了命名空间这个概念，专门用于解决上面的问题，它可作为附加信息来区分不同库中相同名称的函数、类、变量等。使用了命名空间即定义了上下文。本质上，命名空间就是定义了一个范围。

1. 命名空间内部可以包含一切可以出现在全局作用域中的声明：类、变量及其初始化、函数及其定义、模板和其他命名空间
2. 函数和类内部不可定义命名空间
3. 命名空间具有不连续性，即namespace nsp{}在nsp不存在时创建nsp，在nsp存在时打开nsp
4. 命名空间的不连续性使得我们可以将声明和实现分隔。既可以在域内实现，也可以在域外实现
5. 嵌套命名空间也被允许
6. 内联命名空间https://blog.csdn.net/craftsman1970/article/details/82872497

*****************************************/
namespace first_space{
    int sameV = 5;
    void func(){
        cout << "space_1" << endl;
    }
}

namespace second_space{
    int sameV = 60;
    void func(){
        cout << "space_2" << endl;
    }
}


int main()
{
    cout << "first_space sameV = " << first_space::sameV << endl;
    cout << "second_space sameV = " << second_space::sameV << endl;
    first_space::func();
    second_space::func();

    return 0;
}
