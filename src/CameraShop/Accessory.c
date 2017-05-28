#include "Accessory.h"
#include <stdlib.h>
#include <string.h>

Accessory* createAccessory(char* name, char* comment){
    Accessory* result = malloc(sizeof(Accessory));
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);
    result->comment = malloc(sizeof(char)*(strlen(comment)+1));
    strcpy(result->comment, comment);
    return result;
}
void destroyAccessory(Accessory* accessory){
    free(accessory->comment);
    free(accessory->name);
    free(accessory);
}