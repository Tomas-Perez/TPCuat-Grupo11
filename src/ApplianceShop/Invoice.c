#include <malloc.h>
#include "Invoice.h"

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
};
void destroyInvoice(Invoice* invoice){
    for(int i = 0; i < invoice->amountOfLines; i++){
        destroyInvoiceLine(invoice->invoiceLines[i]);
    }
    free(invoice);
}