#include "CameraShopDatabase.h"
#include <stdlib.h>
#include <string.h>

/*
 * Description: Contains the functions related to the CameraShopDatabase
 */

/*
 * Function: newCameraShopDatabase
 * Description: creates a new CameraShopDatabase with the given initial capacity.
 * Returns: CameraShopDatabase pointer
 */

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

/*
 * Function: destroyDatabase
 * Description: deallocates all memory assigned to the CameraShopDatabase
 * Returns: --
 */
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

/*
 * Function: getProvider
 * Description: finds a provider with the given id on the database.
 * Returns: Provider pointer if it exists, NULL otherwise.
 */
Provider* getProvider(int idProvider, CameraShopDatabase* database){
    for(int i = 0; i < database->providerAmount; i++){
        Provider* provider = database->providerList[i];
        if(provider->providerId == idProvider) return provider;
    }
    return NULL;
}
/*
 * Function: getUser
 * Description: finds a user with the given id on the database.
 * Returns: User pointer if it exists, NULL otherwise.
 */
User* getUser(char* name, CameraShopDatabase* database){
    for(int i = 0; i < database->userAmount; i++){
        User* user = database->userList[i];
        if(strcmp(user->name, name) == 0) return user;
    }
    return NULL;
}

/*
 * Function: getProduct
 * Description: finds a product with the given id on the database.
 * Returns: Product pointer if it exists, NULL otherwise.
 */

Product* getProduct(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->productAmount; i++){
        Product* product = database->productList[i];
        if(product->productID == idProduct) return product;
    }
    return NULL;
}

/*
 * Function: getManufacturer
 * Description: finds a manufacturer with the given id on the database.
 * Returns: Manufacturer pointer if it exists, NULL otherwise.
 */

Manufacturer* getManufacturer(int idManufacturer, CameraShopDatabase* database){
    for(int i = 0; i < database->manufacturerAmount; i++){
        Manufacturer* manufacturer = database->manufacturerList[i];
        if(manufacturer->manufacturerId == idManufacturer) return manufacturer;
    }
    return NULL;
}

/*
 * Function: getCamera
 * Description: finds a camera with the given id on the database.
 * Returns: Camera pointer if it exists, NULL otherwise.
 */
Camera* getCamera(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->cameraAmount; i++){
        Camera* camera = database->cameraList[i];
        if(camera->productID == idProduct) return camera;
    }
    return NULL;
}

/*
 * Function: getAccessory
 * Description: finds an accessory with the given id on the database.
 * Returns: Accessory pointer if it exists, NULL otherwise.
 */

Accessory* getAccessory(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->accessoryAmount; i++){
        Accessory* accessory = database->accessoryList[i];
        if(accessory->productID == idProduct) return accessory;
    }
    return NULL;
}

/*
 * Function: addProvider
 * Description: adds a given provider to the database
 * Returns: --
 */
void addProvider(CameraShopDatabase* database, Provider* provider){
    provider->providerId = database->idProviderGenerator++;
    if(database->providerAmount == database->providerCapacity) growProvider(database);
    database->providerList[database->providerAmount++] = provider;
}

/*
 * Function: addUser
 * Description: adds a given user to the database, if its username does not exist already.
 * Returns: 1 if the user was added, 0 if it wasn't.
 */
int addUser(CameraShopDatabase* database, User* user){
    if(getUser(user->name, database) == NULL) {
        user->userID = database->idUserGenerator++;
        if(database->userAmount == database->userCapacity) growUser(database);
        database->userList[database->userAmount++] = user;
        return 1;
    }
    return 0;
}

/*
 * Function: addManufacturer
 * Description: adds a given manufacturer to the database
 * Returns: --
 */
void addManufacturer(CameraShopDatabase* database, Manufacturer* manufacturer){
    manufacturer->manufacturerId = database->idManufacturerGenerator++;
    if(database->manufacturerAmount == database->manufacturerCapacity) growManufacturer(database);
    database->manufacturerList[database->manufacturerAmount++] = manufacturer;
}

/*
 * Function: addCamera
 * Description: adds a given camera to the database, connects it with its provider, manufacturer
 * and assigns its price.
 * Returns: --
 */
void addCamera(CameraShopDatabase* database, Camera* camera, int providerID, int manufacturerID, int price){
    addProduct(database, camera->name, CAMERA, manufacturerID, providerID, price);
    camera->productID = database->idProductGenerator++;
    if(database->cameraAmount == database->cameraCapacity) growCamera(database);
    database->cameraList[database->cameraAmount++] = camera;
}

/*
 * Function: addAccessory
 * Description: adds a given accessory to the database, connects it with its provider, manufacturer
 * and assigns its price.
 * Returns: --
 */
