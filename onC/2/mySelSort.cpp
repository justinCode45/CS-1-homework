#include <iostream>
#define MAXSIZE 100

using namespace std;

void fillArr(int a[], int maxsize, int &actualsize);

void selectionSort(int a[], int n);

int findMin(int a[], int *begin, int *end);

int main()
{
    int arr[MAXSIZE];
    int n;
    fillArr(arr, MAXSIZE, n);
    cout << "Echoing the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minidx = findMin(a, a + i, a + n);
        int temp = a[i];
        a[i] = a[minidx];
        a[minidx] = temp;
    }
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

int findMin(int a[], int *begin, int *end)
{
    int *minp = begin;
    for (; begin < end; begin++)
    {
        if (*begin < *minp)
        {
            minp = begin;
        }
    }
    return minp - a;
}