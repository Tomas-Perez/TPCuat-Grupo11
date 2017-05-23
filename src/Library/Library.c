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

    library->personIdGenerator = 1;
    library->teacherIdGenerator = 1;
    library->studentIdGenerator = 1;
    library->materialIdGenerator = 1;

    return library;
}
void freeLibrary(Library* library){
    for(int i = 0; i < library->personMaxCapacity; i++){
        if(library->personBooleanArray[i] != 0){
            destroyPerson(library->personArray[i]);
        }
    }
    free(library->personArray);
    free(library->personBooleanArray);

    for(int i = 0; i < library->teacherMaxCapacity; i++){
        if(library->teacherBooleanArray[i] != 0){
            destroyTeacher(library->teacherArray[i]);
        }
    }
    free(library->teacherArray);
    free(library->teacherBooleanArray);

    for(int i = 0; i < library->studentMaxCapacity; i++){
        if(library->studentBooleanArray[i] != 0){
            destroyStudent(library->studentArray[i]);
        }
    }
    free(library->studentArray);
    free(library->studentBooleanArray);

    for(int i = 0; i < library->materialMaxCapacity; i++){
        if(library->materialBooleanArray[i] != 0){
            destroyMaterial(library->materialArray[i]);
        }
    }
    free(library->materialArray);
    free(library->materialBooleanArray);

    for(int i = 0; i < library->magazineMaxCapacity; i++){
        if(library->magazineBooleanArray[i] != 0){
            destroyMagazine(library->magazineArray[i]);
        }
    }
    free(library->magazineArray);
    free(library->magazineBooleanArray);

    for(int i = 0; i < library->bookMaxCapacity; i++){
        if(library->bookBooleanArray[i] != 0){
            destroyBook(library->bookArray[i]);
        }
    }
    free(library->bookArray);
    free(library->bookBooleanArray);
}

void growPerson(Library* library){
    library->personArray  = realloc(library->personArray, sizeof(Person*) * library->personMaxCapacity * 2);
    library->personBooleanArray = realloc(library->personBooleanArray, sizeof(int) * library->personMaxCapacity * 2);
    for(int i = library->personMaxCapacity; i < library->personMaxCapacity * 2; i++){
        library->personBooleanArray[i] = 0;
    }
    library->personMaxCapacity *= 2;
}
int addPerson(Library* library, Person* person){
    if(library->amountOfPeople != library->personMaxCapacity) {
        for (int i = 0; i < library->personMaxCapacity; i++) {
            if (!library->personBooleanArray[i]) {
                library->personArray[i] = person;
                library->personBooleanArray[i] = 1;
                library->amountOfPeople++;
                break;
            }
        }
    }

    else {
        growPerson(library);
        library->personArray[library->amountOfPeople] = person;
        library->personBooleanArray[library->amountOfPeople] = 1;
        library->amountOfPeople++;
    }
}
void removePerson(Library* library, int idPerson){
    for(int i = 0; i < library->personMaxCapacity; i++){
        if(library->personBooleanArray[i] != 0){
            if(idPerson == library->personArray[i]->idPerson){
                if(library->personArray[i]->type == 1){
                    for(int j = 0; j < library->studentMaxCapacity; j++){
                       if(library->studentBooleanArray[j] != 0){
                            if(idPerson == library->studentArray[j]->idPerson){
                                destroyStudent(library->studentArray[j]);
                                library->studentBooleanArray[j] = 0;
                                library->amountOfStudent--;
                                break;
                            }
                        }
                    }
                } else if(library->personArray[i]->type == 2){
                    for(int j = 0; j < library->teacherMaxCapacity; j++){
                       if(library->teacherBooleanArray[j] != 0){
                            if(idPerson == library->teacherArray[j]->idPerson){
                                destroyTeacher(library->teacherArray[j]);
                                library->teacherBooleanArray[j] = 0;
                                library->amountOfTeacher--;
                                break;
                            }
                        }
                    }
                }
                destroyPerson(library->personArray[i]);
                library->personBooleanArray[i] = 0;
                library->amountOfPeople--;
                return;
            }
        }
    }
}

void growTeacher(Library* library) {
    library->teacherArray = realloc(library->teacherArray, sizeof(Teacher*) * library->teacherMaxCapacity * 2);
    library->teacherBooleanArray = realloc(library->teacherBooleanArray, sizeof(int) * library->teacherMaxCapacity * 2);
    for (int i = library->teacherMaxCapacity; i < library->teacherMaxCapacity * 2; i++) {
        library->teacherBooleanArray[i] = 0;
    }
    library->teacherMaxCapacity *= 2;
}
int addTeacher(Library* library, Teacher* teacher){
    if(library->amountOfTeacher != library->teacherMaxCapacity) {
        for (int i = 0; i < library->teacherMaxCapacity; i++) {
            if (!library->teacherBooleanArray[i]) {
                library->teacherArray[i] = teacher;
                library->teacherBooleanArray[i] = 1;
                library->amountOfTeacher++;
                break;
            }
        }
    }

    else {
        growTeacher(library);
        library->teacherArray[library->amountOfTeacher] = teacher;
        library->teacherBooleanArray[library->amountOfTeacher] = 1;
        library->amountOfTeacher++;
    }
}

