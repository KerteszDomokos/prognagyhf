#include "Ticket.h"

Ticket::Ticket() : passengerName(""), seatNumber(-1) {}

Ticket::Ticket(const std::string& passengerName, int seatNumber)
    : passengerName(passengerName), seatNumber(seatNumber) {}

const std::string& Ticket::getPassengerName() const {
    return passengerName;
}

int Ticket::getSeatNumber() const {
    return seatNumber;
}