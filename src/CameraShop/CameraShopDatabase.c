#include "CameraShopDatabase.h"
#include <stdlib.h>
#include <string.h>

CameraShopDatabase* newCameraShopDatabase(int initialCapacity){
    CameraShopDatabase* result = malloc(sizeof(CameraShopDatabase));
    result->manufacturerList = createStaticList(initialCapacity);
    result->productList = createStaticList(initialCapacity);
    result->providerList = createStaticList(initialCapacity);
    result->cameraList = createStaticList(initialCapacity);
    result->accessoryList = createStaticList(initialCapacity);
    result->userList = createStaticList(initialCapacity);

    result->idManufacturerGenerator = 0;
    result->idProductGenerator = 0;
    result->idProviderGenerator = 0;
    result->idUserGenerator = 0;
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
    list = database->userList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyUser ((User*) getActual(list));
    }
    freeStaticList(list);
    free(list);
    free(database->accessoryList);
    free(database->productList);
    free(database->cameraList);
    free(database->productList);
    free(database->manufacturerList);
    free(database->userList);
    free(database);
}
static void addProduct(CameraShopDatabase* database, char* name, ProductType type, int manufacturerID, int providerID, int price){
    Product* product = newProduct(database->idProductGenerator, name, type, manufacturerID, providerID, price);
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
            free(product);
            break;
        }
    }
    free(list);
}
Provider* getProvider(int idProvider, CameraShopDatabase* database){
    StaticList* list = database->providerList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Provider* provider = (Provider*) getActual(list);
        if(provider->providerId == idProvider) return provider;
    }
    free(list);
    return NULL;
}
User* getUser(char* name, CameraShopDatabase* database){
    StaticList* list = database->userList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        User* user = (User*) getActual(list);
        if(strcmp(user->name, name)) return user;
    }
    free(list);
    return NULL;
}
Product* getProduct(int idProduct, CameraShopDatabase* database){
    StaticList* list = database->productList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Product* product = (Product*) getActual(list);
        if(product->productID == idProduct) return product;
    }
    free(list);
    return NULL;
}
Manufacturer* getManufacturer(int idManufacturer, CameraShopDatabase* database){
    StaticList* list = database->manufacturerList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Manufacturer* manufacturer = (Manufacturer*) getActual(list);
        if(manufacturer->manufacturerId == idManufacturer) return manufacturer;
    }
    free(list);
    return NULL;
}
Camera* getCamera(int idProduct, CameraShopDatabase* database){
    StaticList* list = database->cameraList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Camera* camera = (Camera*) getActual(list);
        if(camera->productID == idProduct) return camera;
    }
    free(list);
    return NULL;
}
Accessory* getAccessory(int idProduct, CameraShopDatabase* database){
    StaticList* list = database->accessoryList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Accessory* accessory = (Accessory*) getActual(list);
        if(accessory->productID == idProduct) return accessory;
    }
    free(list);
    return NULL;
}
void addProvider(CameraShopDatabase* database, Provider* provider){
    provider->providerId = database->idProviderGenerator++;
    goLast(database->providerList);
    addNext(database->providerList, (int) provider);
}
int addUser(CameraShopDatabase* database, User* user){
    if(getUser(user->name, database) == NULL) {
        user->userID = database->idUserGenerator++;
        goLast(database->userList);
        addNext(database->userList, (int) user);
        return 1;
    }
    return 0;
}
void addManufacturer(CameraShopDatabase* database, Manufacturer* manufacturer){
    manufacturer->manufacturerId = database->idManufacturerGenerator++;
    goLast(database->manufacturerList);
    addNext(database->manufacturerList, (int) manufacturer);
}
void addCamera(CameraShopDatabase* database, Camera* camera, int providerID, int manufacturerID, int price){
    addProduct(database, camera->name, CAMERA, manufacturerID, providerID, price);
    camera->productID = database->idProductGenerator++;
    goLast(database->cameraList);
    addNext(database->cameraList, (int) camera);
}
void addAccessory(CameraShopDatabase* database, Accessory* accessory, int providerID, int manufacturerID, int price){
    addProduct(database, accessory->name, ACCESSORY, manufacturerID, providerID, price);
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
    free(list);
}
void removeUser(int idUser, CameraShopDatabase* database){
    StaticList* list = database->userList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        User* user = (User*) getActual(list);
        if(user->userID == idUser){
            destroyUser(user);
            removeS(list);
            break;
        }
    }
    free(list);
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
    free(list);
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
    free(list);
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
            StaticList* cameraList = database->cameraList;
            for(int j = 0; j < cameraList->size; j++){
                goTo(cameraList, j);
                removeCameraAccessory((Camera*) getActual(cameraList), idProduct);
            }
            free(cameraList);
            break;
        }
    }
    free(list);
}
StaticList* getProductIdList(CameraShopDatabase* database){
    StaticList* list = database->productList;
    StaticList* result = createStaticList(list->size);
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Product* product = (Product*) getActual(list);
        addNext(result, product->productID);
    }
    free(list);
    return result;
}
StaticList* getManufacturerIdList(CameraShopDatabase* database){
    StaticList* list = database->manufacturerList;
    StaticList* result = createStaticList(list->size);
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Manufacturer* manufacturer = (Manufacturer*) getActual(list);
        addNext(result, manufacturer->manufacturerId);
    }
    free(list);
    return result;
}
StaticList* getProviderIdList(CameraShopDatabase* database){
    StaticList* list = database->providerList;
    StaticList* result = createStaticList(list->size);
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        Provider* provider = (Provider*) getActual(list);
        addNext(result, provider->providerId);
    }
    free(list);
    return result;
}
