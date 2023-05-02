#include <iostream>
#include "Lamp.h"

void Lamp::init(std::string firm, int power, double price) {
	if (firm == "") throw std::invalid_argument("====������ ������������ �������������====\n\n");
	if (power < 0) throw std::domain_error("====������ ������������ ��������====\n\n");
	if (price < 0) throw std::domain_error("====������ ������������ ����====\n\n");
	_firm = firm;
	_power = power;
	_price = price;
}

Lamp::Lamp(Lamp& lamp) {
	if (this == &lamp) return;
	_firm = lamp._firm;
	_power = lamp._power;
	_price = lamp._price;
}

Lamp::Lamp(std::string firm, int power, double price)
{
	init(firm, power, price);
}

void Lamp::print() {
	if (this == NULL)
	{
		std::cout << "====�� ������� ������� ������! ������ ����!====\n" << std::endl;
		return;
	}

	std::cout << "---------��������---------" << std::endl;;
	std::cout << "�����: " << _firm << std::endl;
	std::cout << "��������: " << _power << " ��" << std::endl;
	std::cout << "����: " << _price << " ���" << std::endl;
	std::cout << "--------------------------" << std::endl << std::endl;
}

void Lamp::setFirm(std::string firm) {
	_firm = firm;
}

Lamp* getLamp() {
	while (true)
	{
		std::cout << "---������� �������� �������---" << std::endl;

		Lamp* lamp;

		std::string firm;
		int power;
		double price;

		int e = 1;
		try {
			std::cout << "������� �������� �����: ";
			std::cin >> firm;
			std::cout << "������� ��������: ";
			std::cin >> power;
			std::cout << "������� ����: ";
			std::cin >> price;
			std::cout << std::endl;

			lamp = new Lamp{ firm, power, price };

			return lamp;
		}
		catch (std::invalid_argument& error) {
			std::cout << error.what();

			std::cout << "---��������� ������� �����? (1 - ��, 0 - ���): ";
			std::cin >> e;
			std::cout << std::endl;

			if (e == 0) return nullptr;
		}
		catch (std::domain_error& error) {
			std::cout << error.what();

			std::cout << "---��������� ������� �����? (1 - ��, 0 - ���): ";
			std::cin >> e;
			std::cout << std::endl;

			if (e == 0) return nullptr;
		}
	}
}