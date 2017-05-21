#ifndef TPCUAT_GRUPO11_RESERVATION_H
#define TPCUAT_GRUPO11_RESERVATION_H

#include "HotelDatabase.h"

typedef struct Reservation{
    int clientID;
    int roomNumber;
    int days;
    int amount;
}Reservation;

Reservation* newReservation(int clientID, int roomNumber, int days, HotelDatabase* database);
void destroyReservation(Reservation* reservation);

#endif //TPCUAT_GRUPO11_RESERVATION_H
