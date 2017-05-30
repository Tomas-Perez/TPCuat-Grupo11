#include <stdlib.h>
#include <string.h>
#include "Product.h"
/*
 * Description: Contains the functions related to the Product ADT.
 */

/*
 * Function: newProduct
 * Description: Creates a new product with the given data.
 * Returns: Product pointer.
 */
Product* newProduct(int productID, char* name, ProductType productType, int manufacturerID, int providerID, int price){
    Product* result = malloc(sizeof(Product));
    result->price = price;
    result->productID = productID;
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);
    result->productType = productType;
    result->manufacturerID = manufacturerID;
    result->providerID = providerID;
    return result;
}

/*
 * Function: destroyProduct
 * Description: Deallocates all memory assigned to the product.
 * Return: --
 */
void destroyProduct(Product* product){
    free(product->name);
    free(product);
}