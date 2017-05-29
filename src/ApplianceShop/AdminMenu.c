#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include "../Util/ScanUtil.h"

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

void checkProviders(Database* database, int* providerIdArray, int* applianceIdArray){
    if(database->amountOfProviders > 0){
        printf("Providers:\n");
        for (int i = 0; i < database->amountOfProviders; i++){
            Provider* provider = getProvider(providerIdArray[i], database);
            printf(        "%d.\n%s\n"
                           "Description: %s\n"
                           "Location: %s, %s\n"
                           "Tel: %d, Web: %s\n",
                   i+1, provider->name, provider->description, provider->address,
                   provider->city, provider->phoneNumber, provider->web);
            printf("Appliances: \n");
            for(int j = 0; j < database->amountOfAppliances; j++){
                Appliance* appliance = getAppliance(applianceIdArray[j], database);
                if(appliance->idProvider == provider->providerId){
                    printf("%s\n", appliance->name);
                }
            }
            printf("-----------------\n\n");
        }
    }
}

void checkManufacturers(Database* database, int* manufacturerIdArray, int* applianceIdArray){
    if(database->amountOfManufacturers > 0){
        printf("Manufacturers:\n");
        for (int i = 0; i < database->amountOfManufacturers; i++){
            Manufacturer* manufacturer = getManufacturer(manufacturerIdArray[i], database);
            printf(        "%d.\n%s\n"
                                   "Description: %s\n"
                                   "Location: %s, %s\n"
                                   "Tel: %d, Web: %s\n",
                           i+1, manufacturer->name, manufacturer->description, manufacturer->address,
                           manufacturer->city, manufacturer->phoneNumber, manufacturer->web);
            printf("Appliances: \n");
            for(int j = 0; j < database->amountOfAppliances; j++){
                Appliance* appliance = getAppliance(applianceIdArray[j], database);
                if(appliance->idManufacturer == manufacturer->manufacturerId){
                    printf("%s\n", appliance->name);
                }
            }
            printf("-----------------\n\n");
        }
    }
}

