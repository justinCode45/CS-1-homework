#include <iostream>
#include "sale.h"
#include "discountsale.h"

using namespace std;


int main()
{
    Sale price1(1000);
    DiscountSale price2(1100, 10);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (price1 < price2)
    {
        cout << "Discounted item is cheaper.\n";
        cout << "Savings is $" << price2.savings(price1) << endl;
    }
    else
    {
        cout << "Discounted item is not cheaper.\n";
    }


    return 0;
}