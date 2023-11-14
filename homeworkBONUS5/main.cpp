#include <iostream>
#include <fstream>
#include <sstream>
#include "./head/Scanner.hpp"
#include "./head/Parser.hpp"

using namespace std;

int main()
{
    string iFileName;
    string oFileName;
    cout << "The purpose of this program is to fix your cpp source syntax error( cin and cout operator) " << endl;

    cout << "Enter the input file name: ";
    cin >> iFileName;
    cout << "Enter the output file name: ";
    cin >> oFileName;
    cout<<"You entered input file name: "<<iFileName<<endl;
    cout<<"You entered output file name: "<<oFileName<<endl;
    ifstream inFile;
    ofstream outFile;
    inFile.open(iFileName);
    if (inFile.fail())
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    outFile.open(oFileName);



    Parser parser(&inFile, &outFile);

    parser.parseing();


    for (auto i : parser.errors)
    {
        cout << i.errorMessage() << endl;
    }

    outFile.close();

    inFile.close();

    return 0;
}
