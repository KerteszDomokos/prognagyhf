#pragma once
#include <string>

class Ticket {
private:
    std::string passengerName;
    int seatNumber;
public:
    Ticket();
    Ticket(const std::string& passengerName, int seatNumber);
	~Ticket();
    const std::string& getPassengerName() const;
    int getSeatNumber() const;
};