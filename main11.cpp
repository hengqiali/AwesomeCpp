
#include <iostream>

using namespace std;

/****************************************

                 C++ 操作符重载
       C++操作符重载能帮助运算符对我们自定义的类型进行操作
       1. 操作符重载实现为类成员函数
       2. 操作符重载实现为非类成员函数(全局函数)

*****************************************/


class NumberOp{
    public:
        NumberOp(){}
        NumberOp(double x_){
            x = x_;
        }
        double getNum(){
            return x;
        }
        void setNum(double x_){
            x = x_;
        }
        NumberOp operator+(NumberOp a);     //1. 操作符重载实现为类成员函数
    private:
        double x;
};

NumberOp NumberOp::operator+(NumberOp a){   //1. 操作符重载实现为类成员函数
    NumberOp newOp;
    newOp.setNum(getNum() + a.x);

    return newOp;
}

NumberOp operator*(NumberOp a, NumberOp b){ //2. 操作符重载实现为非类成员函数(全局函数)
    NumberOp newOp;
    newOp.setNum(a.getNum() * b.getNum());
    return newOp;
}

int main()
{
    NumberOp n1(2.5), n2(3.7);
    NumberOp newN1, newN2;

    newN1 = n1 + n2;  //重载运算符后可以直接使用对象直接相加
    newN2 = n1 * n2;  //重载运算符后可以直接使用对象直接相加
    cout << "运算符重载实现为类成员函数 : n1 + n2 = " << newN1.getNum()<< endl;
    cout << "运算符重载实现为非类成员函数 : n1 * n2 = " << newN2.getNum() << endl;

    return 0;
}
