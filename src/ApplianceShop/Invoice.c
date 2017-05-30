#include <stdlib.h>
#include "Invoice.h"

/*
 * Description: contains the functions related to the Invoice ADT.
 */

/*
 * Function: newInvoice
 * Description: creates an invoice with the given data.
 * Returns: Invoice pointer.
 */

Invoice* newInvoice(Cart* cart, Database* database){
    Invoice* invoice = malloc(sizeof(Invoice));
    invoice->total = cartGetTotal(cart, database);
    invoice->amountOfLines = cart->amountOfLines;
    invoice->invoiceLines = malloc(sizeof(InvoiceLine) * cart->amountOfLines);
    int j = 0;
    for(int i = 0; i < cart->maxCapacity; i++){
        if(cart->spacesTaken[i]){
            invoice->invoiceLines[j] = malloc(sizeof(InvoiceLine*));
            invoice->invoiceLines[j]->applianceId = cart->cartLines[i]->applianceId;
            invoice->invoiceLines[j]->amount = cart->cartLines[i]->amount;
            j++;
        }
    }
    return invoice;
}

/*
 * Function: destroyInvoice
 * Description: Deallocates all memory assgined to the invoice.
 * Returns: --
 */

void destroyInvoice(Invoice* invoice){
    for(int i = 0; i < invoice->amountOfLines; i++){
        destroyInvoiceLine(invoice->invoiceLines[i]);
    }
    free(invoice);
}