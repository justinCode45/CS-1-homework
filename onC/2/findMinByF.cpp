#include <iostream>
#define MAXSIZE 100
using namespace std;

void fillArr(int a[], int maxsize, int &actualsize);

int findMin(int a[], int *begin, int *end);

int main()
{
    int arr[MAXSIZE];
    int n;
    int midx;

    fillArr(arr, MAXSIZE, n);
    midx = findMin(arr, arr, arr + n);
    cout << "Min is at index " << midx << endl;
    cout << "Min is " << arr[midx] << endl;

    return 0;
}

void fillArr(int a[], int maxsize, int &actualsize)
{
    actualsize=0;
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
    int* minp=begin;
    for(;begin<end;begin++)
    {
        if (*begin<*minp)
        {
            minp=begin;
        }
    }
    return minp-a;
}