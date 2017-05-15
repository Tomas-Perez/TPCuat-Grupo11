#include <malloc.h>
#include "Database.h"


Database* newDatabase(){
    Database* database = malloc(sizeof(Database));
    int initialSize = 25;
    database->arrayProvider = malloc(sizeof(Provider*) * initialSize);
    database->booleanArrayProvider = malloc(sizeof(int) * initialSize);
    database->providerMaxCapacity = initialSize;
    database->arrayAppliance = malloc(sizeof(Appliance*) * initialSize);
    database->booleanArrayAppliance = malloc(sizeof(int) * initialSize);
    database->applianceMaxCapacity = initialSize;
    database->arrayManufacturer = malloc(sizeof(Manufacturer*) * initialSize);
    database->booleanArrayManufacturer = malloc(sizeof(int) * initialSize);
    database->manufacturerMaxCapacity = initialSize;
    database->idProviderGenerator = 1;
    database->idApplianceGenerator = 1;
    database->idManufacturerGenerator = 1;
    database->amountOfAppliances = 0;
    database->amountOfProviders = 0;
    database->amountOfManufacturers = 0;
    for(int i = 0; i < initialSize; i++){
        database->booleanArrayProvider[i] = 0;
        database->booleanArrayAppliance[i] = 0;
        database->booleanArrayManufacturer[i] = 0;
    }

    return database;
}

void destroyDatabase(Database* database){
    for(int i = 0; i < database->providerMaxCapacity; i++){
        if(database->booleanArrayProvider[i] != 0){
            destroyProvider(database->arrayProvider[i]);
        }
    }
    free(database->arrayProvider);
    free(database->booleanArrayProvider);
    for(int i = 0; i < database->applianceMaxCapacity; i++){
        if(database->booleanArrayAppliance[i] != 0){
            destroyAppliance(database->arrayAppliance[i]);
        }
    }
    free(database->arrayAppliance);
    free(database->booleanArrayAppliance);
    for(int i = 0; i < database->manufacturerMaxCapacity; i++){
        if(database->booleanArrayManufacturer[i] != 0){
            destroyManufacturer(database->arrayManufacturer[i]);
        }
    }
    free(database->arrayManufacturer);
    free(database->booleanArrayManufacturer);

    free(database);
}

Provider* getProvider(int idProvider, Database* database){
    for(int i = 0; i < database->providerMaxCapacity; i++){
        if(database->booleanArrayProvider[i] != 0){
            Provider* provider = database->arrayProvider[i];
            if(idProvider == provider->providerId)
                return provider;
        }
    }
    return NULL;
}
Appliance* getAppliance(int idAppliance, Database* database){
    for(int i = 0; i < database->applianceMaxCapacity; i++){
        if(database->booleanArrayAppliance[i] != 0){
            Appliance* appliance = database->arrayAppliance[i];
            if(idAppliance == appliance->idAppliance)
                return appliance;
        }
    }
    return NULL;
}
Manufacturer* getManufacturer(int idManufacturer, Database* database){
    for(int i = 0; i < database->manufacturerMaxCapacity; i++){
        if(database->booleanArrayManufacturer[i] != 0){
            Manufacturer* manufacturer = database->arrayManufacturer[i];
            if(idManufacturer == manufacturer->manufacturerId)
                return manufacturer;
        }
    }
    return NULL;
}
void growProvider(Database* database){
    database->arrayProvider = realloc(database->arrayProvider, sizeof(database->arrayProvider) * 2);
    database->booleanArrayProvider = realloc(database->booleanArrayProvider, sizeof(database->booleanArrayProvider) * 2);
    for(int i = database->providerMaxCapacity; i < database->providerMaxCapacity; i++){
        database->booleanArrayProvider[i] = 0;
    }
    database->providerMaxCapacity *= 2;
}
void growAppliance(Database* database){
    database->arrayAppliance = realloc(database->arrayAppliance, sizeof(database->arrayAppliance) * 2);
    database->booleanArrayAppliance = realloc(database->booleanArrayAppliance, sizeof(database->booleanArrayAppliance) * 2);
    for(int i = database->applianceMaxCapacity; i < database->applianceMaxCapacity; i++){
        database->booleanArrayAppliance[i] = 0;
    }
    database->applianceMaxCapacity *= 2;
}
void growManufacturer(Database* database){
    database->arrayManufacturer = realloc(database->arrayManufacturer, sizeof(database->arrayManufacturer) * 2);
    database->booleanArrayManufacturer = realloc(database->booleanArrayManufacturer, sizeof(database->booleanArrayManufacturer) * 2);
    for(int i = database->manufacturerMaxCapacity; i < database->manufacturerMaxCapacity; i++){
        database->booleanArrayManufacturer[i] = 0;
    }
    database->manufacturerMaxCapacity *= 2;
}

