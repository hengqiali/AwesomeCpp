
#include <iostream>

using namespace std;

/****************************************

                 C++ 模板
       C++模板能帮助你解决相同函数面对不同数据类型时的困难
       1. 函数模板
       2. 类模板
       3. 模板特定化

*****************************************/


///////////    类模板 /////////////////

template <class T>   //模板， T可以自己替换任意类名

T addOperator(T x1, T x2){
    return x1 + x2;
}

template <class FIRST, class SECOND>  //定义了两种模板

FIRST smaller(FIRST a, SECOND b){
    return (a < b ? a : b);
}

int main()
{
    int a = 3, b = 4;
    double c = 3.2, d = 4.7;

    //当你定义的函数参数是int类型，而传递的实参是double时，肯定是不行的。相反亦如此。
    //此时模板可以解决此问题。思考一下，模板有时能解决函数重载的一部分应用
    cout << "a + b = " << addOperator(a, b) << endl;
    cout << "c + d = " << addOperator(c, d) << endl;

    cout << "the smaller number is " << smaller(a, c) << endl;
    cout << "the smaller number is " << smaller(c, b) << endl;
    return 0;
}

