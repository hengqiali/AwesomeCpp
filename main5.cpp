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
/////////////////////  第一个例子 ///////////////////////
class CBase{
public:
    //explicit CBase(){std::cout << "constructors()" << std::endl;}
    CBase(){std::cout << "constructors()" << std::endl;};
    //CBase() = default;  //等价于CBase(){};
    CBase(int a_, int c_):a(a_), c(c_){std::cout << "constructors(CBase)" << std::endl;}
    virtual void foo(){std::cout << "CBase" << std::endl;}
    //void foo(){std::cout << "CBase" << std::endl;}
    int a;
private:
    int c;
};

class CChild:public CBase{
public:
    CChild(int d_, int e_):d(d_),e(e_){std::cout << "constructors(CChild)" << std::endl;}
    void f(){std::cout << "CChild" << std::endl;}
    void foo(){std::cout << "测试" << std::endl;}
    int d;
private:
    int e;
};

int main()
{
    CBase base(54,6);   //单独定义基类
    CChild child = CChild(2,3);  //单独定义子类

    //base.c;
    child.a;

    base.foo();   //此时没有相互影响，各自调各自的成员
    child.f();
    child.foo();

    CBase b;     //会调默认的构造函数
    CBase b2();  //不会调默认的构造函数

    CBase *b3 = new CChild(1,2);   //和生成CChild对象一样调一次父类的默认构造函数和子类的构造函数，CBase *b3不会调基类的构造函数
    b3->foo();   //如果基类中有虚函数并且子类重写了，此时才会调用子类的函数（多态），否则其他情况下都是调用基类的成员
    //b3->f();   //出错
    //b3->d;     //出错
    CBase b4 = CChild(45,6);  //和生成CChild对象一样调一次父类的默认构造函数和子类的构造函数
    b4.foo(); //CBase
    b4.d;     //出错
}

/////////////////////  第二个例子 ///////////////////////
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

