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
    int roomNumberGen;

    HotelClient** clients;
    int clientAmount;
    int clientCapacity;
    int clientIDGen;

    HotelInvoice** invoices;
    int invoiceAmount;
    int invoiceCapacity;
    int invoiceIDGen;
}HotelDatabase;

HotelDatabase* newHotelDatabase(int initialCapacity, char* hotelName);

void addRoom(HotelDatabase* database, Room* room);
void addClient(HotelDatabase* database, HotelClient* client);
void addInvoice(HotelDatabase* database, HotelInvoice* invoice);

void removeRoom(HotelDatabase* database, int roomNumber);
void removeClient(HotelDatabase* database, int clientID);
void removeInvoice(HotelDatabase* database, int invoiceID);

Room* getRoom(HotelDatabase* database, int roomNumber);
HotelClient* getClient(HotelDatabase* database, int clientID);
HotelInvoice* getInvoice(HotelDatabase* database, int invoiceID);

void destroyHotelDatabase(HotelDatabase* database);

#endif //TPCUAT_GRUPO11_HOTELDATABASE_H
