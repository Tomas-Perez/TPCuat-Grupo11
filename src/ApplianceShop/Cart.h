#ifndef TPCUAT_GRUPO11_CART_H
#define TPCUAT_GRUPO11_CART_H

#include "CartLine.h"
#include "Database.h"

/*
 * Description: A cart saves the appliances the client buys from the shop.
 */

typedef struct Cart{
    CartLine** cartLines;
    int maxCapacity;
    int* spacesTaken;
    int amountOfLines;
}Cart;

Cart* newCart(int initialCapacity);
void destroyCart(Cart* cart);
void cartAddAppliance(Cart* cart, int productID, int amount);
int cartContainsAppliance(Cart* cart, int productID);
void cartRemoveAppliance(Cart* cart, int productID, int amount);
int cartGetTotal(Cart* cart, Database* database);
void cartGrow(Cart* cart);


#endif //TPCUAT_GRUPO11_CART_H
