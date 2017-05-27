#include <stdio.h>
#include <stdlib.h>
#include "HotelDatabase.h"
#include "../Util/ScanUtil.h"
#include "Reservation.h"


void roomCheck(HotelDatabase* database){
    for(int i = 0; i < database->roomAmount; i++){
        Room* room = database->rooms[i];
        char* type = getRoomType(room);
        printf("Room no. %d (%s Category): $%d/day\n", room->number, type, room->pricePerDay);
    }
}

void invoiceCheck(HotelDatabase* database, int clientID){
    int empty = 1;
    for(int i = 0; i < database->invoiceAmount; i++){
        HotelInvoice* invoice = database->invoices[i];
        if(invoice->clientID == clientID){
            printf("%s Hotel Room no. %d (%d days). Total: $%d\n", invoice->hotelName, invoice->roomNumber, invoice->days, invoice->amount);
            empty = 0;
        }
    }
    if(empty) printf("You do not have any invoices saved\n");
}

void rentRoom(HotelDatabase* database, int clientID){
    roomCheck(database);
    printf("Enter the room number you would like to rent (-1 to exit)\n");
    int choice = scanInt();
    Room* room = NULL;
    while (1){
        if(choice == -1) return;
        room = getRoom(database, choice);
        if(room != NULL) break;
        printf("Please enter a valid number\n");
        choice = scanInt();
    }
    printf("You chose:\n");
    printf("Room no. %d (%s Category): $%d/day\n", room->number, getRoomType(room), room->pricePerDay);
    printf("How many days would you like to stay?\n");
    int days = scanInt();
    while(days <= 0){
        printf("Please enter a valid number\n");
        days = scanInt();
    }
    Reservation* reservation = newReservation(clientID, room->number, days, database);
    printf("This is your reservation, press 1 to accept, 0 to cancel\n");
    printf("Room no. %d (%d days). Total: $%d\n", reservation->roomNumber, reservation->days, reservation->amount);
    int accept = scanInt();
    while (accept != 0 && accept != 1){
        printf("Please enter a valid number\n");
        accept = scanInt();
    }
    if(accept == 0){
        free(reservation);
        printf("Operation canceled");
        return;
    }
    HotelInvoice* hotelInvoice = newHotelInvoice(database->hotelName, reservation->days, reservation->amount, clientID, reservation->roomNumber);
    addInvoice(database, hotelInvoice);
    printf("Thank you for choosing %s, enjoy your stay\n", database->hotelName);
    free(reservation);
}

void hotelClientMenu(HotelDatabase* database){
    printf("Enter your name\n");
    char* name = scanChar();
    printf("Enter your surname\n");
    char* surname = scanChar();
    printf("Enter your DNI\n");
    int dni = scanInt();
    HotelClient* client = newHotelClient(name, surname, dni);
    addClient(database, client);
    int clientID = client->clientID;
    printf("Welcome %s\n", name);
    free(name);
    free(surname);
    while(1){
        printf("1. Rent a room\n");
        printf("2. Check Invoices\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice){
            case 1:
                rentRoom(database, clientID);
                break;
            case 2:
                invoiceCheck(database, clientID);
                break;
            case 0:
                return;
            default:
                printf("Please enter one of the options.\n");
        }
    }
}