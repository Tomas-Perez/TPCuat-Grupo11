#include <stdio.h>
#include "HotelDatabase.h"
#include "../Util/ScanUtil.h"

void roomCheck(HotelDatabase* database);

void invoiceAdminCheck(HotelDatabase *database){
    int empty = 1;
    for(int i = 0; i < database->invoiceAmount; i++){
        HotelInvoice* invoice = database->invoices[i];
        HotelClient* client = getClient(database, invoice->clientID);
        printf("%s, %s rented Room no. %d (%d days). Total: $%d\n", client->surname, client->name, invoice->roomNumber, invoice->days, invoice->amount);
        empty = 0;
    }
    if(empty) printf("You do not have any invoices saved\n");
}

void addRoomMenu(HotelDatabase* database){
    printf("Choose Room category:\n");
    RoomType category;
    int choosing = 1;
    while(choosing){
        printf("1. Single\n");
        printf("2. Deluxe\n");
        printf("3. Master\n");
        int choice = scanInt();
        switch (choice){
            case 1:
                category = SINGLE;
                choosing = 0;
                break;
            case 2:
                category = DELUXE;
                choosing = 0;
                break;
            case 3:
                category = MASTER;
                choosing = 0;
                break;
            default:
                printf("Please enter one of the options.\n");
        }
    }
    printf("Enter price per day:\n");
    int price = scanInt();
    while(price <= 0){
        printf("Please enter a valid price\n");
        price = scanInt();
    }
    Room* room = newRoom(category, price);
    addRoom(database, room);
    printf("Room added\n");
}

void removeRoomMenu(HotelDatabase* database){
    printf("Please enter the room number\n");
    int roomNumber = scanInt();
    removeRoom(database, roomNumber);
    printf("Room removed\n");
}

void roomMenu(HotelDatabase* database){
    roomCheck(database);
    while(1){
        printf("1. Add Room\n");
        printf("2. Remove Room\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice){
            case 1:
                addRoomMenu(database);
                break;
            case 2:
                removeRoomMenu(database);
                break;
            case 0:
                return;
            default:
                printf("Please enter one of the options.\n");
        }
    }
}

void hotelAdminMenu(HotelDatabase* database){
    while(1){
        printf("1. Check Rooms\n");
        printf("2. Check Invoices\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice){
            case 1:
                roomMenu(database);
                break;
            case 2:
                invoiceAdminCheck(database);
                break;
            case 0:
                return;
            default:
                printf("Please enter one of the options.\n");
        }
    }
}