#include <malloc.h>
#include <memory.h>
#include "Library.h"

/*
 * Function: newLibrary
 * Description: Creates a new Library with the given data.
 * Returns: Library pointer.
 */
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

    library->borrowArray = malloc(sizeof(Borrow*) * initialsize);
    library->borrowBooleanArray = malloc(sizeof(int) * initialsize);
    memset(library->borrowBooleanArray, 0, sizeof(int) * initialsize);
    library->borrowMaxCapacity = initialsize;
    library->amountOfBorrow = 0;

    library->borrowIdGenerator = 1;
    library->personIdGenerator = 1;
    library->materialIdGenerator = 1;

    return library;
}

/*
 * Function: destroyLibrary
 * Description: Deallocates all memory related to the Library.
 * Returns: --
 */
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

/*
 * Function: growPerson
 * Description: Increases the size of the person array.
 * Returns: --
 */
void growPerson(Library* library){
    library->personArray  = realloc(library->personArray, sizeof(Person*) * library->personMaxCapacity * 2);
    library->personBooleanArray = realloc(library->personBooleanArray, sizeof(int) * library->personMaxCapacity * 2);
    for(int i = library->personMaxCapacity; i < library->personMaxCapacity * 2; i++){
        library->personBooleanArray[i] = 0;
    }
    library->personMaxCapacity *= 2;
}

/*
 * Function: addPerson
 * Description: adds a given Person to the database.
 * Returns: 1 if the Person was added, 0 if it wasn't.
 */
int addPerson(Library* library, Person* person){
    if(getPersonByUsername(library, person->username) != NULL){
        return 0;
    }
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
    return 1;
}
/*
 * Function: removePerson
 * Description: removes the Person with the given id from the database.
 * Returns: --
 */
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

/*
 * Function: getPersonById
 * Description: finds a Person with the given id in the database.
 * Returns: Person pointer if it exists, NULL otherwise.
 */
Person* getPersonById(Library* library, int idPerson){
    for(int i = 0; i < library->personMaxCapacity; i++){
        if(library->personBooleanArray[i] != 0){
            Person* person = library->personArray[i];
            if(idPerson == person->idPerson)
                return person;
        }
    }
    return NULL;
}

/*
 * Function: getPersonByUsername
 * Description: finds a Person with the given Username in the database.
 * Returns: Person pointer if it exists, NULL otherwise.
 */
Person* getPersonByUsername(Library* library, char* username) {
    for(int i = 0; i < library->personMaxCapacity; i++){
        if(library->personBooleanArray[i] != 0){
            Person* person = library->personArray[i];
            if(strcmp(username, person->username) == 0)
                return person;
        }
    }
    return NULL;
}

/*
 * Function: growTeacher
 * Description: Increases the size of the Teacher array.
 * Returns: --
 */
void growTeacher(Library* library) {
    library->teacherArray = realloc(library->teacherArray, sizeof(Teacher*) * library->teacherMaxCapacity * 2);
    library->teacherBooleanArray = realloc(library->teacherBooleanArray, sizeof(int) * library->teacherMaxCapacity * 2);
    for (int i = library->teacherMaxCapacity; i < library->teacherMaxCapacity * 2; i++) {
        library->teacherBooleanArray[i] = 0;
    }
    library->teacherMaxCapacity *= 2;
}
/*
 * Function: addTeacher
 * Description: adds a given Teacher to the database.
 * Returns: 1 if the Teacher was added, 0 if it wasn't.
 */
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
    return 1;
}
/*
 * Function: getTeacher
 * Description: finds a Teacher with the given id in the database.
 * Returns: Teacher pointer if it exists, NULL otherwise.
 */
Teacher* getTeacher(Library* library, int idPerson){
    for(int i = 0; i < library->teacherMaxCapacity; i++){
        if(library->teacherBooleanArray[i] != 0){
            Teacher* teacher = library->teacherArray[i];
            if(idPerson == teacher->idPerson)
                return teacher;
        }
    }
    return NULL;
}
/*
 * Function: getTeacherById
 * Description: finds a Teacher with the given id in the database.
 * Returns: Teacher pointer if it exists, NULL otherwise.
 */
Teacher* getTeacherById(Library* library, int idTeacher){
    for(int i = 0; i < library->teacherMaxCapacity; i++){
        if(library->teacherBooleanArray[i] != 0){
            Teacher* teacher = library->teacherArray[i];
            if(idTeacher == teacher->idTeacher)
                return teacher;
        }
    }
    return NULL;
}
/*
 * Function: growStudent
 * Description: Increases the size of the Student array.
 * Returns: --
 */
