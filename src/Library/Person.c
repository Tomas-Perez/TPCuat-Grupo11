#include <malloc.h>
#include <memory.h>
#include "Person.h"

/*
 * Function: newPerson
 * Description: Creates a new Person with the given data.
 * Returns: Person pointer.
 */
Person* newPerson(int idPerson, char* username, int type, char* name, char* surname, int phone){
    Person* person = malloc(sizeof(Person));
    person->idPerson = idPerson;
    person->type = type;
    person->phone = phone;
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
/*
 * Function: destroyPerson
 * Description: Deallocates all memory related to the Person.
 * Returns: --
 */
void destroyPerson(Person* person){
    free(person->name);
    free(person->username);
    free(person->surname);
    free(person);
}
/*
 * Function: growBorrowedMaterial
 * Description: Increases the size of the BorrowedMaterial id array.
 * Returns: --
 */
void growBorrowedMaterial(Person *person){
    person->borrowedMaterial = realloc(person->borrowedMaterial, sizeof(int) * person->borrowedMaterialMaxCapacity * 2);
    for(int i = person->borrowedMaterialMaxCapacity; i < person->borrowedMaterialMaxCapacity * 2; i++){
        person->borrowedMaterial[i] = 0;
    }
    person->borrowedMaterialMaxCapacity *= 2;
}
/*
 * Function: addBorrowedMaterial
 * Description: adds a given Material id to the BorrowedMaterial array.
 * Returns: 1 if the id was added, 0 if it wasn't.
 */
void addBorrowedMaterial(Person *person, int idMaterial){
    if(person->amountOfBorrowedMaterial != person->borrowedMaterialMaxCapacity) {
        for (int i = 0; i < person->borrowedMaterialMaxCapacity; i++) {
            if (!person->borrowedMaterial[i]) {
                person->borrowedMaterial[i] = idMaterial;
                person->amountOfBorrowedMaterial++;
                break;
            }
        }
    }
    else {
        growBorrowedMaterial(person);
        person->borrowedMaterial[person->amountOfBorrowedMaterial] = idMaterial;
        person->amountOfBorrowedMaterial++;
    }
}
/*
 * Function: removeBorrowedMaterial
 * Description: removes the BorrowedMaterial id with the given id from the BorrowedMaterial array.
 * Returns: --
 */
void removeBorrowedMaterial(Person *person, int idMaterial){
    for (int i = 0; i < person->borrowedMaterialMaxCapacity; i++) {
        if (person->borrowedMaterial[i] == idMaterial) {
            person->borrowedMaterial[i] = 0;
            person->amountOfBorrowedMaterial--;
            return;
        }
    }
}
