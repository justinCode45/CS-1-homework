#include <iostream>

using namespace std;

const int N = 100;

int main()
{
    int arr[N];
    int n = 0;

    cout << "Enter t most " << N << " non-negative ints." << endl;
    cout << "Mark the end of input with a negative number." << endl;

    while (n < N)
    {
        int input;
        cin >> input;
        if (input < 0)
            break;
        arr[n] = input;
        n++;
    }

    return 0;
}