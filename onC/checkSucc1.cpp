#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("in.txt");
    if (inFile.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    outFile.open("out.txt");

    while (!inFile.eof())
    {
        int first, second, third;
        inFile >> first >> second >> third;
        outFile << "Their sum is " << first + second + third << endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}