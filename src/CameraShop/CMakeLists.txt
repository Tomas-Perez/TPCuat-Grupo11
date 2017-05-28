set(cameraShop_SRCS Cart.c CartLine.c Manufacturer.c Provider.c CameraShopDatabase.c Product.c Camera.c Accessory.c User.c CameraAdminMenu.c CameraClientMenu.c LoginMenu.c)
add_library(cameraShop ${cameraShop_SRCS})
add_executable(cameraShopEXE main.c)
target_link_libraries(cameraShopEXE cameraShop util structs)