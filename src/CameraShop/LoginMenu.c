#include <stdio.h>
#include "User.h"
#include "CameraShopDatabase.h"
#include "../Util/ScanUtil.h"
#include <stdlib.h>

User* loginMenu(CameraShopDatabase* database){
    login:
    printf("Please enter your username\n");
    char* name = scanChar();
    User* user  = getUser(name, database);
    if(user == NULL){
        printf("That username does not exist, enter 0 to exit, anything else to try again\n");
        if(scanInt() == 0) return user;
        else {
            free(name);
            goto login;
        }
    }
    return user;
}

void registerMenu(CameraShopDatabase* database){
    printf("Please enter you DNI");
    int DNI = scanInt();
    printf("Please enter your city\n");
    char* city = scanChar();
    printf("Please enter your address\n");
    char* address = scanChar();
    printf("Please enter your phone\n");
    int phone = scanInt();
    enterUsername:
    printf("Please enter your username\n");
    char *name = scanChar();
    User *user = newUser(name, DNI, address, city, phone, CLIENT);
    if (addUser(database, user)) {
        printf("You have registered successfully\n");
    } else {
        printf("That username already exists, please try again\n");
        destroyUser(user);
        free(name);
        goto enterUsername;
    }
}