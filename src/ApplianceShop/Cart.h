#ifndef TPCUAT_GRUPO11_CART_H
#define TPCUAT_GRUPO11_CART_H

#include "CartLine.h"

typedef struct Cart{
    CartLine** cartLines;
    int maxCapacity;
    int* spacesTaken;
    int amountOfLines;
}Cart;

Cart* newCart(int initialCapacity);
void destroy(Cart* cart);
void addAppliance(Cart* cart, int applianceId));
void removeAppliance(Cart* cart, int applianceId));
int getTotal(Cart* cart, Database* database);
void grow(Cart* cart);


#endif //TPCUAT_GRUPO11_CART_H
