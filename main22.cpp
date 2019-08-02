#include <iostream>
using namespace std;

/*******************************************
                    C++ explicit

    按默认规定，传一个参数的构造函数也定义了一个隐式转换,
    多个参数，只有一个无默认值，其他参数都有默认值的情况也是这样

**********************************************/


class String{
    public:
      explicit String(int n){cout << "int" << endl;}
      String(const char *p){cout << "char *" << endl;}
};

int main()
{
    //String s0 = 5;  //错误：不能做隐式int->String转换，不可以把5包装成String类，要使没有explicit的话就可以
    //String s1 = 'a'; //错误：不能做隐式char(int)->String转换
    String s2(10);   //可以：调用explicit String(int n);
    String s3 = String(10);//可以：调用explicit String(int n);再调用默认的复制构造函数
    String s4 = "Brian"; //可以：隐式转换调用String(const char *p);再调用默认的复制构造函数,可以把"Brian"包装成String类
    String s5("Fawlty"); //可以：正常调用String(const char *p);

    return 0;
}

