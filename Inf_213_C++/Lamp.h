
class Lamp {
private:
	std::string _firm;
	int _power;
	double _price;

	void init(std::string firm, int power, double price) {
		if (firm == "") throw std::invalid_argument("====Ошибка иницализации производителя====\n\n");
		if (power < 0) throw std::domain_error("====Ошибка иницализации мощности====\n\n");
		if (price < 0) throw std::domain_error("====Ошибка иницализации цены====\n\n");
		_firm = firm;
		_power = power;
		_price = price;
	}

public:
	Lamp(std::string firm = "NULL", int power = 0, double price = 0);
	Lamp(Lamp& lamp);
	void print();
	void setFirm(std::string firm);
};

Lamp* getLamp();