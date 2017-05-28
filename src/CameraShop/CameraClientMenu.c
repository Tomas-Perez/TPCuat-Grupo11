#include <stdio.h>
#include "CameraShopDatabase.h"
#include "Cart.h"
#include "../Util/ScanUtil.h"

void checkProducts(CameraShopDatabase* database, StaticList* productIDList){
    for(int i = 0; i < productIDList->size; i++){
        goTo(productIDList, i);
        Product* product = getProduct(getActual(productIDList), database);
        printf("%d.\n%s (%s)\nPrice: %d \n", i+1, product->name, product->productType == CAMERA ? "Camera" : "Accessory", product->price);
        printf("Manufacturer: %s\nProvider: %s\n\n",
               getManufacturer(product->manufacturerID, database)->name,
               getProvider(product->providerID, database)->name);
    }
}

void checkProductDetails(CameraShopDatabase* database, int productID) {
    Product* product = getProduct(productID, database);
    if(product->productType == CAMERA){
        Camera* camera = getCamera(productID, database);
        printf("%s %s Camera ($%d) \n"
               "Specs: \n - %d Mpx\n - %dX Zoom\n %s",
               camera->name, camera->cameraType == DSLR? "DSLR" : "Compact", product->price,
               camera->megaPixels, camera->zoom, camera->hasLCD ? "- LCD screen\n" : "");
        StaticList* accessoryList = camera->accessoryList;
        if(accessoryList->size > 0){
            printf("Accessories: \n");
            for(int i = 0; i < accessoryList->size; i++){
                goTo(accessoryList, i);
                checkProductDetails(database, getActual(accessoryList));
            }
        }
    } else {
        Accessory* accessory = getAccessory(productID, database);
    }
}

void addProductToCartMenu(CameraShopDatabase* database, Cart* cart){
    printf("Select the item you'd like to buy. Type -1 to exit \n");
    StaticList* productIDList = getProductIdList(database);
    checkProducts(database, productIDList);
    int indexInput = scanInt();
    while (indexInput == 0 || indexInput > productIDList->size) {
        printf("Please enter a valid number\n");
        indexInput = scanInt();
    }
    if(indexInput <= -1) return;
    int amount = scanInt();
    printf("You chose:\n");
    printf("How many would you like to buy?\n");
    while (amount <= 0){
        printf("Please enter a valid number\n");
        amount = scanInt();
    }
    cartAddAppliance(cart, applianceIdArray[indexInput-1], amount);
    printf("The Appliance has been added to you cart\n");
}

void checkCartDisplay(CameraShopDatabase *database, Cart *cart){
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

void checkoutDisplay(CameraShopDatabase* database, Cart* cart, User user){
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


void clientMenu(CameraShopDatabase* database, User* user){
    Cart* cart = newCart(5);
    while(1) {
        printf("Client Menu\n");
        printf("1. Buy Appliances\n");
        printf("2. Check cart\n");
        printf("3. Checkout\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                addProductToCartMenu(database, cart);
                break;
            case 2:
                checkCartDisplay(database, cart);
                break;
            case 3:
                checkoutDisplay(database, cart, user);
            case 0:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}