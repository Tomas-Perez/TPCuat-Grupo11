#ifndef TPCUAT_GRUPO11_CART_H
#define TPCUAT_GRUPO11_CART_H

#include "CartLine.h"
#include "Database.h"

typedef struct Cart{
    CartLine** cartLines;
    int maxCapacity;
    int* spacesTaken;
    int amountOfLines;
}Cart;

Cart* newCart(int initialCapacity);
void destroyCart(Cart* cart);
void cartAddAppliance(Cart* cart, int applianceId, int amount);
int cartContainsAppliance(Cart* cart, int applianceId);
void cartRemoveAppliance(Cart* cart, int applianceId, int amount);
int cartGetTotal(Cart* cart, Database* database);
void cartGrow(Cart* cart);


#endif //TPCUAT_GRUPO11_CART_H
