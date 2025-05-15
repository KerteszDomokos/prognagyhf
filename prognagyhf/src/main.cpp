#include <iostream>
#include <string>
#include "Database.h"

int main() {
    Database db;
    std::string command;

    std::cout << "BME Train Ticket Management System\n";
    std::cout << "Type 'help' for commands.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        try {
			db.loadFromFile("session.txt");
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
		}

        try {
            if (command == "exit") {
                break;
            } else if (command == "help") {
                std::cout << "Commands: addtrain, addcarrige, save, reload, exit\n";
            } else if (command == "addtrain") {
                std::string id;
                std::cout << "Train ID: ";
                std::getline(std::cin, id);
                db.addTrain(Train(id));
                std::cout << "Train added.\n";

            } else if (command == "addcarrige") {
				std::string trainId;
				Train* train = nullptr;
				std::cout << "Train ID: ";
				std::cin >> trainId;
                train = db.findTrainInteractions(trainId);
                
                if (!train) {
					continue;
				}
                int id;
				int seatCount=0;

                std::cout << "Carrige ID: ";
                std::cin >> id;
				std::cout << "Seat count: ";
                std::cin >> seatCount;
				train->addCarriage(Carriage(id, seatCount));
                std::cout << "Carrige added\n";

            } else if (command == "save") {
                std::string filename;
                std::cout << "Filename: ";
                std::getline(std::cin, filename);
                db.saveToFile(filename);
                std::cout << "Session saved.\n";

            } else if (command == "book") {
				std::string trainId;
				Train* train = nullptr;
				std::cout << "For which train? Train ID:";
				std::cin >> trainId;
				train = db.findTrainInteractions(trainId);
				if (!train) { continue; }
				int carriageId;
				std::cout << "Carriage ID: ";
				std::cin >> carriageId;
				Carriage* carriage = train->findCarriage(carriageId);
				if (!carriage) { continue; }
				int seatNumber;
				std::cout << "Seat number: ";
				std::cin >> seatNumber;
				std::string passengerName;
				std::cout << "Passenger name: ";
				std::cin.ignore(); // Ignore the newline character left in the buffer
				std::getline(std::cin, passengerName);

            } else if (command == "reload") {
                std::string filename;
                std::cout << "Filename: ";
                std::getline(std::cin, filename);
                db.loadFromFile(filename);
                std::cout << "Session loaded.\n";

            } else {
                std::cout << "Unknown command.\n";
            }
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
    try{
		db.saveToFile("session.txt");
	}
	catch (const std::exception& ex) {
		std::cerr << "Error: " << ex.what() << std::endl;
	}

    return 0;
}