
#define PR_7

#ifdef PR_6
#include <iostream>
#include <Windows.h>
#include "Lamp.h"
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
			std::cout << "Объект номер №" << i + 1 << std::endl;;

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
#endif // PR_6

#ifdef PR_7
#include"Smartphone.h"
#include"Catalog.h"
#include<iostream>


Catalog InitializeCatalog() {
	Catalog catalog;
	catalog.addSmartphone("iPhone 12 Pro", "Apple", "White",
		"6", "3", "64", "Apple", "iOS", 100);
	return catalog;
}

int main(int argc, char* argv[]) {
	Catalog catalog = InitializeCatalog();
	Smartphone whatBuyerLikes{ "iPhone 12 Pro", "Apple", "White",
							 "" , "", "", "", "iOS", 100 };
	Smartphone smartphone = catalog.search(whatBuyerLikes);
	if (smartphone.getModel() != "") {
		std::cout << "You might like this: ";
		std::cout << smartphone.getManufacturer() << " ";
		std::cout << smartphone.getModel() << std::endl;
		std::cout << "Color: " << smartphone.getColor() << std::endl;
		std::cout << "Display: " << smartphone.getDisplay() << std::endl;
		std::cout << "OS: " << smartphone.getOS() << std::endl;
		std::cout << smartphone.getRAM() << "Gb RAM, " << smartphone.getStorage()
			<< " GB storage" << std::endl;
		std::cout << "CPU: " << smartphone.getCPU() << std::endl;
		std::cout << "Price: " << smartphone.getPrice() << std::endl;
	}
	else cout << "Sorry, we have nothing for you.";
	return 0;
}
#endif // PR_7

