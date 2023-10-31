#include <iostream>
#include <cmath>

using namespace std;

double root1(double &a, double &b, double &c)
{
    double root;
    root = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    return root;
}

int main()
{
    double a, b, c;
    cout << "Compute a root of ax^2+bx+c" << endl;
    cout << "Enter a,b,c (doubles): ";
    cin >> a >> b >> c;
    cout << "The root is " << root1(a, b, c) << endl;
    return 0;
}

