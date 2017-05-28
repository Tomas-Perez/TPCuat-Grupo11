#include <stdlib.h>
#include <string.h>
#include "InvoiceLine.h"

InvoiceLine* newInvoiceLine(char* productName, int productPrice, int amount){
    InvoiceLine* invoiceLine = malloc(sizeof(InvoiceLine));
    invoiceLine->productName = malloc(sizeof(char)*(strlen(productName+1)));
    strcpy(invoiceLine->productName, productName);
    invoiceLine->productPrice = productPrice;
    invoiceLine->amount = amount;
    return invoiceLine;
}
void destroyInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine->productName);
    free(invoiceLine);
}