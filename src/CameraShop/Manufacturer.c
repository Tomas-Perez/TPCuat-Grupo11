#include <malloc.h>
#include <memory.h>
#include "Manufacturer.h"

Manufacturer* newManufacturer(char* name, char* description, char* address,
                              char* city, int phoneNumber, char* web, int manufacturerId){
    Manufacturer* result = malloc(sizeof(Manufacturer));

    result->name = malloc(sizeof(char)*(strlen(name)+1));
    result->description = malloc(sizeof(char)*(strlen(description)+1));
    result->address = malloc(sizeof(char)*(strlen(address)+1));
    result->city = malloc(sizeof(char)*(strlen(city)+1));
    result->web = malloc(sizeof(char)*(strlen(web)+1));

    strcpy(result->name, name);
    strcpy(result->description, description);
    strcpy(result->address, address);
    strcpy(result->city, city);
    strcpy(result->web, web);

    result->manufacturerId = manufacturerId;
    result->phoneNumber = phoneNumber;

    return result;
}

void destroyManufacturer(Manufacturer* manufacturer){
    free(manufacturer->name);
    free(manufacturer->address);
    free(manufacturer->city);
    free(manufacturer->description);
    free(manufacturer->web);
    free(manufacturer);
}