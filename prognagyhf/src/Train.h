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
	~Train();
    void addCarriage(const Carriage& carriage);
	Carriage* findCarriage(int id);
	Carriage* findCarriageInteractions(int id);
    const std::string& getId() const;
    const std::vector<Carriage>& getCarriages() const;
	void printReservationMap() const;

};