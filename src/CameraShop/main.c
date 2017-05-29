#include <stdio.h>
#include <stdlib.h>
#include "CameraShopDatabase.h"
#include "../Util/ScanUtil.h"

void adminMenu(CameraShopDatabase* database, User* user);
void clientMenu(CameraShopDatabase* database, User* user);
User* loginMenu(CameraShopDatabase* database);
void registerMenu(CameraShopDatabase* database);

CameraShopDatabase* setup(){
    CameraShopDatabase* cameraShopDatabase = newCameraShopDatabase(5);
    Camera* camera = newCamera("Nikon 35D", 20, 20, 1, DSLR);
    Camera* camera1 = newCamera("Canon 45S", 8, 10, 0, COMPACT);
    Camera* camera2 = newCamera("Nikon SSX", 8, 15, 1, COMPACT);
    Accessory* tripod = newAccessory("Tripod", "It has one leg.");
    Accessory* bipod = newAccessory("Bipod", "It has 4 legs.");
    Provider* dailyMail = newProvider("DailyMail", "The daily mail, what else do you need?", "Your house", "Nextdoor", 444666, "www.yourweb.com");
    Provider* johnnyTheProvider = newProvider("Johnny", "I provider cameras and stuff", "I don't know", "Somewhere", 420, "www.johnyylovescameras.com");
    Manufacturer* nikon = newManufacturer("Nikon", "We are the best", "Camera 123", "Washington DC", 320, "www.nikon.nikon.nikon");
    Manufacturer* canon = newManufacturer("Canon", "We are a worse Nikon", "Camera 122", "Detroit", 319, "www.canon.nikon.nikon");
    addManufacturer(cameraShopDatabase, nikon);
    addManufacturer(cameraShopDatabase, canon);
    addProvider(cameraShopDatabase, dailyMail);
    addProvider(cameraShopDatabase, johnnyTheProvider);
    addCamera(cameraShopDatabase, camera, dailyMail->providerId, nikon->manufacturerId, 666);
    addCamera(cameraShopDatabase, camera1, dailyMail->providerId, canon->manufacturerId, 200);
    /*
    addCamera(cameraShopDatabase, camera2, johnnyTheProvider->providerId, nikon->manufacturerId, 150);
     */
    /*
    addAccessory(cameraShopDatabase, tripod, johnnyTheProvider->providerId, nikon->manufacturerId, 20);
    addAccessory(cameraShopDatabase, bipod, johnnyTheProvider->providerId, canon->manufacturerId, 50);
    addCameraAccessory(camera, tripod->productID);
    addCameraAccessory(camera, bipod->productID);
     */
    User* admin = newUser("admin", 520,  "admin street", "admin town", 1, ADMIN);
    addUser(cameraShopDatabase, admin);
    printf(getProvider(0, cameraShopDatabase)->name);
    printf(getProvider(1, cameraShopDatabase)->name);
    printf(getManufacturer(0, cameraShopDatabase)->name);
    printf(getManufacturer(1, cameraShopDatabase)->name);
    printf(getProduct(0, cameraShopDatabase)->name);
    printf(getCamera(0, cameraShopDatabase)->name);
    printf(getAccessory(0, cameraShopDatabase)->name);
    printf(getUser("admin", cameraShopDatabase)->name);
    return cameraShopDatabase;
}

int main() {
    /*
    CameraShopDatabase* cameraShopDatabase = newCameraShopDatabase(5);
    Camera* camera = newCamera("Nikon 35D", 20, 20, 1, DSLR);
    Manufacturer* canon = newManufacturer("Canon", "We are a worse Nikon", "Camera 122", "Detroit", 319, "www.canon.nikon.nikon");
    addManufacturer(cameraShopDatabase, canon);
    addCamera(cameraShopDatabase, camera, 0, 0, 666);
    Manufacturer* manufacturer = getManufacturer(0, cameraShopDatabase);
    Camera* camera1 = getCamera(0, cameraShopDatabase);
    Product* product = getProduct(0, cameraShopDatabase);
    */
    CameraShopDatabase* cameraShopDatabase = setup();
    /*
    while(1) {
        printf("Welcome to Nikon Argentina\n");
        printf("1. Log in\n");
        printf("2. Register\n");
        printf("0. Exit\n");
        int choice = scanInt();
        switch (choice){
            case 1: {
                User *user = loginMenu(cameraShopDatabase);
                if(user == NULL) break;
                else if(user->role == ADMIN) adminMenu(cameraShopDatabase, user);
                else clientMenu(cameraShopDatabase, user);
            }
            case 2:
                registerMenu(cameraShopDatabase);
            case 0:
                exit(0);
            default:
                printf("Please enter a valid number\n");
        }
    }
     */
}