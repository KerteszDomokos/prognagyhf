#include "Train.h"
#include <iostream>	
// Default constructor
Train::Train() : id("") {}

// Constructor with id
Train::Train(const std::string& id) : id(id) {}

void Train::addCarriage(const Carriage& carriage) {
    carriages.push_back(carriage);
}

Carriage* Train::findCarriage(int id)
{
    for (auto& carriage : carriages) {
        if (carriage.getId() == id) {
            return &carriage;
        }
	}
    return nullptr;
}

Carriage* Train::findCarriageInteractions(int id)
{
	Carriage* c = findCarriage(id);
	if (!c) {
		std::cout << "Carriage not found.\n would you like to create the carriage?(y/n) ";
		std::string answer;
		std::getline(std::cin, answer);
		if (answer == "y") {
			int seatCount = 0;
			std::cout << "Seat count: ";
			std::cin >> seatCount; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
			c = new Carriage(id, seatCount); // Assuming default seat count is 0
			addCarriage(*c);
			std::cout << "Carriage created: " << c->getId() << ", "<<c->getSeatCount()<<"\n";
			return c;
		}
	}
	else {
		return c;
	}
    return nullptr;
}

const std::string& Train::getId() const {
    return id;
}

const std::vector<Carriage>& Train::getCarriages() const {
    return carriages;
}