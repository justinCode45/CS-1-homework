#include <iostream>

using namespace std;

int f(int n);

int main()
{
    int n;
    cout << "This program computes n!." << endl;
    cout << "Enter n (a positive int): ";
    cin >> n;
    cout << n << "! = " << f(n) << endl;
    cout << "Value of n inside function f: " << n << endl;
    return 0;
}

int f(int n)
{
    int result = 1;
    while (n > 0)
    {
        result *= n;
        n--;
    }
    return result;
}