#pragma once
#include <vector>
#include "Ticket.h"

class Carriage {
private:
    int id;
    int seatCount;
    std::vector<Ticket> tickets;
public:
    Carriage();
    Carriage(int id, int seatCount);
    bool reserveSeat(int seatNumber, const Ticket& ticket);
    int getId() const;
    int getSeatCount() const;
    const std::vector<Ticket>& getTickets() const;
    // TODO: seatmap
};