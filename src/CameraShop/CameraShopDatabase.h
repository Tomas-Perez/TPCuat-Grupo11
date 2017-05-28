#ifndef TPCUAT_GRUPO11_CAMERASHOPDATABASE_H
#define TPCUAT_GRUPO11_CAMERASHOPDATABASE_H

#include "Provider.h"
#include "Manufacturer.h"
#include "Product.h"
#include "../structs/StaticList.h"
#include "Camera.h"
#include "Accessory.h"

typedef struct CameraShopDatabase{
    StaticList* providerList;
    StaticList* manufacturerList;
    StaticList* productList;
    StaticList* cameraList;
    StaticList* accessoryList;

    int idProviderGenerator;
    int idManufacturerGenerator;
    int idProductGenerator;
}CameraShopDatabase;

CameraShopDatabase* newCameraShopDatabase(int initialCapacity);
void destroyDatabase(CameraShopDatabase* database);
Provider* getProvider(int idProvider, CameraShopDatabase* database);
Product* getProduct(int idProduct, CameraShopDatabase* database);
Manufacturer* getManufacturer(int idManufacturer, CameraShopDatabase* database);
Camera* getCamera(int idProduct, CameraShopDatabase* database);
Accessory* getAccessory(int idProduct, CameraShopDatabase* database);
void addProvider(CameraShopDatabase* database, Provider* provider);
void addManufacturer(CameraShopDatabase* database, Manufacturer* manufacturer);
void addCamera(CameraShopDatabase* database, Camera* camera, int providerID, int manufacturerID);
void addAccessory(CameraShopDatabase* database, Accessory* accessory, int providerID, int manufacturerID);
void removeProvider(int idProvider, CameraShopDatabase* database);
void removeManufacturer(int idManufacturer, CameraShopDatabase* database);
void removeCamera(int idProduct, CameraShopDatabase* database);
void removeAccessory(int idProduct, CameraShopDatabase* database);

#endif //TPCUAT_GRUPO11_CAMERASHOPDATABASE_H
