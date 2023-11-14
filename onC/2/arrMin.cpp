#include <iostream>

using namespace std;

const int N = 100;

int main()
{
    int a[N];
    int n;
    int midx;

    cout << "This program finds the minimum of n int." << endl;
    cout << "Enter n (no large than " << N << ": ";
    cin >> n;

    cout << "Enter " << n << " ints." << endl;

    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    midx=0;

    for (int i=0;i<n;i++)
    {
        if (a[i]<a[midx])
        {
            midx=i;
        }
    }

    cout << "Minimum element is at a[" << midx << "]"<< "and its value is "<< a[midx] << endl;

    return 0;
}