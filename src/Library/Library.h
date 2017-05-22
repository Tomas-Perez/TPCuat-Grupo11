#ifndef TPCUAT_GRUPO11_LIBRARY_H
#define TPCUAT_GRUPO11_LIBRARY_H

#include "Person.h"
#include "Teacher.h"
#include "Student.h"
#include "Material.h"
#include "Magazine.h"
#include "Book.h"

typedef struct Library Library;
struct Library{
    Person** personArray;
    int* personBooleanArray;
    int amountOfPeople;
    int personMaxCapacity;

    Teacher** teacherArray;
    int* teacherBooleanArray;
    int amountOfTeacher;
    int teacherMaxCapacity;

    Student** studentArray;
    int* studentBooleanArray;
    int amountOfStudent;
    int studentMaxCapacity;

    Material** materialArray;
    int* materialBooleanArray;
    int amountOfMaterial;
    int materialMaxCapacity;

    Magazine** magazineArray;
    int* magazineBooleanArray;
    int amountOfMagazine;
    int magazineMaxCapacity;

    Book** bookArray;
    int* bookBooleanArray;
    int amountOfBook;
    int bookMaxCapacity;

    int personIdGenerator;
    int teacherIdGenerator;
    int studentIdGenerator;
    int materialIdGenerator;
};

Library* newLibrary();
void freeLibrary(Library* library);

void growPerson(Library* library);
int addPerson(Library* library, Person* person);
void removePerson(Library* library, int idPerson);

void growTeacher(Library* library);
int addTeacher(Library* library, Teacher* teacher);
void removeTeacher(Library* library, int idTeacher);

void growStudent(Library* library);
int addStudent(Library* library, Student* student);
void removeStudent(Library* library, int idStudent);


void growMaterial(Library* library);
int addMaterial(Library* library, Material* material);
void removeMaterial(Library* library, int idMaterial);

void growMagazine(Library* library);
int addMagazine(Library* library, Magazine* magazine);

void growBook(Library* library);
int addBook(Library* library, Material* material);

#endif //TPCUAT_GRUPO11_LIBRARY_H

