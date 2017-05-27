#include <stdio.h>
#include <mem.h>
#include "Library.h"
#include "../Util/ScanUtil.h"

void listMaterialMenu(Library *library){
    if(library->amountOfMaterial == 0){
        printf("\nThere are no materials.\n");
        return;
    }
    Material* materialArray[library->amountOfMaterial];
    int k = 0;
    printf("\n-- Books and Magazines --\n\n");
    if(library->amountOfBook > 0) {
        printf("\n- Books -\n");
        for (int i = 0, j = 0; i < library->materialMaxCapacity, j < library->amountOfBook; i++) {
            if (library->materialBooleanArray[i] != 0) {
                Material *material = library->materialArray[i];
                if (material->type == 1) {
                    Book* book = getBook(library, material->idMaterial);
                    j++;
                    materialArray[k] = material;
                    k++;
                    printf("\n%d. %s\n", k, material->title);
                    printf("Author: %s\n", material->author);
                    printf("year: %d\n", material->year);
                    printf("Editorial: %s\n", book->editorial);
                    if (material->isTaken) {
                        printf("Available: No\n");
                    }
                    else
                        printf("Available: Yes\n");
                }
            }
        }
    }
    if(library->amountOfMagazine > 0) {
        printf("\n- Magazines -\n");
        for (int i = 0, j = 0; i < library->materialMaxCapacity, j < library->amountOfMagazine; i++) {
            if (library->materialBooleanArray[i] != 0) {
                Material *material = library->materialArray[i];
                if (material->type == 2) {
                    j++;
                    materialArray[k] = material;
                    k++;
                    printf("\n%d. %s\n", k, material->title);
                    printf("Author: %s\n", material->author);
                    printf("year: %d\n", material->year);
                    if (material->isTaken)
                        printf("Available: No\n");
                    else
                        printf("Available: Yes\n");

                }

            }
        }
    }
    printf("\nUsername that borrows:\n");
    printf("(-1 to exit)\n");
    char* username;
    Person* person;
    while(1){
        username = scanChar();
        person = getPersonByUsername(library, username);
        if(strcmp(username,"-1") == 0){
            return;
        }
        if(person != NULL){
            break;
        }
        printf("User does not exist\n");
    }
    char* type;
    if(person->type == 1){
        type = "student";
    }
    else if (person->type == 2){
        type = "teacher";
    }
    printf("User: %s %s\n", person->name, person->surname);
    printf("(%s)\n", type);
    int material = 0;
    while(1){
        printf("\nInsert number of the material to borrow:\n");
        material = scanInt();
        if(material == -1){
            return;
        }
        if(material > 0 && material <= k){
            if(materialArray[material-1]->isTaken){
                printf("That material is already borrowed\n");
            } else{
                printf("- Dates -\n");
                printf("From:\n");
                char* from = scanChar();
                printf("Until:\n");
                char* until = scanChar();
                materialArray[material-1]->isTaken = 1;
                Borrow* borrow = newBorrow(generateIdBorrow(library),materialArray[material-1]->idMaterial,person->idPerson,from,until);
                addBorrow(library, borrow);
                addBorrowedMaterial(person, materialArray[material-1]->idMaterial);
                printf("Material \"%s\" borrowed by %s %s.\n", materialArray[material-1]->title, person->name, person->surname);
            }
        } else{
            printf("Please insert a valid number.\n");
        }
    }
}
void listBorrowedMaterialMenu(Library *library){
    printf("\nUsername:\n");
    printf("(-1 to exit)\n");
    char* username;
    Person* person;
    while(1){
        username = scanChar();
        person = getPersonByUsername(library, username);
        if(strcmp(username,"-1") == 0){
            return;
        }
        if(person != NULL){
            break;
        }
        printf("User does not exist\n");
    }
    if(person->amountOfBorrowedMaterial == 0){
        printf("\n%s %s has no borrowed material.\n", person->name, person->surname);
        return;
    }
    Material* materialArray[person->amountOfBorrowedMaterial];
    printf("\n-- %s %s borrowed material --\n\n", person->name, person->surname);
    for(int i = 0, j = 0; i<person->borrowedMaterialMaxCapacity, j<person->amountOfBorrowedMaterial;i++){
        if(person->borrowedMaterial[i] != 0){
            Material* material = getMaterial(library, person->borrowedMaterial[i]);
            materialArray[j] = material;
            j++;
            printf("%d. %s\n", j, material->title);
        }
    }
    int material = 0;
    while(1){
        printf("\nInsert number of the material to return:\n");
        printf("(-1 to exit)\n");
        material = scanInt();
        if(material == -1){
            return;
        }
        if(material > 0 && material <= person->amountOfBorrowedMaterial){
            materialArray[material-1]->isTaken = 0;
            removeBorrowedMaterial(person, materialArray[material-1]->idMaterial);
            printf("Material \"%s\" returned.\n", materialArray[material-1]->title);
            return;
        } else{
            printf("Please insert a valid number.\n");
        }
    }
}
void addMaterialMenu(Library* library){
    printf("\n-- Add Material --\n");
    printf("(-1 to cancel)\n");
    printf("Type (1 book, 2 magazine):\n");
    int type = 0;
    while (1){
        type = scanInt();
        if(type == 1 || type == 2){
            break;
        }
        if(type < 0){
            return;
        }
        printf("Please insert a valid type\n");
    }
    printf("Title:\n");
    char* title = scanChar();
    if(strcmp(title,"-1") == 0){
        return;
    }
    printf("Author:\n");
    char* author = scanChar();
    if(strcmp(author,"-1") == 0){
        return;
    }
    printf("Year:\n");
    int year = scanInt();
    if(year == -1){
        return;
    }

    Material* material = newMaterial(generateIdMaterial(library), type, title, author, year);
    if(type == 1){
        printf("Editorial:\n");
        char* editorial = scanChar();
        if(strcmp(editorial,"-1") == 0){
            return;
        }
        Book* book = newBook(material->idMaterial, editorial);
        addBook(library, book);
    } else if(type == 2){
        Magazine* magazine = newMagazine(material->idMaterial);
        addMagazine(library, magazine);
    }
    addMaterial(library, material);
    printf("Material added successfully\n");
}
void removeMaterialMenu(Library* library){
    if(library->amountOfMaterial == 0){
        printf("\nThere are no materials.\n");
        return;
    }
    Material* materialArray[library->amountOfMaterial];
    int k = 0;
    printf("\n-- Books and Magazines --\n\n");
    if(library->amountOfBook > 0) {
        printf("\n- Books -\n");
        for (int i = 0, j = 0; i < library->materialMaxCapacity, j < library->amountOfBook; i++) {
            if (library->materialBooleanArray[i] != 0) {
                Material *material = library->materialArray[i];
                if (material->type == 1) {
                    Book* book = getBook(library, material->idMaterial);
                    j++;
                    materialArray[k] = material;
                    k++;
                    printf("\n%d. %s\n", k, material->title);
                    printf("Author: %s\n", material->author);
                    printf("year: %d\n", material->year);
                    printf("Editorial: %s\n", book->editorial);
                    if (material->isTaken) {
                        printf("Available: No\n");
                    }
                    else
                        printf("Available: Yes\n");
                }
            }
        }
    }
    if(library->amountOfMagazine > 0) {
        printf("\n- Magazines -\n");
        for (int i = 0, j = 0; i < library->materialMaxCapacity, j < library->amountOfMagazine; i++) {
            if (library->materialBooleanArray[i] != 0) {
                Material *material = library->materialArray[i];
                if (material->type == 2) {
                    j++;
                    materialArray[k] = material;
                    k++;
                    printf("\n%d. %s\n", k, material->title);
                    printf("Author: %s\n", material->author);
                    printf("year: %d\n", material->year);
                    if (material->isTaken)
                        printf("Available: No\n");
                    else
                        printf("Available: Yes\n");

                }

            }
        }
    }
    int material = 0;
    while(1){
        printf("\nInsert number of the material to remove:\n");
        printf("(-1 to exit)\n");
        material = scanInt();
        if(material == -1){
            return;
        }
        if(material > 0 && material <= library->amountOfMaterial){
            removeMaterial(library, materialArray[material-1]->idMaterial);
            printf("Material removed.\n");
            return;
        } else{
            printf("Please insert a valid number.\n");
        }
    }
}

