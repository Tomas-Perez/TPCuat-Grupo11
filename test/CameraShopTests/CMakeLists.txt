set(CamShopTest_SRCS ../CUTest/CuTest.c CameraShopTests.c)
add_executable(runCamShopTests ${CamShopTest_SRCS})
# target_link_libraries(runCamShopTests cameraShop)