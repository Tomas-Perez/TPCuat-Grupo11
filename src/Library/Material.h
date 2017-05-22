#ifndef TPCUAT_GRUPO11_MATERIAL_H
#define TPCUAT_GRUPO11_MATERIAL_H

typedef struct Material Material;
struct Material{
    int idMaterial;
    int type;//1 book, 2 magazine
    int isTaken;
    char* title;
    char* author;
    int year;
};

Material* newMaterial(int idMaterial, int type, char* title, char* author, int year);
void destroyMaterial(Material* material);

#endif //TPCUAT_GRUPO11_MATERIAL_H
