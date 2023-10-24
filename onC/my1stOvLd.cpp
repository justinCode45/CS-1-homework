#include <iostream>
using namespace std;

double avg(double n1, double n2)
{
    return (n1 + n2) / 2;
}
double avg(double n1, double n2, double n3)
{
    return (n1 + n2 + n3) / 3;
}

int main()
{
    int n;
    double d1, d2, d3;
    cout << "Enter the number of doubles that you want to take the average (2 or3): ";
    cin >> n;
    if (n == 2)
    {
        cout << "Enter two doubles: ";
        cin >> d1 >> d2;
        cout << "Average = " << avg(d1, d2) << endl;
    }
    else if (n == 3)
    {
        cout << "Enter three doubles: ";
        cin >> d1 >> d2 >> d3;
        cout << "Average = " << avg(d1, d2, d3) << endl;
    }
    return 0;
}