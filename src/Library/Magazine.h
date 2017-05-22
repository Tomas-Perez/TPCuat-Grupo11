#ifndef TPCUAT_GRUPO11_MAGAZINE_H
#define TPCUAT_GRUPO11_MAGAZINE_H

typedef struct Magazine Magazine;
struct Magazine{
    int idMaterial;
};

Magazine* newMagazine(int idMaterial);
void destroyMagazine(Magazine* magazine);

#endif //TPCUAT_GRUPO11_MAGAZINE_H
