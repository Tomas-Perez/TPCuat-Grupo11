#include <malloc.h>
#include <memory.h>
#include "Admin.h"

Admin* newAdmin(int dni, char* name, char* surname){
    Admin* admin = malloc(sizeof(Admin));
    admin->dni = dni;
    admin->name = malloc(sizeof(char) * (strlen(name) + 1 ));
    strcpy(admin->name, name);
    admin->surname = malloc(sizeof(char) * (strlen(surname) + 1 ));
    strcpy(admin->surname, surname);
    return admin;
}
void destroyAdmin(Admin* admin){
    free(admin->name);
    free(admin->surname);
    free(admin);
}
