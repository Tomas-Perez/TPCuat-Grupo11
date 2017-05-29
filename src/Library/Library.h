#ifndef TPCUAT_GRUPO11_LIBRARY_H
#define TPCUAT_GRUPO11_LIBRARY_H

#include "Person.h"
#include "Teacher.h"
#include "Student.h"
#include "Material.h"
#include "Magazine.h"
#include "Book.h"
#include "Borrow.h"

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

    Borrow** borrowArray;
    int* borrowBooleanArray;
    int amountOfBorrow;
    int borrowMaxCapacity;

    int borrowIdGenerator;
    int personIdGenerator;
    int materialIdGenerator;
};

Library* newLibrary();
void freeLibrary(Library* library);

int addPerson(Library* library, Person* person);
void removePerson(Library* library, int idPerson);
Person* getPersonById(Library* library, int idPerson);
Person* getPersonByUsername(Library* library, char* username);

int addTeacher(Library* library, Teacher* teacher);
Teacher* getTeacher(Library* library, int idPerson);
Teacher* getTeacherById(Library* library, int idTeacher);

int addStudent(Library* library, Student* student);
Student* getStudent(Library* library, int idPerson);
Student* getStudentById(Library* library, int idStudent);

int addMaterial(Library* library, Material* material);
void removeMaterial(Library* library, int idMaterial);
Material* getMaterial(Library* library, int idMaterial);

int addMagazine(Library* library, Magazine* magazine);
Magazine* getMagazine(Library* library, int idMaterial);

int addBook(Library* library, Book* book);
Book* getBook(Library* library, int idMaterial);

int addBorrow(Library* library, Borrow* borrow);
Borrow* getBorrow(Library* library, int idBorrow);
void removeBorrow(Library* library, int idBorrow);

int generateIdBorrow(Library* library);
int generateIdPerson(Library* library);
int generateIdMaterial(Library* library);

#endif //TPCUAT_GRUPO11_LIBRARY_H

