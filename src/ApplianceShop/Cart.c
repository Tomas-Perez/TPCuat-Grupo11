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
void addAppliance(Cart* cart, int applianceId, int amount){
    int lineIndex = containsAppliance(cart, applianceId);
    if(lineIndex == -1) {
        if (cart->amountOfLines == cart->maxCapacity) {
            grow(cart);
            cart->cartLines[cart->amountOfLines] = newCartLine(applianceId);
            cart->spacesTaken[cart->amountOfLines] = 1;
        } else {
            for (int i = 0; i < cart->maxCapacity; i++) {
                if (cart->spacesTaken[i] == 0) {
                    cart->cartLines[i] = newCartLine(applianceId);
                    cart->spacesTaken[i] = 1;
                    break;
                }
            }
        }
        cart->amountOfLines++;
    } else {
        cart->cartLines[lineIndex]->amount += amount;
    }
}

int containsAppliance(Cart* cart, int applianceId){
    for(int i = 0; i < cart->maxCapacity; i++){
        if(cart->spacesTaken[i] == 1){
            if(cart->cartLines[i]->applianceId == applianceId) return i;
        }
    }
    return -1;
}

void removeAppliance(Cart* cart, int applianceId, int amount){
    int lineIndex = containsAppliance(cart, applianceId);
    if(lineIndex != -1){
        CartLine* line = cart->cartLines[lineIndex];
        line->amount -= amount;
        if(line->amount <= 0){
            cart->spacesTaken[lineIndex] = 0;
            destroyCartLine(line);
        }
    }
}

int getTotal(Cart* cart, Database* database){

}

void grow(Cart* cart){
    cart->cartLines = realloc(cart->cartLines, sizeof(cart->cartLines)*2);
    cart->spacesTaken = realloc(cart->spacesTaken, sizeof(cart->spacesTaken)*2);
    cart->maxCapacity = cart->maxCapacity*2;
}
