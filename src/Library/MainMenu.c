#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include "Library.h"
#include "../Util/ScanUtil.h"

void adminMenu(Library* library);

void logInMenu(Library* library){
    printf("\n-- Admin log in --\n");
    printf("(-1 to cancel)\n");
    char* username;
    while(1) {
        printf("Username:\n");
        username = scanChar();
        if(strcmp(username,"-1") == 0){
            return;
        }
        Person* person = getPersonByUsername(library, username);
        if (person == NULL || person->type != 3) {
            printf("No such admin.\n");
        } else{
            adminMenu(library);
            break;
        }
    }
}

void accountCreationMenu(Library* library){
    printf("\n-- New Account --\n");
    printf("(-1 to cancel)\n\n");
    char* username;
    while(1) {
        printf("Username:\n");
        username = scanChar();
        if(strcmp(username,"-1") == 0){
            return;
        }
        if (getPersonByUsername(library, username) == NULL) {
            break;
        }
        printf("Username already taken.\n");
    }
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
    int phone = 0;
    while(1) {
        printf("Phone:\n");
        phone = scanInt();
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
        type = scanInt();
        if (type == -1) {
            return;
        } else if(type == 1 || type == 2){
            break;
        }
        printf("Number not valid\n");
    }
    int id = 0;
    while(1) {
        if(type == 2) {
            printf("Student id:\n");
            id = scanInt();
            if (id == -1) {
                return;
            }
            if (id > 0) {
                if (getStudentById(library, id) == NULL)
                    break;
                printf("There is already someone with that id.\n");
            }
        }
        else if(type == 1) {
            printf("Teacher id:\n");
            id = scanInt();
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
        printf("\nWelcome to the library\n");
        printf("1. Log in as admin\n");
        printf("2. Create account\n");
        printf("-1. exit\n");
        int choice = scanInt();
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
        }
    }
}