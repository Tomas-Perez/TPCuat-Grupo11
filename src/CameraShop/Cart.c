#include <stdlib.h>
#include "Cart.h"

Cart* newCart(int initialCapacity){
    Cart* result = malloc(sizeof(Cart));
    result->cartLineList = createStaticList(initialCapacity);
    return result;
}

void destroyCart(Cart* cart){
    StaticList* list = cart->cartLineList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyCartLine((CartLine*) getActual(list));
    }
    freeStaticList(list);
    free(cart->cartLineList);
    free(cart);
}

void cartAddAppliance(Cart* cart, int productID, int amount){
    StaticList* list = cart->cartLineList;
    int lineIndex = cartContainsAppliance(cart, productID);
    if(lineIndex == -1) {
        goLast(list);
        CartLine* line = newCartLine(productID, amount);
        addNext(list, (int) line);
    } else {
        goTo(list, lineIndex);
        CartLine* line = (CartLine*) getActual(list);
        line->amount += amount;
    }
}

int cartContainsAppliance(Cart* cart, int productID){
    StaticList* list = cart->cartLineList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        CartLine* line = (CartLine*) getActual(list);
        if(line->productID == productID) return i;
    }
    return -1;
}

void cartRemoveAppliance(Cart* cart, int productID, int amount){
    StaticList* list = cart->cartLineList;
    int lineIndex = cartContainsAppliance(cart, productID);
    if(lineIndex != -1){
        goTo(list, lineIndex);
        CartLine* line = (CartLine*) getActual(list);
        line->amount -= amount;
        if(line->amount <= 0){
            destroyCartLine(line);
            removeS(list);
        }
    }
}

int cartGetTotal(Cart* cart, CameraShopDatabase* database){
    StaticList* list = cart->cartLineList;
    int result = 0;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        CartLine* line = (CartLine*) getActual(list);
        Product* product = getProduct(line->productID, database);
        result += product->price * line->amount;
    }
    return result;
}

Invoice* checkout(Cart* cart, CameraShopDatabase* database){
    StaticList* list = cart->cartLineList;
    StaticList* invoiceLineList = createStaticList(list->size);
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        CartLine* line = (CartLine*) getActual(list);
        Product* product = getProduct(line->productID, database);
        InvoiceLine* invoiceLine = newInvoiceLine(product->name, product->price, line->amount);
        addNext(invoiceLineList, (int) invoiceLine);
    }
    return newInvoice(cartGetTotal(cart, database), invoiceLineList);
}

