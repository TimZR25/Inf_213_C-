#include <iostream>
#include <Windows.h>
#include "Lamp.h"
#include <string>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		Lamp lamp1, lamp2{ "Camelion", 13, 120 };

		lamp1.print();
		lamp2.print();

		Lamp lamp3{ lamp2 };
		lamp3.print();

		lamp1.setFirm("Эра");
		lamp1.print();

		for (int i = 0; i < 2; i++)
		{
			std::cout << "Объект номер №" + std::to_string(i+1) << std::endl;;

			Lamp* lamp = getLamp();
			lamp->print();
			delete lamp;
		}
	}
	catch (std::invalid_argument& error) {
		std::cout << error.what();
	}
	catch (std::domain_error& error) {
		std::cout << error.what();
	}

}