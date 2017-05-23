#include "HotelInvoice.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

HotelInvoice* newHotelInvoice(char* hotelName, int days, int amount, int clientID, int roomNumber){
    HotelInvoice* result = malloc(sizeof(HotelInvoice));
    result->days = days;
    result->amount = amount;
    result->clientID = clientID;
    result->roomNumber = roomNumber;
    result->hotelName = (char*) malloc(sizeof(char) * strlen(hotelName) + 1);
    strncpy(result->hotelName, hotelName, strlen(hotelName));

    return result;
}
void destroyHotelInvoice(HotelInvoice* hotelInvoice){
    free(hotelInvoice->hotelName);
    free(hotelInvoice);
}