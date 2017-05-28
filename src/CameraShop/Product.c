#include <stdlib.h>
#include <string.h>
#include "Product.h"

Product* newProduct(int productID, char* name, ProductType productType, int manufacturerID, int providerID){
    Product* result = malloc(sizeof(Product));
    result->productID = productID;
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);
    result->productType = productType;
    result->manufacturerID = manufacturerID;
    result->providerID = providerID;
}
void destroyProduct(Product* product){
    free(product->name);
    free(product);
}