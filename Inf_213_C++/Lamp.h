#pragma once
class Lamp {
private:
	std::string _firm;
	int _power;
	double _price;

	void init(std::string firm, int power, double price);

public:
	Lamp(std::string firm = "NULL", int power = 0, double price = 0);
	Lamp(Lamp& lamp);
	void print();
	void setFirm(std::string firm);
};

Lamp* getLamp();