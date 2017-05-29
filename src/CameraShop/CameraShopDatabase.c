#include "CameraShopDatabase.h"
#include <stdlib.h>
#include <string.h>

CameraShopDatabase* newCameraShopDatabase(int initialCapacity){
    CameraShopDatabase* result = malloc(sizeof(CameraShopDatabase));
    result->productCapacity = initialCapacity*2;
    result->providerCapacity = initialCapacity;
    result->manufacturerCapacity = initialCapacity;
    result->cameraCapacity = initialCapacity;
    result->accessoryCapacity = initialCapacity;
    result->userCapacity = initialCapacity;

    result->productAmount = 0;
    result->providerAmount = 0;
    result->manufacturerAmount = 0;
    result->cameraAmount = 0;
    result->accessoryAmount = 0;
    result->userAmount = 0;


    result->manufacturerList = malloc(sizeof(Manufacturer*)*result->manufacturerCapacity);
    result->productList = malloc(sizeof(Product*)*result->productCapacity);
    result->providerList = malloc(sizeof(Provider*)*result->providerCapacity);
    result->cameraList = malloc(sizeof(Camera*)*result->cameraCapacity);
    result->accessoryList = malloc(sizeof(Accessory*)*result->accessoryCapacity);
    result->userList = malloc(sizeof(User*)*result->userCapacity);

    result->idManufacturerGenerator = 0;
    result->idProductGenerator = 0;
    result->idProviderGenerator = 0;
    result->idUserGenerator = 0;

    return result;
}
void destroyDatabase(CameraShopDatabase* database){
    for(int i = 0; i < database->cameraCapacity; i++){
        destroyCamera (database->cameraList[i]);
    }
    for(int i = 0; i < database->accessoryCapacity; i++){
        destroyAccessory (database->accessoryList[i]);
    }
    for(int i = 0; i < database->providerCapacity; i++){
        destroyProvider (database->providerList[i]);
    }
    for(int i = 0; i < database->productCapacity; i++){
        destroyProduct (database->productList[i]);
    }
    for(int i = 0; i < database->manufacturerCapacity; i++){
        destroyManufacturer (database->manufacturerList[i]);
    }
    for(int i = 0; i < database->userCapacity; i++){
        destroyUser (database->userList[i]);
    }
    free(database->accessoryList);
    free(database->productList);
    free(database->cameraList);
    free(database->productList);
    free(database->manufacturerList);
    free(database->userList);
    free(database);
}

static void growProduct(CameraShopDatabase* database){
    database->productCapacity *= 2;
    database->productList = realloc(database->productList, sizeof(Product*)*database->productCapacity);
}
static void growProvider(CameraShopDatabase* database){
    database->providerCapacity *= 2;
    database->providerList = realloc(database->providerList, sizeof(Provider*)*database->providerCapacity);
}
static void growUser(CameraShopDatabase* database){
    database->userCapacity *= 2;
    database->userList = realloc(database->userList, sizeof(User*)*database->userCapacity);
}
static void growManufacturer(CameraShopDatabase* database){
    database->manufacturerCapacity *= 2;
    database->manufacturerList = realloc(database->manufacturerList, sizeof(Manufacturer*)*database->manufacturerCapacity);
}
static void growCamera(CameraShopDatabase* database){
    database->cameraCapacity *= 2;
    database->cameraList = realloc(database->cameraList, sizeof(Camera*)*database->cameraCapacity);
}
static void growAccessory(CameraShopDatabase* database){
    database->accessoryCapacity *= 2;
    database->accessoryList = realloc(database->accessoryList, sizeof(Accessory*)*database->accessoryCapacity);
}
static void addProduct(CameraShopDatabase* database, char* name, ProductType type, int manufacturerID, int providerID, int price){
    Product* product = newProduct(database->idProductGenerator, name, type, manufacturerID, providerID, price);
    if(database->productAmount == database->productCapacity) growProduct(database);
    database->productList[database->productAmount++] = product;
}
static void removeProduct(CameraShopDatabase* database, int idProduct){
    for(int i = 0; i < database->productAmount; i++){
        Product* product = database->productList[i];
        if(product->productID == idProduct){
            destroyProduct(product);
            database->productAmount--;
            for(; i < database->productAmount; i++){
                database->productList[i] = database->productList[i+1];
            }
            break;
        }
    }
}
Provider* getProvider(int idProvider, CameraShopDatabase* database){
    for(int i = 0; i < database->providerAmount; i++){
        Provider* provider = database->providerList[i];
        if(provider->providerId == idProvider) return provider;
    }
    return NULL;
}
User* getUser(char* name, CameraShopDatabase* database){
    for(int i = 0; i < database->userAmount; i++){
        User* user = database->userList[i];
        if(strcmp(user->name, name) == 0) return user;
    }
    return NULL;
}
Product* getProduct(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->productAmount; i++){
        Product* product = database->productList[i];
        if(product->productID == idProduct) return product;
    }
    return NULL;
}
Manufacturer* getManufacturer(int idManufacturer, CameraShopDatabase* database){
    for(int i = 0; i < database->manufacturerAmount; i++){
        Manufacturer* manufacturer = database->manufacturerList[i];
        if(manufacturer->manufacturerId == idManufacturer) return manufacturer;
    }
    return NULL;
}
Camera* getCamera(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->cameraAmount; i++){
        Camera* camera = database->cameraList[i];
        if(camera->productID == idProduct) return camera;
    }
    return NULL;
}
Accessory* getAccessory(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->accessoryAmount; i++){
        Accessory* accessory = database->accessoryList[i];
        if(accessory->productID == idProduct) return accessory;
    }
    return NULL;
}
void addProvider(CameraShopDatabase* database, Provider* provider){
    provider->providerId = database->idProviderGenerator++;
    if(database->providerAmount == database->providerCapacity) growProvider(database);
    database->providerList[database->providerAmount++] = provider;
}
int addUser(CameraShopDatabase* database, User* user){
    if(getUser(user->name, database) == NULL) {
        user->userID = database->idUserGenerator++;
        if(database->userAmount == database->userCapacity) growUser(database);
        database->userList[database->userAmount++] = user;
        return 1;
    }
    return 0;
}
void addManufacturer(CameraShopDatabase* database, Manufacturer* manufacturer){
    manufacturer->manufacturerId = database->idManufacturerGenerator++;
    if(database->manufacturerAmount == database->manufacturerCapacity) growManufacturer(database);
    database->manufacturerList[database->manufacturerAmount++] = manufacturer;
}
void addCamera(CameraShopDatabase* database, Camera* camera, int providerID, int manufacturerID, int price){
    addProduct(database, camera->name, CAMERA, manufacturerID, providerID, price);
    camera->productID = database->idProductGenerator++;
    if(database->cameraAmount == database->cameraCapacity) growCamera(database);
    database->cameraList[database->cameraCapacity++] = camera;
}
void addAccessory(CameraShopDatabase* database, Accessory* accessory, int providerID, int manufacturerID, int price){
    addProduct(database, accessory->name, ACCESSORY, manufacturerID, providerID, price);
    accessory->productID = database->idProductGenerator++;
    if(database->accessoryAmount == database->accessoryCapacity) growAccessory(database);
    database->accessoryList[database->accessoryAmount++] = accessory;
}

