#include <iostream>
#include <exception>
using namespace std;

/****************************************

            C++ 异常

*****************************************/

int main()
{
    int x;
    int y;

    cout << "请输入整数：" << endl;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    try   //try包含需要异常检查的代码块
    {
        if(x < y)
            throw 0;  //抛出异常1
        else
            throw 1;  //抛出异常2
    }
    catch(int e)  //捕获异常  catch(std::exception e)   cout << e.what();
    {
        switch(e) //根据异常类型分别处理
        {
        case 0:
            cout << "x 小于 y" << endl;
            break;
        case 1:
            cout << "x 大于 y" << endl;
            break;
        }
    }
}
