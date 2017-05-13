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
    database->providerMaxCapacity *= 2;
}
void growAppliance(Database* database){
    database->arrayAppliance = realloc(database->arrayAppliance, sizeof(database->arrayAppliance) * 2);
    database->booleanArrayAppliance = realloc(database->booleanArrayAppliance, sizeof(database->booleanArrayAppliance) * 2);
    database->applianceMaxCapacity *= 2;
}
void growManufacturer(Database* database){
    database->arrayManufacturer = realloc(database->arrayManufacturer, sizeof(database->arrayManufacturer) * 2);
    database->booleanArrayManufacturer = realloc(database->booleanArrayManufacturer, sizeof(database->booleanArrayManufacturer) * 2);
    database->manufacturerMaxCapacity *= 2;
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
