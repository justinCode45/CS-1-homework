/* File Name:HW5_112652044.cpp
 * Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:5
 * Description: The purpose of this program is to fix your cpp source syntax error( cin and cout operator)
 * Last Change: Nov.9,2023
 * Anything special?
 * 1.No requirement for spaces between cin, cout and operator.
 * 2.try to do Lexical analysis and Syntactic analysis (other file)
 * 
 * Complier: g++ (Rev2, Built by MSYS2 project) 13.2.0 ,C++17
 *           g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0 ,C++17
 *           g++ (tdm64-1) 9.2.0 ,C++17 (Embarcadero Dev-C++)
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

void correctFile(ifstream &inFile, ofstream &outFile);

enum class state
{
    Scout,
    Scin,
    none
};
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

    correctFile(inFile, outFile);

    inFile.close();
    outFile.close();
    return 0;
}

void correctFile(ifstream &inFile, ofstream &outFile)
{
    string line;
    state nowState = state::none;
    bool inStr = false;
    while (getline(inFile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == 'c')
            {
                if (line.substr(i, 3) == "cin")
                {
                    nowState = state::Scin;
                    i += 3;
                }
                if (line.substr(i, 4) == "cout")
                {
                    nowState = state::Scout;
                    i += 4;
                }
            }
            if (line[i] == ';')
            {
                nowState = state::none;
            }
            if (line[i] == '\'' || line[i] == '\"')
            {
                inStr = !inStr;
            }
            if (line[i] == '<' && nowState == state::Scin && !inStr)
            {
                line[i] = '>';
                line[i + 1] = '>';
                i += 1;
            }
            if (line[i] == '>' && nowState == state::Scout && !inStr)
            {
                line[i] = '<';
                line[i + 1] = '<';
                i += 1;
            }
        }
        outFile << line << endl;
    }
}