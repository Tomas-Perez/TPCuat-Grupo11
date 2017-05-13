#include <malloc.h>
#include "Cart.h"
#include "CartLine.h"

Cart* newCart(int initialCapacity){
    Cart* result = malloc(sizeof(Cart));

    result -> maxCapacity = initialCapacity;
    result -> amountOfLines = 0;

    result -> cartLines = malloc(sizeof(CartLine*)*initialCapacity);
    result -> spacesTaken = malloc(sizeof(int)*initialCapacity);

    return result;
}
void destroy(Cart* cart){
    for(int i = 0; i < cart->maxCapacity; i++){
        if(cart->spacesTaken[i]) destroyCartLine(cart->cartLines[i]);
    }
    free(cart->cartLines);
    free(cart->spacesTaken);
    free(cart);
}
void addAppliance(Cart* cart, int applianceId){
    if(cart->amountOfLines == cart->maxCapacity){
        grow(cart);
        cart->cartLines[cart->amountOfLines] = newCartLine(applianceId);
    }
}
void removeAppliance(Cart* cart, int applianceId){

}
int getTotal(Cart* cart, Database* database){

}

void grow(Cart* cart){
    cart->cartLines = realloc(cart->cartLines, sizeof(cart->cartLines)*2);
    cart->spacesTaken = realloc(cart->spacesTaken, sizeof(cart->spacesTaken)*2);
    cart->maxCapacity = cart->maxCapacity*2;
}
