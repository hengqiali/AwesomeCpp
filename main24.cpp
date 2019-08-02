#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> v = {1,2,3,4,5};

    for(auto i : v)
        cout << i << endl;
    for(vector<double>::iterator iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << endl;
    for(auto iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << endl;
}
