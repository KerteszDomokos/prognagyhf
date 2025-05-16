#pragma once
#include <vector>
#include <string>
#include "Train.h"

class Database {
private:
    std::vector<Train> trains;
public:
    Database();
	~Database();
    Train* addTrain(const Train& train);
    Train* findTrain(const std::string& id);
	Train* findTrainInteractions(const std::string& id);
    void saveToFile(std::string filename) const;
    void loadFromFile(std::string filename);
    const std::vector<Train>& getTrains() const;

};