


#include <iostream>
#include <stdlib.h>


using namespace std;

/**************************************

    C++ 关于指针变量所占内存空间大小的问题
    https://blog.csdn.net/cool_oyty/article/details/8078632

***************************************/
int main()
{
    int* a = (int *)malloc(10);

    std::cout << sizeof(a) << endl;

    std::cout << sizeof((int *)malloc(10)) << endl;
    std::cout << sizeof((double *)malloc(10)) << endl;
    std::cout << sizeof((char *)malloc(10)) << endl;

    return 0;

}
