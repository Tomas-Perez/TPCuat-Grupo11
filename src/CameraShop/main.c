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
    return cameraShopDatabase;
}

int main() {
    CameraShopDatabase* cameraShopDatabase = setup();
    while(1) {
        printf("Welcome to Nikon Argentina\n");
        printf("1. Log in\n");
        printf("2. Register\n");
        printf("0. Exit");
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
}