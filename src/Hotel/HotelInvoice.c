#include "HotelInvoice.h"
#include <stdlib.h>
#include <string.h>

HotelInvoice* newHotelInvoice(char* hotelName, int days, int amount, int clientID, int roomNumber){
    HotelInvoice* result = malloc(sizeof(HotelInvoice));
    //result->hotelName = malloc(sizeof(char)*(strlen(hotelName) + 1));
    //result->hotelName = malloc(sizeof(char)*strlen(hotelName) + 1);
    result->invoiceID = 0;
    result->days = days;
    result->amount = amount;
    result->clientID = clientID;
    result->roomNumber = roomNumber;
    result->hotelName = (char*) malloc(sizeof(char) * strlen(hotelName) + 1);
    strcpy(result->hotelName, hotelName);

    return result;
}
void destroyHotelInvoice(HotelInvoice* hotelInvoice){
    free(hotelInvoice->hotelName);
    free(hotelInvoice);
}