void growStudent(Library* library){
    library->studentArray  = realloc(library->studentArray, sizeof(Student*) * library->studentMaxCapacity * 2);
    library->studentBooleanArray = realloc(library->studentBooleanArray, sizeof(int) * library->studentMaxCapacity * 2);
    for(int i = library->studentMaxCapacity; i < library->studentMaxCapacity * 2; i++){
        library->studentBooleanArray[i] = 0;
    }
    library->studentMaxCapacity *= 2;
}
/*
 * Function: addStudent
 * Description: adds a given Student to the database.
 * Returns: 1 if the Student was added, 0 if it wasn't.
 */
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
    return 1;
}
/*
 * Function: getStudent
 * Description: finds a Student with the given id in the database.
 * Returns: Student pointer if it exists, NULL otherwise.
 */
Student* getStudent(Library* library, int idPerson){
    for(int i = 0; i < library->studentMaxCapacity; i++){
        if(library->studentBooleanArray[i] != 0){
            Student* student = library->studentArray[i];
            if(idPerson == student->idPerson)
                return student;
        }
    }
    return NULL;
}
/*
 * Function: getStudentById
 * Description: finds a Student with the given id in the database.
 * Returns: Student pointer if it exists, NULL otherwise.
 */
Student* getStudentById(Library* library, int idStudent){
    for(int i = 0; i < library->teacherMaxCapacity; i++){
        if(library->teacherBooleanArray[i] != 0){
            Student* student = library->studentArray[i];
            if(idStudent == student->idStudent)
                return student;
        }
    }
    return NULL;
}
/*
 * Function: growMaterial
 * Description: Increases the size of the Material array.
 * Returns: --
 */
void growMaterial(Library* library){
    library->materialArray  = realloc(library->materialArray, sizeof(Material*) * library->materialMaxCapacity * 2);
    library->materialBooleanArray = realloc(library->magazineBooleanArray, sizeof(int) * library->materialMaxCapacity * 2);
    for(int i = library->materialMaxCapacity; i < library->materialMaxCapacity * 2; i++){
        library->materialBooleanArray[i] = 0;
    }
    library->materialMaxCapacity *= 2;
}
/*
 * Function: addMaterial
 * Description: adds a given Material to the database.
 * Returns: 1 if the Material was added, 0 if it wasn't.
 */
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
    return 1;
}
/*
 * Function: removeMaterial
 * Description: removes the Material with the given id from the database.
 * Returns: --
 */
