#include <malloc.h>
#include <memory.h>
#include "Library.h"

Library* newLibrary(){
    Library* library = malloc(sizeof(Library));
    int initialsize = 50;
    library->personArray = malloc(sizeof(Person*) * initialsize);
    library->personBooleanArray = malloc(sizeof(int) * initialsize);
    memset(library->personBooleanArray, 0, sizeof(int) * initialsize);
    library->personMaxCapacity = initialsize;
    library->amountOfPeople = 0;

    library->teacherArray = malloc(sizeof(Teacher*) * initialsize);
    library->teacherBooleanArray = malloc(sizeof(int) * initialsize);
    memset(library->teacherBooleanArray, 0, sizeof(int) * initialsize);
    library->teacherMaxCapacity = initialsize;
    library->amountOfTeacher = 0;

    library->studentArray = malloc(sizeof(Student*) * initialsize);
    library->studentBooleanArray = malloc(sizeof(int) * initialsize);
    memset(library->studentBooleanArray, 0, sizeof(int) * initialsize);
    library->studentMaxCapacity = initialsize;
    library->amountOfStudent = 0;

    library->materialArray = malloc(sizeof(Material*) * initialsize);
    library->materialBooleanArray = malloc(sizeof(int) * initialsize);
    memset(library->materialBooleanArray, 0, sizeof(int) * initialsize);
    library->materialMaxCapacity = initialsize;
    library->amountOfMaterial = 0;

    library->bookArray = malloc(sizeof(Book*) * initialsize);
    library->bookBooleanArray = malloc(sizeof(int) * initialsize);
    memset(library->bookBooleanArray, 0, sizeof(int) * initialsize);
    library->bookMaxCapacity = initialsize;
    library->amountOfBook = 0;

    library->magazineArray = malloc(sizeof(Magazine*) * initialsize);
    library->magazineBooleanArray = malloc(sizeof(int) * initialsize);
    memset(library->magazineBooleanArray, 0, sizeof(int) * initialsize);
    library->magazineMaxCapacity = initialsize;
    library->amountOfMagazine = 0;

    //TODO
    library->personIdGenerator = 1;
}
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
