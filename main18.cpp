#include <iostream>
using namespace std;

/*******************************************
                    C++ 预编译

预处理器是一些指令，指示编译器在实际编译之前所需完成的预处理；
所有的预处理器指令都是以井号（#）开头，只有空格字符可以出现在预处理指令之前。预处理指令不是 C++ 语句，所以它们不会以分号（;）结尾；
之前所有的实例中都有 #include 指令。这个宏用于把头文件包含到源文件中；
C++ 还支持很多预处理指令，比如 #include、#define、#if、#else、#line 等；

**********************************************/


#define PI 3.14  //常量宏

#define MIN(a, b) (a < b ? a : b)  //参数宏

#define TEST



int main()
{
    double r  = 2.5;
    int a = 20, b = 34;

    cout << "area of circle is " << PI * r * r << endl;
    cout << "the smaller number is " << MIN(a, b) << endl;

#ifdef TEST  //前面已经宏定义了TEST
    cout << "this is test code ! " << endl;
#endif // TEST

#ifdef 0  //如果是0的话，就不会被输出
    cout << "these codes won't not print" << endl;
#endif // 0
    return 0;
}
