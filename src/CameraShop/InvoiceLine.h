#ifndef TPCUAT_GRUPO11_INVOICELINE_H
#define TPCUAT_GRUPO11_INVOICELINE_H

/*
 * Description: contains a product name, price and the amount of product. It's a way to avoid duplicated
 * items in an invoice.
 */

typedef struct InvoiceLine{
    char* productName;
    int productPrice;
    int amount;
}InvoiceLine;

InvoiceLine* newInvoiceLine(char* productName, int productPrice, int amount);
void destroyInvoiceLine(InvoiceLine* invoiceLine);

#endif //TPCUAT_GRUPO11_INVOICELINE_H
