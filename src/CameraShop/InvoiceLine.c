#include <stdlib.h>
#include <string.h>
#include "InvoiceLine.h"

/*
 * Description: Contains functions related to the invoice ADT.
 */

/*
 * Function: newInvoiceLine
 * Description: creates a new invoice line with the given data.
 * Returns: --
 */
InvoiceLine* newInvoiceLine(char* productName, int productPrice, int amount){
    InvoiceLine* invoiceLine = malloc(sizeof(InvoiceLine));
    invoiceLine->productName = malloc(sizeof(char)*(strlen(productName+1)));
    strcpy(invoiceLine->productName, productName);
    invoiceLine->productPrice = productPrice;
    invoiceLine->amount = amount;
    return invoiceLine;
}
/*
 * Function: destroyInvoiceLine
 * Description: deallocates all memory assigned to the invoice line.
 * Returns: --
 */
void destroyInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine->productName);
    free(invoiceLine);
}