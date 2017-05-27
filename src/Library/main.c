#include <stdio.h>
#include "Library.h"

void mainMenu(Library* library);
void logInMenu(Library* library);
void accountCreationMenu(Library* library);

Library* setUp(){
    Library* library = newLibrary();
    Material* material1 = newMaterial(generateIdMaterial(library), 1, "Analyzing 1", "Josh drake", 2015);
    Book* book1 = newBook(material1->idMaterial,"Nova");
    Material* material2 = newMaterial(generateIdMaterial(library), 1, "123 no 4", "Brandon Sanderson", 2008);
    Book* book2 = newBook(material2->idMaterial,"We edit");
    Material* material3 = newMaterial(generateIdMaterial(library), 1, "How to name a book", "Santa Claus", 1997);
    Book* book3 = newBook(material3->idMaterial,"Magical");
    Material* material4 = newMaterial(generateIdMaterial(library), 1, "C programming", "Jax main", 2011);
    Book* book4 = newBook(material4->idMaterial,"NewTech");
    Material* material5 = newMaterial(generateIdMaterial(library), 2, "Science for everyone", "King", 2013);
    Magazine* magazine1 = newMagazine(material5->idMaterial);
    Material* material6 = newMaterial(generateIdMaterial(library), 2, "The history", "Old dudes", 2016);
    Magazine* magazine2 = newMagazine(material6->idMaterial);
    Material* material7 = newMaterial(generateIdMaterial(library), 2, "Time", "Space magic", 2017);
    Magazine* magazine3 = newMagazine(material7->idMaterial);

    addMaterial(library, material1);
    addMaterial(library, material2);
    addMaterial(library, material3);
    addMaterial(library, material4);
    addMaterial(library, material5);
    addMaterial(library, material6);
    addMaterial(library, material7);
    addBook(library, book1);
    addBook(library, book2);
    addBook(library, book3);
    addBook(library, book4);
    addMagazine(library, magazine1);
    addMagazine(library, magazine2);
    addMagazine(library, magazine3);

    Person* person1 = newPerson(generateIdPerson(library),"student1",1,"John","White",132456);
    Student* student1 = newStudent(255,person1->idPerson);
    Person* person2 = newPerson(generateIdPerson(library),"student2",1,"Selina","Kyle",124525);
    Student* student2 = newStudent(452,person2->idPerson);
    Person* person3 = newPerson(generateIdPerson(library),"teacher1",2,"Ronald","Burger",85721);
    Teacher* teacher1 = newTeacher(321,person3->idPerson);
    Person* person4 = newPerson(generateIdPerson(library),"admin",3,"admin","admin",85721);

    addPerson(library, person1);
    addPerson(library, person2);
    addPerson(library, person3);
    addPerson(library, person4);
    addStudent(library, student1);
    addStudent(library, student2);
    addTeacher(library, teacher1);

    material2->isTaken = 1;
    material5->isTaken = 1;
    addBorrowedMaterial(person2, material2->idMaterial);
    addBorrowedMaterial(person2, material5->idMaterial);
    Borrow* borrow1 = newBorrow(generateIdBorrow(library),material2->idMaterial,person2->idPerson,"27/06/2017","3/07/2017");
    Borrow* borrow2 = newBorrow(generateIdBorrow(library),material5->idMaterial,person2->idPerson,"27/06/2017","3/07/2017");
    addBorrow(library, borrow1);
    addBorrow(library, borrow2);

    return library;
}

int main() {
    Library* library = setUp();
    mainMenu(library);
    return 0;
}