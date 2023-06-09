#define PR_8

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
		"6", "3", "64", "Apple", "iOS", 2017, 67000);

	Smartphone smartphone = Smartphone{ "iPhone 12 Pro", "Apple", "White",
		"6", "3", "64", "Apple", "iOS", 2016, 55000 };
	catalog.addSmartphone(smartphone);

	return catalog;
}

int main(int argc, char* argv[]) {
	Catalog catalog = InitializeCatalog();
	Smartphone whatBuyerLikes{ "iPhone 12 Pro", "Apple", "White",
							 "" , "", "", "", "iOS", 2016, 0 };

	Smartphone smartphone = catalog.search("iPhone 12 Pro", 2016, 0);

	if (smartphone.getModel() != "") {
		std::cout << "You might like this: ";
		smartphone.print();
	}
	else std::cout << "Sorry, we have nothing for you.";
	return 0;
}
#endif // PR_7

#ifdef PR_8
#include <Windows.h>
#include"Smartphone.h"
#include"Catalog.h"
#include<iostream>
using namespace std;
Catalog InitializeCatalog() {
	Catalog catalog;

	catalog.addSmartphone("iPhone 12 Pro", Price(Valuta::DOLLAR, 25), Manufacturer::APPLE,
		Color::WHITE, 6, 3, 64, CPU::APPLE, OS::IOS);

	catalog.addSmartphone("iPhone 12 Pro", Price(Valuta::TENGE, 25), Manufacturer::APPLE,
		Color::BLACK, 6, 3, 128, CPU::APPLE, OS::IOS);

	catalog.addSmartphone("iPhone 12 Pro", Price(Valuta::RUBLE, 1000), Manufacturer::APPLE,
		Color::WHITE, 6, 3, 64, CPU::APPLE, OS::IOS);

	return catalog;
}
int main(int argc, char* argv[]) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Catalog catalog = InitializeCatalog();

	Smartphone whatBuyerLikes{ "iphone 12 pro", Price(Valuta::RUBLE, 1000), Manufacturer::APPLE,
	Color::WHITE, 0 , 0, 0, CPU::UNDEFINED, OS::UNDEFINED };

	vector<Smartphone> results = catalog.search(whatBuyerLikes);

	if (!results.empty()) {
		cout << "You might like this:" << endl;
		for (Smartphone s : results) {
			s.print();
		}
	}
	else cout << "Sorry, we have nothing for you.";
	return 0;
}
#endif // PR_8

#ifdef Laba_3
#include <iostream>
#include "DataStorage.h"
void main()
{
	setlocale(LC_ALL, "Rus");

	DataStorage* ds{};
	try
	{
		ds = new DataStorage{ "Toshiba", "", 421325, Type::SSD, 1024, 3, 512, TypePartitionTable::MBR };
	}
	catch (const std::exception& error)
	{
		std::cout << error.what();
	}
	
	try
	{
		ds = new DataStorage{ "Toshiba", "Andre", 421325, Type::SSD, 1024, 3, 512, TypePartitionTable::GPT };
	}
	catch (const std::exception& error)
	{
		std::cout << error.what();
	}

	DataStorage ds2{ *ds };
	ds2.setPartitions(1, 128);
	(*ds).createNewTable(TypePartitionTable::GPT);
	(*ds).setPartitions(2, 256);
	(*ds).print();
	ds2.print();

	std::cout << "Осталось места на диске: " << (*ds).getRemainingVolume() << " GB";

	delete ds;
}
#endif // Laba_3