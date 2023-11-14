#include <iostream>
using namespace std;

void newLine();

int main()
{
    int n;
    char c;
    cin >> n;
    newLine();
    cin.get(c);
    cout << n << endl;
    cout << c << endl;

    return 0;
}

void newLine()
{
    char symbol;
    do
    {
        cin.get(symbol);
    } while (symbol != '\n');
}