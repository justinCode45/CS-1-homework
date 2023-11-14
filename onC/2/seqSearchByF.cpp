#include <iostream>
#define N 100
using namespace std;

void fillArr(int a[], int maxsize, int &actualsize);

int search(int a[], int n, int target);

int main()
{
    int arr[N];
    int n;
    int tindex;
    int target;

    fillArr(arr, N, n);
    cout << "Enter target: ";
    cin >> target;
    tindex = search(arr, n, target);

    if (tindex >= 0)
        cout << "Found at index " << tindex << endl;
    else
        cout << "Not found." << endl;


    return 0;
}

void fillArr(int a[], int maxsize, int &actualsize)
{
    actualsize = 0;
    cout << "Enter n (no larger than " << maxsize << "): ";
    cout << "Enter t most " << maxsize << " non-negative ints." << endl;
    cout << "Mark the end of input with a negative number." << endl;

    while (actualsize < maxsize)
    {
        int input;
        cin >> input;
        if (input < 0)
            break;
        a[actualsize] = input;
        actualsize++;
    }
}

int search(int a[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
            return i;
    }
    return -1;
}