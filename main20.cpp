#include <iostream>
#include <fstream>

using namespace std;

/*******************************************************

                C++ const
               
        1. 当const在*的前面时，允许修改指针p的位置，而不允许修改*p的值
        2. 当const在*的后面时，指针p不能变，*p可以变
        3. 当const在*的前后都有时，指针p不能变，*p也不可以变
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
