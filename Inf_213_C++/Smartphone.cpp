#define PR_8

#ifdef PR_7
#include "Smartphone.h"
#include <iostream>

Smartphone::Smartphone() {
	_model = "";  _manufacturer = ""; 
	_color = ""; _display = "";  
	_ram = ""; _storage = "";  
	_cpu = ""; _os = "";
	_year = 0; _price = 0;
}

Smartphone::Smartphone(std::string model, std::string manufacturer,
	std::string color, std::string display, std::string ram,
	std::string storage, std::string cpu, std::string os, int year, double price) {
	_model = model;    _manufacturer = manufacturer;
	_color = color;    _display = display;
	_ram = ram;  _storage = storage;
	_cpu = cpu;  _os = os;
	_year = year;	_price = price;
}

std::string Smartphone::getModel() const {
	return _model;
}

std::string Smartphone::getManufacturer() const
{
	return _manufacturer;
}

std::string Smartphone::getColor() const
{
	return _color;
}

std::string Smartphone::getDisplay() const
{
	return _display;
}

std::string Smartphone::getRAM() const
{
	return _ram;
}

std::string Smartphone::getStorage() const
{
	return _storage;
}

std::string Smartphone::getCPU() const
{
	return _cpu;
}

std::string Smartphone::getOS() const
{
	return _os;
}

int Smartphone::getYear() const
{
	return _year;
}

double Smartphone::getPrice() const
{
	return _price;
}


void Smartphone::setModel(std::string model)
{
	_model = model;
}

void Smartphone::setManufacturer(std::string manufacturer)
{
	_manufacturer = manufacturer;
}

void Smartphone::setColor(std::string color)
{
	_color = color;
}

void Smartphone::setDisplay(std::string display)
{
	_display = display;
}

void Smartphone::setRAM(std::string ram)
{
	_ram = ram;
}

void Smartphone::setStorage(std::string storage)
{
	_storage = storage;
}

void Smartphone::setCPU(std::string cpu)
{
	_cpu = cpu;
}

void Smartphone::setOS(std::string os)
{
	_os = os;
}

void Smartphone::setYear(int year) {
	_year = year;
}

void Smartphone::setPrice(double price) {
	_price = price;
}

void Smartphone::print() const
{
	std::cout << getManufacturer() << " ";
	std::cout << getModel() << std::endl;
	std::cout << "Color: " << getColor() << std::endl;
	std::cout << "Display: " << getDisplay() << std::endl;
	std::cout << "OS: " << getOS() << std::endl;
	std::cout << getRAM() << "Gb RAM, " << getStorage()
		<< " GB storage" << std::endl;
	std::cout << "CPU: " << getCPU() << std::endl;
	std::cout << "Year of Production: " << getYear() << std::endl;
	std::cout << "Price: " << getPrice() << std::endl << std::endl;
}
#endif // PR_7

#ifdef PR_8
#include "Smartphone.h"
Smartphone::Smartphone() {
	_model = "";  _price = 0;
	_manufacturer = Manufacturer::UNDEFINED;
	_color = Color::UNDEFINED;
	_displaySize = 0;  _ram = 0;
	_storage = 0;
	_cpu = CPU::UNDEFINED;  _os = OS::UNDEFINED;
}
Smartphone::Smartphone(string model, double price, Manufacturer
	manufacturer,
	Color color, float displaySize, int ram,
	int storage, CPU cpu, OS os) {
	_model = model;  _price = price;
	_manufacturer = manufacturer;
	_color = color;
	_displaySize = displaySize;  _ram = ram;
	_storage = storage;
	_cpu = cpu;  _os = os;
}
string Smartphone::getModel() const {
	return _model;
}
// ѕропущены методы получени€ значений характеристик,
// которые реализуютс€ подобным образом 
void Smartphone::setPrice(double price) {
	_price = price;
}
#endif // PR_8