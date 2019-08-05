
#include <iostream>
#include <typeinfo>
#include <cassert>




using namespace std;

/******************************************

                C++

    1. assert   断言，运行时判断，无要求，比较方便
    2. static_assert  静态断言，编译时判断，需要判断的表达式是常量，即在编译时即可运算的，所以判断的范围比较局限

******************************************/

int main()
{
    const int a = 50;
    //const int b = 50;
    const double b = .5;
    char c = 'c';


    assert(typeid(a).name() == typeid(b).name());
    static_assert(a == b, "err");
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
}

/*
template <typename T, typename U> int bit_copy(T& a, U& b){
    //assert(sizeof(b) == sizeof(a));
    static_assert(sizeof(b) == sizeof(a), "template parameter size no equal!");
    memcpy(&a,&b,sizeof(b));
};

int main()
{
    int aaa = 0x2468;
    double bbb;
    bit_copy(aaa, bbb);
    getchar();
    return 0;
}*/

