#include <stdio.h>
#include <memory.h>
#include "BlockbusterDatabase.h"
#include "../Util/ScanUtil.h"

void adminMenu(BlockbusterDatabase* database);

void accountCreationMenu(BlockbusterDatabase* database){
    printf("\n-- New Account --\n");
    printf("(-1 to cancel)\n\n");
    printf("Name:\n");
    char *name = scanChar();
    if(strcmp(name,"-1") == 0){
        return;
    }
    printf("Surname:\n");
    char *surname = scanChar();
    if(strcmp(surname,"-1") == 0){
        return;
    }
    int dni = 0;
    while(1) {
        printf("Dni:\n");
        dni = scanInt();
        if (dni == -1) {
            return;
        }
        if(dni > 0){
            Client* client = newClient(dni, name, surname);
            if(addClient(database, client)){
                break;
            }
            printf("There is already a client with that dni.\n");
        }
        printf("Dni not valid\n");
    }
    printf("Account created.\n");
}
void logInMenu(BlockbusterDatabase* database){
    printf("\n-- Admin log in --\n");
    printf("(-1 to cancel)\n");
    int dni = 0;
    while(1) {
        printf("Dni:\n");
        dni = scanInt();
        if(dni == -1){
            return;
        }
        Admin* admin = getAdmin(database, dni);
        if (admin == NULL) {
            printf("No such admin.\n");
        } else{
            adminMenu(database);
            break;
        }
    }
}
void mainMenu(BlockbusterDatabase* database){
    while(1) {
        printf("\nWelcome to the Blockbuster\n");
        printf("1. Log in as admin\n");
        printf("2. Create client account\n");
        printf("-1. exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                logInMenu(database);
                break;
            case 2:
                accountCreationMenu(database);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}