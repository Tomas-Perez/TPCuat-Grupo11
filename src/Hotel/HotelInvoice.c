#include "HotelInvoice.h"
#include <stdlib.h>
#include <string.h>

HotelInvoice* newHotelInvoice(int invoiceID, char* hotelName, int days, int amount, int clientID, int roomNumber){
    HotelInvoice* result = malloc(sizeof(HotelInvoice));
    result->invoiceID = invoiceID;
    result->hotelName = malloc(sizeof(char)*strlen(hotelName) + 1);
    strcpy(result->hotelName, hotelName);
    result->days = days;
    result->amount = amount;
    result->clientID = clientID;
    result->roomNumber = roomNumber;

    return result;
}
void destroyHotelInvoice(HotelInvoice* hotelInvoice){
    free(hotelInvoice->hotelName);
    free(hotelInvoice);
}