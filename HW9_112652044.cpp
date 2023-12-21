#include <iostream>
#include <chrono>
#include <tuple>
#include <functional>
#include <limits>
using namespace std;
using namespace std::chrono;

tuple<microseconds, int> time_it(function<int(int)> f, int n)
{
    auto start = high_resolution_clock::now();
    int result = f(n);
    auto end = high_resolution_clock::now();
    return make_tuple(duration_cast<microseconds>(end - start), result);
}

int trianNum_rec(int n)
{
    static int arr[20000]; // dp
    if (n < 20000 && arr[n] != 0)
        return arr[n];
    if (n == 0)
    {
        arr[0] = 0;
        return 0;
    }
    if (n == 1)
    {
        arr[1] = 1;
        return 1;
    }
    if (n == 2)
    {
        arr[2] = 3;
        return 3;
    }
    if (n < 10000)
    {
        arr[n] = 3 * trianNum_rec(n - 1) - 3 * trianNum_rec(n - 2) + trianNum_rec(n - 3);
        return arr[n];
    }
    return 3 * trianNum_rec(n - 1) - 3 * trianNum_rec(n - 2) + trianNum_rec(n - 3);
}

int trianNum_iter(int n)
{
    int a1 = 0;
    int a2 = 1;
    int a3 = 3;
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
        int temp = a3;
        a3 = 3 * a3 - 3 * a2 + a1;
        a1 = a2;
        a2 = temp;
    }
    return a3;
}

int main()
{
    int overflow_n = 10000;

    while (1)
    {

        int n;
        cout << "Enter a positive number: ";
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            cout << trianNum_iter(i) << " ";
            if ((i + 1) % 10 == 0)
                cout << endl;
        }
        cout << endl
             << endl;

        {
            auto result = time_it(trianNum_iter, n);
            cout << "trianNum_iter(" << n << ") = " << get<1>(result) << endl;
            cout << "Time used: " << get<0>(result).count() << " micorseconds" << endl;
        }
        cout << endl;
        if ( n < 20000)
        {
            auto result = time_it(trianNum_rec, n);
            cout << "trianNum_rec(" << n << ") = " << get<1>(result) << endl;
            cout << "Time used: " << get<0>(result).count() << " micorseconds" << endl;
        }
        else
        {
            cout << "trianNum_rec(" << n << ") " << "may cause stack overflow" << endl;
        }
        cout << endl;
        for (int i = overflow_n - 100; i <= 10000000000; i++)
        {
            if (trianNum_iter(i) < 0)
            {
                cout << " when n > " << i << " trainNum_iter(n) overflow" << endl;
                overflow_n = i;
                break;
            }
        }

        char again;
        cout << "Do you want to continue? (y/n): ";
        cin >> again;
        if (again == 'n' || again == 'N')
        {
            break;
        }
    }

    return 0;
}