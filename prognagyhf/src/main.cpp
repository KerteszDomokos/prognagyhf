#include <iostream>
#include <string>
#include "Database.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main() {
    //_CrtSetBreakAlloc(176);
    Database db;
    std::string command;

    std::cout << "BME Train Ticket Management System" << std::endl;
    std::cout << "Type 'help' for commands."<<std::endl;

    try {
        db.loadFromFile("session.txt");
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    while (true) {
        std::cout << "> ";
        std::cin >> command;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        try {
            if (command == "exit") {
                break;
            }
            else if (command == "help") {
                std::cout << "Commands: addtrain, addcarrige, save, reload, book, map, tickets, exit\n";
            }
            else if (command == "tickets") {
                for (const auto& train : db.getTrains()) {
                    std::cout << "Train ID: " << train.getId() << "\n";
                    for (const auto& carriage : train.getCarriages()) {
                        std::cout << "  Carriage ID: " << carriage.getId() << ", Seat Count: " << carriage.getSeatCount() << "\n";
                        for (const auto& ticket : carriage.getTickets()) {
                            std::cout << "    Ticket: \033[1;33m" << ticket.getPassengerName() << "\033[0m, Seat Number: \033[1;33m" << ticket.getSeatNumber() << "\033[0m\n";
                        }
                    }
                }

            }
            else if (command == "addtrain") {
                std::string id;
                std::cout << "Train ID: ";
                std::getline(std::cin, id);
                if (db.findTrain(id)) {
                    std::cout << "Train already exists.\n";
                    continue;
                }
                db.addTrain(Train(id));
                std::cout << "Train added.\n";
            }
            else if (command == "map") {
                std::cout << "Print reservation map...\n";
                std::string trainId;
                Train* train = nullptr;
                std::cout << "Train ID:";
                std::cin >> trainId;

                train = db.findTrainInteractions(trainId);
                if (train == nullptr) {
                    std::cout << "Train not found, exiting.\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                    continue;
                }

                train->printReservationMap();
                std::cout << std::endl;
            }
            else if (command == "addcarrige") {
                std::string trainId;
                Train* train = nullptr;
                std::cout << "Train ID: ";
                std::cin >> trainId;
                train = db.findTrainInteractions(trainId);

                if (!train) {
                    continue;
                }
                int id;
                int seatCount = 0;

                std::cout << "Carrige ID: ";
                std::cin >> id;
                std::cout << "Seat count: ";
                std::cin >> seatCount;
                train->addCarriage(Carriage(id, seatCount));
                std::cout << "Carrige added\n";

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer


            }
            else if (command == "book") {
                std::cout << "Booking a ticket...\n";
                std::string trainId;
                Train* train = nullptr;
                std::cout << "For which train? Train ID:";
                std::cin >> trainId;

                train = db.findTrainInteractions(trainId);
                if (train == nullptr) {
                    std::cout << "Train not found, exiting.\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                    continue;
                }
                int carriageId=0;
                std::cout << "Carriage ID: ";
                std::cin >> carriageId;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                Carriage* carriage = train->findCarriageInteractions(carriageId);
                if (carriage == nullptr) {
                    std::cout << "Carriage not found, exiting.\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                int seatNumber;
                std::cout << "Seat number: ";
                std::cin >> seatNumber; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                std::string passengerName;
                std::cout << "Passenger name: ";
                std::getline(std::cin, passengerName);

                Ticket ticket(passengerName, seatNumber);

                bool success = train->findCarriage(carriageId)->reserveSeat(seatNumber, ticket);

                std::cout << "Ticket booked successfully.\n";


                //saving and realoading
            }
            else if (command == "reload") {
                std::string filename;
                std::cout << "Filename: ";
                std::getline(std::cin, filename);
                db.loadFromFile(filename);
                std::cout << "Session loaded.\n";
            }
            else if (command == "save") {
                std::string filename;
                std::cout << "Filename: ";
                std::getline(std::cin, filename);
                db.saveToFile(filename);
                std::cout << "Session saved.\n";

            }
            else {
                std::cout << "Unknown command.\n";
            }
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
    try {
        db.saveToFile("session.txt");
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
	db.~Database(); // Explicitly call destructor to clean up resources
	command.clear(); // Clear the command string

	_CrtDumpMemoryLeaks(); // Check for memory leaks
    return 0;
}