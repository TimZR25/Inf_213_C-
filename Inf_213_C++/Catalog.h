#ifdef PR_7
#pragma once
#include<string>
#include"Smartphone.h"
#include <list>

class Catalog {
private:
    std::list<Smartphone> _smartphones;
public:
    void addSmartphone(std::string model, std::string manufacturer,
        std::string color, std::string display, std::string ram,
        std::string storage, std::string cpu, std::string os, int year, double price);

    void addSmartphone(Smartphone& smartphone);

    Smartphone getSmartphone(string model);
    Smartphone search(const Smartphone& searchSmartphone);
    Smartphone search(std::string model, int year, double price);
};
#endif // PR_7

#ifdef PR_8
#pragma once
#include<string>
#include<vector>
#include"Smartphone.h"
using namespace std;
class Catalog {
private:
    vector<Smartphone> smartphones;
public:
    void addSmartphone(string model, double price, Manufacturer manufacturer,
        Color color, float displaySize, int ram,
        int storage, CPU cpu, OS os);
    Smartphone getSmartphone(string model);
    vector<Smartphone> search(const Smartphone& searchSmartphone);
};
#endif // PR_8