#ifndef TPCUAT_GRUPO11_DATABASE_H
#define TPCUAT_GRUPO11_DATABASE_H

#include "Provider.h"
#include "Appliance.h"
#include "Manufacturer.h"

struct Database{
    Provider** arrayProvider;
    int* booleanArrayProvider;
    int providerMaxCapacity;
    int amountOfProviders;

    Appliance** arrayAppliance;
    int* booleanArrayAppliance;
    int applianceMaxCapacity;
    int amountOfAppliances;

    Manufacturer** arrayManufacturer;
    int* booleanArrayManufacturer;
    int manufacturerMaxCapacity;
    int amountOfManufacturers;

    int idProviderGenerator;
    int idApplianceGenerator;
    int idManufacturerGenerator;
}typedef Database;

Database* newDatabase();
void destroyDatabase(Database* database);
Provider* getProvider(int idProvider, Database* database);
Appliance* getAppliance(int idAppliance, Database* database);
Manufacturer* getManufacturer(int idManufacturer, Database* database);
void growProvider(Database* database);
void growAppliance(Database* database);
void growManufacturer(Database* database);
void addProvider(Database* database, Provider* provider);
void addAppliance(Database* database, Appliance* appliance);
void addManufacturer(Database* database, Manufacturer* manufacturer);
void removeProvider(int idProvider, Database* database);
void removeAppliance(int idAppliance, Database* database);
void removeManufacturer(int idManufacturer, Database* database);
int getNextProviderId(Database* database);
int getNextApplianceId(Database* database);
int getNextManufacturerId(Database* database);


#endif //TPCUAT_GRUPO11_DATABASE_H
