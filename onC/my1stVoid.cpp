#include <iostream>

using namespace std;

void iniScreen();
double FtoC(double f);
void showResult(double f, double c);

int main()
{
    iniScreen();
    double f;
    cout << "Enter a temperature in Fahrenheit: ";
    cin >> f;
    double c = FtoC(f);
    showResult(f, c);
    return 0;
}
void iniScreen()
{
    cout << endl;
}
double FtoC(double f)
{
    return (f - 32) * 5 / 9;
}
void showResult(double f, double c)
{
    cout << f << " F is " << c << " C" << endl;
}