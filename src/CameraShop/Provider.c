#include <stdlib.h>
#include <string.h>
#include "Provider.h"

/*
 * Description: Contains all functions related to the Provider ADT.
 */

/*
 * Function: newProvider
 * Description: Creates a new provider from the given data.
 * Returns: Provider pointer.
 */

Provider* newProvider(char* name, char* description, char* address,
                      char* city, int phoneNumber, char* web){
    Provider* provider = malloc(sizeof(Provider));
    provider->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(provider->name, name);
    provider->description = malloc(sizeof(char) * (strlen(description) + 1));
    strcpy(provider->description, description);
    provider->address = malloc(sizeof(char) * (strlen(address) + 1));
    strcpy(provider->address, address);
    provider->city = malloc(sizeof(char) * (strlen(city) + 1));
    strcpy(provider->city, city);
    provider->web = malloc(sizeof(char) * (strlen(web) + 1));
    strcpy(provider->web, web);
    provider->phoneNumber = phoneNumber;
    return provider;
}

/*
 * Function: destroyProvider
 * Description: Deallocates all memory assigned to the provider.
 * Returns: --
 */
void destroyProvider(Provider* provider){
    free(provider->address);
    free(provider->web);
    free(provider->city);
    free(provider->description);
    free(provider->name);
    free(provider);
}