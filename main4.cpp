
#include <iostream>

using namespace std;

/****************************************

                           C++ 继承
        
    1. 创建派生类时，会先调用基类构造函数，再调用派生类构造函数
    2. 销毁派生类时，会先调用派生类析构，再调用基类析构
    3. 析构函数需要定义为虚函数，这样在实现多态时才能调用子类的析构函数；否则只会调用父类的析构函数
        非多态时，满足1和2
    4. Fruit *f;不会调用构造函数

*****************************************/

class Fruit{
    public:
        Fruit(){ //构造函数，创建对象时自动调用
            cout << "创建Fruit" << endl;
        }
        ~Fruit(){ //前面带~，和名字和类名一样，代表是析构函数
            cout << "销毁Fruit" << endl;
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

/** Banana继承自Fruit **/
class Banana:public Fruit{ // :public Fruit 代表继承Fruit
    public:
        Banana(){cout << "创建Banana" << endl;};
        ~Banana(){cout << "销毁Banana" << endl;};
};

int main()
{
    string name;

    Fruit fru; //创建类对象fru,此时会自动调用构造函数
    Banana ban;
    cout << "子类会同时继承父类的构造函数和析构函数，以及public方法和变量" << endl;
    cout << "Banana类虽然没有实现setName()和getName()，但是它继承了Fruit父类的这两个函数" << endl;
    ban.setName("banana");  //类对象fru调用函数
    name = ban.getName();
    cout << "Banana's name = " << name << endl;

    return 0;
} //在作用域结束后,fru对象会销毁掉，此时会自动调用构造函数

