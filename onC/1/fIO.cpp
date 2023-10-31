#include <fstream>

using namespace std;

int main()
{
    int first, second, third;

    ifstream inFile;
    ofstream outFile;

    inFile.open("in.txt");
    outFile.open("out.txt");
    inFile >> first >> second >> third;
    outFile << "Their sum is " << first + second + third << endl;

    inFile.close();
    outFile.close();

    return 0;
}