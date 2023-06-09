#define PR_8

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
#include <algorithm>
void Catalog::addSmartphone(string model, double price, Manufacturer
    manufacturer,
    Color color, float displaySize, int ram,
    int storage, CPU cpu, OS os) {
    smartphones.push_back(Smartphone{ model, price, manufacturer,
      color, displaySize, ram,
      storage, cpu, os });
}
Smartphone Catalog::getSmartphone(string model) {
    transform(model.begin(), model.end(), model.begin(), tolower);
    for (Smartphone s : smartphones) {
        string currModel = s.getModel();
        transform(currModel.begin(), currModel.end(), currModel.begin(),
            tolower);
            if (currModel == model)
                return s;
    }  return Smartphone();
}
vector<Smartphone> Catalog::search(const Smartphone& searchSmartphone) {
    vector<Smartphone> results;
    for (Smartphone s : smartphones) {
        string model = searchSmartphone.getModel();
        transform(model.begin(), model.end(), model.begin(), tolower);

        string model2 = s.getModel();
        transform(model2.begin(), model2.end(), model2.begin(), tolower);

        if (!model.empty() && model != model2) continue;
        Manufacturer manufacturer = searchSmartphone.getManufacturer();

        if (manufacturer != Manufacturer::UNDEFINED && manufacturer !=
            s.getManufacturer()) continue;

        Color color = searchSmartphone.getColor();
        if (color != Color::UNDEFINED && color != s.getColor()) continue;

        float displaySize = searchSmartphone.getDisplaySize();
        if (displaySize > 0 && displaySize != s.getDisplaySize()) continue;

        int ram = searchSmartphone.getRAM();
        if (ram > 0 && ram != s.getRAM()) continue;

        int storage = searchSmartphone.getStorage();
        if (storage > 0 && storage != s.getStorage()) continue;

        CPU cpu = searchSmartphone.getCPU();
        if (cpu != CPU::UNDEFINED && cpu != s.getCPU()) continue;

        OS os = searchSmartphone.getOS();
        if (os != OS::UNDEFINED && os != s.getOS()) continue;

        results.push_back(s);

    }  return results;
}
#endif // PR_8