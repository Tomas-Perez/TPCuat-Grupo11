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

void appliancesMenu(Database *database, int *applianceIdArray, int* providerIdArray, int* manufacturerIdArray){
    while(1) {
        printf("Appliances\n");
        printf("1. Check appliances\n");
        printf("2. Add appliance\n");
        printf("3. Remove appliance\n");
        printf("-1. Exit\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                checkAppliances(database, applianceIdArray);
                break;
            case 2:
                addApplianceMenu(database, applianceIdArray, providerIdArray, manufacturerIdArray);
                break;
            case 3:
                //removeApplianceMenu(database, applianceIdArray);
            case -1:
                return;
            default:
                printf("Please enter one of the options");
                fseek(stdin,0,SEEK_END);
        }
    }
}



void checkAppliances(Database* database, int* applianceIdArray){
    if(database->amountOfAppliances > 0){
        printf("Appliances:\n");
        for (int i = 0; i < database->amountOfAppliances; i++){
            Appliance* appliance = getAppliance(applianceIdArray[i],database);
            printf("%d.\n%s\nPrice: %d \n", i+1, appliance->name, appliance->price);
            printf("Manufacturer: %s\nProvider: %s\n\n",
                   getManufacturer(appliance->idManufacturer, database)->name,
                   getProvider(appliance->idProvider, database)->name);
        }
    }
}

void checkProviders(Database* database, int* providerIdArray){
    int a = 0;
}

void checkManufacturers(Database* database, int* manufacturerIdArray){

}

void addApplianceMenu(Database* database, int* applianceIdArray, int* providerIdArray, int* manufacturerIdArray){
    printf("Add appliance:\n");
    printf("Name:\n");
    char* name = malloc(sizeof(char) * 20);
    scanf("%s", name);
    printf("Price:\n");
    int price = 0;
    while(price == 0){
        scanf("%d", &price);
        fseek(stdin,0,SEEK_END);
    }
    printf("Provider (0 to list providers):\n");
    int providerIndex = 0;
    while(providerIndex <= 0 && providerIndex > database->amountOfProviders){
        scanf("%d", &providerIndex);
        fseek(stdin,0,SEEK_END);
        if(providerIndex == 0){
            checkProviders(database, providerIdArray);
        }
    }
    int idProvider = providerIdArray[providerIndex-1];
    printf("Manufacturer (0 to list manufacturers):\n");
    int manufacturerIndex = -1;
    while(manufacturerIndex == -1 && manufacturerIndex >= -1 && manufacturerIndex <= database->amountOfManufacturers){
        scanf("%d", &manufacturerIndex);
        fseek(stdin,0,SEEK_END);
        if(manufacturerIndex == 0){
            checkManufacturers(database, manufacturerIdArray);
        }
    }
    int idManufacturer = manufacturerIdArray[manufacturerIndex-1];
    Appliance* appliance = newAppliance(name,price,getNextApplianceId(database),idProvider,idManufacturer);
    addAppliance(database, appliance);
    applianceIdArray = getApplianceIdArray(database);
}

void adminMenu(Database* database){
    int* applianceIdArray = getApplianceIdArray(database);
    int* manufacturerIdArray = getManufacturerIdArray(database);
    int* providerIdArray = getProviderIdArray(database);
    while(1) {
        printf("Admin Menu\n");
        printf("1. Appliances\n");
        printf("2. Manufacturers\n");
        printf("3. Providers\n");
        printf("-1. Exit\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                appliancesMenu(database, applianceIdArray, manufacturerIdArray, providerIdArray);
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