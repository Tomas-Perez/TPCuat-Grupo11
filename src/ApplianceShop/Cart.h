#ifndef TPCUAT_GRUPO11_CART_H
#define TPCUAT_GRUPO11_CART_H

#include "CartLine.h"

typedef struct Cart{
    CartLine* cartLines;
    int total;
}Cart;

Cart* newCart();
void destroy(Cart* cart);
void addAppliance(int applianceId);
void removeAppliance(int applianceId);


#endif //TPCUAT_GRUPO11_CART_H
