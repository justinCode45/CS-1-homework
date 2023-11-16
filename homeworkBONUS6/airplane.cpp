#include "airplane.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#define CSI "\x1b["
using namespace std;

template <class... T>
string color(string in, T... c)
{
    string out = CSI;
    ((out += to_string((int)c) + ';'), ...);
    out.pop_back();
    out += 'm' + in + CSI "0m";
    return out;
}

void Cabin::load(ifstream &file)
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

}

void Cabin::print()
{
    cout << this->name<<endl;
    for (int i = 0; i < row; i++)
    {
        cout.setf(ios::left);
        cout <<setw(4)<<i + this->rowStart ;
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
}

void Airplane::load()
{
    std::ifstream file("A380.txt");
    if (file.fail())
    {
        std::cout << "Failed to open airplane.txt" << std::endl;
        return;
    }
    int n;
    file >> n;
    for (int i = 0; i < n; i++)
    {
        Cabin* c=new Cabin();
        c->load(file);
        cabins.push_back(c);
    }

    file.close();
}
