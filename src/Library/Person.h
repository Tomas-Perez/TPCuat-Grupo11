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
    int* borrowedMaterial;
    int amountOfBorrowedMaterial;
    int borrowedMaterialMaxCapacity;
};

Person* newPerson(int idPerson, char* username, int type, char* name, char* surname, int phone);
void destroyPerson(Person* person);
void addBorrowedMaterial(Person *person, int idMaterial);
void removeBorrowedMaterial(Person *person, int idMater);

#endif //TPCUAT_GRUPO11_PERSON_H
