#ifndef TPCUAT_GRUPO11_PRODUCT_H
#define TPCUAT_GRUPO11_PRODUCT_H

typedef enum{CAMERA, ACCESSORY}ProductType;

typedef struct Product{
    char* name;
    ProductType productType;
    int price;
    int productID;
    int manufacturerID;
    int providerID;
}Product;

Product* newProduct(int productID, char* name, ProductType productType, int manufacturerID, int providerID, int price);
void destroyProduct(Product* product);

#endif //TPCUAT_GRUPO11_PRODUCT_H
