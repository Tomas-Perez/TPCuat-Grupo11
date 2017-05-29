#include <stdlib.h>
#include "Invoice.h"


Invoice* newInvoice(int total, StaticList* invoiceLineList){
    Invoice* invoice = malloc(sizeof(Invoice));
    invoice->total = total;
    invoice->invoiceLineList = invoiceLineList;
    return invoice;
}
void destroyInvoice(Invoice* invoice){
    StaticList* list = invoice->invoiceLineList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyInvoiceLine((InvoiceLine*) getActual(list));
    }
    freeStaticList(invoice->invoiceLineList);
    free(invoice->invoiceLineList);
    free(invoice);
}