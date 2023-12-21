#include <iostream>
#define L 1
#define M 2
#define R 3
using namespace std;

void hanoi(int n, int s, int d);

int main()
{
    int n;
    cout << "Enter a positive number:"<<endl;
    cin >> n;
    hanoi(n, L, R);
    return 0;
}

void hanoi(int n, int s, int d)
{
    if (n == 0)
    {
        return;
    }
    int temp = 6 - s -d;
    hanoi(n - 1, s, temp);
    cout << "move disk from " << s << " to " << d << endl;
    hanoi(n-1,temp,d);
}