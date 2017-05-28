#ifndef TPCUAT_GRUPO11_INVOICELINE_H
#define TPCUAT_GRUPO11_INVOICELINE_H

typedef struct InvoiceLine{
    char* productName;
    int productPrice;
    int amount;
}InvoiceLine;

InvoiceLine* newInvoiceLine(char* productName, int productPrice, int amount);
void destroyInvoiceLine(InvoiceLine* invoiceLine);

#endif //TPCUAT_GRUPO11_INVOICELINE_H
