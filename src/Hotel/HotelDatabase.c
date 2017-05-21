#include "HotelDatabase.h"
#include <stdlib.h>
#include <string.h>

HotelDatabase* newHotelDatabase(int initialCapacity, char* hotelName){
    HotelDatabase* result = malloc(sizeof(HotelDatabase));

    result->hotelName = malloc(sizeof(char)*strlen(hotelName)+1);
    strcpy(result->hotelName, hotelName);

    result->clientAmount = 0;
    result->clientCapacity = initialCapacity;
    result->invoiceAmount = 0;
    result->invoiceCapacity = initialCapacity;
    result->roomAmount = 0;
    result->roomCapacity = 0;

    result->clients = malloc(sizeof(HotelClient*)*result->clientCapacity);
    result->invoices = malloc(sizeof(HotelInvoice*)*result->invoiceCapacity);
    result->rooms = malloc(sizeof(Room*)*result->roomCapacity);

    return result;
}

static void growRooms(HotelDatabase* database){

}

static void growClients(HotelDatabase* database){

}

static void growInvoices(HotelDatabase* database){

}
static int containsRoom(HotelDatabase* database, int roomNumber){

}
static int containsClient(HotelDatabase* database, int clientID){

}
static int containsInvoice(HotelDatabase* database, int invoiceID){

}
int addRoom(HotelDatabase* database, Room* room){
    if(containsRoom(database, room->number)) return 0;
    if(database->roomAmount == database->roomCapacity){
        growRooms(database);
    }
    database->rooms[database->roomAmount] = room;
    database->roomAmount++;
    return 1;
}
int addClient(HotelDatabase* database, HotelClient* client){
    if(containsClient(database, client->clientID)) return 0;
    if(database->clientAmount == database->clientCapacity){
        growClients(database);
    }
    database->clients[database->clientAmount] = client;
    database->clientAmount++;
    return 1;
}
int addInvoice(HotelDatabase* database, HotelInvoice* invoice){
    if(containsInvoice(database, invoice->invoiceID)) return 0;
    if(database->invoiceAmount == database->invoiceCapacity){
        growInvoices(database);
    }
    database->invoices[database->invoiceAmount] = invoice;
    database->invoiceAmount++;
    return 1;
}

void removeRoom(HotelDatabase* database, int roomNumber){
    for(int i = 0; i < database->roomAmount; i++){
        if(database->rooms[i]->number == roomNumber){
            for(; i < database->roomAmount - 1; i++){
                database->rooms[i] = database->rooms[i+1];
            }
            database->roomAmount--;
            break;
        }
    }
}

void removeClient(HotelDatabase* database, int clientID){
    for(int i = 0; i < database->clientAmount; i++){
        if(database->clients[i]->clientID == clientID){
            for(; i < database->clientAmount - 1; i++){
                database->clients[i] = database->clients[i+1];
            }
            database->clientAmount--;
            break;
        }
    }
}

void removeInvoice(HotelDatabase* database, int invoiceID){
    for(int i = 0; i < database->invoiceAmount; i++){
        if(database->invoices[i]->invoiceID == invoiceID){
            for(; i < database->invoiceAmount - 1; i++){
                database->invoices[i] = database->invoices[i+1];
            }
            database->invoiceAmount--;
            break;
        }
    }
}

Room* getRoom(HotelDatabase* database, int roomNumber){
    for(int i = 0; i < database->roomAmount; i++){
        if(database->rooms[i]->number == roomNumber) return database->rooms[i];
    }
}

HotelClient* getClient(HotelDatabase* database, int clientID){
    for(int i = 0; i < database->clientAmount; i++) {
        if (database->clients[i]->clientID == clientID) return database->clients[i];
    }
    return NULL;
}

HotelInvoice* getInvoice(HotelDatabase* database, int invoiceID){
    for(int i = 0; i < database->invoiceAmount; i++) {
        if (database->invoices[i]->invoiceID == invoiceID) return database->invoices[i];
    }
    return NULL;
}

void destroyHotelDatabase(HotelDatabase* database){
    for(int i = 0; i < database->roomAmount; i++){
        destroyRoom(database->rooms[i]);
    }
    for(int i = 0; i < database->clientAmount; i++){
        destroyHotelClient(database->clients[i]);
    }
    for(int i = 0; i < database->invoiceAmount; i++){
        destroyHotelInvoice(database->invoices[i]);
    }
    free(database->invoices);
    free(database->clients);
    free(database->rooms);
    free(database->hotelName);
    free(database);
}