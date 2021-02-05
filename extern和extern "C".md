[extern声明一个变量和函数时，放到.h文件中，在.c中实现，当其他文件想引用这些变量或者函数时，只需包含它们所在声明的.h文件，编译器找到extern声明的变量、函数时就不会出错，知道它们是在外部
文件中定义的，会在链接阶段寻找](https://developer.aliyun.com/article/338215)

[extern "C"实现C++与C语言的混编，gcc会根据文件后缀.c和.cpp来实现不同编译风格，.c按照C语言的编译风格即变量和函数名字不会变，.cpp会根据C++语言的编译风格即变量和函数会根据所在范围类型、函数名字、函数参数个数和类型来区分，以实现重载，在C++中想使用C语言实现的代码时，使用extern "c"来包裹这部分代码，告诉C++编译器这部分在外部C语言文件中，应该以C语言编译的方式去链接寻找！](https://www.jianshu.com/p/83c97305316b, https://developer.aliyun.com/article/338215)

[extern "C" {.....} 的例子:包含C++调用C和C调用C++](https://www.cnblogs.com/skynet/archive/2010/07/10/1774964.html)

