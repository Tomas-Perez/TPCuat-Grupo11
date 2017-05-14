#include <stdlib.h>
#include <stdio.h>
#include "Database.h"
#include "Cart.h"
#include "Invoice.h"

int* getApplianceIdArray(Database* database){
    int* result = malloc(sizeof(int)*database->amountOfAppliances);
    for(int i = 0, j = 0; i < database->applianceMaxCapacity, j < database->amountOfAppliances; i++){
        if(database->booleanArrayAppliance[i]){
            result[j] = database->arrayAppliance[i]->idAppliance;
            j++;
        }
    }
    return result;
}

void addApplianceMenu(Database* database, Cart* cart, int* applianceIdArray){
    printf("Select the item you'd like to buy. Type -1 to exit \n");
    for(int i = 0; i < database->amountOfAppliances; i++){
        Appliance* appliance = getAppliance(applianceIdArray[i], database);
        printf("%d.\n%s\nPrice: %d \n", i+1, appliance->name, appliance->price);
        printf("Manufacturer: %s\nProvider: %s\n\n",
               getManufacturer(appliance->idManufacturer, database)->name,
               getProvider(appliance->idProvider, database)->name);
    }
    int indexInput = 0;
    do {
        scanf("%d", &indexInput);
    } while (indexInput == 0 || indexInput > database->amountOfAppliances);
    if(indexInput == -1) return;
    int amount = 0;
    printf("How many would you like to buy?\n");
    do {
        scanf("%d", &amount);
    } while (amount == 0);
    cartAddAppliance(cart, applianceIdArray[indexInput-1], amount);
    printf("The Appliance has been added to you cart\n");
}

void checkCartDisplay(Database *database, Cart *cart){
    if(cart->amountOfLines > 0){
        printf("These are the items currently in your cart \n");
        for(int i = 0, j = 0; i < cart->maxCapacity, j < cart->amountOfLines; i++){
            if(cart->spacesTaken[i]){
                Appliance* appliance = getAppliance(cart->cartLines[i]->applianceId, database);
                printf("%s: \nPrice per unit: %d \nAmount:%d\n", appliance->name, appliance->price, cart->cartLines[i]->amount);
                printf("--------------------\n");
                j++;
            }
        }
        printf("Total Price: %d\n\n", cartGetTotal(cart, database));
    }
}

void checkoutDisplay(Database* database, Cart* cart){
    Invoice* invoice = newInvoice(cart, database);
    for(int i = 0; i < invoice->amountOfLines; i++){
        Appliance* appliance = getAppliance(invoice->invoiceLines[i]->applianceId, database);
        printf("%s (x%d): %d\n", appliance->name, invoice->invoiceLines[i]->amount, appliance->price*invoice->invoiceLines[i]->amount);
        printf("--------------------\n");
    }
    printf("Total Price: %d", invoice->total);
    free(cart);
    free(invoice);
    printf("Thank you for you purchase, logging out... \n\n");
}

void clientMenu(Database* database){
    Cart* cart = newCart(5);
    int* applianceIdArray = getApplianceIdArray(database);
    while(1) {
        printf("Client Menu\n");
        printf("1. Buy Appliances\n");
        printf("2. Check cart\n");
        printf("3. Checkout\n");
        printf("-1. Exit\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addApplianceMenu(database, cart, applianceIdArray);
                break;
            case 2:
                checkCartDisplay(database, cart);
                break;
            case 3:
                checkoutDisplay(database, cart);
            case -1:
                return;
            default:
                printf("Please enter one of the options");
                fseek(stdin,0,SEEK_END);
        }
    }

}