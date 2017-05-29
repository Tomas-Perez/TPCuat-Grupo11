#include <stdlib.h>
#include "Invoice.h"


Invoice* newInvoice(int total, InvoiceLine** invoiceLines, int amountOfLines){
    Invoice* invoice = malloc(sizeof(Invoice));
    invoice->total = total;
    invoice->invoiceLines = invoiceLines;
    invoice->amountOfLines = amountOfLines;
    return invoice;
}
void destroyInvoice(Invoice* invoice){
    for(int i = 0; i < invoice->amountOfLines; i++){
        destroyInvoiceLine(invoice->invoiceLines[i]);
    }
    free(invoice->invoiceLines);
    free(invoice);
}