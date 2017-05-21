#ifndef TPCUAT_GRUPO11_HOTELDATABASE_H
#define TPCUAT_GRUPO11_HOTELDATABASE_H

#include "Room.h"
#include "HotelClient.h"
#include "HotelInvoice.h"

typedef struct HotelDatabase{
    char* hotelName;

    Room** rooms;
    int roomAmount;
    int roomCapacity;

    HotelClient** clients;
    int clientAmount;
    int clientCapacity;

    HotelInvoice** invoices;
    int invoiceAmount;
    int invoiceCapacity;
}HotelDatabase;

HotelDatabase* newHotelDatabase(int initialCapacity, char* hotelName);

int addRoom(HotelDatabase* database, Room* room);
int addClient(HotelDatabase* database, HotelClient* client);
int addInvoice(HotelDatabase* database, HotelInvoice* invoice);

void removeRoom(HotelDatabase* database, int roomNumber);
void removeClient(HotelDatabase* database, int clientID);
void removeInvoice(HotelDatabase* database, int invoiceID);

Room* getRoom(HotelDatabase* database, int roomNumber);
HotelClient* getClient(HotelDatabase* database, int clientID);
HotelInvoice* getInvoice(HotelDatabase* database, int invoiceID);

void destroyHotelDatabase(HotelDatabase* database);

#endif //TPCUAT_GRUPO11_HOTELDATABASE_H
