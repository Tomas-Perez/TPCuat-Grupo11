#include <malloc.h>
#include <mem.h>
#include "Material.h"

Material* newMaterial(int idMaterial, int type, char* title, char* author, int year){
    Material* material = malloc(sizeof(Material));
    material->idMaterial = idMaterial;
    material->type = type;
    material->year = year;
    material->title = malloc(sizeof(char) * (strlen(title)+1));
    strcpy(material->title, title);
    material->author = malloc(sizeof(char) * (strlen(author)+1));
    strcpy(material->author, author);
    return material;
}
void destroyMaterial(Material* material){
    free(material->title);
    free(material->author);
    free(material);
}