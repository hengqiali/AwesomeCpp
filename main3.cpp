#include <iostream>

using namespace std;

/****************************************

        C++ 构造函数和析构函数:

        1. 构造函数在类创建对象时自动调用
        2. 析构函数在类对象销毁时自动调用

*****************************************/

class Fruit{
    public:
        Fruit(){ //构造函数，创建对象时自动调用
            cout << "我是构造函数，创建类对象时会自动调用,我的名字必须和类名相同，" <<
                "我不能有返回值，即使是void也不能有，但是我可以有一个或者多个参数!" << endl;
        }
        ~Fruit(){ //前面带~，和名字和类名一样，代表是析构函数
            cout << "我是析构函数，销毁类对象时会自动调用,我的名字必须和类名相同，" <<
                "我不能有返回值，即使是void也不能有，我也不能有任何的参数!" << endl;
        }
        string getName();//先声明再实现
        void setName(string n);//先声明再实现
    private:
        string name;  //名字
        double weight;//重量
        string color; //颜色
        int number;   //个数
};//注意分号

string Fruit::getName(){  //::代表 作用域符，Fruit::getName 代表在Fruit类中的getName函数
    return name;
}

void Fruit::setName(string n){
    name = n;
}

int main()
{
    string name;

    Fruit fru; //创建类对象fru,此时会自动调用构造函数

    fru.setName("banana");  //类对象fru调用函数
    name = fru.getName();
    cout << "name = " << name << endl;

    return 0;
} //在作用域结束后,fru对象会销毁掉，此时会自动调用构造函数

