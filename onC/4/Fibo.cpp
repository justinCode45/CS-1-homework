#include <iostream>

using namespace std;

int F(int n);

int main()
{
    int n;
    cout << "Enter a number(non-negative): ";
    cin >> n;
    if (n >= 0)
        cout << "F(" << n << ") = " << F(n) << endl;

    return 0;
}

int F(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return F(n - 1) + F(n - 2);
}