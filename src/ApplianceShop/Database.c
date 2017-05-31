#include <stdlib.h>
#include "Database.h"

/*
 * Function: newDatabase
 * Description: Creates a new Database with the given data.
 * Returns: Database pointer.
 */
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
/*
 * Function: destroyDatabase
 * Description: Deallocates all memory related to the Database.
 * Returns: --
 */
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
/*
 * Function: getProvider
 * Description: finds a Provider with the given id in the database.
 * Returns: Provider pointer if it exists, NULL otherwise.
 */
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
/*
 * Function: getAppliance
 * Description: finds a Appliance with the given id in the database.
 * Returns: Appliance pointer if it exists, NULL otherwise.
 */
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
/*
 * Function: getManufacturer
 * Description: finds a Manufacturer with the given id in the database.
 * Returns: Manufacturer pointer if it exists, NULL otherwise.
 */
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
/*
 * Function: growProvider
 * Description: Increases the size of the Provider array.
 * Returns: --
 */
void growProvider(Database* database){
    database->arrayProvider = realloc(database->arrayProvider, sizeof(Provider*) * database->providerMaxCapacity * 2);
    database->booleanArrayProvider = realloc(database->booleanArrayProvider, sizeof(int) * database->providerMaxCapacity * 2);
    for(int i = database->providerMaxCapacity; i < database->providerMaxCapacity * 2; i++){
        database->booleanArrayProvider[i] = 0;
    }
    database->providerMaxCapacity *= 2;
}
/*
 * Function: growAppliance
 * Description: Increases the size of the Appliance array.
 * Returns: --
 */
void growAppliance(Database* database){
    database->arrayAppliance = realloc(database->arrayAppliance, sizeof(Appliance*) * database->applianceMaxCapacity * 2);
    database->booleanArrayAppliance = realloc(database->booleanArrayAppliance, sizeof(int) * database->applianceMaxCapacity * 2);
    for(int i = database->applianceMaxCapacity; i < database->applianceMaxCapacity  * 2; i++){
        database->booleanArrayAppliance[i] = 0;
    }
    database->applianceMaxCapacity *= 2;
}
/*
 * Function: growManufacturer
 * Description: Increases the size of the Manufacturer array.
 * Returns: --
 */
void growManufacturer(Database* database){
    database->arrayManufacturer = realloc(database->arrayManufacturer, sizeof(Manufacturer*) * database->manufacturerMaxCapacity * 2);
    database->booleanArrayManufacturer = realloc(database->booleanArrayManufacturer, sizeof(int) * database->manufacturerMaxCapacity * 2);
    for(int i = database->manufacturerMaxCapacity; i < database->manufacturerMaxCapacity * 2; i++){
        database->booleanArrayManufacturer[i] = 0;
    }
    database->manufacturerMaxCapacity *= 2;
}
/*
 * Function: addProvider
 * Description: adds a given Provider to the database.
 * Returns: 1 if the Provider was added, 0 if it wasn't.
 */
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
/*
 * Function: addAppliance
 * Description: adds a given Appliance to the database.
 * Returns: 1 if the Appliance was added, 0 if it wasn't.
 */
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
/*
 * Function: addManufacturer
 * Description: adds a given Manufacturer to the database.
 * Returns: 1 if the Manufacturer was added, 0 if it wasn't.
 */
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
/*
 * Function: removeProvider
 * Description: removes the Provider with the given id from the database.
 * Returns: --
 */
void removeProvider(int idProvider, Database* database){
    for(int i = 0; i < database->providerMaxCapacity; i++){
        if(database->booleanArrayProvider[i] != 0){
            if(idProvider == database->arrayProvider[i]->providerId){
                for(int j = 0; i<database->applianceMaxCapacity; j++){
                    if(database->booleanArrayAppliance[i] != 0){
                        if(database->arrayAppliance[i]->idProvider == idProvider){
                            destroyAppliance(database->arrayAppliance[i]);
                            database->booleanArrayAppliance[i] = 0;
                            database->amountOfAppliances--;
                        }
                    }
                }
                destroyProvider(database->arrayProvider[i]);
                database->booleanArrayProvider[i] = 0;
                database->amountOfProviders--;
                break;
            }
        }
    }
}
/*
 * Function: removeAppliance
 * Description: removes the Appliance with the given id from the database.
 * Returns: --
 */
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
/*
 * Function: removeManufacturer
 * Description: removes the Manufacturer with the given id from the database.
 * Returns: --
 */
void removeManufacturer(int idManufacturer, Database* database){
    for(int i = 0; i < database->manufacturerMaxCapacity; i++){
        if(database->booleanArrayManufacturer[i] != 0){
            if(idManufacturer == database->arrayManufacturer[i]->manufacturerId){
                for(int j = 0; i<database->applianceMaxCapacity; j++){
                    if(database->booleanArrayAppliance[i] != 0){
                        if(database->arrayAppliance[i]->idManufacturer == idManufacturer){
                            destroyAppliance(database->arrayAppliance[i]);
                            database->booleanArrayAppliance[i] = 0;
                            database->amountOfAppliances--;
                        }
                    }
                }
                destroyManufacturer(database->arrayManufacturer[i]);
                database->booleanArrayManufacturer[i] = 0;
                database->amountOfManufacturers--;
                break;
            }
        }
    }
}

/*
 * Function: getNextProviderId
 * Description: Generates the next Provider id.
 * Returns: int that is the next id.
 */
int getNextProviderId(Database* database){
    int result = database->idProviderGenerator;
    database->idProviderGenerator += 1;
    return result;
}
/*
 * Function: getNextApplianceId
 * Description: Generates the next Appliance id.
 * Returns: int that is the next id.
 */
int getNextApplianceId(Database* database){
    int result = database->idApplianceGenerator;
    database->idApplianceGenerator += 1;
    return result;
}
/*
 * Function: getNextManufacturerId
 * Description: Generates the next Manufacturer id.
 * Returns: int that is the next id.
 */
int getNextManufacturerId(Database* database) {
    int result = database->idManufacturerGenerator;
    database->idManufacturerGenerator += 1;
    return result;
}
