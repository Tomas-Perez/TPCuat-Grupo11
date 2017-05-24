#ifndef TPCUAT_GRUPO11_PERSON_H
#define TPCUAT_GRUPO11_PERSON_H

typedef struct Person Person;
struct Person{
    int idPerson;
    int type;//1 Student, 2 Teacher, 3 Admin
    char* name;
    char* username;
    char* surname;
    int phone;
    double debt;
    int* borrowedMaterial;
    int amountOfBorrowedMaterial;
    int borrowedMaterialMaxCapacity;
};

Person* newPerson(int idPerson, char* username, int type, char* name, char* surname, int phone);
void destroyPerson(Person* person);
void growBorrowedMaterial(Person *person);
void addBorrowedMaterial(Person *person, int idBook);
void removeBorrowedMaterial(Person *person, int idBook);

#endif //TPCUAT_GRUPO11_PERSON_H
