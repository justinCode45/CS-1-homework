#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <set>
#include "./header/General.hpp"

using std::string;
using std::map;
using std::vector;
using std::ifstream;
using std::unordered_map;
using std::set;
using std::pair;

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
    Seat **seats;
    Cabin()
    {
        seats = nullptr;
    }
    void load(ifstream &file, string &cabinName);
    bool reserveSeat(int rowC);
    string print();
};

class Airplane
{
public:
    string name;
    // vector<Cabin*> cabins;
    map<string, Cabin *> cabinMap;
    Airplane(string path)
    {
        load(path);
    }
    void load(string path);
    string getCabinList();
};

#endif
