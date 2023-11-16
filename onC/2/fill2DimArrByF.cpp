#include <iostream>

using namespace std;

const int N1 = 100, N2 = 200;

void fillArr(int **arr, int &nr, int &nc);

int main()
{
    int **arr;

    arr = new int *[N1];
    for (int i = 0; i < N1; i++)
    {
        arr[i] = new int[N2];
    }

    int nr, nc;
    fillArr(arr, nr, nc);

    

    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    delete[] arr;
    return 0;
}

void fillArr(int **arr, int &nr, int &nc)
{

    cout << "Enter nr (no large than " << N1 << "): ";
    cin >> nr;
    cout << "Enter nc (no large than " << N2 << "): ";
    cin >> nc;

    cout << "Enter " << nr << " rows, " << nc << " ints each." << endl;
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            cin >> arr[i][j];
        }
    }

}