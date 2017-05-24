#include <stdio.h>
#include "Library.h"

void mainMenu(Library* library);
void logInMenu(Library* library);
void accountCreationMenu(Library* library);

int main() {
    Library* library = newLibrary();
    mainMenu(library);
    return 0;
}