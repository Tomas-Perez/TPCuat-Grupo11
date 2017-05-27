#include <wchar.h>
#include "../CUTest/CuTest.h"
#include "../../src/Hotel/HotelDatabase.h"

void TestAdd(CuTest* tc){

    HotelDatabase* hotelDatabase = newHotelDatabase(1, "Vista");

    char* Alfonso = "Alfonso";
    char* Ravera = "Ravera";
    char* Roberta = "Roberta";
    char* Caballero = "Caballero";
    char* Ricardo = "Ricardo";

    HotelClient* client1 = newHotelClient(Alfonso,Ravera, 420);
    HotelClient* client2 = newHotelClient(Roberta,Caballero, 65);
    HotelClient* client3 = newHotelClient(Ricardo, Ricardo, 666);

    addClient(hotelDatabase, client1);
    addClient(hotelDatabase, client2);
    addClient(hotelDatabase, client3);

    CuAssertIntEquals(tc, 0, client1->clientID);
    CuAssertIntEquals(tc, 1, client2->clientID);
    CuAssertIntEquals(tc, 2, client3->clientID);
    CuAssertIntEquals(tc, 3, hotelDatabase->clientAmount);

    Room* room1 = newRoom(DELUXE, 500);
    Room* room2 = newRoom(SINGLE, 200);
    Room* room3 = newRoom(MASTER, 990);

    addRoom(hotelDatabase, room1);
    addRoom(hotelDatabase, room2);
    addRoom(hotelDatabase, room3);

    CuAssertIntEquals(tc, 0, room1->number);
    CuAssertIntEquals(tc, 1, room2->number);
    CuAssertIntEquals(tc, 2, room3->number);
    CuAssertIntEquals(tc, 3, hotelDatabase->roomAmount);

    HotelInvoice* invoice1 = newHotelInvoice("dadadsa", 15, 6000, 5, 2);
    HotelInvoice* invoice2 = newHotelInvoice("dacxz", 12, 1023, 5, 2);
    HotelInvoice* invoice3 = newHotelInvoice("xcvdfgd", 68, 1000006, 2, 7);

    addInvoice(hotelDatabase, invoice1);
    addInvoice(hotelDatabase, invoice2);
    addInvoice(hotelDatabase, invoice3);

    CuAssertIntEquals(tc, 0, invoice1->invoiceID);
    CuAssertIntEquals(tc, 1, invoice2->invoiceID);
    CuAssertIntEquals(tc, 2, invoice3->invoiceID);
    CuAssertIntEquals(tc, 3, hotelDatabase->invoiceAmount);
}

void TestRemove(CuTest* tc){
    HotelDatabase* hotelDatabase = newHotelDatabase(1, "Vista");

    HotelClient* client1 = newHotelClient("Alfonso","Ravera", 420);
    HotelClient* client2 = newHotelClient("Roberta","Caballero", 65);

    addClient(hotelDatabase, client1);
    addClient(hotelDatabase, client2);

    Room* room1 = newRoom(DELUXE, 500);
    Room* room2 = newRoom(SINGLE, 200);

    addRoom(hotelDatabase, room1);
    addRoom(hotelDatabase, room2);

    HotelInvoice* invoice1 = newHotelInvoice("dadadsa", 15, 6000, 5, 2);
    HotelInvoice* invoice2 = newHotelInvoice("dacxz", 12, 1023, 5, 2);

    addInvoice(hotelDatabase, invoice1);
    addInvoice(hotelDatabase, invoice2);

    removeClient(hotelDatabase, 0);
    removeClient(hotelDatabase, 1);
    CuAssertIntEquals(tc, 0, hotelDatabase->clientAmount);
    CuAssertTrue(tc, getClient(hotelDatabase, 0) == NULL);
    CuAssertTrue(tc, getClient(hotelDatabase, 1) == NULL);

    removeInvoice(hotelDatabase, 0);
    removeInvoice(hotelDatabase, 1);
    CuAssertIntEquals(tc, 0, hotelDatabase->invoiceAmount);
    CuAssertTrue(tc, getInvoice(hotelDatabase, 0) == NULL);
    CuAssertTrue(tc, getInvoice(hotelDatabase, 1) == NULL);

    removeRoom(hotelDatabase, 0);
    removeRoom(hotelDatabase, 1);
    CuAssertIntEquals(tc, 0, hotelDatabase->roomAmount);
    CuAssertTrue(tc, getRoom(hotelDatabase, 0) == NULL);
    CuAssertTrue(tc, getRoom(hotelDatabase, 1) == NULL);
}

void TestGet(CuTest* tc){
    HotelDatabase* hotelDatabase = newHotelDatabase(1, "Vista");

    HotelClient* client1 = newHotelClient("Alfonso","Ravera", 420);
    HotelClient* client2 = newHotelClient("Roberta","Caballero", 65);
    HotelInvoice* invoice1 = newHotelInvoice("dadadsa", 15, 6000, 5, 2);
    HotelInvoice* invoice2 = newHotelInvoice("dacxz", 12, 1023, 5, 2);
    Room* room1 = newRoom(DELUXE, 500);
    Room* room2 = newRoom(SINGLE, 200);

    addClient(hotelDatabase, client1);
    addClient(hotelDatabase, client2);
    addRoom(hotelDatabase, room1);
    addRoom(hotelDatabase, room2);
    addInvoice(hotelDatabase, invoice1);
    addInvoice(hotelDatabase, invoice2);

    CuAssertStrEquals(tc, "Alfonso", getClient(hotelDatabase, 0)->name);
    CuAssertStrEquals(tc, "Ravera", getClient(hotelDatabase, 0)->surname);
    CuAssertIntEquals(tc, 420, getClient(hotelDatabase, 0)->DNI);

    CuAssertStrEquals(tc, "dadadsa", getInvoice(hotelDatabase, 0)->hotelName);
    CuAssertIntEquals(tc, 15, getInvoice(hotelDatabase, 0)->days);
    CuAssertIntEquals(tc, 6000, getInvoice(hotelDatabase, 0)->amount);

    CuAssertIntEquals(tc, DELUXE, getRoom(hotelDatabase, 0)->type);
    CuAssertIntEquals(tc, 500, getRoom(hotelDatabase, 0)->pricePerDay);
}

CuSuite* getHotelDatabaseTestSuite(){
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestAdd);
    SUITE_ADD_TEST(suite, TestRemove);
    return suite;
}