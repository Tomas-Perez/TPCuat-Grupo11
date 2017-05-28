#ifndef TPCUAT_GRUPO11_MANUFACTURER_H
#define TPCUAT_GRUPO11_MANUFACTURER_H

typedef struct Manufacturer{
    char* name;
    char* description;
    char* address;
    char* city;
    int phoneNumber;
    char* web;
    int manufacturerId;
}Manufacturer;

Manufacturer* newManufacturer(char* name, char* description, char* address,
                              char* city, int phoneNumber, char* web);
void destroyManufacturer(Manufacturer* manufacturer);

#endif //TPCUAT_GRUPO11_MANUFACTURER_H
