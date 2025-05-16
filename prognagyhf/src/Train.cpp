#include "Train.h"
#include <iostream>	
// Default constructor
Train::Train() : id("") {}

// Constructor with id
Train::Train(const std::string& id) : id(id) {}

Train::~Train()
{

	//carriages.clear(); // Clear the vector of carriages
}

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
			Carriage carriage(id, seatCount);
			addCarriage(carriage);
			std::cout << "Carriage created: " << carriage.getId() << ", "<< carriage.getSeatCount()<<"\n";
			return findCarriage(id); // Return pointer to the carriage in the vector
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

void Train::printReservationMap() const
{
    for (const auto& carriage : getCarriages()) {
        std::cout << "Carriage ID: " << carriage.getId() << ", Seat Count: " << carriage.getSeatCount() << std::endl;
        for (int i = 0; i < carriage.getSeatCount(); ++i) {
            if (i % 2 == 0) {
                std::cout << "  ";
            }if (i % 4 == 0) {
                std::cout << "\n";
            }
            bool reserved = false;
            for (const auto& ticket : carriage.getTickets()) {
                if (ticket.getSeatNumber() == i) {
                    reserved = true;
                }
            }
            std::cout << (reserved ? "\033[1;31m[X]" : "\033[1;32m[ ]");
        }
    std::cout << "\033[0m\n" << std::endl; // Reset color
    }
}
