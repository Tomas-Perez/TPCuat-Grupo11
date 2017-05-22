#ifndef TPCUAT_GRUPO11_INVOICE_H
#define TPCUAT_GRUPO11_INVOICE_H

typedef struct HotelInvoice{
    int invoiceID;
    char* hotelName;
    int roomNumber;
    int clientID;
    int days;
    int amount;
}HotelInvoice;

HotelInvoice* newHotelInvoice(char* hotelName, int days, int amount, int clientID, int roomNumber);
void destroyHotelInvoice(HotelInvoice* hotelInvoice);

#endif //TPCUAT_GRUPO11_INVOICE_H
