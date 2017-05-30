#include <stdio.h>
#include <stdlib.h>
#include "CameraShopDatabase.h"
#include "../Util/ScanUtil.h"


void checkProducts(CameraShopDatabase* database, StaticList* productIDList);
void checkProductDetails(CameraShopDatabase* database, int productID);

void checkManufacturers(CameraShopDatabase* database, StaticList* manufacturerIDList){
    if(database->manufacturerAmount > 0){
        printf("Manufacturers:\n");
        for (int i = 0; i < manufacturerIDList->size; i++){
            goTo(manufacturerIDList, i);
            Manufacturer* manufacturer = getManufacturer(getActual(manufacturerIDList), database);
            printf("%d.\n%s\n"
                   "Description: %s\n"
                   "Location: %s, %s\n"
                   "Tel: %d, Web: %s\n",
                   i+1, manufacturer->name, manufacturer->description, manufacturer->address,
                   manufacturer->city, manufacturer->phoneNumber, manufacturer->web);
            printf("Products: \n");
            StaticList* productIDList = getProductIdList(database);
            for(int j = 0; j < productIDList->size; j++){
                goTo(productIDList, j);
                Product* product = getProduct(getActual(productIDList), database);
                if(product->manufacturerID == manufacturer->manufacturerId) {
                    printf("%s (%s) $%d\n", product->name,
                           product->productType == CAMERA ? "Camera" : "Accessory", product->price);
                }
            }
            printf("-----------------\n\n");
            freeStaticList(productIDList);
        }
    } else printf("There are no available manufacturers.\n");
}

