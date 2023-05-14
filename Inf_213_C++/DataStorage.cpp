#include "DataStorage.h"

void DataStorage::init(std::string manufacturer, std::string model, int serialNumber, std::string type, int capacity, int amountParts, int capacityParts, std::string partilionStyle)
{
	_manufacturer = manufacturer;
	_model = model;
	_serialNumber = serialNumber;
	_type = type;
	_capacity = capacity;
	_amountParts = amountParts;
	_capacityParts = capacityParts;
	_partilionStyle = partilionStyle;
}

DataStorage::DataStorage(std::string manufacturer, std::string model, int serialNumber, std::string type, int capacity, int amountParts, int capacityParts, std::string partilionStyle)
{
	init(manufacturer, model, serialNumber, type, capacity, amountParts, capacityParts, partilionStyle);
}

void DataStorage::print()
{
	std::cout << "Производитель: " << _manufacturer << std::endl;
	std::cout << "Модель: " << _model << std::endl;
	std::cout << "Серийный номер: " << _serialNumber << std::endl;
	std::cout << "Тип: " << _type << std::endl;
	std::cout << "Объём: " << _capacity << std::endl;
	std::cout << "Количество разделов: " << _amountParts << std::endl;
	std::cout << "Суммарный объём разделов: " << _capacityParts << std::endl;
	std::cout << "Тип таблицы разделов: " << _partilionStyle << std::endl;
}