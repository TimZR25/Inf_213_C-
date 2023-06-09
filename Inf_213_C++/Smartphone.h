#ifdef PR_7
#pragma once
#include <string>
using namespace std;
class Smartphone {
private:
    std::string _model, _manufacturer, _color, _display, _ram, _storage, _cpu, _os;
    int _year;
    double _price;
public:
    Smartphone();

    Smartphone(std::string model, std::string manufacturer,
        std::string color, std::string display, std::string ram,
        std::string storage, std::string cpu, std::string os, int year, double price);

    std::string getModel() const;  std::string getManufacturer() const;
    std::string getColor() const;  std::string getDisplay() const;
    std::string getRAM() const;    std::string getStorage() const;
    std::string getCPU() const;    std::string getOS() const;
    int getYear() const;    double getPrice() const;

    void setModel(std::string model);   void setManufacturer(std::string manufacturer);
    void setColor(std::string color);   void setDisplay(std::string display);
    void setRAM(std::string ram);       void setStorage(std::string storage);
    void setCPU(std::string cpu);       void setOS(std::string os);
    void setYear(int year);       void setPrice(double price);

    void print() const;
};
#endif // PR_7

#ifdef PR_8
#pragma once
#include <string>
#include "Price.h"
using namespace std;
enum class Manufacturer {
    APPLE, SAMSUNG, XIAOMI, HTC, LG, UNDEFINED
};
enum class Color {
    WHITE, GRAY, BLACK, BLUE, RED, GOLD, GREEN, UNDEFINED
};
enum class OS {
    ANDROID, IOS, FIREFOX, UNDEFINED
};
enum class CPU {
    SNAPDRAGON, APPLE, SAMSUNG, UNDEFINED
};
class Smartphone {
private:
    string _model;  Manufacturer _manufacturer;  Color _color;
    float _displaySize;  int _ram, _storage;
    CPU _cpu;  OS _os;  Price _price;
public:
    Smartphone();
    Smartphone(string model, Price price, Manufacturer manufacturer,
        Color color, float displaySize, int ram,
        int storage, CPU cpu, OS os);
    string getModel() const;
    Manufacturer getManufacturer() const;
    Color getColor() const;
    float getDisplaySize() const;
    int getRAM() const;
    int getStorage() const;
    CPU getCPU() const;
    OS getOS() const;
    Price getPrice() const;
    void setPrice(Price price);

    void print() const;
};
#endif // PR_7