#include <iostream>
#include <ctime>
using namespace std;

int fib_r(int n);

int fib_i(int n);

int main()
{
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    time_t start, end;

    start = time(NULL);
    int result = fib_r(n);
    end = time(NULL);
    cout << "fib_r(" << n << ") = " << result << endl;
    cout << "Time used: " << end - start << " seconds." << endl;

    start = time(NULL);
    result = fib_i(n);
    end = time(NULL);
    cout << "fib_i(" << n << ") = " << result << endl;
    cout << "Time used: " << end - start << " seconds." << endl;
    

    return 0;
}

int fib_r(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fib_r(n-1) + fib_r(n-2);
}

int fib_i(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int f0 = 1;
    int f1 = 1;
    int f2 = 0;
    for (int i = 2; i <= n; i++)
    {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }

    return f2;
}