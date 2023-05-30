#pragma once

#ifdef PR_7
#include <string>

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
    std::string _model;  Manufacturer _manufacturer;  Color _color;
    float _displaySize;  int _ram, _storage;
    CPU _cpu;  OS _os;  double _price;
public:
    Smartphone();

    Smartphone(std::string model, double price, Manufacturer manufacturer,
        Color color, float displaySize, int ram,
        int storage, CPU cpu, OS os);

    std::string getModel() const;  Manufacturer getManufacturer() const;
    Color getColor() const;        float getDisplaySize() const;
    int getRAM() const;            int getStorage() const;
    CPU getCPU() const;            OS getOS() const;
    double getPrice() const;
    
    void setModel(std::string model);   void setManufacturer(Manufacturer manufacturer);
    void setColor(Color color);   void setDisplaySize(float displaySize);
    void setRAM(int ram);       void setStorage(int storage);
    void setCPU(CPU cpu);       void setOS(OS os);
    void setPrice(double price);

    friend std::string toString(Manufacturer manufacturer);
    friend std::string toString(Color color);
    friend std::string toString(CPU cpu);
    friend std::string toString(OS os);

    void print() const;
};
#endif // PR_7

#ifdef PR_8
#include <string>
using namespace std;
enum class Manufacturer {
    APPLE, SAMSUNG, XIAOMI, HTC, UNDEFINED
};
enum class Color {
    WHITE, GRAY, BLACK, BLUE, RED, GOLD, UNDEFINED
};
enum class OS {
    ANDROID, IOS, UNDEFINED
};
enum class CPU {
    SNAPDRAGON, APPLE, UNDEFINED
};

class Smartphone {
private:
    string _model;  Manufacturer _manufacturer;  Color _color;
    float _displaySize;  int _ram, _storage;
    CPU _cpu;  OS _os;  double _price;

public:
    Smartphone();
    Smartphone(string model, double price, Manufacturer manufacturer,
        Color color, float displaySize, int ram,
        int storage, CPU cpu, OS os);
    string getModel() const;
    Manufacturer getManufacturer() const;
    Color getColor() const;
    float getDisplay() const;
    int getRAM() const;
    int getStorage() const;
    CPU getCPU() const;
    OS getOS() const;
    double getPrice() const;
    void setPrice(double price);
};
#endif // PR_8