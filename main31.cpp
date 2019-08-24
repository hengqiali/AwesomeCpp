


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
    //答案都是4
    //即指针的内存大小只有CPU的位数有关，32位的都是4个字节，与指针类型无关
    //这个空间只是用来寻找和类型有关的内存
    return 0;

}