void removeProvider(int idProvider, CameraShopDatabase* database){
    for(int i = 0; i < database->providerAmount; i++){
        Provider* provider = database->providerList[i];
        if(provider->providerId == idProvider){
            destroyProvider(provider);
            database->providerAmount--;
            for(; i < database->providerAmount; i++){
                database->providerList[i] = database->providerList[i+1];
            }
            break;
        }
    }
}
void removeUser(int idUser, CameraShopDatabase* database){
    for(int i = 0; i < database->userAmount; i++){
        User* user = database->userList[i];
        if(user->userID == idUser){
            destroyUser(user);
            database->userAmount--;
            for(; i < database->userAmount; i++){
                database->userList[i] = database->userList[i+1];
            }
            break;
        }
    }
}
void removeManufacturer(int idManufacturer, CameraShopDatabase* database){
    for(int i = 0; i < database->manufacturerAmount; i++){
        Manufacturer* manufacturer = database->manufacturerList[i];
        if(manufacturer->manufacturerId == idManufacturer){
            destroyManufacturer(manufacturer);
            database->manufacturerAmount--;
            for(; i < database->manufacturerAmount; i++){
                database->manufacturerList[i] = database->manufacturerList[i+1];
            }
            break;
        }
    }
}

void removeCamera(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->cameraAmount; i++){
        Camera* camera = database->cameraList[i];
        if(camera->productID == idProduct){
            destroyCamera(camera);
            database->cameraAmount--;
            removeProduct(database, idProduct);
            for(; i < database->cameraAmount; i++){
                database->cameraList[i] = database->cameraList[i+1];
            }
            break;
        }
    }
}
void removeAccessory(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->accessoryAmount; i++){
        Accessory* accessory = database->accessoryList[i];
        if(accessory->productID == idProduct){
            destroyAccessory(accessory);
            database->accessoryAmount--;
            for(; i < database->accessoryAmount; i++){
                database->accessoryList[i] = database->accessoryList[i+1];
            }
            for(int j = 0; j < database->cameraAmount; i++){
                Camera* camera = database->cameraList[i];
                removeCameraAccessory(camera, idProduct);
            }
            break;
        }
    }
}
StaticList* getProductIdList(CameraShopDatabase* database){
    StaticList* result = createStaticList(database->productAmount);
    for(int i = 0; i < database->productAmount; i++){
        Product* product = database->productList[i];
        addNext(result, product->productID);
    }
    return result;
}
StaticList* getManufacturerIdList(CameraShopDatabase* database){
    StaticList* result = createStaticList(database->manufacturerAmount);
    for(int i = 0; i < database->manufacturerAmount; i++){
        Manufacturer* manufacturer = database->manufacturerList[i];
        addNext(result, manufacturer->manufacturerId);
    }
    return result;
}
StaticList* getProviderIdList(CameraShopDatabase* database){
    StaticList* result = createStaticList(database->providerAmount);
    for(int i = 0; i < database->providerAmount; i++){
        Provider* provider = database->providerList[i];
        addNext(result, provider->providerId);
    }
    return result;
}
