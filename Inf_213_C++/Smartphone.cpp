#include "Smartphone.h"

Smartphone::Smartphone() {
	_model = "";  _manufacturer = ""; 
	_color = ""; _display = "";  
	_ram = ""; _storage = "";  
	_cpu = ""; _os = "";
	_price = 0;
}

Smartphone::Smartphone(std::string model, std::string manufacturer,
	std::string color, std::string display, std::string ram,
	std::string storage, std::string cpu, std::string os, double price) {
	_model = model;    _manufacturer = manufacturer;
	_color = color;    _display = display;
	_ram = ram;  _storage = storage;
	_cpu = cpu;  _os = os;
	_price = price;
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

void Smartphone::setPrice(double price) {
	_price = price;
}