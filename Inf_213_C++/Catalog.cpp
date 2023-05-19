#define PR

#ifdef PR_7
#include "Catalog.h"

void Catalog::addSmartphone(std::string model, std::string manufacturer,
    std::string color, std::string display, std::string ram,
    std::string storage, std::string cpu, std::string os, int year, double price) {
    _smartphones.push_back(Smartphone{ model, manufacturer,
      color, display, ram,
      storage, cpu, os , year, price });
}

void Catalog::addSmartphone(Smartphone& smartphone)
{
    _smartphones.push_back(smartphone);
}

Smartphone Catalog::getSmartphone(std::string model) {
    for (Smartphone s : _smartphones) {
        if (s.getModel() == model)  return s;
    }  return Smartphone();
}

Smartphone Catalog::search(const Smartphone& searchSmartphone) {
    for (Smartphone s : _smartphones) {

        std::string model = searchSmartphone.getModel();
        if (!model.empty() && model != s.getModel()) continue;

        std::string manufacturer = searchSmartphone.getManufacturer();
        if (!manufacturer.empty() && manufacturer != s.getManufacturer()) continue;

        std::string color = searchSmartphone.getColor();
        if (!color.empty() && color != s.getColor()) continue;

        std::string display = searchSmartphone.getDisplay();
        if (!display.empty() && display != s.getDisplay()) continue;

        std::string ram = searchSmartphone.getRAM();
        if (!ram.empty() && ram != s.getRAM()) continue;

        std::string storage = searchSmartphone.getStorage();
        if (!storage.empty() && storage != s.getStorage()) continue;

        std::string cpu = searchSmartphone.getCPU();
        if (!cpu.empty() && cpu != s.getCPU()) continue;

        std::string os = searchSmartphone.getOS();
        if (!os.empty() && os != s.getOS()) continue;

        int year = searchSmartphone.getYear();
        if (year != 0() && year != s.getYear()) continue;

        double price = searchSmartphone.getPrice();
        if (price != 0() && price != s.getPrice()) continue;

        return s;
    }  
    return Smartphone();
}

Smartphone Catalog::search(std::string model, int year, double price)
{
    for (Smartphone s : _smartphones) {

        std::string _model = model;
        if (!_model.empty() && _model != s.getModel()) continue;

        int _year = year;
        if (_year != 0() && _year != s.getYear()) continue;

        double _price = price;
        if (_price != 0() && _price != s.getPrice()) continue;

        return s;
    }
    return Smartphone();
}
#endif // PR_7

#ifdef PR_8
#include "Catalog.h"

void Catalog::addSmartphone(std::string model, std::string manufacturer,
    std::string color, std::string display, std::string ram,
    std::string storage, std::string cpu, std::string os, int year, double price) {
    _smartphones.push_back(Smartphone{ model, manufacturer,
      color, display, ram,
      storage, cpu, os , year, price });
}

void Catalog::addSmartphone(Smartphone& smartphone)
{
    _smartphones.push_back(smartphone);
}

Smartphone Catalog::getSmartphone(std::string model) {
    for (Smartphone s : _smartphones) {
        if (s.getModel() == model)  return s;
    }  return Smartphone();
}

Smartphone Catalog::search(const Smartphone& searchSmartphone) {
    for (Smartphone s : _smartphones) {

        std::string model = searchSmartphone.getModel();
        if (!model.empty() && model != s.getModel()) continue;

        std::string manufacturer = searchSmartphone.getManufacturer();
        if (!manufacturer.empty() && manufacturer != s.getManufacturer()) continue;

        std::string color = searchSmartphone.getColor();
        if (!color.empty() && color != s.getColor()) continue;

        std::string display = searchSmartphone.getDisplay();
        if (!display.empty() && display != s.getDisplay()) continue;

        std::string ram = searchSmartphone.getRAM();
        if (!ram.empty() && ram != s.getRAM()) continue;

        std::string storage = searchSmartphone.getStorage();
        if (!storage.empty() && storage != s.getStorage()) continue;

        std::string cpu = searchSmartphone.getCPU();
        if (!cpu.empty() && cpu != s.getCPU()) continue;

        std::string os = searchSmartphone.getOS();
        if (!os.empty() && os != s.getOS()) continue;

        int year = searchSmartphone.getYear();
        if (year != 0() && year != s.getYear()) continue;

        double price = searchSmartphone.getPrice();
        if (price != 0() && price != s.getPrice()) continue;

        return s;
    }
    return Smartphone();
}

Smartphone Catalog::search(std::string model, int year, double price)
{
    for (Smartphone s : _smartphones) {

        std::string _model = model;
        if (!_model.empty() && _model != s.getModel()) continue;

        int _year = year;
        if (_year != 0() && _year != s.getYear()) continue;

        double _price = price;
        if (_price != 0() && _price != s.getPrice()) continue;

        return s;
    }
    return Smartphone();
}
#endif // PR_8