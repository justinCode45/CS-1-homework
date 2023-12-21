#ifndef SALE_H
#define SALE_H

#include <string>
#include <iostream>
using namespace std;

class Sale
{
public:
    Sale();
    Sale(double _price);
    virtual double bill() const;
    double savings(const Sale& other) const;
protected:
    double price;   
};
bool operator < (const Sale& first, const Sale& second);

#endif