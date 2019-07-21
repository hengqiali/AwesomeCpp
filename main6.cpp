#include <iostream>

using namespace std;

/****************************************

                 C++ 重写
       1. Override,重写主要发生在继承关系中
       2. 主要重写的方法体，方法的参数和返回值必须一致

*****************************************/


class Fruit{
    public:
        void foo(){
            cout << "Fruit::foo被调用" << endl;
        }
};


class Banana:public Fruit{
    public:
        void foo(){   //重写基类的foo方法，要求返回值和参数个数、参数类型完全一致
            cout << "Banana::foo被调用" << endl;
        }
};


int main()
{
    Fruit fru;
    Banana ban;

    fru.foo();
    ban.foo();

    // 思考和多态的区别和联系
    return 0;
}


