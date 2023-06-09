#include "Price.h"
#include <iostream>

void Price::setPrice(double value, Valuta v)
{
    _value = value;
    _valuta = v;
}

double Price::getValue(Valuta v) const
{
	switch (v)
	{
	case Valuta::RUBLE:
		switch (_valuta)
		{
		case Valuta::RUBLE: return _value;
			break;
		case Valuta::DOLLAR: return _value * 0.012181;
			break;
		case Valuta::TENGE: return _value * 5.44;
			break;
		case Valuta::UNDEFINED:
			break;
		default:
			break;
		}
		break;
	case Valuta::DOLLAR:
		switch (_valuta)
		{
		case Valuta::RUBLE: return _value * 82.09;
			break;
		case Valuta::DOLLAR: return _value;
			break;
		case Valuta::TENGE: return _value * 446.65;
			break;
		case Valuta::UNDEFINED:
			break;
		default:
			break;
		}
		break;
	case Valuta::TENGE:
		switch (_valuta)
		{
		case Valuta::RUBLE: return _value * 0.1838;
			break;
		case Valuta::DOLLAR: return _value * 0.002239;
			break;
		case Valuta::TENGE: return _value;
			break;
		case Valuta::UNDEFINED:
			break;
		default:
			break;
		}
		break;
	case Valuta::UNDEFINED:
		break;
	default:
		break;
	}
}

Price::Price(Valuta valuta, double value)
{
	if (value <= 0) return;
	if (valuta == Valuta::UNDEFINED) return;


	_valuta = valuta;
	_value = value;
}

Valuta Price::getValuta()
{
	return _valuta;
}

std::string Price::getSymbol()
{
	switch (_valuta)
	{
	case Valuta::RUBLE: return "RUB";
		break;
	case Valuta::DOLLAR: return "USD";
		break;
	case Valuta::TENGE: return "KZT";
		break;
	case Valuta::UNDEFINED:
		break;
	default:
		break;
	}
}
