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
	std::cout << "�������������: " << _manufacturer << std::endl;
	std::cout << "������: " << _model << std::endl;
	std::cout << "�������� �����: " << _serialNumber << std::endl;
	std::cout << "���: " << _type << std::endl;
	std::cout << "�����: " << _capacity << std::endl;
	std::cout << "���������� ��������: " << _amountParts << std::endl;
	std::cout << "��������� ����� ��������: " << _capacityParts << std::endl;
	std::cout << "��� ������� ��������: " << _partilionStyle << std::endl;
}