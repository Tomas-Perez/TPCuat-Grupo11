#include <stdio.h>
#include <stdlib.h>
#include "CameraShopDatabase.h"
#include "Cart.h"
#include "../Util/ScanUtil.h"

void checkProductMainInfo(CameraShopDatabase* database, int productID){
    Product* product = getProduct(productID, database);
    printf("%s (%s) $%d\n", product->name, product->productType == CAMERA ? "Camera" : "Accessory", product->price);
    printf("Manufacturer: %s\nProvider: %s\n\n",
           getManufacturer(product->manufacturerID, database)->name,
           getProvider(product->providerID, database)->name);
}

void checkProducts(CameraShopDatabase* database, StaticList* productIDList){
    for(int i = 0; i < productIDList->size; i++){
        goTo(productIDList, i);
        printf("%d.\n", i+1);
        checkProductMainInfo(database, getActual(productIDList));
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
            printf("Available Accessories: \n");
            for(int i = 0; i < accessoryList->size; i++){
                goTo(accessoryList, i);
                checkProductDetails(database, getActual(accessoryList));
            }
        }
    } else {
        Accessory* accessory = getAccessory(productID, database);
        printf("%s Accessory ($%d):\n %s\n", accessory->name, product->price, accessory->comment);
    }
}

void addProductToCartMenu(CameraShopDatabase* database, Cart* cart){
    printf("Select the item you'd like to buy. Type -1 to exit.\n");
    StaticList* productIDList = getProductIdList(database);
    checkProducts(database, productIDList);
    int indexInput = scanInt();
    while (indexInput == 0 || indexInput > productIDList->size || indexInput < -1) {
        printf("Please enter a valid number.\n");
        indexInput = scanInt();
    }
    if(indexInput == -1) return;
    printf("You chose:\n");
    goTo(productIDList, indexInput - 1);
    checkProductDetails(database, getActual(productIDList));
    printf("How many would you like to buy?\n");
    int amount = scanInt();
    while (amount <= 0){
        printf("Please enter a valid number.\n");
        amount = scanInt();
    }
    cartAddProduct(cart, getActual(productIDList), amount);
    printf("The product has been added to you cart.\n");
    freeStaticList(productIDList);
}


void checkCartDisplay(CameraShopDatabase *database, Cart *cart){
    if(cart->amountOfLines > 0){
        printf("These are the items currently in your cart.\n");
        for(int i = 0; i < cart->amountOfLines; i++){
            CartLine* cartLine = cart->cartLines[i];
            Product* product = getProduct(cartLine->productID, database);
            printf("%s $%d (x%d): $%d\n", product->name, product->price, cartLine->amount, product->price * cartLine->amount);
            printf("--------------------\n");
        }
        printf("Total Price: $%d\n\n", cartGetTotal(cart, database));
    }
    else{
        printf("You have no items in your cart.\n");
    }
}

void checkInvoice(Invoice* invoice){
    for (int i = 0; i < invoice->amountOfLines; i++) {
        InvoiceLine* line = invoice->invoiceLines[i];
        printf("%s $%d (x%d): $%d\n", line->productName, line->productPrice , line->amount,
               line->productPrice * line->amount);
        printf("--------------------\n");
    }
    printf("Total Price: $%d\n\n", invoice->total);
}

void checkoutDisplay(CameraShopDatabase* database, Cart* cart, User* user){
    if(cart->amountOfLines > 0) {
        Invoice *invoice = checkout(cart, database);
        checkInvoice(invoice);
        addInvoice(user, invoice);
        printf("Thank you for you purchase, your invoice has been saved into you account, logging out... \n\n");
    } else {
        printf("You have no items in your cart.\n");
    }
}

void invoiceDisplay(User* user){
    if(user->invoiceAmount > 0) {
        for (int i = 0; i < user->invoiceAmount; i++) {
            Invoice *invoice = user->invoiceList[i];
            checkInvoice(invoice);
        }
    } else {
        printf("You have no invoices saved.\n");
    }
}

void removeProductFromCartMenu(CameraShopDatabase* database, Cart* cart){
    checkCartDisplay(database, cart);
    for(int i = 0; i < cart->amountOfLines; i++){

    }
}


void clientMenu(CameraShopDatabase* database, User* user){
    begin: {
        Cart *cart = newCart(5);
        while (1) {
            printf("Client Menu\n");
            printf("1. Buy Product\n");
            printf("2. Check cart\n");
            printf("3. Checkout\n");
            printf("4. Check Invoices\n");
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
                    destroyCart(cart);
                    goto begin;
                case 4:
                    invoiceDisplay(user);
                    break;
                case 0:
                    destroyCart(cart);
                    return;
                default:
                    printf("Please enter one of the options\n");
            }
        }
    }
}