#include <stdio.h>
#include <stdlib.h>
#include "../Util/ScanUtil.h"
#include "HotelDatabase.h"

void hotelClientMenu(HotelDatabase* database);
void hotelAdminMenu(HotelDatabase* database);

HotelDatabase* setup(char* hotelName){
    HotelDatabase* database = newHotelDatabase(5, hotelName);;
    Room* room1 = newRoom(DELUXE, 600);
    Room* room2 = newRoom(SINGLE, 200);
    Room* room3 = newRoom(MASTER, 400);
    Room* room4 = newRoom(SINGLE, 150);
    Room* room5 = newRoom(SINGLE, 100);
    Room* room6 = newRoom(MASTER, 500);
    Room* room7 = newRoom(MASTER, 350);
    addRoom(database, room1);
    addRoom(database, room2);
    addRoom(database, room3);
    addRoom(database, room4);
    addRoom(database, room5);
    addRoom(database, room6);
    addRoom(database, room7);
    return database;
}

int main() {
    printf("Enter a hotel name: \n");
    char* hotelName = scanChar();
    printf("Welcome to %s\n", hotelName);
    HotelDatabase* database = setup(hotelName);
    free(hotelName);
    while(1) {
        printf("Would you like to enter as a (1) User or (2) Admin?\n");
        printf("Otherwise exit with -1\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                hotelClientMenu(database);
                break;
            case 2:
                printf("Admin Menu\n");
                hotelAdminMenu(database);
                break;
            case -1:
                exit(0);
            default:
                printf("Please enter one of the options\n");
        }
    }
}

