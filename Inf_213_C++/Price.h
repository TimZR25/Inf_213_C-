#pragma once
class Price
{
private:
	double _price, _dollars, _rubles;
public:
	double convertToDollar();
	double convertToRuble();
};

