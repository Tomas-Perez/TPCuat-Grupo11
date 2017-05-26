#include <stdio.h>
#include "Library.h"
#include "../Util/ScanUtil.h"

void personListMaterialMenu(Library* library, Person* person){
    if(library->amountOfMaterial == 0){
        printf("\nThere are no materials.\n");
        return;
    }
    Material* materialArray[library->amountOfMaterial];
    int k = 0;
    printf("\n-- Books and Magazines --\n\n");
    printf("\n- Books -\n\n");
    for(int i = 0, j = 0; i<library->personMaxCapacity, j<library->amountOfBook;i++){
        if(library->materialBooleanArray[i] != 0 ){
            Material* material = library->materialArray[i];
            if(material->type == 1){
                j++;
                materialArray[k] = material;
                k++;
                printf("%d. %s\n", j, material->title);
                if(material->isTaken)
                    printf("Available: No\n");
                else
                    printf("Available: Yes\n");
            }
        }
    }
    printf("\n- Magazines -\n\n");
    for(int i = 0, j = 0; i<library->personMaxCapacity, j<library->amountOfMagazine;i++){
        if(library->materialBooleanArray[i] != 0 ){
            Material* material = library->materialArray[i];
            if(material->type == 2){
                j++;
                materialArray[k] = material;
                k++;
                printf("%d. %s\n", j, material->title);
                if(material->isTaken)
                    printf("Available: No\n");
                else
                    printf("Available: Yes\n");

            }

        }
    }
    int material = 0;
    while(1){
        printf("\nInsert number of the material to borrow:\n");
        printf("(-1 to exit)\n");
        material = scanInt();
        if(material == -1){
            return;
        }
        if(material > 0 && material <= k){
            if(materialArray[material-1]->isTaken){
                printf("That material is already borrowed\n");
            } else{
                materialArray[material-1]->isTaken = 0;
                addBorrowedMaterial(person, materialArray[material-1]->idMaterial);
                printf("Material :%s: Borrowed.\n", materialArray[material-1]->title);
            }
        } else{
            printf("Please insert a valid number.\n");
        }
    }
}


void personListBorrowedMaterialMenu(Library* library,Person* person){
    if(person->amountOfBorrowedMaterial == 0){
        printf("\nYou have no borrowed material.\n");
        return;
    }
    Material* materialArray[person->amountOfBorrowedMaterial];
    printf("\n-- Your borrowed material --\n\n");
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
            printf("Material :%s: returned.\n", materialArray[material-1]->title);
            return;
        } else{
            printf("Please insert a valid number.\n");
        }
    }
}

void personMenu(Library* library, Person* person){
    while(1) {
        printf("\n-- Library --\n");
        printf("1. List Books and magazines\n");
        printf("2. My borrowed material\n");
        printf("-1. exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                personListMaterialMenu(library, person);
                break;
            case 2:
                personListBorrowedMaterialMenu(library, person);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}