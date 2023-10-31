#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>
using namespace std;

int main()
{
    double x, y;
    cout << "Enter two doubles x and y: ";
    cin >> x >> y;
    cout << "x to the power of y is " << pow(x, y) << endl;
    return 0;
}