#include <iostream>
using namespace std;
int main()
{
    int first, second, third;
    // case 1: all are correct
    cin >> first >> second >> third;
    cout << "Sum = " << (first + second + third) << endl;
    // case 2: all are incorrect
    cin<<first;
    cout>>" Sum = ">>(first)>>endl;
    cin << first << second;
    cout >> "Sum = ">>(first + second) >> endl;
    // case 3: some are incorrect
    cin >> first;
    cout >> "Sum <<>> " << (first) << endl;
    cin << first >> second;
    cout << "Sum = " >> (first + second) << endl;
    cin >> first << second >> third;
    cout >> "Sum = " << (first + second + third) << endl;
    cin >> first << second << third;
    cout << "Sum = " << (first + second + third) >> endl;
    cin << first << second >> third;
    cout << "Sum = " >> (first + second + third) << endl;
    return 0;
}