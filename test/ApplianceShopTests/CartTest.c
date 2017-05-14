#include <afxres.h>
#include "../../src/ApplianceShop/Cart.h"
#include "../CUTest/CuTest.h"


void TestCartContains(CuTest *tc){
    Cart* cart = newCart(1);
    int actual = cartContainsAppliance(cart, 5);
    CuAssertIntEquals(tc, -1, actual);

    cartAddAppliance(cart, 6, 32);
    actual = cartContainsAppliance(cart, 6);
    CuAssertIntEquals(tc, 0, actual);

    cartAddAppliance(cart, 8, 32);
    actual = cartContainsAppliance(cart, 6);
    CuAssertIntEquals(tc, 0, actual);

    actual = cartContainsAppliance(cart, 8);
    CuAssertIntEquals(tc, 1, actual);

    cartAddAppliance(cart, 2, 10);
    actual = cartContainsAppliance(cart, 2);
    CuAssertIntEquals(tc, 2, actual);

    cartRemoveAppliance(cart, 2, 10);
    actual = cartContainsAppliance(cart, 2);
    CuAssertIntEquals(tc, -1, actual);
}

void TestCartAddAppliance(CuTest *tc){
    Cart* cart = newCart(1);
    cartAddAppliance(cart, 5, 10);
    cartAddAppliance(cart, 7, 10);
    cartAddAppliance(cart, 6, 10);
    int actual = cartContainsAppliance(cart, 5);
    CuAssertIntEquals(tc, 0, actual);

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
    CuAssertIntEquals(tc, 0, cartLineId5->amount);
    CuAssertIntEquals(tc, -1, cartContainsAppliance(cart, 5));
}

/**
 * Takes all the tests and saves them in a test suite, then returns it
 * @return test suite containing all tests, ready for executing
 */

CuSuite* getCartTestSuite(){
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCartContains);
    SUITE_ADD_TEST(suite, TestCartAddAppliance);
    SUITE_ADD_TEST(suite, TestCartRemoveAppliance);
    return suite;
}