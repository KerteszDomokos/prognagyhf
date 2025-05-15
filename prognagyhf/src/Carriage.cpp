#include "Carriage.h"

Carriage::Carriage() : id(0), seatCount(0) {}

Carriage::Carriage(int id, int seatCount) : id(id), seatCount(seatCount) {}

bool Carriage::reserveSeat(int seatNumber, const Ticket& ticket) {
    // TODO: Implement seat reservation and create it from istream
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