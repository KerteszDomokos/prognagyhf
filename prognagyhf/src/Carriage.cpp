#include "Carriage.h"

Carriage::Carriage() : id(0), seatCount(0) {}

Carriage::Carriage(int id, int seatCount) : id(id), seatCount(seatCount) {}

bool Carriage::reserveSeat(int seatNumber, const Ticket& ticket) {
	// chack if the seat number is available
    for (const auto& t : tickets) {
        if (t.getSeatNumber() == seatNumber) {
            return false; // Seat already reserved
        }
    }
    tickets.push_back(ticket);
    return true;
}

int Carriage::getId() const {
    return id;
}

int Carriage::getSeatCount() const {
    return seatCount;
}

const std::vector<Ticket>& Carriage::getTickets() const {
    return tickets;
}