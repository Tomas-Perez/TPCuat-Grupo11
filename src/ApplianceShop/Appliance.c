#include <stdlib.h>
#include <string.h>
#include "Appliance.h"

/*
 * Description: Contains the functions related to the Appliance ADT.
 */

/*
 * Function: newAppliance
 * Description: Creates a new Appliance with the given data.
 * Returns: Appliance pointer.
 */
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

/*
 * Function: destroyAppliance
 * Description: Deallocates all memory related to the Appliance.
 * Returns: --
 */
void destroyAppliance(Appliance *appliance) {
    free(appliance->name);
    free(appliance);
}