void removeMaterial(Library* library, int idMaterial){
    for(int i = 0; i < library->materialMaxCapacity; i++){
        if(library->materialBooleanArray[i] != 0){
            if(idMaterial == library->materialArray[i]->idMaterial){
                for(int k = 0; k<library->personMaxCapacity; k++){
                    if(library->personBooleanArray[k] != 0){
                        removeBorrowedMaterial(library->personArray[k], idMaterial);
                    }
                }
                for(int k = 0; k<library->borrowMaxCapacity; k++){
                    if(library->borrowBooleanArray[k] != 0){
                        if(library->borrowArray[k]->idMaterial == idMaterial)
                            removeBorrow(library, library->borrowArray[k]->idBorrow);
                    }
                }
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
/*
 * Function: getMaterial
 * Description: finds a Material with the given id in the database.
 * Returns: Material pointer if it exists, NULL otherwise.
 */
Material* getMaterial(Library* library, int idMaterial){
    for(int i = 0; i < library->materialMaxCapacity; i++){
        if(library->materialBooleanArray[i] != 0){
            Material* material = library->materialArray[i];
            if(idMaterial == material->idMaterial)
                return material;
        }
    }
    return NULL;
}
/*
 * Function: growMagazine
 * Description: Increases the size of the Magazine array.
 * Returns: --
 */
void growMagazine(Library* library){
    library->magazineArray  = realloc(library->magazineArray, sizeof(Magazine*) * library->magazineMaxCapacity * 2);
    library->magazineBooleanArray = realloc(library->magazineBooleanArray, sizeof(int) * library->magazineMaxCapacity * 2);
    for(int i = library->magazineMaxCapacity; i < library->magazineMaxCapacity * 2; i++){
        library->magazineBooleanArray[i] = 0;
    }
    library->magazineMaxCapacity *= 2;
}
/*
 * Function: addMagazine
 * Description: adds a given Magazine to the database.
 * Returns: 1 if the Magazine was added, 0 if it wasn't.
 */
int addMagazine(Library* library, Magazine* magazine){
    if(library->amountOfMagazine != library->magazineMaxCapacity) {
        for (int i = 0; i < library->magazineMaxCapacity; i++) {
            if (library->magazineBooleanArray[i] == 0) {
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
/*
 * Function: getMagazine
 * Description: finds a Magazine with the given id in the database.
 * Returns: Magazine pointer if it exists, NULL otherwise.
 */
Magazine* getMagazine(Library* library, int idMaterial){
    for(int i = 0; i < library->magazineMaxCapacity; i++){
        if(library->magazineBooleanArray[i] != 0){
            Magazine* magazine = library->magazineArray[i];
            if(idMaterial == magazine->idMaterial)
                return magazine;
        }
    }
    return NULL;
}
/*
 * Function: growBook
 * Description: Increases the size of the Book array.
 * Returns: --
 */
void growBook(Library* library){
    library->bookArray  = realloc(library->bookArray, sizeof(Book*) * library->bookMaxCapacity * 2);
    library->bookBooleanArray = realloc(library->bookBooleanArray, sizeof(int) * library->bookMaxCapacity * 2);
    for(int i = library->bookMaxCapacity; i < library->bookMaxCapacity * 2; i++){
        library->bookBooleanArray[i] = 0;
    }
    library->bookMaxCapacity *= 2;
}
/*
 * Function: addBook
 * Description: adds a given Book to the database.
 * Returns: 1 if the Book was added, 0 if it wasn't.
 */
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
    return 1;
}
/*
 * Function: getBook
 * Description: finds a Book with the given id in the database.
 * Returns: Book pointer if it exists, NULL otherwise.
 */
Book* getBook(Library* library, int idMaterial){
    for(int i = 0; i < library->bookMaxCapacity; i++){
        if(library->bookBooleanArray[i] != 0){
            Book* book = library->bookArray[i];
            if(idMaterial == book->idMaterial)
                return book;
        }
    }
    return NULL;
}
/*
 * Function: growBorrow
 * Description: Increases the size of the Borrow array.
 * Returns: --
 */
void growBorrow(Library* library){
    library->borrowArray  = realloc(library->borrowArray, sizeof(Borrow*) * library->borrowMaxCapacity * 2);
    library->borrowBooleanArray = realloc(library->borrowBooleanArray, sizeof(int) * library->borrowMaxCapacity * 2);
    for(int i = library->borrowMaxCapacity; i < library->borrowMaxCapacity * 2; i++){
        library->borrowBooleanArray[i] = 0;
    }
    library->borrowMaxCapacity *= 2;
}
/*
 * Function: addBorrow
 * Description: adds a given Borrow to the database.
 * Returns: 1 if the Borrow was added, 0 if it wasn't.
 */
int addBorrow(Library* library, Borrow* borrow){
    if(library->amountOfBorrow != library->borrowMaxCapacity) {
        for (int i = 0; i < library->borrowMaxCapacity; i++) {
            if (!library->borrowArray[i]) {
                library->borrowArray[i] = borrow;
                library->borrowBooleanArray[i] = 1;
                library->amountOfBorrow++;
                break;
            }
        }
    }

    else {
        growBorrow(library);
        library->borrowArray[library->amountOfBorrow] = borrow;
        library->borrowBooleanArray[library->amountOfBorrow] = 1;
        library->amountOfBorrow++;
    }
    return 1;
}
/*
 * Function: getBorrow
 * Description: finds a Borrow with the given id in the database.
 * Returns: Borrow pointer if it exists, NULL otherwise.
 */
Borrow* getBorrow(Library* library, int idBorrow){
    for(int i = 0; i < library->borrowMaxCapacity; i++){
        if(library->borrowBooleanArray[i] != 0){
            Borrow* borrow = library->borrowArray[i];
            if(idBorrow == borrow->idBorrow)
                return borrow;
        }
    }
    return NULL;
}
/*
 * Function: removeBorrow
 * Description: removes the Borrow with the given id from the database.
 * Returns: --
 */
void removeBorrow(Library* library, int idBorrow){
    for(int i = 0; i < library->borrowMaxCapacity; i++){
        if(library->borrowBooleanArray[i] != 0){
            if(idBorrow == library->borrowArray[i]->idBorrow) {
                destroyBorrow(library->borrowArray[i]);
                library->borrowBooleanArray[i] = 0;
                library->amountOfBorrow--;
                return;
            }
        }
    }
}

/*
 * Function: generateIdBorrow
 * Description: Generates the next borrow id.
 * Returns: int that is the next id.
 */
int generateIdBorrow(Library* library){
    return ++library->borrowIdGenerator;
}
/*
 * Function: generateIdPerson
 * Description: Generates the next Person id.
 * Returns: int that is the next id.
 */
int generateIdPerson(Library* library){
    return ++library->personIdGenerator;
}
/*
 * Function: generateIdMaterial
 * Description: Generates the next Material id.
 * Returns: int that is the next id.
 */
int generateIdMaterial(Library* library){
    return ++library->materialIdGenerator;
}
