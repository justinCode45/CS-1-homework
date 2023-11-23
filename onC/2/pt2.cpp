#include <iostream>


using namespace std;    

int main()
{
    int *p1,*p2;
    p1 = new int;
    *p1 = 42;
    p2 = p1;
    *p2 = 53;
    p1 = new int;
    *p1 = 88;
    delete p1;
    p2 = p1;

    return 0;
}