#include "Train.h"

// Default constructor
Train::Train() : id("") {}

// Constructor with id
Train::Train(const std::string& id) : id(id) {}

void Train::addCarriage(const Carriage& carriage) {
    carriages.push_back(carriage);
}

const std::string& Train::getId() const {
    return id;
}

const std::vector<Carriage>& Train::getCarriages() const {
    return carriages;
}