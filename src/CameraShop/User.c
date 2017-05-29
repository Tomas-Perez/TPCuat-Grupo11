#include "User.h"
#include <stdlib.h>
#include <string.h>

User* newUser(char* name, int DNI, char* address, char* city, int phoneNumber, UserRole role){
    User* result = malloc(sizeof(User));
    result->DNI = DNI;
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);
    result->address = malloc(sizeof(char)*(strlen(address)+1));
    strcpy(result->address, address);
    result->city = malloc(sizeof(char)*(strlen(city)+1));
    strcpy(result->city, city);
    result->phoneNumber = phoneNumber;
    result->role = role;
    result->invoiceList = createStaticList(5);
    result->invoideIDGen = 0;
    return result;
}

void addInvoice(User* user, Invoice* invoice){
    invoice->invoiceID = user->invoideIDGen++;
    goLast(user->invoiceList);
    addNext(user->invoiceList, (int) invoice);
}

void destroyUser(User* user){
    free(user->name);
    free(user->address);
    free(user->city);
    free(user);
}