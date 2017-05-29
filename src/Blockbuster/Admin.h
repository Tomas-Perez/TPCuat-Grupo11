#ifndef TPCUAT_GRUPO11_ADMIN_H
#define TPCUAT_GRUPO11_ADMIN_H

typedef struct Admin Admin;

struct Admin{
    int dni;
    char* name;
    char* surname;
};

Admin* newAdmin(int dni, char* name, char* surname);
void destroyAdmin(Admin* admin);

#endif //TPCUAT_GRUPO11_ADMIN_H
