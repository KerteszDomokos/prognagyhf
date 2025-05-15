#pragma once
#include <string>
#include <vector>
#include "Carriage.h"

class Train {
private:
    std::string id;
    std::vector<Carriage> carriages;
public:
    Train();
    Train(const std::string& id);
    void addCarriage(const Carriage& carriage);
    const std::string& getId() const;
    const std::vector<Carriage>& getCarriages() const;

};