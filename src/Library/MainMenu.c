#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include "Library.h"

void logInMenu(Library* library){

}

void accountCreationMenu(Library* library){
    printf("\n-- New Account--\n");
    printf("(-1 to cancel)\n\n");
    char* username = malloc(sizeof(char) * 20);
    while(1) {
        printf("Username:\n");
        fseek(stdin,0,SEEK_END);
        scanf("%s", username);
        if(strcmp(username,"-1") == 0){
            return;
        }
        if (getPersonByUsername(library, username) == NULL) {
            break;
        }
        printf("Username already taken.\n");
    }
    printf("Name:\n");
    char *name = malloc(sizeof(char) * 20);
    scanf("%s", name);
    if(strcmp(name,"-1") == 0){
        return;
    }
    printf("Surname:\n");
    char *surname = malloc(sizeof(char) * 20);
    scanf("%s", surname);
    if(strcmp(surname,"-1") == 0){
        return;
    }
    int phone = 0;
    while(1) {
        printf("Phone:\n");
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &phone);
        if (phone == -1) {
            return;
        }
        if(phone != 0){
            break;
        }
        printf("Number not valid\n");
    }
    int type = 0;
    while(1) {
        printf("1. Teacher\n");
        printf("2. Student\n");
        fseek(stdin, 0, SEEK_END);
        scanf("%d", &type);
        if (type == -1) {
            return;
        } else if(type == 1 || type == 2){
            break;
        }
        printf("Number not valid\n");
    }
    Person* person = newPerson(generateIdPerson(library), username, type, name, surname, phone);
    addPerson(library, person);
    printf("Account created.\n");
}

void mainMenu(Library* library){
    while(1) {
        printf("Welcome to the library\n");
        printf("1. Log in\n");
        printf("2. Create account\n");
        printf("-1. exit\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                logInMenu(library);
                break;
            case 2:
                accountCreationMenu(library);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
                fseek(stdin,0,SEEK_END);
        }
    }
}