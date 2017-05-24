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
    person->borrowedBooks = malloc(sizeof(int) * 10);
    memset(person->borrowedBooks, 0 , sizeof(int) * 10);
    person->amountOfBorrowedBooks = 0;
    person->borrowedBooksMaxCapacity = 10;
    return person;
}
void destroyPerson(Person* person){
    free(person->name);
    free(person->username);
    free(person->surname);
    free(person);
}

void growBorrowedBooks(Person* person){
    person->borrowedBooks = realloc(person->borrowedBooks, sizeof(int) * person->borrowedBooksMaxCapacity * 2);
    for(int i = person->borrowedBooksMaxCapacity; i < person->borrowedBooksMaxCapacity * 2; i++){
        person->borrowedBooks[i] = 0;
    }
    person->borrowedBooksMaxCapacity *= 2;
}
void addBorrowedBook(Person* person, int idBook){
    if(person->amountOfBorrowedBooks != person->borrowedBooksMaxCapacity) {
        for (int i = 0; i < person->borrowedBooksMaxCapacity; i++) {
            if (!person->borrowedBooks[i]) {
                person->borrowedBooks[i] = idBook;
                person->amountOfBorrowedBooks++;
                break;
            }
        }
    }
    else {
        growBorrowedBooks(person);
        person->borrowedBooks[person->amountOfBorrowedBooks] = idBook;
        person->amountOfBorrowedBooks++;
    }
}
void removeBorrowedBook(Person* person, int idBook){
    for (int i = 0; i < person->borrowedBooksMaxCapacity; i++) {
        if (person->borrowedBooks[i] == idBook) {
            person->borrowedBooks[i] = 0;
            person->amountOfBorrowedBooks--;
            return;
        }
    }
}
