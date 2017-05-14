#include <stdio.h>
#include <malloc.h>
#include "Database.h"

int* getApplianceIdArray(Database* database);

int* getManufacturerIdArray(Database* database){
    int* result = malloc(sizeof(int)*database->amountOfManufacturers);
    for(int i = 0, j = 0; i < database->manufacturerMaxCapacity, j < database->amountOfManufacturers; i++){
        if(database->booleanArrayManufacturer[i]){
            result[j] = database->arrayManufacturer[i]->manufacturerId;
            j++;
        }
    }
    return result;
}

int* getProviderIdArray(Database* database){
    int* result = malloc(sizeof(int)*database->amountOfProviders);
    for(int i = 0, j = 0; i < database->manufacturerMaxCapacity, j < database->amountOfProviders; i++){
        if(database->booleanArrayManufacturer[i]){
            result[j] = database->arrayProvider[i]->providerId;
            j++;
        }
    }
    return result;
}

void checkAppliances(Database* database, int* applianceIdArray){

}

void checkProviders(Database* database, int* providerIdArray){

}

void checkManufacturers(Database* database, int* manufacturerIdArray){

}

void adminMenu(Database* database){
    int* applianceIdArray = getApplianceIdArray(database);
    int* manufacturerIdArray = getManufacturerIdArray(database);
    int* providerIdArray = getProviderIdArray(database);
    while(1) {
        printf("Admin Menu\n");
        printf("1. Check Appliances\n");
        printf("2. Check Manufacturers\n");
        printf("3. Check Providers\n");
        printf("-1. Exit\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                checkAppliances(database, applianceIdArray);
                break;
            case 2:
                checkManufacturers(database, manufacturerIdArray);
                break;
            case 3:
                checkProviders(database, providerIdArray);
            case -1:
                return;
            default:
                printf("Please enter one of the options");
                fseek(stdin,0,SEEK_END);
        }
    }
}