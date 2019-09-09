
#include <iostream>

using namespace std;

/****************************************

                 C++ 操作符重载
       C++操作符重载能帮助运算符对我们自定义的类型进行操作
       1. 操作符重载实现为类成员函数
       2. 操作符重载实现为非类成员函数(全局函数)
       
       重载[]和()
       https://blog.csdn.net/neonlight/article/details/6065196
       https://blog.csdn.net/easylovecsdn/article/details/65643295

*****************************************/


class NumberOp{
    public:
        NumberOp(){}
        NumberOp(double x_){
            x = x_;
        }
        double getNum(){
            return x;
        }
        void setNum(double x_){
            x = x_;
        }
        NumberOp operator+(NumberOp a);     //1. 操作符重载实现为类成员函数
		NumberOp operator+(double a);
    private:
        double x;
};

NumberOp NumberOp::operator+(NumberOp a){   //1. 操作符重载实现为类成员函数
    NumberOp newOp;
    newOp.setNum(getNum() + a.x);

    return newOp;
}

NumberOp NumberOp::operator+(double a){   //1. 操作符重载实现为类成员函数
    NumberOp newOp;
    newOp.setNum(getNum() + a);

    return newOp;
}

NumberOp operator*(NumberOp a, NumberOp b){ //2. 操作符重载实现为非类成员函数(全局函数)
    NumberOp newOp;
    newOp.setNum(a.getNum() * b.getNum());
    return newOp;
}

int main()
{
    NumberOp n1(2.5), n2(3.7);
    NumberOp newN1, newN2, newN3;

    newN1 = n1 + n2;  //重载运算符后可以直接使用对象直接相加
	newN3 = n1 + 10.0;
    newN2 = n1 * n2;  //重载运算符后可以直接使用对象直接相加
    cout << "n1 + n2 = " << newN1.getNum()<< endl;
	cout << "n1 + 10.0 = " << newN3.getNum()<< endl;
    cout << "运算符重载实现为非类成员函数 : n1 * n2 = " << newN2.getNum() << endl;

    return 0;
}


--------------------------------------------------------------------------------------------------
//重载[]
class Vector
{
public:
    Vector(int a1, int a2, int a3, int a4) 
    {
        m_nGril[0] = a1 ; m_nGril[1] = a2 ;
        m_nGril[2] = a3 ; m_nGril[3] = a4 ;
    }
    int& operator[](int nIndex) ; // 重载数组下标运算符"[]"
private:
    int m_nGril[4] ;
};
//重载数组下标运算符"[]"：
 
int& Vector::operator[](int nIndex)
{
    if (nIndex < 0 || nIndex >= 4) // 数组越界检查 
    {   
        cout << "数组下标越界！" << endl ;
        return m_nGril[0] ;
    }
    return m_nGril[nIndex];
}
//测试代码：
 
int main()
{
    Vector vt(0, 1, 2, 3) ;
    cout << vt[2] << endl ;
    vt[3] = vt[2] ;
    cout << vt[3] << endl ;
    vt[2] = 22 ;
    cout << vt[2] << endl ;
    system("Pause");
    return 0 ;
}


--------------------------------------------------------------------------------------------------
//重载()
  class Matrix
{
public:
    Matrix(int, int) ;
    int& operator()(int, int) ; // 重载圆括号运算符"()"
private:
    int * m_nMatrix ;
    int m_nRow, m_nCol ;
};
Matrix::Matrix(int nRow, int nCol)
{
    m_nRow = nRow ;  
    m_nCol = nCol ;
    m_nMatrix = new int[nRow * nCol] ;
    for(int i = 0 ; i < nRow * nCol ; ++i)
    {
        *(m_nMatrix + i) = i ;
    }
}
//重载圆括号运算符"()"：
int& Matrix::operator()(int nRow, int nCol)
{
    return *(m_nMatrix + nRow * m_nCol + nCol) ; //返回矩阵中第nRow行第nCol列的值
}
//测试代码：
 
int main()
{
    Matrix mtx(10, 10) ;        //生成一个矩阵对象aM
    cout << mtx(3, 4) << endl ; //输出矩阵中位于第3行第4列的元素值
    mtx(3, 4) = 35 ;            //改变矩阵中位于第3行第4列的元素值
    cout << mtx(3, 4) << endl ;
    system("Pause") ;
    return 0 ;
}
