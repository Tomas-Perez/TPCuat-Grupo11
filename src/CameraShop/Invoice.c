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

Invoice* newInvoice(int total, InvoiceLine** invoiceLines, int amountOfLines){
    Invoice* invoice = malloc(sizeof(Invoice));
    invoice->total = total;
    invoice->invoiceLines = invoiceLines;
    invoice->amountOfLines = amountOfLines;
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
    free(invoice->invoiceLines);
    free(invoice);
}