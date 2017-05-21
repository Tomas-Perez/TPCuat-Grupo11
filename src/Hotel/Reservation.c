#include "Reservation.h"
#include <stdlib.h>

Reservation* newReservation(int clientID, int roomNumber, int days, HotelDatabase* database){
    Reservation* result = malloc(sizeof(Reservation));
    result->clientID = clientID;
    result->roomNumber = roomNumber;
    result->days = days;
    result->amount = days * getRoom(database, roomNumber)->pricePerDay;

    return result;
}
void destroyReservation(Reservation* reservation){
    free(reservation);
}