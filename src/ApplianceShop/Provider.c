#include <malloc.h>
#include <mem.h>
#include "Provider.h"

Provider* newProvider(char* name, char* description, char* address,
                      char* city, int phoneNumber, char* web, int providerId){
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
    provider->providerId = providerId;
    return provider;
}

void destroyProvider(Provider* provider){
    free(provider->address);
    free(provider->web);
    free(provider->city);
    free(provider->description);
    free(provider->name);
    free(provider);
}