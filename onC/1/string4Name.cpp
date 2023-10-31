#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string iName,oName;
    ifstream inFile;
    ofstream outFile;
    int next;
    cout << "Enter the input file name: ";
    cin >> iName;
    cout << "Enter the output file name: ";
    cin >> oName;
    inFile.open(iName);
    if (inFile.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    outFile.open(oName);
    while (inFile >> next)
    {
        outFile << next << endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}