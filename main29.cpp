
#include <iostream>

using namespace std;

int main()
{
    /******************    enum枚举 --符号常量集合     **********************/
    /* https://www.runoob.com/w3cnote/cpp-enums-intro-and-strongly-typed.html 
    https://www.cnblogs.com/ForFreeDom/archive/2012/03/22/2412055.html*/
    enum Color {RED = 50, GREEN = 1, BLUE = 25};   //枚举类型，符号常量外围可见
    //enum {RED = 50, GREEN = 1, BLUE = 25};   //Color可省略

    enum class StrongColor:int{RED = 5, YELLOW = 30}; //强枚举类型，只在StrongColor域中可见

    int Color_RED = RED; //correct
    cout << Color_RED << GREEN << BLUE << endl;
    cout << RED << GREEN << BLUE << endl; //  无域默认调用枚举类型符号常量
    cout << Color::RED << endl;

    //int Strong_RED = StrongColor::RED;  //error
    StrongColor my = StrongColor::RED; //这块可以定义新的枚举常量了，所以不建议用强枚举类型
    cout << static_cast<int>(my) << endl;
    cout << static_cast<int>(StrongColor::RED) << endl;

    /******************    union联合 --节省内存      **********************/
    //https://blog.csdn.net/u013066730/article/details/84638489
    
}



