#include <iostream>

using namespace std;


using intPtr =int*;

void sneaky(intPtr x)
{
    *x = 99 ;
    cout << *x << " ";  
}

int main()
{
    intPtr p = new int;
    *p = 77;
    cout << *p << " ";
    sneaky(p);
    cout << *p << endl;
    return 0;
}