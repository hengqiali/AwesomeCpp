#include <iostream>

using namespace std;

/****************************************

                 C++ 重载
       1. Overload,重载主要发生在同一作用域中
       2. 和重写不同，重载只要求方法名一致，方法的参数和返回值可以不同

*****************************************/


class Fruit{
    public:
        double add_tare_and_core(double tareWeight, double coreWeight){
            cout << "double" << endl;
            return tareWeight + coreWeight;
        }
        int add_tare_and_core(int tareWeight, int coreWeight){  // 重载上面的函数
            cout << "int" << endl;
            return tareWeight + coreWeight;
        }
};



int main()
{
    Fruit fru;

    cout << "重载会根据参数个数和类型来自动调用对应函数" << endl;
    cout << fru.add_tare_and_core(5.33, 2.81) << endl;
    cout << fru.add_tare_and_core(5, 3) << endl;

    return 0;
}