void addManufacturerMenu(CameraShopDatabase* database){
    printf("Add Manufacturer:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("Description:\n");
    char* description = scanChar();
    printf("Address:\n");
    char* address = scanChar();
    printf("City:\n");
    char* city = scanChar();
    printf("Web:\n");
    char* web = scanChar();
    printf("Phone:\n");
    int phone = scanInt();
    Manufacturer* manufacturer = newManufacturer(name, description, address, city, phone, web);
    addManufacturer(database, manufacturer);
    free(name);
    free(description);
    free(address);
    free(city);
    free(web);
}

void removeManufacturerMenu(CameraShopDatabase* database){
    if(database->manufacturerAmount > 0) {
        StaticList *manufacturerIDList = getManufacturerIdList(database);
        checkManufacturers(database, manufacturerIDList);
        printf("Choose manufacturer to remove.\n");
        int manufacturerChoice = scanInt();
        while (manufacturerChoice < 0 || manufacturerChoice > manufacturerIDList->size) {
            printf("Please enter a valid number.\n");
            manufacturerChoice = scanInt();
        }
        goTo(manufacturerIDList, manufacturerChoice - 1);
        removeManufacturer(getActual(manufacturerIDList), database);
        freeStaticList(manufacturerIDList);
    } else printf("There are no available manufacturers.\n");
}

void manufacturerMenu(CameraShopDatabase* database){
    while(1) {
        printf("Manufacturer Menu\n");
        printf("1. Check Manufacturers\n");
        printf("2. Add Manufacturer\n");
        printf("3. Remove Manufacturer\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1: {
                checkManufacturers(database, getManufacturerIdList(database));
                break;
            }
            case 2:
                addManufacturerMenu(database);
                break;
            case 3:
                removeManufacturerMenu(database);
                break;
            case 0:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}

void checkProviders(CameraShopDatabase* database, StaticList* providerIDList){
    if(database->productAmount > 0){
        printf("Providers:\n");
        for (int i = 0; i < providerIDList->size; i++){
            goTo(providerIDList, i);
            Provider* provider = getProvider(getActual(providerIDList), database);
            printf("%d.\n%s\n"
                   "Description: %s\n"
                   "Location: %s, %s\n"
                   "Tel: %d, Web: %s\n",
                   i+1, provider->name, provider->description, provider->address,
                   provider->city, provider->phoneNumber, provider->web);
            printf("Products: \n");
            StaticList* productIDList = getProductIdList(database);
            for(int j = 0; j < productIDList->size; j++){
                goTo(productIDList, j);
                Product* product = getProduct(getActual(productIDList), database);
                if(product->providerID == provider->providerId) {
                    printf("%s (%s) $%d\n", product->name,
                           product->productType == CAMERA ? "Camera" : "Accessory", product->price);
                }
            }
            printf("-----------------\n\n");
            freeStaticList(productIDList);
        }
    } else printf("There are no available providers.\n");
}

void addProviderMenu(CameraShopDatabase* database){
    printf("Add provider:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("Description:\n");
    char* description = scanChar();
    printf("Address:\n");
    char* address = scanChar();
    printf("City:\n");
    char* city = scanChar();
    printf("Web:\n");
    char* web = scanChar();
    printf("Phone:\n");
    int phone = scanInt();
    Provider* provider = newProvider(name, description, address, city, phone, web);
    addProvider(database, provider);
    free(name);
    free(description);
    free(address);
    free(city);
    free(web);
}

void removeProviderMenu(CameraShopDatabase* database){
    if(database->providerAmount > 0) {
        StaticList *providerIDList = getProviderIdList(database);
        checkProviders(database, providerIDList);
        printf("Choose provider to remove.\n");
        int providerChoice = scanInt();
        while (providerChoice < 0 || providerChoice > providerIDList->size) {
            printf("Please enter a valid number.\n");
            providerChoice = scanInt();
        }
        goTo(providerIDList, providerChoice - 1);
        removeProvider(getActual(providerIDList), database);
        freeStaticList(providerIDList);
    } else printf("There are no available providers.\n");
}

void providerMenu(CameraShopDatabase* database){
    while(1) {
        printf("Provider Menu\n");
        printf("1. Check Providers\n");
        printf("2. Add Provider\n");
        printf("3. Remove Provider\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1: {
                checkProviders(database, getProviderIdList(database));
                break;
            }
            case 2:
                addProviderMenu(database);
                break;
            case 3:
                removeProviderMenu(database);
                break;
            case 0:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}


void addProductMenu(CameraShopDatabase* database){
    printf("Add product:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("Price:\n");
    int price = scanInt();

    //Provider
    StaticList* providerIDList = getProviderIdList(database);
    checkProviders(database, providerIDList);
    printf("Please select a provider:\n");
    int providerChoice = scanInt();
    while(providerChoice < 0 || providerChoice > providerIDList->size){
        printf("Please enter a valid number.\n");
        providerChoice = scanInt();
    }
    goTo(providerIDList, providerChoice - 1);
    int providerID = getActual(providerIDList);

    //Manufacturer
    StaticList* manufacturerIDList = getProviderIdList(database);
    checkManufacturers(database, manufacturerIDList);
    printf("Please select a manufacturer:\n");
    int manufacturerChoice = scanInt();
    while(manufacturerChoice < 0 || manufacturerChoice > manufacturerIDList->size){
        printf("Please enter a valid number.\n");
        manufacturerChoice = scanInt();
    }
    goTo(manufacturerIDList, manufacturerChoice - 1);
    int manufacturerID = getActual(manufacturerIDList);


    printf("Enter 1 for Camera 2 for Accessory\n");
    int choice = scanInt();
    while(choice != 1 && choice != 2){
        printf("Please enter a valid number.\n");
        choice = scanInt();
    }
    if(choice == 1){
        printf("Please enter the camera's Mpx.\n");
        int megaPixels = scanInt();
        while(megaPixels <= 0){
            printf("Please enter a valid number.\n");
            megaPixels = scanInt();
        }
        printf("Please enter the camera's Zoom.\n");
        int zoom = scanInt();
        while(zoom <= 0){
            printf("Please enter a valid number.\n");
            zoom = scanInt();
        }
        printf("Does it have an LCD screen? Yes = 1, 0 = No\n");
        int hasLCD = scanInt();
        while (hasLCD != 1 && hasLCD != 0){
            printf("Please enter a valid number.\n");
            hasLCD = scanInt();
        }
        printf("Choose a category:\n1. DSLR\n2. Compact\n");
        CameraType cameraType;
        enterType: {
            int type = scanInt();
            if (type == 1) {
                cameraType = DSLR;
            } else if (type == 2) {
                cameraType = COMPACT;
            } else {
                printf("Please enter a valid number.\n");
                type = scanInt();
                goto enterType;
            }
        }
        Camera* camera = newCamera(name, megaPixels, zoom, hasLCD, cameraType);
        addCamera(database, camera, providerID, manufacturerID, price);
    } else {
        printf("Please enter a small description.\n");
        char* description = scanChar();
        Accessory* accessory = newAccessory(name, description);
        addAccessory(database, accessory, providerID, manufacturerID, price);
        free(description);
    }
    freeStaticList(providerIDList);
    freeStaticList(manufacturerIDList);
    free(name);
}

void removeProductMenu(CameraShopDatabase* database){
    if(database->productAmount > 0) {
        StaticList *productIDList = getProductIdList(database);
        checkProducts(database, productIDList);
        printf("Choose product to remove.\n");
        int productChoice = scanInt();
        while (productChoice <= 0 || productChoice > productIDList->size) {
            printf("Please enter a valid number.\n");
            productChoice = scanInt();
        }
        goTo(productIDList, productChoice - 1);
        int productID = getActual(productIDList);
        if (getProduct(productID, database)->productType == CAMERA) {
            removeCamera(productID, database);
        } else removeAccessory(productID, database);
        freeStaticList(productIDList);
    } else printf("There are no available products.\n");
}

void addAccessoryToCamera(CameraShopDatabase* database){
    printf("Select a camera.\n");
    StaticList* cameraIDList = getCameraIdList(database);
    checkProducts(database, cameraIDList);
    int indexInput = scanInt();
    while (indexInput <= 0 || indexInput > cameraIDList->size) {
        printf("Please enter a valid number.\n");
        indexInput = scanInt();
    }
    printf("You chose:\n");
    goTo(cameraIDList, indexInput - 1);
    checkProductDetails(database, getActual(cameraIDList));
    printf("Select an accessory to add.\n");
    StaticList* accessoryIDList = getAccessoryIdList(database);
    checkProducts(database, accessoryIDList);
    int accessoryInput = scanInt();
    while (accessoryInput <= 0 || accessoryInput > accessoryIDList->size) {
        printf("Please enter a valid number.\n");
        accessoryInput = scanInt();
    }
    goTo(accessoryIDList, accessoryInput - 1);
    addCameraAccessory(getCamera(getActual(cameraIDList), database), getActual(accessoryIDList));
    printf("Accessory successfully added.\n");
}

void productMenu(CameraShopDatabase* database){
    while(1) {
        printf("Product Menu\n");
        printf("1. Check Products\n");
        printf("2. Add Product\n");
        printf("3. Add Accessory to Camera\n");
        printf("4. Remove Product\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1: {
                checkProducts(database, getProductIdList(database));
                break;
            }
            case 2:
                addProductMenu(database);
                break;
            case 3:
                addAccessoryToCamera(database);
                break;
            case 4:
                removeProductMenu(database);
                break;
            case 0:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}

void adminMenu(CameraShopDatabase* database){
    while(1) {
        printf("Admin Menu\n");
        printf("1. Product Menu\n");
        printf("2. Provider Menu\n");
        printf("3. Manufacturer Menu\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                productMenu(database);
                break;
            case 2:
                providerMenu(database);
                break;
            case 3:
                manufacturerMenu(database);
                break;
            case 0:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}