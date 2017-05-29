#include "HotelDatabase.h"
#include <stdlib.h>
#include <string.h>

/*
 * Description: File containing functions related to the HotelDatabase ADT.
 */


/*
 * Function: newHotelDatabase
 * Description: creates a new HotelDatabase with the specified initial capacity and hotel name.
 * Returns: HotelDatabase pointer.
 */
HotelDatabase* newHotelDatabase(int initialCapacity, char* hotelName){
    HotelDatabase* result = malloc(sizeof(HotelDatabase));

    result->hotelName = malloc(sizeof(char)*(strlen(hotelName)+1));
    strcpy(result->hotelName, hotelName);

    result->clientAmount = 0;
    result->clientCapacity = initialCapacity;
    result->invoiceAmount = 0;
    result->invoiceCapacity = initialCapacity;
    result->roomAmount = 0;
    result->roomCapacity = initialCapacity;
    result->roomNumberGen = 1;
    result->clientIDGen = 0;
    result->invoiceIDGen = 0;

    result->clients = malloc(sizeof(HotelClient*)*result->clientCapacity);
    result->invoices = malloc(sizeof(HotelInvoice*)*result->invoiceCapacity);
    result->rooms = malloc(sizeof(Room*)*result->roomCapacity);

    return result;
}

static void growRooms(HotelDatabase* database){
    database->rooms = realloc(database->rooms, sizeof(Room*) * database->roomCapacity*2);
    database->roomCapacity *= 2;
}

static void growClients(HotelDatabase* database){
    database->clients = realloc(database->clients, sizeof(HotelClient*) * database->clientCapacity*2);
    database->clientCapacity *= 2;
}

static void growInvoices(HotelDatabase* database){
    database->invoices = realloc(database->invoices, sizeof(HotelInvoice*) * database->invoiceCapacity*2);
    database->invoiceCapacity *= 2;
}

/*
 * Function: addRoom
 * Description: adds a room to the database.
 * Returns: --
 */
void addRoom(HotelDatabase* database, Room* room){
    if(database->roomAmount == database->roomCapacity){
        growRooms(database);
    }
    room->number = database->roomNumberGen++;
    database->rooms[database->roomAmount] = room;
    database->roomAmount++;
}

/*
 * Function: addClient
 * Description: adds a client to the database.
 * Returns: --
 */
void addClient(HotelDatabase* database, HotelClient* client){
    if(database->clientAmount == database->clientCapacity){
        growClients(database);
    }
    client->clientID = database->clientIDGen++;
    database->clients[database->clientAmount] = client;
    database->clientAmount++;
}

/*
 * Function: addInvoice
 * Description: adds a invoice to the database.
 * Returns: --
 */
void addInvoice(HotelDatabase* database, HotelInvoice* invoice){
    if(database->invoiceAmount == database->invoiceCapacity){
        growInvoices(database);
    }
    invoice->invoiceID = database->invoiceIDGen++;
    database->invoices[database->invoiceAmount] = invoice;
    database->invoiceAmount++;
}

/*
 * Function: removeRoom
 * Description: removes a room from the database, whose room number is equal to the given room number.
 * Returns: --
 */
void removeRoom(HotelDatabase* database, int roomNumber){
    for(int i = 0; i < database->roomAmount; i++){
        if(database->rooms[i]->number == roomNumber){
            destroyRoom(database->rooms[i]);
            for(; i < database->roomAmount - 1; i++){
                database->rooms[i] = database->rooms[i+1];
            }
            database->roomAmount--;
            break;
        }
    }
}

/*
 * Function: removeClient
 * Description: removes a client from the database, whose client id is equal to the given client id.
 * Returns: --
 */
void removeClient(HotelDatabase* database, int clientID){
    for(int i = 0; i < database->clientAmount; i++){
        if(database->clients[i]->clientID == clientID){
            destroyHotelClient(database->clients[i]);
            for(; i < database->clientAmount - 1; i++){
                database->clients[i] = database->clients[i+1];
            }
            database->clientAmount--;
            break;
        }
    }
}

/*
 * Function: removeInvoice
 * Description: removes a invoice from the database, whose invoice id is equal to the given invoice id.
 * Returns: --
 */
void removeInvoice(HotelDatabase* database, int invoiceID){
    for(int i = 0; i < database->invoiceAmount; i++){
        if(database->invoices[i]->invoiceID == invoiceID){
            destroyHotelInvoice(database->invoices[i]);
            for(; i < database->invoiceAmount - 1; i++){
                database->invoices[i] = database->invoices[i+1];
            }
            database->invoiceAmount--;
            break;
        }
    }
}

/*
 * Function: getRoom
 * Description: retrieves a room from the database with the same room number as given.
 * Returns: Room pointer if the room exists, NULL if it doesn't.
 */
Room* getRoom(HotelDatabase* database, int roomNumber){
    for(int i = 0; i < database->roomAmount; i++){
        if(database->rooms[i]->number == roomNumber) return database->rooms[i];
    }
    return NULL;
}

/*
 * Function: getClient
 * Description: retrieves a client from the database with the same client id as given.
 * Returns: Client pointer if the client exists, NULL if it doesn't.
 */
HotelClient* getClient(HotelDatabase* database, int clientID){
    for(int i = 0; i < database->clientAmount; i++) {
        if (database->clients[i]->clientID == clientID) return database->clients[i];
    }
    return NULL;
}

/*
 * Function: getInvoice
 * Description: retrieves a invoice from the database with the same invoice id as given.
 * Returns: Invoice pointer if the invoice exists, NULL if it doesn't.
 */

HotelInvoice* getInvoice(HotelDatabase* database, int invoiceID){
    for(int i = 0; i < database->invoiceAmount; i++) {
        if (database->invoices[i]->invoiceID == invoiceID) return database->invoices[i];
    }
    return NULL;
}

/*
 * Function: destroyHotelDatabase
 * Description: deallocates all memory assigned to the hotel database
 * Returns: --
 */
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