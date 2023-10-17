#include <iostream>

using namespace std;
const double PI = 3.14159;

double areaDifference(double r1, double r2);

int main()
{
    double radius1, radius2, difference;
    cout << "Enter the radius 1 and radius 2 (double): ";
    cin >> radius1 >> radius2;
    difference = areaDifference(radius1, radius2);
    cout << "The difference of the areas is " << difference << endl;

    return 0;
}

double areaDifference(double r1, double r2)
{
    return PI * (r1 * r1 - r2 * r2);
}