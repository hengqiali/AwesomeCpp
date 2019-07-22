#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1("HI I am a pretty boy!");

    cout << "s1.substr(10, 6) = " << s1.substr(10, 6) << endl;  //截取子字符串，从第10个字符开始截取长度为6的子字符串

    string s2("I am a s and am a b");
    cout << "s2.find(am) = " << s2.find("am") << endl;   //寻找子字符串的位置
    cout << "s2.rfind(am) = " << s2.rfind("am") << endl; //从字符串末尾开始寻找

    string s3("interesting");
    cout << "s3 = " << s3 << endl;
    cout << "s3.erase(3, 5) = " << s3.erase(3, 5) << endl; //删除子字符串，从第3个字符开始删除长度为5的子字符串，调用之后会直接改变原字符串

    string s4("amazing");
    cout << "s4 = " << s4 << endl;
    cout << "s4.replace(3, 2) = " << s4.replace(3, 2, "HHHHH") << endl; //替换子字符串，从第3个字符开始替换长度为2的子字符串，调用之后会直接改变原字符串

    string s5("comeon");
    cout << "s5 = " << s5 << endl;
    cout << "s5.insert(3, \"lucky\") = " << s5.insert(3, "lucky") << endl; //插入子字符串，从第3个字符开始插入子字符串，调用之后会直接改变原字符串

    string one("apple"), two("banana");
    cout << "swap之前 : one = " << one << "\t two = " << two << endl; //交换字符串，交换之后直接改变原字符串
    one.swap(two);
    cout << "swap之后 : one = " << one << "\t two = " << two << endl;


    return 0;
}
