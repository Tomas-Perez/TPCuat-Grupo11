#include <afxres.h>
#include "../../src/ApplianceShop/Cart.h"
#include "../CUTest/CuTest.h"


void TestCartAddAppliance(CuTest *tc){
    Cart* cart = newCart(1);
    cartAddAppliance(cart, 5, 10);
    cartAddAppliance(cart, 7, 10);
    cartAddAppliance(cart, 6, 10);


    CartLine* cartLineId5 = cart->cartLines[0];
    CuAssertIntEquals(tc, 10, cartLineId5->amount);

    cartAddAppliance(cart, 5, 3);
    CuAssertIntEquals(tc, 13, cartLineId5->amount);
}

void TestCartRemoveAppliance(CuTest *tc){
    Cart* cart = newCart(1);
    cartAddAppliance(cart, 5, 10);
    CartLine* cartLineId5 = cart->cartLines[0];
    CuAssertIntEquals(tc, 10, cartLineId5->amount);

    cartRemoveAppliance(cart, 5, 3);
    CuAssertIntEquals(tc, 7, cartLineId5->amount);

    cartRemoveAppliance(cart, 5, 7);
}

/**
 * Takes all the tests and saves them in a test suite, then returns it
 * @return test suite containing all tests, ready for executing
 */

CuSuite* getCartTestSuite(){
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCartAddAppliance);
    SUITE_ADD_TEST(suite, TestCartRemoveAppliance);
    return suite;
}