#include <iostream>

using namespace std;

/****************************************

            C++ 类和对象:
    类只是多个变量和方法的简单组合而已
    
    C++中的类可以使用struct和class，二者唯一的区别就是默认访问权限不同
    struct默认访问权限是public
    class默认访问权限是private

*****************************************/

class Fruit{
    public:
        Fruit(){}  //构造函数，创建对象时调用，可以先不管后面会讲到

        /** 类实现函数，1.可以先声明再实现(如getName())，2.直接在类中实现(如setName()) **/
        string getName();//1. 先声明在实现
        void setName(string n){//2. 直接在类中实现
            name = n;
        }
    private:
        string name;  //名字
        double weight;//重量
        string color; //颜色
        int number;   //个数
};//注意分号

string Fruit::getName(){  //类函数的第一种实现方法， ::代表 作用域符，Fruit:: 代表在Fruit类中
    return name;
}

int main()
{
    string name;

    Fruit fru; //创建类对象fru
    fru.setName("banana");  //类对象fru调用函数
    name = fru.getName();

    cout << "name = " << name << endl;

    return 0;
}
