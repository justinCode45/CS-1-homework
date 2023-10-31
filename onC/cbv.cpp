#include <iostream>

using namespace std;

void getNumbers(int, int);

int main()
{
    int n1 = 0, n2 = 0;
    getNumbers(n1, n2);
    cout << "The two numbers are " << n1 << " and " << n2 << endl;
    return 0;
}

void getNumbers(int input1, int input2)
{
    cout << "Enter two integers: ";
    cin >> input1 >> input2;
}