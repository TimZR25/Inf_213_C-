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