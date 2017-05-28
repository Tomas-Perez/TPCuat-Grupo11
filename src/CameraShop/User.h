#ifndef TPCUAT_GRUPO11_USER_H
#define TPCUAT_GRUPO11_USER_H

typedef enum{ADMIN, CLIENT}UserRole;

typedef struct User{
    char* name;
    int DNI;
    char* address;
    char* city;
    int phoneNumber;
    int userID;
    UserRole role;
}User;

User* newUser(char* name, char* address,
                      char* city, int phoneNumber, UserRole role);
void destroyUser(User* user);

#endif //TPCUAT_GRUPO11_USER_H
