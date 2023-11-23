#include <iostream>

using namespace std;

int main()
{
    int *p, v;
    v = 0;
    p = &v;
    *p = 42;

    cout << v << endl;
    
    return 0;
}