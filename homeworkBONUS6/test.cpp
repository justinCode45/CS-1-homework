#include <iostream>
#include "airplane.hpp"


using namespace std;

int main ()
{   
    Airplane airplane("A380.txt");
    cout << airplane.cabinMap["Economy"]->print();
    airplane.cabinMap["Economy"]->reserveSeat(45); 
    cout << airplane.cabinMap["Economy"]->print();
    return 0;
}