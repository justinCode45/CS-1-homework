#include <iostream>

using namespace std;


int fact(int n);


int main()
{
    int n;
    cout << "Enter a number(non-negative): ";
    cin >> n;
    if (n >= 0)
        cout << "F(" << n << ") = " << fact(n) << endl;
    return 0;
}


int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n-1);
}