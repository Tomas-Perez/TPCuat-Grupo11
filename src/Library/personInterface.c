#include <stdio.h>
#include "Library.h"
#include "../Util/ScanUtil.h"

void personListMaterialMenu(Library* library, Person* person){
    if(person->amountOfBorrowedMaterial == 0){
        printf("\nThere are no subjects for this career.\n");
        return;
    }
    printf("\n- Your borrowed materials -\n\n");
    for(int i = 0, j = 0; i<person->borrowedMaterialMaxCapacity, j<person->amountOfBorrowedMaterial;i++){
        if(person->borrowedMaterial[i] != 0){
            j++;
            Material* material = getMaterial(library, person->borrowedMaterial[i]);
            printf("%d. %s\n", j, material->title);
            //TODO
        }
    }
}

void personMenu(Library* library, Person* person){
    while(1) {
        printf("-- Library --\n");
        printf("1. List Books and magazines\n");
        printf("2. My borrowed material\n");
        printf("3. Return borrowed material\n");
        printf("-1. exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                personListMaterialMenu(library, person);
                break;
            case 2:
                personListBorrowedMaterialMenu(library, person);
                break;
            case 3:
                personListReturnMaterialMenu(library, person);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}