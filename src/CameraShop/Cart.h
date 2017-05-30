#ifndef TPCUAT_GRUPO11_CART_H
#define TPCUAT_GRUPO11_CART_H

#include "CartLine.h"
#include "../structs/StaticList.h"
#include "CameraShopDatabase.h"
#include "Invoice.h"
#include "InvoiceLine.h"

typedef struct Cart{
    CartLine** cartLines;
    int amountOfLines;
    int maxCapacity;
}Cart;

Cart* newCart(int initialCapacity);
void destroyCart(Cart* cart);
void cartAddProduct(Cart* cart, int productID, int amount);
void cartRemoveProduct(Cart* cart, int productID, int amount);
int cartGetTotal(Cart* cart, CameraShopDatabase* database);
Invoice* checkout(Cart* cart, CameraShopDatabase* database);

#endif //TPCUAT_GRUPO11_CART_H
