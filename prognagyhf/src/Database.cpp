#include "Database.h"
#include <fstream>
#include <iostream>
#include <string>

Database::Database() {}

void Database::addTrain(const Train& train) {
    trains.push_back(train);
}

Train* Database::findTrain(const std::string& id) {
    for (auto& train : trains) {
        if (train.getId() == id) return &train;
    }
    return nullptr;
}

void Database::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file for writing");
    }

    file << trains.size() << std::endl;

    for (const auto& train : trains) {
        file << train.getId() << std::endl;

        const auto& carriages = train.getCarriages();
        file << carriages.size() << std::endl;

        for (const auto& carriage : carriages) {
            file << carriage.getId() << " " << carriage.getSeatCount() << std::endl;
        }
    }

    file.close();
}

void Database::loadFromFile(const std::string& filename) {
    //trains.clear();//kellez?

    std::ifstream ifs(filename);
    if (!ifs) {
        throw std::runtime_error("Cannot open file for reading");
    }

    size_t trainCount;
    ifs >> trainCount;
    ifs.ignore(); // Skip nl

    for (size_t i = 0; i < trainCount; ++i) {
        std::string trainId;
        std::getline(ifs, trainId);

        Train train(trainId);

        size_t carriageCount;
        ifs >> carriageCount;
        ifs.ignore();

        for (size_t j = 0; j < carriageCount; ++j) {
            int carriageId, seatCount;
            ifs >> carriageId >> seatCount;
            ifs.ignore();

            Carriage carriage(carriageId, seatCount);
            train.addCarriage(carriage);

        }

        addTrain(train);
    }

    ifs.close();
}


const std::vector<Train>& Database::getTrains() const {
    return trains;
}

