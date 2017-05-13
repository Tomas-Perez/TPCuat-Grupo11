#ifndef TPCUAT_GRUPO11_PROVIDER_H
#define TPCUAT_GRUPO11_PROVIDER_H

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
void destroyProvider(Provider* Provider);

#endif //TPCUAT_GRUPO11_PROVIDER_H
