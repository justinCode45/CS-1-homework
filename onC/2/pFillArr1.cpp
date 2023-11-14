#include <iostream>

using namespace std;

const int N = 100;

int main()
{
    int arr[N];
    int n;

    cout << "Enter n (no large than " << N << ": ";
    cin >> n;

    if (n <= N)
    {
        cout << "Enter " << n << " ints." << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    return 0;
}