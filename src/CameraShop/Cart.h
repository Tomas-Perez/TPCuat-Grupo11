#ifndef TPCUAT_GRUPO11_CART_H
#define TPCUAT_GRUPO11_CART_H

#include "CartLine.h"
#include "../structs/StaticList.h"
#include "CameraShopDatabase.h"
#include "Invoice.h"
#include "InvoiceLine.h"

typedef struct Cart{
    StaticList* cartLineList;
}Cart;

Cart* newCart(int initialCapacity);
void destroyCart(Cart* cart);
void cartAddAppliance(Cart* cart, int productID, int amount);
int cartContainsAppliance(Cart* cart, int productID);
void cartRemoveAppliance(Cart* cart, int productID, int amount);
int cartGetTotal(Cart* cart, CameraShopDatabase* database);
Invoice* checkout(Cart* cart, CameraShopDatabase* database);

#endif //TPCUAT_GRUPO11_CART_H
