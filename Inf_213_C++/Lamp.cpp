#include <iostream>
#include "Lamp.h"


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
		std::cout << "====Не удалось вывести данные! Объект пуст!====\n" << std::endl;
		return;
	}

	std::cout << "---------Лампочка---------" << std::endl;;
	std::cout << "Фирма: " << _firm << std::endl;
	std::cout << "Мощность: " << _power << " Вт" << std::endl;
	std::cout << "Цена: " << _price << " руб" << std::endl;
	std::cout << "--------------------------" << std::endl << std::endl;
}

void Lamp::setFirm(std::string firm) {
	_firm = firm;
}

Lamp* getLamp() {
	while (true)
	{
		std::cout << "---Попытка создания объекта---" << std::endl;
		int e = 1;
		try {
			Lamp* lamp;

			std::string firm;
			int power;
			double price;

			std::cout << "Введите название фирмы: ";
			std::cin >> firm;
			std::cout << "Введите мощность: ";
			std::cin >> power;
			std::cout << "Введите цену: ";
			std::cin >> price;
			std::cout << std::endl;

			lamp = new Lamp{ firm, power, price };

			return lamp;
		}
		catch (std::invalid_argument& error) {
			std::cout << error.what();

			std::cout << "---Повторить попытку ввода? (1 - да, 0 - нет): ";
			std::cin >> e;
			std::cout << std::endl;

			if (e == 0) return nullptr;
		}
		catch (std::domain_error& error) {
			std::cout << error.what();

			std::cout << "---Повторить попытку ввода? (1 - да, 0 - нет): ";
			std::cin >> e;
			std::cout << std::endl;

			if (e == 0) return nullptr;
		}
	}
}