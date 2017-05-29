#include "User.h"
#include <stdlib.h>
#include <string.h>

User* newUser(char* name, int DNI, char* address, char* city, int phoneNumber, UserRole role, int invoiceCapacity){
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
    result->invoiceCapacity = invoiceCapacity;
    result->invoiceAmount = 0;
    result->invoiceList = malloc(sizeof(Invoice*)*invoiceCapacity);
    result->invoiceIDGen = 0;
    return result;
}

static void grow(User* user){
    user->invoiceCapacity *= 2;
    user->invoiceList = realloc(user->invoiceList, sizeof(Invoice*)*user->invoiceCapacity);
}

void addInvoice(User* user, Invoice* invoice){
    invoice->invoiceID = user->invoiceIDGen++;
    if(user->invoiceAmount == user->invoiceCapacity) grow(user);
    user->invoiceList[user->invoiceAmount++] = invoice;
}

void destroyUser(User* user){
    for(int i = 0; i < user->invoiceAmount; i++){
        destroyInvoice(user->invoiceList[i]);
    }
    free(user->invoiceList);
    free(user->name);
    free(user->address);
    free(user->city);
    free(user);
}