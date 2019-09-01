


#include <iostream>
#include <stdlib.h>


using namespace std;

/**************************************

    C++ 关于指针变量所占内存空间大小的问题
    https://blog.csdn.net/cool_oyty/article/details/8078632
    C++ string、char*、char[],sizeof不是函数，更像宏
    https://blog.csdn.net/lanchunhui/article/details/50738498

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
    
    
    string s = "";
    string ss = "Hello";
    char* css = "Hello";
    char ccss[] = "Hello";
    string sss = "Hlo";
    cout << sizeof (string) << endl; //4
    cout << sizeof (s) << endl;  //4
    cout << sizeof (ss) << endl;  //4
    cout << sizeof (css) << endl;  //4
    cout << sizeof (ccss) << endl;  //6
    cout << sizeof (sss) << endl;  //4
    cout << sizeof (new string()) << endl; //4
    //此时的sizeof里面传的其实是char *，'\0'也算一个字符
    //字符串中的"\0"问题  https://blog.csdn.net/jesse621/article/details/8033183
    cout << sizeof ("Hello") << endl; //6
    cout << sizeof ("He") << endl; //3
    cout << sizeof ("H") << endl;  //2

    int a = 0;

    cout<<sizeof(a=3)<<endl;

    cout<<a<<endl;
    return 0;

}
