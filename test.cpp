#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

const int N =10;
const int W = 10;
const int M = 100;

int main()
{
    int n;
    
    cout << "RAND_MAX=" << RAND_MAX << endl << endl;
    
    srand(time(0));
    
    cout << N << " numbers in range 0 to " << RAND_MAX << endl;
    for(int i = 1; i <= N; i++)
    {
        n=rand();
        cout << setw(W) << i << setw(W) << n << endl;
    }
    cout << endl;
    
    cout << N << " numbers in range 0 to " << M-1 << endl;
    for(int i = 1; i <= N; i++)
    {
        n = rand()%M;
        cout << setw(W) << i << setw(W) << n << endl;
    }
    cout << endl;
    
    cout << N << " numbers in range 0 to " << M <<endl;
    for(int i = 1; i <= N; i++)
    {
        n = rand()%M+1;
        cout << setw(W) << i << setw(W) << n << endl;
    }
    cout << endl;
    
    return 0;
}