void addProvider(Database* database, Provider* provider){
    if(database->amountOfProviders != database->providerMaxCapacity) {
        for (int i = 0; i < database->providerMaxCapacity; i++) {
            if (!database->booleanArrayProvider[i]) {
                database->arrayProvider[i] = provider;
                database->booleanArrayProvider[i] = 1;
                database->amountOfProviders++;
                break;
            }
        }
    }

    else {
        growProvider(database);
        database->arrayProvider[database->amountOfProviders] = provider;
        database->booleanArrayProvider[database->amountOfProviders] = 1;
        database->amountOfProviders++;
    }
}
void addAppliance(Database* database, Appliance* appliance){
    if(database->amountOfAppliances != database->applianceMaxCapacity) {
        for (int i = 0; i < database->applianceMaxCapacity; i++) {
            if (!database->booleanArrayAppliance[i]) {
                database->arrayAppliance[i] = appliance;
                database->booleanArrayAppliance[i] = 1;
                database->amountOfAppliances++;
                break;
            }
        }
    }
    else {
        growAppliance(database);
        database->arrayAppliance[database->amountOfAppliances] = appliance;
        database->booleanArrayAppliance[database->amountOfAppliances] = 1;
        database->amountOfAppliances++;
    }
}
void addManufacturer(Database* database, Manufacturer* manufacturer){
    if(database->amountOfManufacturers != database->manufacturerMaxCapacity) {
        for (int i = 0; i < database->manufacturerMaxCapacity; i++) {
            if (!database->booleanArrayManufacturer[i]) {
                database->arrayManufacturer[i] = manufacturer;
                database->booleanArrayManufacturer[i] = 1;
                database->amountOfManufacturers++;
                break;
            }
        }
    }
    else {
        growManufacturer(database);
        database->arrayManufacturer[database->amountOfManufacturers] = manufacturer;
        database->booleanArrayManufacturer[database->amountOfManufacturers] = 1;
        database->amountOfManufacturers++;
    }
}
//TODO should remove all related Appliances
void removeProvider(int idProvider, Database* database){
    for(int i = 0; i < database->providerMaxCapacity; i++){
        if(database->booleanArrayProvider[i] != 0){
            if(idProvider == database->arrayProvider[i]->providerId){
                destroyProvider(database->arrayProvider[i]);
                database->booleanArrayProvider[i] = 0;
                database->amountOfProviders--;
                break;
            }
        }
    }
}
//TODO nothing ay lmao
void removeAppliance(int idAppliance, Database* database){
    for(int i = 0; i < database->applianceMaxCapacity; i++){
        if(database->booleanArrayAppliance[i] != 0){
            if(idAppliance == database->arrayAppliance[i]->idAppliance){
                destroyAppliance(database->arrayAppliance[i]);
                database->booleanArrayAppliance[i] = 0;
                database->amountOfAppliances--;
                break;
            }
        }
    }
}
//TODO should remove all related Appliances
void removeManufacturer(int idManufacturer, Database* database){
    for(int i = 0; i < database->manufacturerMaxCapacity; i++){
        if(database->booleanArrayManufacturer[i] != 0){
            if(idManufacturer == database->arrayManufacturer[i]->manufacturerId){
                destroyManufacturer(database->arrayManufacturer[i]);
                database->booleanArrayManufacturer[i] = 0;
                database->amountOfManufacturers--;
                break;
            }
        }
    }
}

int getNextProviderId(Database* database){
    int result = database->idProviderGenerator;
    database->idProviderGenerator += 1;
    return result;
}
int getNextApplianceId(Database* database){
    int result = database->idApplianceGenerator;
    database->idApplianceGenerator += 1;
    return result;
}
int getNextManufacturerId(Database* database) {
    int result = database->idManufacturerGenerator;
    database->idManufacturerGenerator += 1;
    return result;
}
