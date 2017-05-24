#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include "Library.h"

void personMenu(Library* library, Person* person);

void logInMenu(Library* library){
    printf("\n-- Log in --\n");
    printf("(-1 to cancel)\n");
    char* username = malloc(sizeof(char) * 20);
    while(1) {
        printf("Username:\n");
        fseek(stdin,0,SEEK_END);
        scanf("%s", username);
        if(strcmp(username,"-1") == 0){
            return;
        }
        Person* person = getPersonByUsername(library, username);
        if (person == NULL) {
            printf("No such user.\n");
        } else{
            personMenu(library, person);
            break;
        }
    }
}

void accountCreationMenu(Library* library){
    printf("\n-- New Account --\n");
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
    int id = 0;
    while(1) {
        if(type == 1) {
            printf("Student id:\n");
            fseek(stdin, 0, SEEK_END);
            scanf("%d", &id);
            if (id == -1) {
                return;
            }
            if (id > 0) {
                if (getStudentById(library, id) == NULL)
                    break;
                printf("There is already someone with that id.\n");
            }
        }
        else if(type == 2) {
            printf("Teacher id:\n");
            fseek(stdin, 0, SEEK_END);
            scanf("%d", &id);
            if (id == -1) {
                return;
            }
            if (id > 0) {
                if (getTeacher(library, id) == NULL)
                    break;
                printf("There is already someone with that id.\n");
            }
        }
        printf("Number not valid\n");
    }
    Person* person = newPerson(generateIdPerson(library), username, type, name, surname, phone);
    addPerson(library, person);
    if(type == 1){
        Student* student = newStudent(id, person->idPerson);
        addStudent(library, student);
    }
    else if (type == 2){
        Teacher* teacher = newTeacher(id, person->idPerson);
        addTeacher(library, teacher);
    }
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