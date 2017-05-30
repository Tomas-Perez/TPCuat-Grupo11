#include "Accessory.h"
#include <stdlib.h>
#include <string.h>

/*
 * Description: Contains the function related to the Accessory ADT.
 */

/*
 * Function: newAccessory
 * Description: Creates a new accessory with the given data.
 * Returns: Accessory pointer.
 */

Accessory* newAccessory(char *name, char *comment){
    Accessory* result = malloc(sizeof(Accessory));
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);
    result->comment = malloc(sizeof(char)*(strlen(comment)+1));
    strcpy(result->comment, comment);
    return result;
}

/*
 * Function: destroyAccessory
 * Description: Deallocates all memory assigned to the accessory.
 * Returns: --
 */
void destroyAccessory(Accessory* accessory){
    free(accessory->comment);
    free(accessory->name);
    free(accessory);
}