#include <stdlib.h>
#include "InvoiceLine.h"

/*
 * Description: Contains the functions related to the invoice ADT.
 */

/*
 * Function: newInvoiceLine
 * Description: creates a new invoice line with the given data.
 * Returns: --
 */

InvoiceLine* newInvoiceLine(CartLine* cartLine){
    InvoiceLine* invoiceLine = malloc(sizeof(InvoiceLine));
    invoiceLine->applianceId = cartLine->applianceId;
    invoiceLine->amount = cartLine->amount;
    return invoiceLine;
}

/*
 * Function: destroyInvoiceLine
 * Description: deallocates all memory assigned to the invoice line.
 * Returns: --
 */
void destroyInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine);
}