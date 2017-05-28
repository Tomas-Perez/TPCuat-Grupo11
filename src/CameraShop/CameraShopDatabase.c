#include "CameraShopDatabase.h"
#include <stdlib.h>

CameraShopDatabase* newCameraShopDatabase(int initialCapacity){
    CameraShopDatabase* result = malloc(sizeof(CameraShopDatabase));
    result->manufacturerList = createStaticList(initialCapacity);
    result->productList = createStaticList(initialCapacity);
    result->providerList = createStaticList(initialCapacity);
    result->cameraList = createStaticList(initialCapacity);
    result->accessoryList = createStaticList(initialCapacity);

    result->idManufacturerGenerator = 0;
    result->idProductGenerator = 0;
    result->idProviderGenerator = 0;
}
void destroyDatabase(CameraShopDatabase* database){
    StaticList* list = database->cameraList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyCamera ((Camera*) getActual(list));
    }
    freeStaticList(list);
    list = database->providerList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyProvider ((Provider*) getActual(list));
    }
    freeStaticList(list);
    list = database->accessoryList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyAccessory ((Accessory*) getActual(list));
    }
    freeStaticList(list);
    list = database->manufacturerList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyManufacturer ((Manufacturer*) getActual(list));
    }
    freeStaticList(list);
    list = database->productList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyProduct ((Product*) getActual(list));
    }
    freeStaticList(list);
    free(list);
    free(database);
}
static void addProduct(CameraShopDatabase* database, char* name, ProductType type, int manufacturerID, int providerID){
    Product* product = newProduct(database->idProductGenerator, name, type, manufacturerID, providerID);
    goLast(database->productList);
    addNext(database->productList, (int) product);
}
static void removeProduct(CameraShopDatabase* database, int idProduct){
    StaticList* list = database->productList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Product* product = (Product*) getActual(list);
        if(product->productID == idProduct){
            destroyProduct(product);
            removeS(list);
            break;
        }
    }
}
Provider* getProvider(int idProvider, CameraShopDatabase* database){
    StaticList* list = database->providerList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Provider* provider = (Provider*) getActual(list);
        if(provider->providerId == idProvider) return provider;
    }
    return NULL;
}
Product* getProduct(int idProduct, CameraShopDatabase* database){
    StaticList* list = database->productList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Product* product = (Product*) getActual(list);
        if(product->productID == idProduct) return product;
    }
    return NULL;
}
Manufacturer* getManufacturer(int idManufacturer, CameraShopDatabase* database){
    StaticList* list = database->manufacturerList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Manufacturer* manufacturer = (Manufacturer*) getActual(list);
        if(manufacturer->manufacturerId == idManufacturer) return manufacturer;
    }
    return NULL;
}
Camera* getCamera(int idProduct, CameraShopDatabase* database){
    StaticList* list = database->cameraList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Camera* camera = (Camera*) getActual(list);
        if(camera->productID == idProduct) return camera;
    }
    return NULL;
}
Accessory* getAccessory(int idProduct, CameraShopDatabase* database){
    StaticList* list = database->accessoryList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Accessory* accessory = (Accessory*) getActual(list);
        if(accessory->productID == idProduct) return accessory;
    }
    return NULL;
}
void addProvider(CameraShopDatabase* database, Provider* provider){
    provider->providerId = database->idProviderGenerator++;
    goLast(database->providerList);
    addNext(database->providerList, (int) provider);
}
void addManufacturer(CameraShopDatabase* database, Manufacturer* manufacturer){
    manufacturer->manufacturerId = database->idManufacturerGenerator++;
    goLast(database->manufacturerList);
    addNext(database->manufacturerList, (int) manufacturer);
}
void addCamera(CameraShopDatabase* database, Camera* camera, int providerID, int manufacturerID){
    addProduct(database, camera->name, CAMERA, manufacturerID, providerID);
    camera->productID = database->idProductGenerator++;
    goLast(database->cameraList);
    addNext(database->cameraList, (int) camera);
}
void addAccessory(CameraShopDatabase* database, Accessory* accessory, int providerID, int manufacturerID){
    addProduct(database, accessory->name, ACCESSORY, manufacturerID, providerID);
    accessory->productID = database->idProductGenerator++;
    goLast(database->accessoryList);
    addNext(database->accessoryList, (int) accessory);
}

void removeProvider(int idProvider, CameraShopDatabase* database){
    StaticList* list = database->providerList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Provider* provider = (Provider*) getActual(list);
        if(provider->providerId == idProvider){
            destroyProvider(provider);
            removeS(list);
            break;
        }
    }
}
void removeManufacturer(int idManufacturer, CameraShopDatabase* database){
    StaticList* list = database->manufacturerList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Manufacturer* manufacturer = (Manufacturer*) getActual(list);
        if(manufacturer->manufacturerId == idManufacturer){
            destroyManufacturer(manufacturer);
            removeS(list);
            break;
        }
    }
}

void removeCamera(int idProduct, CameraShopDatabase* database){
    StaticList* list = database->cameraList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Camera* camera = (Camera*) getActual(list);
        if(camera->productID == idProduct){
            removeProduct(database, idProduct);
            destroyCamera(camera);
            removeS(list);
            break;
        }
    }
}
void removeAccessory(int idProduct, CameraShopDatabase* database){
    StaticList* list = database->accessoryList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Accessory* accessory = (Accessory*) getActual(list);
        if(accessory->productID == idProduct){
            removeProduct(database, idProduct);
            destroyAccessory(accessory);
            removeS(list);
            break;
        }
    }
}