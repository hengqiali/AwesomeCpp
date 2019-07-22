

#include <iostream>

using namespace std;

/****************************************

                 C++ 模板
       C++模板能帮助你解决相同函数面对不同数据类型时的困难
       1. 函数模板
       2. 类模板
       3. 模板特定化 template specialization

*****************************************/


///////////    模板特化 /////////////////

template <class T>   //模板， T可以自己替换任意类名

class Compare{
    public:
        void foo(T x){
            cout << x << " is not a string" << endl;
        }
};

template <>

class Compare<string>{
    public:
        void foo(string x){
            cout << x << " is a string" << endl;
        }
};

int main()
{
    Compare<double> comp1;
    Compare<string> comp2;

    comp1.foo(2.35);
    comp2.foo("hi");

    return 0;
}












