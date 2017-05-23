#ifndef TPCUAT_GRUPO11_PERSON_H
#define TPCUAT_GRUPO11_PERSON_H

typedef struct Person Person;
struct Person{
    int idPerson;
    int type;//1 Student, 2 Teacher
    char* name;
    char* surname;
    int phone;
    double debt;
    int* borrowedBooks;
    int amountOfBorrowedBooks;
    int borrowedBooksMaxCapacity;
};

Person* person(int idPerson, int type, char* name, char* surname, int phone);
void destroyPerson(Person* person);
void growBorrowedBooks(Person* person);
void addBorrowedBook(Person* person, int idBook);
void removeBorrowedBook(Person* person, int idBook);

#endif //TPCUAT_GRUPO11_PERSON_H
