
#include <iostream>

using namespace std;

/***********************************

                        C++ 虚函数表
    https://blog.csdn.net/lihao21/article/details/50688337
    虚表是在编译阶段就确定的，每个元素是一个虚函数指针，此时的虚表属于类，不属于对象
    每个对象都有一个虚表指针 *_vptr指向类的虚表，虚表指针在生成对象时自动生成
    普通的函数即非虚函数，其调用并不需要经过虚表，所以虚表的元素并不包括普通函数的函数指针
    虚函数调用需要经过虚表
    继承时会继承虚表，更新重写的虚函数 https://bbs.csdn.net/topics/390454343
    所以会实现多态
***********************************/

class A{
public:
    void f1(){cout << "f1" << endl;}
    virtual void f2(){cout << "f2" << endl;}
};

int main()
{
    A *a = new A;
    a->f1();
    a->f2();

    A *a1 = nullptr;  //虚函数调用需要经过虚表，没生成对象，没有虚表指针，找不到虚表，所以找不到虚函数
    a1->f1();
    a1->f2();

    return 0;
}
