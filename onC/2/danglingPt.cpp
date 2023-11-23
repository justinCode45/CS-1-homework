#include <iostream>

using namespace std;

int main()
{
    int *p;

    p = new int;
    *p = 42;
    cout << "*p = " << *p << endl;
    delete p;
    *p = 53;
    cout << "*p = " << *p << endl;



    return 0;
}