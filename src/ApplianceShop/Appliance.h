#ifndef TPCUAT_GRUPO11_APPLIANCE_H
#define TPCUAT_GRUPO11_APPLIANCE_H

/*
 * Description: Represents an Appliance in the ApplianceShop system.
 */

typedef struct Appliance{
    char* name;
    int price;
    int idAppliance;
    int idProvider;
    int idManufacturer;
}Appliance;

Appliance* newAppliance(char* name, int price, int idAppliance, int idProvider, int idManufacturer);
void destroyAppliance(Appliance* appliance);


#endif //TPCUAT_GRUPO11_APPLIANCE_H
