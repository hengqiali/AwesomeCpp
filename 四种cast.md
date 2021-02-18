```c++
#include <iostream>

/*********************************************

    C++  static_cast  const_cast dynamic_cast reinterpret_cast

*********************************************/
void foo(int *num) //用于测试const_cast
{
    std::cout << "const_cast函数参数测试 " << *num << std::endl;
}

int main()
{
    /********  static_cast  *********/
    // 1. 强制类型转换，从量上直接从大类型转换到小类型和从小类型转换到大类型都可以, 但是指针从大类型到小类型或者小类型到大类型都不可以编译, 但是C的强制转换会编译成功,进而导致莫名其妙的错误结果,也就是说static_cast会进行安全类型检查
    // 2. 找回void *指针中存在的值
    double a = 5.3;
    int b = static_cast<int>(a);
    const char *cp = "hq";

    // 1. 强制类型转换
    std::cout << b << std::endl;
    std::string scp = static_cast<std::string>(cp);
    std::cout << scp << std::endl;

    // 2. 找回void *指针中存在的值
    void *p = &a;
    double *dp = static_cast<double *>(p);
    std::cout << *dp << std::endl;


    /********  const_cast  *********/
    // 1. const_cast绝对不能改变const修饰的常量的值
    // 2. 当一个量定义为const，函数形参要求是non_const时，可使用const_cast去掉const传递
    // 3. 当一个量是non_const，却使用一个const指针指向它，若需要修改其，使用const_cast
    //[当企图对一个const变量使用const_cast赋值给non const指针指向来修改其值时，虽然地址相同但值却不同，这是未定义且不安全的行为，尽量避免](https://www.cnblogs.com/QG-whz/p/4513136.html)
    // 4. const_cast只能对指针使用,对量直接使用编译不通过

    // 1. const_cast绝对不能改变const修饰的常量的值
    const int constant = 25;  //如果带const不能通过去const指针来修改
    //int constant = 25; // 3. 当一个量是non_const，却使用一个const指针指向它，若需要修改其，使用const_cast
    const int *constant_p = &constant;
    int *modify = const_cast<int *>(constant_p);
    *modify = 3;
    std::cout << "constant = " << constant << std::endl;
    std::cout << "*modify = " << *modify << std::endl;
    /*  错误，const_cast一般对指针去const
    int modify_2 = const_cast<int>(constant);
    modify_2 = 6;
    std::cout << "constant = " << constant << std::endl;
    std::cout << "modify_2 = " << modify_2 << std::endl;
    */
    // 2. 当一个量定义为const，函数形参要求是non_const时，可使用const_cast去掉const传递
    //foo(&constant); //error: invalid conversion from 'const int*' to 'int*' [-fpermissive]|
    foo(const_cast<int *>(&constant));
    
    
    /********  reinterpret_cast  *********/
    //什么类型转换都可以实现，但是其不会改变值，但是会从位模式上重新解释原来的值，可能会造成结果不一致，所以不建议使用
    //https://zhuanlan.zhihu.com/p/33040213
    // 有时候明知道一个变量是 int8_t类型的指针,但为了进一步保证从位模式上使用int8_t来解释,会使用此类型变换进一步完成保证
    // 有时候对量进行编解码,例如对提取到的特征结构体,直接从位模式上重新解释,映射成字符串进行存储,使用的时候再重新解码
    int num = 0x00636261;
    int *pnum = &num;
    //char *psnum = pnum;  //出错，不能直接转换
    char *ps2num = reinterpret_cast<char *> (pnum);
    //char *ps3num = static_cast<char *>(pnum);  //出错，不允许int*到char*的强制转换
    cout << hex << *pnum << endl;
    //cout << *psnum << endl;
    cout << *ps2num << endl;
    cout << ps2num << endl;
    //cout << ps3num << endl;
    //double *dum = pnum;  //出错，不能直接转换
    double *dnum = reinterpret_cast<double*>(pnum);
    //double *d2num = static_cast<double*>(pnum);  //出错，不允许int*到double*的强制转换
    cout << *dnum << endl;
    //cout << *d2num << endl;



    /********  dynamic_cast  *********/
    //用于多态类型之间进行转换，支持向上，向下、横向类型间转换，在执行期会动态检查安全性
    //用于将父类的指针或引用转换为子类的指针或引用，此场景下父类必须要有虚函数，因为dynamic_cast是运行时检查，检查需要运行时信息RTTI，而RTTI存储在虚函数表中
    //https://www.cnblogs.com/weidagang2046/archive/2010/04/10/1709226.html
    //https://blog.csdn.net/hongkangwl/article/details/21161713
    
    
    
    /***************  为什么不用C语言的强制转换方式呢？？ ************/
    1) 首先C语言的强制类型转换不够明确，比较暴力，不能进行错误检查，容易出错；
        C++的强制类型转换可能根据需求不同选择不同的cast进行转换
    2) 同时，C++的强制转换提供了类型转换安全检查，且功能强大

    return 0;
}
```
