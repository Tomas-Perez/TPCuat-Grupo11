#include <malloc.h>
#include <memory.h>
#include "Admin.h"

/*
 * Function: newAdmin
 * Description: Creates a new Admin with the given data.
 * Returns: Admin pointer.
 */
Admin* newAdmin(int dni, char* name, char* surname){
    Admin* admin = malloc(sizeof(Admin));
    admin->dni = dni;
    admin->name = malloc(sizeof(char) * (strlen(name) + 1 ));
    strcpy(admin->name, name);
    admin->surname = malloc(sizeof(char) * (strlen(surname) + 1 ));
    strcpy(admin->surname, surname);
    return admin;
}
/*
 * Function: destroyAdmin
 * Description: Deallocates all memory related to the Admin.
 * Returns: --
 */
void destroyAdmin(Admin* admin){
    free(admin->name);
    free(admin->surname);
    free(admin);
}
