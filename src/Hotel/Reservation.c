#include "Reservation.h"
#include <stdlib.h>

/*
 * Description: Contains the functions related to the Reservation ADT.
 */

/*
 * Function: newReservation.
 * Description: creates a new reservation.
 * Returns: Reservation pointer.
 */
Reservation* newReservation(int clientID, int roomNumber, int days, HotelDatabase* database){
    Reservation* result = malloc(sizeof(Reservation));
    result->clientID = clientID;
    result->roomNumber = roomNumber;
    result->days = days;
    result->amount = days * getRoom(database, roomNumber)->pricePerDay;

    return result;
}

/*
 * Function: destroyReservation
 * Description: deallocates all memory assigned to the reservation.
 * Returns: --
 */

void destroyReservation(Reservation* reservation){
    free(reservation);
}