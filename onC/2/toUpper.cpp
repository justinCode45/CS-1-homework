#include <iostream>

using namespace std;

int main()
{
    char c = 'a';
    cout << "c =" << c << endl;
    cout << "toupper(c) = " << toupper(c) << endl;
    cout << "(char)toupper(c) = " << (char)toupper(c) << endl;
    char x = toupper(c);
    cout << "x=" << x << endl;
    return 0;
}