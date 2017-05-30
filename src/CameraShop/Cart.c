#include <stdlib.h>
#include "Cart.h"
/*
 * Description: Contains the functions related to the cart ADT.
 */

/*
 * Function: newCart
 * Description: creates a new cart with the given initial capacity;
 * Returns: --
 */
Cart* newCart(int initialCapacity){
    Cart* result = malloc(sizeof(Cart));
    result->cartLines = malloc(sizeof(CartLine*)*initialCapacity);
    result->maxCapacity = initialCapacity;
    result->amountOfLines = 0;
    return result;
}

/*
 * Function: destroyCart
 * Description: Deallocates all memory assigned to the cart.
 * Returns: --
 */
void destroyCart(Cart* cart){
    for(int i = 0; i < cart->amountOfLines; i++){
        destroyCartLine(cart->cartLines[i]);
    }
    free(cart->cartLines);
    free(cart);
}

static void growCart(Cart* cart){
    cart->maxCapacity *= 2;
    cart->cartLines = realloc(cart->cartLines, sizeof(CartLine*)*cart->maxCapacity);
}

static int cartContainsProduct(Cart* cart, int productID){
    for(int i = 0; i < cart->amountOfLines; i++){
        CartLine* line = cart->cartLines[i];
        if(line->productID == productID) return i;
    }
    return -1;
}

/*
 * Function: cartAddProduct
 * Description: Adds a specific amount of product to the cart.
 * Returns: --
 */
void cartAddProduct(Cart* cart, int productID, int amount){
    int lineIndex = cartContainsProduct(cart, productID);
    if(lineIndex == -1) {
        if(cart->amountOfLines == cart->maxCapacity) growCart(cart);
        cart->cartLines[cart->amountOfLines] = newCartLine(productID, amount);
        cart->amountOfLines++;
    } else {
        CartLine* line = cart->cartLines[lineIndex];
        line->amount += amount;
    }
}

/*
 * Function: cartRemoveProduct
 * Description: Removes a specific amount of product from the cart.
 * Returns: --
 */
void cartRemoveProduct(Cart* cart, int productID, int amount){
    int lineIndex = cartContainsProduct(cart, productID);
    if(lineIndex != -1){
        CartLine* line = cart->cartLines[lineIndex];
        line->amount -= amount;
        if(line->amount <= 0){
            destroyCartLine(line);
            cart->amountOfLines--;
            for(int i = lineIndex; i < cart->amountOfLines; i++){
                cart->cartLines[i] = cart->cartLines[i+1];
            }
        }
    }
}

/*
 * Function: getTotal
 * Description: Given a database, it calculates the total price of the products in the cart.
 * Returns: total price of the cart.
 */
int cartGetTotal(Cart* cart, CameraShopDatabase* database){
    int result = 0;
    for(int i = 0; i < cart->amountOfLines; i++){
        CartLine* line = cart->cartLines[i];
        Product* product = getProduct(line->productID, database);
        result += product->price * line->amount;
    }
    return result;
}

/*
 * Function: checkout
 * Description: Given a database, creates an invoice for the current cart purchase.
 * Returns: current purchase Invoice.
 */

Invoice* checkout(Cart* cart, CameraShopDatabase* database){
    InvoiceLine** invoiceLines = malloc(sizeof(InvoiceLine*)*cart->amountOfLines);
    for(int i = 0; i < cart->amountOfLines; i++){
        CartLine* line = cart->cartLines[i];
        Product* product = getProduct(line->productID, database);
        InvoiceLine* invoiceLine = newInvoiceLine(product->name, product->price, line->amount);
        invoiceLines[i] = invoiceLine;
    }
    return newInvoice(cartGetTotal(cart, database), invoiceLines, cart->amountOfLines);
}
