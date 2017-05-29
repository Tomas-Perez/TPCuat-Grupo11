#ifndef TPCUAT_GRUPO11_USER_H
#define TPCUAT_GRUPO11_USER_H

#include "../structs/StaticList.h"
#include "Invoice.h"

typedef enum{ADMIN, CLIENT}UserRole;

typedef struct User{
    char* name;
    int DNI;
    char* address;
    char* city;
    int phoneNumber;
    int userID;
    UserRole role;
    Invoice** invoiceList;
    int invoiceAmount;
    int invoiceCapacity;
    int invoiceIDGen;
}User;

User* newUser(char* name, int DNI, char* address, char* city, int phoneNumber, UserRole role, int invoiceCapacity);
void destroyUser(User* user);
void addInvoice(User* user, Invoice* invoice);

#endif //TPCUAT_GRUPO11_USER_H
