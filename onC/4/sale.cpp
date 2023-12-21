#include "sale.h"

Sale::Sale() : price(0)
{
}

Sale::Sale(double _price) : price(_price)
{
}

double Sale::bill() const
{
    return price;
}

double Sale::savings(const Sale& other) const
{
    return bill() - other.bill();
}

bool operator < (const Sale& first, const Sale& second)
{
    return first.bill() < second.bill();
}