void borrowReportMenu(Library* library){
    if(library->amountOfBorrow == 0){
        printf("\nThere are no borrows.\n");
        return;
    }
    printf("\n-- Borrow report --\n\n");
    for(int i = 0, j = 0; i<library->borrowMaxCapacity, j<library->amountOfBorrow;i++){
        if(library->borrowBooleanArray[i] != 0){
            Borrow* borrow = library->borrowArray[i];
            Material* material = getMaterial(library, borrow->idMaterial);
            Person* person = getPersonById(library, borrow->idPerson);
            j++;
            printf("\n%d.\n", j);
            printf("User: %s %s (%s)\n", person->name, person->surname, person->username);
            printf("Material: %s\n", material->title);
            printf("Start date: %s\n", borrow->startDate);
            printf("Finish date: %s\n\n", borrow->finishDate);
        }
    }
}

void adminMenu(Library* library){
    while(1) {
        printf("\n-- Library --\n");
        printf("1. Borrow Books and magazines\n");
        printf("2. Return borrowed material\n");
        printf("3. Add Material\n");
        printf("4. Remove Material\n");
        printf("5. Borrow report\n");
        printf("-1. exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                listMaterialMenu(library);
                break;
            case 2:
                listBorrowedMaterialMenu(library);
                break;
            case 3:
                addMaterialMenu(library);
                break;
            case 4:
                removeMaterialMenu(library);
                break;
            case 5:
                borrowReportMenu(library);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}