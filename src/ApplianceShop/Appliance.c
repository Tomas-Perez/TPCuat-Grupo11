#include <malloc.h>
#include <memory.h>
#include "Appliance.h"

Appliance *newAppliance(char *name, int price, int idAppliance, int idProvider, int idManufacturer) {
    Appliance* result = malloc(sizeof(Appliance));

    result->name = malloc(sizeof(char)*(strlen(name) + 1));
    strcpy(result->name, name);

    result->price = price;
    result->idAppliance = idAppliance;
    result->idProvider = idProvider;
    result->idManufacturer = idManufacturer;
    return result;
}

void destroyAppliance(Appliance *appliance) {
    free(appliance->name);
    free(appliance);
}

