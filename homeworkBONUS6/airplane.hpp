#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;


template <class... T>
string color(string in, T... c);


enum class FSGR
{
    black = 30,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    brightBlack = 90,
    brightRed,
    brightGreen,
    brightYellow,
    brightBlue,
    brightMagenta,
    brightCyan,
    brightWhite
};

enum class BSGR
{
    black = 40,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    brightBlack = 100,
    brightRed,
    brightGreen,
    brightYellow,
    brightBlue,
    brightMagenta,
    brightCyan,
    brightWhite
};

class Seat
{
public:
    bool havePeople;
    bool haveSeat;
    bool havePandemic;
    bool nearLavatory;
    Seat()
    {
        havePeople = false;
        haveSeat = true;
        havePandemic = false;
        nearLavatory = false;
    }
    bool available()
    {
        return !havePeople && haveSeat && !havePandemic && !nearLavatory;
    }
};

class Cabin
{
public:
    char aisle[2];
    string name;
    int rowStart;
    int row;
    int col;
    map<char, int> colMapci;
    map<int, char> colMapic;
    Seat** seats;
    void load(ifstream& file);
    Cabin()
    {
        seats = nullptr;
    }
    void print();
};

class Airplane
{
public:
    vector<Cabin*> cabins;
    void load();
};

#endif
