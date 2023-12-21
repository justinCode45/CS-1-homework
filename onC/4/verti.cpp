#include <iostream>

using namespace std;

void writeVertical(int n);

int main()
{
    cout << "Enter a positive int" << endl;
    int n;
    cin >> n;
    writeVertical(n);
    return 0;
}

void writeVertical(int n)
{
    if (n < 10)
    {
        cout << n << endl;
        return ;
    }
    writeVertical(n/10);
    cout << n%10 <<endl;
    
}