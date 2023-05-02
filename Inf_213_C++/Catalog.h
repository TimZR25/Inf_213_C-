#pragma once
#include<string>
#include<vector>
#include"Smartphone.h"

class Catalog {
private:
    vector<Smartphone> _smartphones;
public:
    void addSmartphone(std::string model, std::string manufacturer,
        std::string color, std::string display, std::string ram,
        std::string storage, std::string cpu, std::string os, double price);

    Smartphone getSmartphone(string model);
    Smartphone search(const Smartphone& searchSmartphone);
};