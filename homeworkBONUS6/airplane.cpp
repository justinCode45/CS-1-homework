#include "airplane.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#define CSI "\x1b["
using namespace std;


void Cabin::load(ifstream &file, string &cabinName)
{
    file >> this->name >> this->rowStart >> this->row >> this->col;
    this->seats = new Seat *[this->row];
    for (int i = 0; i < this->row; i++)
    {
        seats[i] = new Seat[this->col];
    }
    colMapci.clear();
    for (int i = 0; i < this->col; i++)
    {
        char c;
        file >> c;
        colMapci[c] = i;
        colMapic[i] = c;
    }
    file >> this->aisle[0] >> this->aisle[1];

    while (1)
    {
        int r;
        char c;
        file >> r >> c;
        if (file.eof() || (r == 0 && c == 'Z'))
        {
            break;
        }
        seats[r - rowStart][colMapci[c]].haveSeat = false;
    }

    while (1)
    {
        int r;
        char c;
        file >> r >> c;
        if (file.eof() || (r == 0 && c == 'Z'))
        {
            break;
        }
        seats[r - rowStart][colMapci[c]].nearLavatory = true;
    }
    cabinName = this->name;
}

bool Cabin::reserveSeat(int rowC)
{
    bool reserved = false;
    for (int i = 0; i < col; i++)
    {
        if (seats[rowC - this->rowStart][i].available())
        {
            seats[rowC - this->rowStart][i].havePeople = true;
            reserved = true;

            if (rowC - this->rowStart - 1 >= 0)
                seats[rowC - this->rowStart - 1][i].havePandemic = true;
            if (rowC - this->rowStart + 1 < row)
                seats[rowC - this->rowStart + 1][i].havePandemic = true;
            if (i - 1 >= 0)
                seats[rowC - this->rowStart][i - 1].havePandemic = true;
            if (i + 1 < col)
                seats[rowC - this->rowStart][i + 1].havePandemic = true;
            break;
        }
    }
    return reserved;
}

string Cabin::print()
{
    stringstream cout;
    cout << this->name << endl;
    for (int i = 0; i < row; i++)
    {
        cout.setf(ios::left);
        cout << setw(4) << i + this->rowStart;
        for (int j = 0; j < col; j++)
        {
            // cout << 'X' <<" ";
            if (seats[i][j].haveSeat)
            {
                if (seats[i][j].havePeople)
                {
                    cout << color("X", BSGR::brightGreen, FSGR::brightWhite) << " ";
                }
                else if (seats[i][j].nearLavatory)
                {
                    cout << color(string(1, colMapic[j]), BSGR::brightCyan) << " ";
                }
                else if (seats[i][j].havePandemic)
                {
                    cout << color(string(1, colMapic[j]), BSGR::brightRed, FSGR::black) << " ";
                }
                else
                {
                    cout << colMapic[j] << " ";
                }
            }
            else
            {
                cout << "  ";
            }

            if (j == colMapci[aisle[0]])
            {
                cout << "  ";
            }
            if (j == colMapci[aisle[1]])
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return cout.str();
}

void Airplane::load(string path)
{
    std::ifstream file(path);
    if (file.fail())
    {
        std::cout << "Failed to open airplane.txt" << std::endl;
        exit(1);
        return;
    }
    file >> this->name;
    int n;
    file >> n;
    for (int i = 0; i < n; i++)
    {
        string cabinName;
        Cabin *c = new Cabin();
        c->load(file, cabinName);
        cabinMap[cabinName] = c;
    }

    file.close();
}

string Airplane::getCabinList()
{
    string out = "";
    for (auto &i : cabinMap)
    {
        out += i.first + ", ";//color(", ",FSGR::brightWhite);
    }
    out.pop_back();
    out.pop_back();
    return out;
}