#include "discountsale.h"

DiscountSale::DiscountSale() : Sale(), discount(0)
{
}

DiscountSale::DiscountSale(double _price, double _discount) : Sale(_price), discount(_discount)
{
}

double DiscountSale::bill() const
{
    return (1-discount/100)*price;
}

