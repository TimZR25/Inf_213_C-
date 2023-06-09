#include "Price.h"

void Price::setPrice(double price)
{
    _price = price;
}

double Price::getPrice(Valuta v) const
{
    return _price;
}