void growStudent(Library* library){
    library->studentArray  = realloc(library->studentArray, sizeof(Student*) * library->studentMaxCapacity * 2);
    library->studentBooleanArray = realloc(library->studentBooleanArray, sizeof(int) * library->studentMaxCapacity * 2);
    for(int i = library->studentMaxCapacity; i < library->studentMaxCapacity * 2; i++){
        library->studentBooleanArray[i] = 0;
    }
    library->studentMaxCapacity *= 2;
}
int addStudent(Library* library, Student* student){
    if(library->amountOfStudent != library->studentMaxCapacity) {
        for (int i = 0; i < library->studentMaxCapacity; i++) {
            if (!library->studentBooleanArray[i]) {
                library->studentArray[i] = student;
                library->studentBooleanArray[i] = 1;
                library->amountOfStudent++;
                break;
            }
        }
    }

    else {
        growStudent(library);
        library->studentArray[library->amountOfStudent] = student;
        library->studentBooleanArray[library->amountOfStudent] = 1;
        library->amountOfStudent++;
    }
}


void growMaterial(Library* library){
    library->materialArray  = realloc(library->materialArray, sizeof(Material*) * library->materialMaxCapacity * 2);
    library->materialBooleanArray = realloc(library->magazineBooleanArray, sizeof(int) * library->materialMaxCapacity * 2);
    for(int i = library->materialMaxCapacity; i < library->materialMaxCapacity * 2; i++){
        library->materialBooleanArray[i] = 0;
    }
    library->materialMaxCapacity *= 2;
}
int addMaterial(Library* library, Material* material){
    if(library->amountOfMaterial != library->materialMaxCapacity) {
        for (int i = 0; i < library->materialMaxCapacity; i++) {
            if (!library->materialBooleanArray[i]) {
                library->materialArray[i] = material;
                library->materialBooleanArray[i] = 1;
                library->amountOfMaterial++;
                break;
            }
        }
    }

    else {
        growMaterial(library);
        library->materialArray[library->amountOfMaterial] = material;
        library->materialBooleanArray[library->amountOfMaterial] = 1;
        library->amountOfMaterial++;
    }
}
void removeMaterial(Library* library, int idMaterial){
    for(int i = 0; i < library->materialMaxCapacity; i++){
        if(library->materialBooleanArray[i] != 0){
            if(idMaterial == library->materialArray[i]->idMaterial){
                if(library->materialArray[i]->type == 1){
                    for(int j = 0; j < library->bookMaxCapacity; j++){
                        if(library->bookBooleanArray[j] != 0){
                            if(idMaterial == library->bookArray[j]->idMaterial){
                                destroyBook(library->bookArray[j]);
                                library->bookBooleanArray[j] = 0;
                                library->amountOfBook--;
                                break;
                            }
                        }
                    }
                } else if(library->materialArray[i]->type == 2){
                    for(int j = 0; j < library->magazineMaxCapacity; j++){
                        if(library->magazineBooleanArray[j] != 0){
                            if(idMaterial == library->magazineArray[j]->idMaterial){
                                destroyMagazine(library->magazineArray[j]);
                                library->magazineBooleanArray[j] = 0;
                                library->amountOfMagazine--;
                                break;
                            }
                        }
                    }
                }
                destroyMaterial(library->materialArray[i]);
                library->materialBooleanArray[i] = 0;
                library->amountOfMaterial--;
                return;
            }
        }
    }
}

void growMagazine(Library* library){
    library->magazineArray  = realloc(library->magazineArray, sizeof(Magazine*) * library->magazineMaxCapacity * 2);
    library->magazineBooleanArray = realloc(library->magazineBooleanArray, sizeof(int) * library->magazineMaxCapacity * 2);
    for(int i = library->magazineMaxCapacity; i < library->magazineMaxCapacity * 2; i++){
        library->magazineBooleanArray[i] = 0;
    }
    library->magazineMaxCapacity *= 2;
}
int addMagazine(Library* library, Magazine* magazine){
    if(library->amountOfMagazine != library->magazineMaxCapacity) {
        for (int i = 0; i < library->magazineMaxCapacity; i++) {
            if (!library->magazineBooleanArray[i]) {
                library->magazineArray[i] = magazine;
                library->magazineBooleanArray[i] = 1;
                library->amountOfMagazine++;
                break;
            }
        }
    }

    else {
        growMagazine(library);
        library->magazineArray[library->amountOfMagazine] = magazine;
        library->magazineBooleanArray[library->amountOfMagazine] = 1;
        library->amountOfMagazine++;
    }
}

void growBook(Library* library){
    library->bookArray  = realloc(library->bookArray, sizeof(Book*) * library->bookMaxCapacity * 2);
    library->bookBooleanArray = realloc(library->bookBooleanArray, sizeof(int) * library->bookMaxCapacity * 2);
    for(int i = library->bookMaxCapacity; i < library->bookMaxCapacity * 2; i++){
        library->bookBooleanArray[i] = 0;
    }
    library->bookMaxCapacity *= 2;
}
int addBook(Library* library, Book* book){
    if(library->amountOfBook != library->bookMaxCapacity) {
        for (int i = 0; i < library->bookMaxCapacity; i++) {
            if (!library->bookBooleanArray[i]) {
                library->bookArray[i] = book;
                library->bookBooleanArray[i] = 1;
                library->amountOfBook++;
                break;
            }
        }
    }

    else {
        growBook(library);
        library->bookArray[library->amountOfBook] = book;
        library->bookBooleanArray[library->amountOfBook] = 1;
        library->amountOfBook++;
    }
}
