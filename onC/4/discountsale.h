#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "sale.h"

class DiscountSale : public Sale
{
public:
    DiscountSale();
    DiscountSale(double _price, double _discount);
    double bill() const;
protected:
    double discount;
};

#endif
