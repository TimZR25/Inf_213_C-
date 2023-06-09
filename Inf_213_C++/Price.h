#pragma once
#include <string>
typedef enum class Valuta
{
	RUBLE, DOLLAR, TENGE, UNDEFINED
}Valuta;

class Price
{
private:
	Valuta _valuta;
	double _value;
public:
	void setPrice(double value, Valuta v);
	double getValue(Valuta v) const;
	Price(Valuta valuta = Valuta::UNDEFINED, double value = 0);
	Valuta getValuta();
	std::string getSymbol();
};

