#include <iostream>
#include "airplane.hpp"
#include <vector>

using namespace std;

int main()
{
    Airplane A380;
    A380.load();
    A380.cabins[0]->print();
    A380.cabins[1]->print();
    A380.cabins[2]->print();

    return 0;
}