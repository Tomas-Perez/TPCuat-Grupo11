#include <malloc.h>
#include <memory.h>
#include "Person.h"

Person* newPerson(int idPerson, char* username, int type, char* name, char* surname, int phone){
    Person* person = malloc(sizeof(Person));
    person->idPerson = idPerson;
    person->type = type;
    person->phone = phone;
    person->debt = 0;
    person->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(person->name, name);
    person->username = malloc(sizeof(char) * (strlen(username) + 1));
    strcpy(person->username, username);
    person->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    strcpy(person->surname, surname);
    person->borrowedMaterial = malloc(sizeof(int) * 10);
    memset(person->borrowedMaterial, 0 , sizeof(int) * 10);
    person->amountOfBorrowedMaterial = 0;
    person->borrowedMaterialMaxCapacity = 10;
    return person;
}
void destroyPerson(Person* person){
    free(person->name);
    free(person->username);
    free(person->surname);
    free(person);
}

void growBorrowedMaterial(Person *person){
    person->borrowedMaterial = realloc(person->borrowedMaterial, sizeof(int) * person->borrowedMaterialMaxCapacity * 2);
    for(int i = person->borrowedMaterialMaxCapacity; i < person->borrowedMaterialMaxCapacity * 2; i++){
        person->borrowedMaterial[i] = 0;
    }
    person->borrowedMaterialMaxCapacity *= 2;
}
void addBorrowedMaterial(Person *person, int idBook){
    if(person->amountOfBorrowedMaterial != person->borrowedMaterialMaxCapacity) {
        for (int i = 0; i < person->borrowedMaterialMaxCapacity; i++) {
            if (!person->borrowedMaterial[i]) {
                person->borrowedMaterial[i] = idBook;
                person->amountOfBorrowedMaterial++;
                break;
            }
        }
    }
    else {
        growBorrowedMaterial(person);
        person->borrowedMaterial[person->amountOfBorrowedMaterial] = idBook;
        person->amountOfBorrowedMaterial++;
    }
}
void removeBorrowedMaterial(Person *person, int idBook){
    for (int i = 0; i < person->borrowedMaterialMaxCapacity; i++) {
        if (person->borrowedMaterial[i] == idBook) {
            person->borrowedMaterial[i] = 0;
            person->amountOfBorrowedMaterial--;
            return;
        }
    }
}
