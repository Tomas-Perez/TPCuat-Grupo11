#include <stdlib.h>
#include <string.h>
#include "Cart.h"

Cart* newCart(int initialCapacity){
    Cart* result = malloc(sizeof(Cart));

    result -> maxCapacity = initialCapacity;
    result -> amountOfLines = 0;

    result -> cartLines = malloc(sizeof(CartLine*)*initialCapacity);
    result -> spacesTaken = malloc(sizeof(int)*initialCapacity);
    memset(result -> spacesTaken, 0, sizeof(int)*initialCapacity);

    return result;
}

void destroyCart(Cart* cart){
    for(int i = 0; i < cart->maxCapacity; i++){
        if(cart->spacesTaken[i]) destroyCartLine(cart->cartLines[i]);
    }
    free(cart->cartLines);
    free(cart->spacesTaken);
    free(cart);
}

void cartAddAppliance(Cart* cart, int applianceId, int amount){
    int lineIndex = cartContainsAppliance(cart, applianceId);
    if(lineIndex == -1) {
        if (cart->amountOfLines == cart->maxCapacity) {
            cartGrow(cart);
            cart->cartLines[cart->amountOfLines] = newCartLine(applianceId, amount);
            cart->spacesTaken[cart->amountOfLines] = 1;
        } else {
            for (int i = 0; i < cart->maxCapacity; i++) {
                if (cart->spacesTaken[i] == 0) {
                    cart->cartLines[i] = newCartLine(applianceId, amount);
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

int cartContainsAppliance(Cart* cart, int applianceId){
    for(int i = 0; i < cart->maxCapacity; i++){
        if(cart->spacesTaken[i] != 0){
            if(cart->cartLines[i]->applianceId == applianceId) return i;
        }
    }
    return -1;
}

void cartRemoveAppliance(Cart* cart, int applianceId, int amount){
    int lineIndex = cartContainsAppliance(cart, applianceId);
    if(lineIndex != -1){
        CartLine* line = cart->cartLines[lineIndex];
        line->amount -= amount;
        if(line->amount <= 0){
            cart->spacesTaken[lineIndex] = 0;
            destroyCartLine(line);
            cart->amountOfLines--;
        }
    }
}

int cartGetTotal(Cart* cart, Database* database){
    int result = 0;
    for(int i = 0; i < cart->maxCapacity; i++){
        if(cart->spacesTaken[i]){
            int id = cart->cartLines[i]->applianceId;
            int amount = cart->cartLines[i]->amount;
            Appliance* appliance = getAppliance(id, database);
            result += appliance->price * amount;
        }
    }
    return result;
}

void cartGrow(Cart* cart){
    int maxCapacity = cart->maxCapacity;
    cart->cartLines = realloc(cart->cartLines, sizeof(CartLine*) * (maxCapacity*2));
    cart->spacesTaken = realloc(cart->spacesTaken, sizeof(int) * (maxCapacity*2));
    cart->maxCapacity = maxCapacity*2;
    for(int i = maxCapacity; i < cart->maxCapacity; i++){
        cart->spacesTaken[i] = 0;
    }
}
