#include <iostream>

using namespace std;

void getNumbers(int &, int &);
void swapValues(int &, int &);

int main()
{
    int n1, n2;
    cout << "This program inputs two integers and swap numbers." << endl;
    getNumbers(n1, n2);
    swapValues(n1, n2);
    cout << "After swapping, they are: " << n1 << " and " << n2 << endl;
    return 0;
}

void getNumbers(int &input1, int &input2)
{
    cout << "Enter two integers: ";
    cin >> input1 >> input2;
}
void swapValues(int &variable1, int &variable2)
{
    int temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}