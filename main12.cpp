

#include <iostream>

using namespace std;

/*********************************************************************************************************************************************

                                                            C++ 友元
    在C++中，我们使用类对数据进行了隐藏和封装，类的数据成员一般都定义为私有成员，成员函数一般都定义为公有的，以此提供类与外界的通讯接口；
    但是，有时需要定义一些函数，这些函数不是类的一部分，但又需要频繁地访问类的数据成员，这时可以将这些函数定义为该函数的友元函数；
    除了友元函数外，还有友元类，两者统称为友元。友元类的所有成员函数都是另一个类的友元函数，都可以访问另一个类中的隐藏信息（包括私有成员和保护成员）；
    友元的作用是提高了程序的运行效率（即减少了类型检查和安全性检查等都需要时间开销），但它破坏了类的封装性和隐藏性，使得非成员函数可以访问类的私有成员

    1. 友元函数
    2. 友元类

**********************************************************************************************************************************************/

class Fruit{
    public:
        Fruit(string n){
            name = n;
        }
        void fruitName(Fruit fru);  //类成员函数，可以访问类的私有变量
        friend void fruitNameFriend(Fruit fru);  //友元函数，不是类成员函数，但声明为友元函数之后可以访问私有变量
    private:
        string name;
};

void Fruit::fruitName(Fruit fru){  //类成员函数要有类作用域
    string name = fru.name;

    cout << "Fruit name is " + name << endl;
}

void fruitNameFriend(Fruit fru){  //注意，这里不能写成Friut::fruitNameFriend(Fruit fru)
    string name = fru.name;

    cout << "Fruit name is " + name << endl;
}

int main()
{
    Fruit fru("banana");

    cout << "注意对比友元函数和类成员函数的区别" << endl;
    fru.fruitName(fru);
    fruitNameFriend(fru);

    return 0;
}