void addAccessory(CameraShopDatabase* database, Accessory* accessory, int providerID, int manufacturerID, int price){
    addProduct(database, accessory->name, ACCESSORY, manufacturerID, providerID, price);
    accessory->productID = database->idProductGenerator++;
    if(database->accessoryAmount == database->accessoryCapacity) growAccessory(database);
    database->accessoryList[database->accessoryAmount++] = accessory;
}

/*
 * Function: removeProvider
 * Description: removes the provider with the given ID from the database.
 * Returns: --
 */
void removeProvider(int idProvider, CameraShopDatabase* database){
    for(int i = 0; i < database->providerAmount; i++){
        Provider* provider = database->providerList[i];
        if(provider->providerId == idProvider){
            destroyProvider(provider);
            database->providerAmount--;
            for(; i < database->providerAmount; i++){
                database->providerList[i] = database->providerList[i+1];
            }
            StaticList* productIDList = getProductIdList(database);
            for(int j = 0; j < productIDList->size; j++){
                goTo(productIDList, j);
                Product* product = getProduct(getActual(productIDList), database);
                if(product->providerID == idProvider) {
                    if (product->productType == CAMERA) {
                        removeCamera(getActual(productIDList), database);
                    } else removeAccessory(getActual(productIDList), database);
                }
            }
            break;
        }
    }
}

/*
 * Function: removeUser
 * Description: removes the user with the given ID from the database.
 * Returns: --
 */
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

/*
 * Function: removeManufacturer
 * Description: removes the manufacturer with the given ID from the database.
 * Returns: --
 */
void removeManufacturer(int idManufacturer, CameraShopDatabase* database){
    for(int i = 0; i < database->manufacturerAmount; i++){
        Manufacturer* manufacturer = database->manufacturerList[i];
        if(manufacturer->manufacturerId == idManufacturer){
            destroyManufacturer(manufacturer);
            database->manufacturerAmount--;
            for(; i < database->manufacturerAmount; i++){
                database->manufacturerList[i] = database->manufacturerList[i+1];
            }
            StaticList* productIDList = getProductIdList(database);
            for(int j = 0; j < productIDList->size; j++){
                goTo(productIDList, j);
                Product* product = getProduct(getActual(productIDList), database);
                if(product->manufacturerID == idManufacturer) {
                    if (product->productType == CAMERA) {
                        removeCamera(getActual(productIDList), database);
                    } else removeAccessory(getActual(productIDList), database);
                }
            }
            break;
        }
    }
}

/*
 * Function: removeCamera
 * Description: removes the camera with the given ID from the database.
 * Returns: --
 */
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

/*
 * Function: removeAccessory
 * Description: removes the accessory with the given ID from the database.
 * Returns: --
 */
void removeAccessory(int idProduct, CameraShopDatabase* database){
    for(int i = 0; i < database->accessoryAmount; i++){
        Accessory* accessory = database->accessoryList[i];
        if(accessory->productID == idProduct){
            destroyAccessory(accessory);
            database->accessoryAmount--;
            removeProduct(database, idProduct);
            for(; i < database->accessoryAmount; i++){
                database->accessoryList[i] = database->accessoryList[i+1];
            }
            for(int j = 0; j < database->cameraAmount; j++){
                Camera* camera = database->cameraList[j];
                removeCameraAccessory(camera, idProduct);
            }
            break;
        }
    }
}

/*
 * Function: getProductIDList
 * Description: returns a list with the IDs of all products.
 * Returns: StaticList pointer
 */
StaticList* getProductIdList(CameraShopDatabase* database){
    StaticList* result = createStaticList(database->productAmount);
    for(int i = 0; i < database->productAmount; i++){
        Product* product = database->productList[i];
        addNext(result, product->productID);
    }
    return result;
}

/*
 * Function: getManufacturerIDList
 * Description: returns a list with the IDs of all manufacturers.
 * Returns: StaticList pointer
 */
StaticList* getManufacturerIdList(CameraShopDatabase* database){
    StaticList* result = createStaticList(database->manufacturerAmount);
    for(int i = 0; i < database->manufacturerAmount; i++){
        Manufacturer* manufacturer = database->manufacturerList[i];
        addNext(result, manufacturer->manufacturerId);
    }
    return result;
}

/*
 * Function: getProviderIDList
 * Description: returns a list with the IDs of all products.
 * Returns: StaticList pointer
 */
StaticList* getProviderIdList(CameraShopDatabase* database){
    StaticList* result = createStaticList(database->providerAmount);
    for(int i = 0; i < database->providerAmount; i++){
        Provider* provider = database->providerList[i];
        addNext(result, provider->providerId);
    }
    return result;
}
