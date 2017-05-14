set(AppShopTest_SRCS ../CUTest/CuTest.c AppShopTests.c CartTest.c)
add_executable(runAppShopTests ${AppShopTest_SRCS})
target_link_libraries(runAppShopTests applianceShop)