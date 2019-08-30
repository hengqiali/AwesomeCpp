#include <iostream>
#include <fstream>

using namespace std;

/*******************************************************

                C++ const与指针
               
        1. 当const在*的前面时，允许修改指针p的位置，而不允许修改*p的值
        2. 当const在*的后面时，指针p不能变，*p可以变
        3. 当const在*的前后都有时，指针p不能变，*p也不可以变
        4. 顶层const表示指针本身是个常量， 底层const表示指针所指对象是一个常量
        
                C++ const与成员函数
        https://www.cnblogs.com/wintergrass/archive/2011/04/15/2015020.html
        const放在返回值类型前面修饰返回值为常量，放在函数后面修饰该函数为常量函数。
        在类中将成员函数修饰为const表明在该函数体内，不能修改对象的数据成员而且不能调用非const函数。
        为什么不能调用非const函数？因为非const函数可能修改数据成员，const成员函数是不能修改数据成员的，
        所以在const成员函数内只能调用const函数
        
*******************************************************/

int main()
{
    double num = 8;
    const double *p = &num;  //当const在*的前面时，允许修改指针p的位置，而不允许修改*p（即num）的值,等价于double const *p = &num

    cout << p << endl;
    p++;
    cout << p << endl;
    //*p = 5;
    //cout << *p << num << endl;

    double num2 = 10;
    double* const p2 = &num2; //当const在*的后面时，指针p不能变，*p可以变

    cout << p2 << endl;
    //p2++;
    //cout << p2 << endl;

    *p2 = 3;
    cout << *p2 << num2 << endl;

    double num3 = 5;
    const double* const p3 = &num3; //当const在*的前后都有时，指针p不能变，*p也不可以变

    cout << p3 << endl;
    //  p2++;
    //cout << p2 << endl;

    //*p3 = 3;
    //cout << *p3 << num3 << endl;

    return 0;
}
