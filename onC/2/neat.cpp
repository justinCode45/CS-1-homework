#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void makeNeat(ifstream& messyFile, ofstream& neatFile,int n, int w);


int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("rawData.txt");
    outFile.open("neat.txt");
    makeNeat(inFile, outFile,5,12);

    inFile.close();
    outFile.close();


    return 0;
}

void makeNeat(ifstream& messyFile, ofstream& neatFile,int n,int w)
{
    double next;
    neatFile.setf(ios::fixed);
    neatFile.setf(ios::showpoint);
    neatFile.precision(n);
    while (messyFile >> next)
    {
        neatFile << setw(w) << next << endl;
    }
}