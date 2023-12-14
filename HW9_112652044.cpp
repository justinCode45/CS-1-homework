#include <iostream>
#include <chrono>
#include <tuple>
#include <functional>
#include <limits>

using namespace std;
using namespace std::chrono;


tuple<milliseconds, long long> time_it(function<int(long long)> f, int n)
{
    auto start = steady_clock::now();
    long long result = f(n);
    auto end = steady_clock::now();
    return make_tuple(duration_cast<milliseconds>(end - start), result);
}

long long trianNum_rec(int n)
{
    static long long arr[10000];
    std::fill(arr, arr + 10000, -1);
    if (n<10000 && arr[n] != -1)
        return arr[n];
    if (n == 0)
    {
        arr[0]=0;
        return 0;
    }
    if (n == 1)
    {
        arr[1]=1;
        return 1;
    }
    if (n == 2)
    {
        arr[2]=3;
        return 3;
    }
    arr[n] = 3*trianNum_rec(n - 1) - 3*trianNum_rec(n - 2) + trianNum_rec(n - 3);
    return arr[n];
}

long long trianNum_iter(int n)
{
    long long a1 = 0;
    long long a2 = 1;
    long long a3 = 3;
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 3;
    }
    for (int i = 3; i <= n; i++)
    {
        long long temp = a3;
        a3 = 3*a3 - 3*a2 + a1;
        a1 = a2;
        a2 = temp;
    }
    return a3;
}

int main()
{
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    // auto result = time_it(trianNum_rec, n);
    // cout << "trianNum_rec(" << n << ") = " << get<1>(result) << endl;
    // cout << "Time used: " << get<0>(result).count() << " milliseconds." << endl;

    auto result = time_it(trianNum_iter, n);
    cout << "trianNum_iter(" << n << ") = " << get<1>(result) << endl;
    cout << "Time used: " << get<0>(result).count() << " milliseconds." << endl;

    return 0;
}