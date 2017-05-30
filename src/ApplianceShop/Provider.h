#ifndef TPCUAT_GRUPO11_PROVIDER_H
#define TPCUAT_GRUPO11_PROVIDER_H

/*
 * Description: Contains all information related to a provider in the ApplianceShop system.
 */

typedef struct Provider{
    char* name;
    char* description;
    char* address;
    char* city;
    int phoneNumber;
    char* web;
    int providerId;
}Provider;

Provider* newProvider(char* name, char* description, char* address,
                              char* city, int phoneNumber, char* web, int providerId);
void destroyProvider(Provider* provider);

#endif //TPCUAT_GRUPO11_PROVIDER_H
