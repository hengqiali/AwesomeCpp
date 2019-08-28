#include <iostream>
#include <boost/shared_array.hpp>
#include <cstring>
using namespace std;

int main()
{
    boost::shared_array<double[3]> p(new double[3][3]);
    for(int i = 0; i < 3; i++)
    {
        memset(p[i], 0, sizeof(double) * 3);
    }
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            //p[i][j] = i + i * j;
            cout << p[i][j] << endl;
        }
    //cout << p[2][2] << endl;
    int **k = new int*[3];
    for(int i = 0; i < 3; i++){
        k[i] = new int[4];
        memset(k[i], 0, sizeof(int)* 4);
    }


    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++){
            cout << k[i][j] << endl;
        }

    return 0;
}


