#pragma once
#include <string>
typedef enum class Valuta
{
	RUBLE, DOLLAR, TENGE
}Valuta;

class Price
{
private:
	double _price;
public:
	void setPrice(double price);
	double getPrice(Valuta v) const;
};