void addApplianceMenu(Database* database, int*** applianceIdArray, int* providerIdArray, int* manufacturerIdArray){
    printf("Add appliance:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("Price:\n");
    int price = scanInt();
    printf("Provider (0 to list providers):\n");
    int providerIndex = 0;
    while(providerIndex <= 0 || providerIndex > database->amountOfProviders){
        providerIndex = scanInt();
        if(providerIndex == 0){
            checkProviders(database, providerIdArray, **applianceIdArray);
            printf("Provider (0 to list providers):\n");
        }
    }
    int idProvider = providerIdArray[providerIndex-1];
    printf("Manufacturer (0 to list manufacturers):\n");
    int manufacturerIndex = -1;
    while(manufacturerIndex == -1 && manufacturerIndex >= -1 && manufacturerIndex <= database->amountOfManufacturers){
        manufacturerIndex = scanInt();
        if(manufacturerIndex == 0){
            checkManufacturers(database, manufacturerIdArray, **applianceIdArray);
        }
    }
    int idManufacturer = manufacturerIdArray[manufacturerIndex-1];
    Appliance* appliance = newAppliance(name,price,getNextApplianceId(database),idProvider,idManufacturer);
    addAppliance(database, appliance);
    free(**applianceIdArray);
    **applianceIdArray = getApplianceIdArray(database);
    free(name);
}

void removeApplianceMenu(Database* database, int*** applianceIdArray){
    if(database->amountOfAppliances > 0){
        printf("Appliances:\n");
        for (int i = 0; i < database->amountOfAppliances; i++){
            Appliance* appliance = getAppliance(**applianceIdArray[i],database);
            printf("%d.\n%s\nPrice: %d \n", i+1, appliance->name, appliance->price);
            printf("Manufacturer: %s\nProvider: %s\n\n",
                   getManufacturer(appliance->idManufacturer, database)->name,
                   getProvider(appliance->idProvider, database)->name);
        }
    }
    int appliance = 0;
    while(1){
        printf("\nInsert number of the appliance to remove:\n");
        printf("(-1 to exit)\n");
        appliance = scanInt();
        if(appliance == -1){
            return;
        }
        if(appliance > 0 && appliance <= database->amountOfAppliances){
            removeAppliance(**applianceIdArray[appliance-1], database);
            printf("Appliance removed.\n");
            **applianceIdArray = getApplianceIdArray(database);
            return;
        } else{
            printf("Please insert a valid number.\n");
        }
    }
}

void appliancesMenu(Database *database, int **applianceIdArray, int* providerIdArray, int* manufacturerIdArray){
    while(1) {
        printf("Appliances\n");
        printf("1. Check appliances\n");
        printf("2. Add appliance\n");
        printf("3. Remove appliance\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                checkAppliances(database, *applianceIdArray);
                break;
            case 2:
                addApplianceMenu(database, &applianceIdArray, providerIdArray, manufacturerIdArray);
                break;
            case 3:
                removeApplianceMenu(database, &applianceIdArray);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}

void addProviderMenu(Database *database, int ***providerIdArray){
    printf("Add provider:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("Description:\n");
    char* description = scanChar();
    printf("Address:\n");
    char* address = scanChar();
    printf("City:\n");
    char* city = scanChar();
    printf("Web:\n");
    char* web = scanChar();
    printf("Phone:\n");
    int phone = scanInt();
    Provider* provider = newProvider(name, description, address, city, phone, web, getNextProviderId(database));
    addProvider(database, provider);
    free(**providerIdArray);
    **providerIdArray = getProviderIdArray(database);
    free(name);
    free(description);
    free(address);
    free(city);
    free(web);
}

void removeProviderMenu(Database* database, int*** providerIdArray, int*** applianceIdArray){
    if(database->amountOfProviders > 0) {
        checkProviders(database, **providerIdArray, **applianceIdArray);
        int choiceIndex = scanInt();
        while (choiceIndex <= 0 || choiceIndex > database->amountOfProviders) {
            printf("Please enter a valid number\n");
            choiceIndex = scanInt();
        }
        removeProvider(**providerIdArray[choiceIndex - 1], database);
        free(**providerIdArray);
        **providerIdArray = getProviderIdArray(database);
    }
}


void providersMenu(Database *database, int **applianceIdArray, int** providerIdArray){
    while(1) {
        printf("Providers\n");
        printf("1. Check providers\n");
        printf("2. Add provider\n");
        printf("3. Remove provider\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                checkProviders(database, *providerIdArray, *applianceIdArray);
                break;
            case 2:
                addProviderMenu(database, &providerIdArray);
                break;
            case 3:
                removeProviderMenu(database, &providerIdArray, &applianceIdArray);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}

void addManufacturerMenu(Database* database, int*** manufacturerIdArray){
    printf("Add Manufacturer:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("Description:\n");
    char* description = scanChar();
    printf("Address:\n");
    char* address = scanChar();
    printf("City:\n");
    char* city = scanChar();
    printf("Web:\n");
    char* web = scanChar();
    printf("Phone:\n");
    int phone = scanInt();
    Manufacturer* manufacturer = newManufacturer(name, description, address, city, phone, web, getNextManufacturerId(database));
    addManufacturer(database, manufacturer);
    free(**manufacturerIdArray);
    **manufacturerIdArray = getProviderIdArray(database);
    free(name);
    free(description);
    free(address);
    free(city);
    free(web);
}

void removeManufacturerMenu(Database* database, int*** manufacturerIdArray, int*** applianceIdArray){
    if(database->amountOfManufacturers > 0) {
        checkManufacturers(database, **manufacturerIdArray, **applianceIdArray);
        int choiceIndex = scanInt();
        while (choiceIndex <= 0 || choiceIndex > database->amountOfManufacturers) {
            printf("Please enter a valid number\n");
            choiceIndex = scanInt();
        }
        removeProvider(**manufacturerIdArray[choiceIndex - 1], database);
        free(**manufacturerIdArray);
        **manufacturerIdArray = getProviderIdArray(database);
    }
}

void manufacturersMenu(Database *database, int **applianceIdArray, int** manufacturerIdArray){
    while(1) {
        printf("Manufacturers\n");
        printf("1. Check manufacturers\n");
        printf("2. Add manufacturer\n");
        printf("3. Remove manufacturer\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                checkManufacturers(database, *manufacturerIdArray, *applianceIdArray);
                break;
            case 2:
                addManufacturerMenu(database, &manufacturerIdArray);
                break;
            case 3:
                removeManufacturerMenu(database, &manufacturerIdArray, &applianceIdArray);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
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
        int choice = scanInt();
        switch (choice) {
            case 1:
                appliancesMenu(database, &applianceIdArray, manufacturerIdArray, providerIdArray);
                break;
            case 2:
                manufacturersMenu(database, &applianceIdArray, &manufacturerIdArray);
                break;
            case 3:
                providersMenu(database, &applianceIdArray, &providerIdArray);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}