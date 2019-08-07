#include <iostream>

/*********************************************

    C++  static_cast  const_cast dynamic_cast

*********************************************/
void foo(int *num) //用于测试const_cast
{
    std::cout << "const_cast函数参数测试 " << *num << std::endl;
}

int main()
{
    /********  static_cast  *********/
    // 1. 强制类型转换，从大类型转换到小类型和从小类型转换到大类型都可以
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

    /********  dynamic_cast  *********/
    //用于将基类的指针或引用安全地转换成派生类的指针或引用

    return 0;
}
