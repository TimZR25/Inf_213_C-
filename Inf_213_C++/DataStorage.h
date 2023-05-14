#include <iostream>

class DataStorage
{
private:
	std::string _manufacturer, _model, _type, _partilionStyle;
	int _serialNumber, _capacity, _amountParts, _capacityParts;

	void init(std::string manufacturer,
		std::string model,
		int serialNumber,
		std::string type,
		int capacity,
		int amountParts,
		int capacityParts,
		std::string partilionStyle);
public:
	DataStorage(std::string manufacturer,
		std::string model,
		int serialNumber,
		std::string type,
		int capacity,
		int amountParts,
		int capacityParts,
		std::string partilionStyle);

	void print();
	std::string getManufacturer();
	std::string getModel();
	int getSerialNumber();
	std::string getType();
	int getCapacity();
	int getAmountParts();
	int getCapacityParts();
	std::string getPartilionStyle();
};

