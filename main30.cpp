
#include <iostream>

using namespace std;


/******************    struct --内存对齐      **********************/
/*
内存对齐主要遵循下面三个原则:
1. 结构体变量的起始地址能够被其最宽的成员大小整除
2. 结构体每个成员相对于起始地址的偏移能够被其自身大小整除，如果不能则在前一个成员后面补充字节
3. 结构体总体大小能够被最宽的成员的大小整除，如不能则在后面补充字节

其实这里有点不严谨，编译器在编译的时候是可以指定对齐大小的，实际使用的有效对齐其实是取指定大小和自身大小的最小值，一般默认的对齐大小是4。
再回到上面的例子，如果默认的对齐大小是4，结构体a的其实地址为0x0000，能够被最宽的数据成员大小(这里是int， 大小为4，有效对齐大小也是4)整除，
故char a的从0x0000开始存放占用一个字节即0x0000~0x0001，然后是int b，其大小为4，故要满足2，需要从0x0004开始，所以在char a后填充三个字节，
因此a对齐后占用的空间是0x0000~0x0003，b占用的空间是0x0004~0x0007, 然后是short c其大小是2，故从0x0008开始占用两个字节，即0x0008~0x0009。
此时整个结构体占用的空间是0x0000~0x0009， 占用10个字节，10%4 ！= 0,
不满足第三个原则，所以需要在后面补充一个字节，即最后内存对齐后占用的空间是0x0000~0x000B，一共12个字节。

https://levphy.github.io/2017/03/23/memory-alignment.html
https://www.zhihu.com/question/27862634
*/

struct{
    char a; //0->1（7），1还没占
    double b; //偏移的是0->7总共8个字节是8的整数倍，占8->16，16还没占
    short c; //16->18，18还没占 总共0-17
} test1;

struct{
    char a; //0->2，2还没占
    int b; //4->8  8还没占
    short c; //8->10（12），10还没占，补充到0-11
} test2;

struct{
    char a; //0->1
    short c; //2->4
    int b; //4->8
} test3;

struct{
    int b; //0->4
    char a; //4->5
    short c; //跳过0-5，6->8，8还没占
} test4;

struct{
    int number;             //0->4
    union UBffer
    {
        char buffer[13];    //4->17 17还没占
        int number;
    }ubuf;
    int aa;                 //17开始的话，偏移了0-16 = 17不行，得偏移20个字节，所以0->20  20还没占,所以当前占20->24
    double dou;             //24->32   0--31
}test5;

struct {
    short number;  // 0->8
    union UBffer
    {
        char buffer[13];  //相当于偏移了0-7，8没占，8->21，21还没占，但是为了内存补齐规则3，必须得是8->24,24没占
        double number;
    }ubuf;
}test6;

struct {
    short number;  // 0->8
    union UBffer
    {
        char buffer[13];  //相当于偏移了0-7，8没占，8->21，21还没占，但是为了内存补齐规则3，必须得是8->24,24没占
        double number;
    }ubuf;
    char a;   //24->32
    double b; //32->40  所以最后是0-39 占用40个B
}test7;

int main()
{
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;

    cout << sizeof(test1) << endl;  // 24
    cout << sizeof(test2) << endl;  // 12
    cout << sizeof(test3) << endl;  // 8
    cout << sizeof(test4) << endl;  // 8
    cout << sizeof(test5) << endl;  // 32
    cout << sizeof(test6) << endl;  // 24
    cout << sizeof(test7) << endl;  // 40

    return 0;
}



