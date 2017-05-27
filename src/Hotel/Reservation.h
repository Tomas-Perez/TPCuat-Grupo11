#ifndef TPCUAT_GRUPO11_RESERVATION_H
#define TPCUAT_GRUPO11_RESERVATION_H

#include "HotelDatabase.h"

/*
 * Description: A reservation represents the step previous to a confirmed hotel room rental, before the client pays.
 */

typedef struct Reservation{
    int clientID;
    int roomNumber;
    int days;
    int amount;
}Reservation;

Reservation* newReservation(int clientID, int roomNumber, int days, HotelDatabase* database);
void destroyReservation(Reservation* reservation);

#endif //TPCUAT_GRUPO11_RESERVATION_H
