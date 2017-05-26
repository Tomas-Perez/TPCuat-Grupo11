#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include "../Util/ScanUtil.h"


void clientMenu(Database* database);
void adminMenu(Database* database);

Database* setup(){
    Database* database = newDatabase();
    Manufacturer* phillips = newManufacturer("Phillips", "Philips is a Dutch technology company headquartered in Amsterdam",
                                             "San Martin 512", "BSAS", 51266448, "phillips.com.ar", getNextManufacturerId(database));
    addManufacturer(database, phillips);
    Provider* fedEx = newProvider("FedEx", "FedEx Corporation is an American multinational courier delivery services company",
                                  "Belgrano 1024", "Cordoba", 6233000, "fedex.com", getNextProviderId(database));
    addProvider(database, fedEx);
    Appliance* dishwasher = newAppliance("Dishwasher", 50, getNextApplianceId(database), fedEx->providerId, phillips->manufacturerId);
    addAppliance(database, dishwasher);
    return database;
}

int main() {
    Database* database = setup();
    while(1) {
        printf("Would you like to enter as a (1) User or (2) Admin?\n");
        printf("Otherwise exit with -1\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                clientMenu(database);
                break;
            case 2:
                printf("Admin Menu");
                adminMenu(database);
                break;
            case -1:
                exit(0);
            default:
                printf("Please enter one of the options\n");
        }
    }
}
