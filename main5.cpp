#include <iostream>

using namespace std;

/****************************************

                                         C++ 虚函数和多态
      1. 虚函数是在基类中使用virtual声明的函数。当在编写类函数代码的时候，不确定调用
         的基类的类函数代码还是派生类的类函数代码，即需要在运行时刻确定（动态绑定），所以定义为"虚"函数。
      2. 当在基类中没有具体的实现、但要求每个派生类必须实现此类函数时，需要纯虚函数。其在基类中声明但不实现，且在函数原型后必须加"=0"，
         如 virtual void function()=0;
      3. 多态就是多种形态、动态绑定。多态和虚函数紧密相连，其意味着：当对象调用类函数时，根据对象类型来执行不同的函数。

      更多需要注意的点：
      1. 在很多情况下，基类本身生成对象是不合情理的。例如，动物作为一个基类可以派生出老虎、孔雀等子类，但动物本身生成对象明显不合常理，
         所以需要纯虚函数以实现多态。含有纯虚函数的类称为抽象类，它不能生成对象；
      2. 友元不是成员函数，只有成员函数才可以是虚拟的，因此友元不能是虚拟函数；
      3. 析构函数需要定义为虚函数，这样在实现多态时才能调用子类的析构函数；否则只会调用父类的析构函数
*****************************************/


class Fruit{
    public:
        Fruit(){cout << "父类构造函数" << endl;}
        virtual ~Fruit(){cout << "父类析构函数" << endl;}  // 析构函数需定义为虚函数
        virtual void foo(){   //实现多态必须是虚函数，如果基类不是虚函数，则只能实现重写，不能实现多态
            cout << "Fruit::foo()被调用" << endl;
        }
        //virtual void foo() = 0;  //纯虚函数，此时类不能定义对象
    private:
        string name;
        double weight;
        string color;
        int number;

};


class Banana:public Fruit{
    public:
        Banana(){cout << "子类构造函数" << endl;}
        ~Banana(){cout << "子类析构函数" << endl;}
        void foo(){  //重写实现多态
            cout << "Banana::foo()被调用" << endl;
        }
};


int main()
{
    //多态
    Fruit *fru1 = new Fruit();
    Fruit *fru2 = new Banana();

    fru1->foo();
    fru2->foo();

    //调用析构函数，分析虚构函数为什么需要是虚函数
    delete fru1;
    delete fru2;

    return 0;
}

