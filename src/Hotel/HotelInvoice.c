#include "HotelInvoice.h"
#include <stdlib.h>
#include <string.h>

/*
 * Description: Contains functions related to the HotelInvoice ADT.
 */

/*
 * Function: newHotelInvoice
 * Description: creates a new hotel invoice.
 * Returns: Invoice pointer
 */
HotelInvoice* newHotelInvoice(char* hotelName, int days, int amount, int clientID, int roomNumber){
    HotelInvoice* result = malloc(sizeof(HotelInvoice));
    result->days = days;
    result->amount = amount;
    result->clientID = clientID;
    result->roomNumber = roomNumber;
    result->hotelName = malloc(sizeof(char) * strlen(hotelName) + 1);
    strcpy(result->hotelName, hotelName);

    return result;
}

/*
 * Function: destroyHotelInvoice
 * Description: deallocates all memory assigned to the hotel invoice
 * Returns: --
 */
void destroyHotelInvoice(HotelInvoice* hotelInvoice){
    free(hotelInvoice->hotelName);
    free(hotelInvoice);
}