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
            if (command == "exit") {
                break;
            } else if (command == "help") {
                std::cout << "Commands: addtrain, save, load, exit\n";
            } else if (command == "addtrain") {
                std::string id;
                std::cout << "Train ID: ";
                std::getline(std::cin, id);
                db.addTrain(Train(id));
                std::cout << "Train added.\n";
            } else if (command == "save") {
                std::string filename;
                std::cout << "Filename: ";
                std::getline(std::cin, filename);
                db.saveToFile(filename);
                std::cout << "Session saved.\n";
            } else if (command == "load") {
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

    return 0;
}