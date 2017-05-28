
/*
    Header file that defines the array -  based implementation of a List
*/

#ifndef STRUCTURES_STATICLIST_H
#define STRUCTURES_STATICLIST_H

typedef struct staticList StaticList;

/* ~~~ Structs ~~~ */

struct staticList{

    int capacity;
    int size;
    int* array;
    int current;
};

/* ~~~ Function Prototypes ~~~ */

StaticList* createStaticList(int initialCapacity);
void freeStaticList(StaticList* list);
int size(StaticList* list);
int isEmpty(StaticList* list);
void forward(StaticList* list);
void backwards(StaticList* list);
int getActual(StaticList* list);
int getPosition(StaticList* list);
void goFirst(StaticList* list);
void goLast(StaticList *list);
void goTo(StaticList* list, int positionToGo);
void addNext(StaticList* list, int toAdd);
void addBefore(StaticList* list, int toAdd);
int removeS(StaticList* list);


#endif //STRUCTURES_STATICLIST_H
