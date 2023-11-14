#include <iostream>

using namespace std;

const int N = 100;

void justOutput(int v);

void adjust(int &v);

int main()
{
    int a[N];
    int n;

    cout << "This program finds the minimum of n int." << endl;
    cout << "Enter n (no large than " << N << ": ";
    cin >> n;

    cout << "Enter " << n << " ints." << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        justOutput(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        adjust(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        justOutput(a[i]);
    }

    return 0;
}

void justOutput(int v)
{
    cout << v << endl;
}

void adjust(int &v)
{
    v += 5;
}