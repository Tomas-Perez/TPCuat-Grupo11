#ifndef TPCUAT_GRUPO11_CAMERASHOPDATABASE_H
#define TPCUAT_GRUPO11_CAMERASHOPDATABASE_H

#include "Provider.h"
#include "Manufacturer.h"
#include "Product.h"
#include "../structs/StaticList.h"
#include "Camera.h"
#include "Accessory.h"
#include "User.h"

typedef struct CameraShopDatabase{
    StaticList* providerList;
    StaticList* manufacturerList;
    StaticList* productList;
    StaticList* cameraList;
    StaticList* accessoryList;
    StaticList* userList;

    int idProviderGenerator;
    int idManufacturerGenerator;
    int idProductGenerator;
    int idUserGenerator;
}CameraShopDatabase;

CameraShopDatabase* newCameraShopDatabase(int initialCapacity);
void destroyDatabase(CameraShopDatabase* database);
Provider* getProvider(int idProvider, CameraShopDatabase* database);
Product* getProduct(int idProduct, CameraShopDatabase* database);
Manufacturer* getManufacturer(int idManufacturer, CameraShopDatabase* database);
Camera* getCamera(int idProduct, CameraShopDatabase* database);
Accessory* getAccessory(int idProduct, CameraShopDatabase* database);
User* getUser(char* name, CameraShopDatabase* database);
void addProvider(CameraShopDatabase* database, Provider* provider);
void addManufacturer(CameraShopDatabase* database, Manufacturer* manufacturer);
void addCamera(CameraShopDatabase* database, Camera* camera, int providerID, int manufacturerID, int price);
void addAccessory(CameraShopDatabase* database, Accessory* accessory, int providerID, int manufacturerID, int price);
int addUser(CameraShopDatabase* database, User* user);
void removeProvider(int idProvider, CameraShopDatabase* database);
void removeManufacturer(int idManufacturer, CameraShopDatabase* database);
void removeCamera(int idProduct, CameraShopDatabase* database);
void removeAccessory(int idProduct, CameraShopDatabase* database);
void removeUser(int idUser, CameraShopDatabase* database);
StaticList* getProviderIdList(CameraShopDatabase* database);
StaticList* getManufacturerIdList(CameraShopDatabase* database);
StaticList* getProductIdList(CameraShopDatabase* database);

#endif //TPCUAT_GRUPO11_CAMERASHOPDATABASE_H
