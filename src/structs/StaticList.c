/*
    Description: C file that contains the functions prototyped in StaticList.h

*/

#include "StaticList.h"
#include <stdlib.h>

/*
    Function: createStaticList
    - Description: allocates a Static List in memory.
    - Parameters: -
    - Returns: pointer referencing the memory address used.
*/

StaticList* createStaticList(int initialCapacity){

    StaticList* list = malloc(sizeof(StaticList));
    list->array = malloc(sizeof(int)*initialCapacity);
    list->capacity = initialCapacity;
    list->size = 0;
    list->current = 0;
    return list;
}

/*
    Function: freeStaticList
    - Description: frees a Linked List from memory.
    - Parameters: StaticList pointer.
    - Returns: -
*/

void freeStaticList(StaticList* list){

    free(list->array);
    free(list);
}

static void grow(StaticList* list){
    list->array = realloc(list->array, sizeof(int)*list->capacity*2);
    list->capacity = list->capacity*2;
}

/*
    Function: size
    - Description: returns the amount of items (size) contained in the Linked List
    - Parameters: StaticList pointer.
    - Returns: integer representing the Static List's size.
*/

int size(StaticList* list){
    return list->size;
}

/*
    Function: isEmpty
    - Description: determines whether a Static List is empty or not.
    - Parameters: StaticList pointer
    - Returns: 1 if condition is TRUE, 0 if condition is FALSE.
*/

int isEmpty(StaticList* list){
    if(list->size != 0) return 1;
    return 0;
}

/*
    Function: forward
    - Description: moves the current view one place forward
    - Parameters: StaticList pointer.
    - Returns: -
*/

void forward(StaticList* list){

    if(isEmpty(list) && list->current + 1 != list->size) list->current++;
}

/*
    Function: backwards
    - Description: moves the current view one place backwards.
    - Parameters: StaticList pointer.
    - Returns: -
*/

void backwards(StaticList* list){

    if(isEmpty(list) && list->current != 0) list->current--;
}

/*
    Function: getActual
    - Description: returns the item currently in view.
    - Parameters: StaticList pointer.
    - Returns: an integer (depends on what the list is holding)
*/

int getActual(StaticList* list){

    return list->array[list->current];
}

/*
    Function: getPosition
    - Description: returns the position in the StaticList of the current view.
    - Parameters: StaticList pointer.
    - Returns: an integer representing the position.
*/

int getPosition(StaticList* list){

    return list->current;
}

/*
    Function: goFirst
    - Description: sets the current view in the first place of the Static List
    The Static List must have a size > 0 else, it does nothing..
    - Parameters: StaticList pointer.
    - Returns: -
*/

void goFirst(StaticList* list){

    list->current = 0;
}

/*
    Function: goLast
    - Description: sets the current view in the last place of the Static List.
    The Static List must have a size > 0 else, it does nothing.
    - Parameters: StaticList pointer.
    - Returns: -
*/

void goLast(StaticList *list){

    list->current = list->size - 1;
}

/*
    Function: goTo
    - Description: moves the current view to the desired position in the Static List.
    The position wished must be smaller than the List's size.
    - Parameters: LinkedList pointer, integer position.
    - Returns: -
*/

void goTo(StaticList* list, int positionToGo){

    if(positionToGo > 0 && positionToGo < list->size) list->current = positionToGo;
}

/*
    Function: addNext
    - Description: adds an item in the Static List next to the one in the current
    view. The current view is not changed..
    - Parameters: StaticList pointer, integer toAdd.
    - Returns: -
*/

void addNext(StaticList* list, int toAdd){

    if(list->size == 0){
        list->array[0] = toAdd;
        list->size++;
        return;
    }
    if(list->capacity == list->size) grow(list);
    for(int i = list->size-1;i >= list->current+1; i--){
        list->array[i+1] = list->array[i];
    }
    list->array[list->current + 1] = toAdd;
    list->size++;
}

/*
    Function: addBefore
    - Description: adds an item to the Static List before the one in the current
    vew. The current view is not changed.
    - Parameters: StaticList pointer, int toAdd.
    - Returns: -
*/

void addBefore(StaticList* list, int toAdd){

    if(list->current == 0) exit(2);
    if(list->capacity == list->size) grow(list);
    for(int i = list->size-1;i >= list->current; i--){
        list->array[i+1] = list->array[i];
    }
    list->array[list->current] = toAdd;
    list->size++;
    list->current;

}

/*
    Function: removeS
    - Description: removes the item curently in view. The current view will shift
    right or left depending which one is available. If the two options are available,
    the current view will shift to the right.
    - Parameters: StaticList pointer.
    - Returns: integer with the current view.
*/

int removeS(StaticList* list){

    for(int i = list->current; i < list->size-1;i++){
        list->array[i] = list->array[i+1];
    }
    if(list->current == 0) list->current = 0;
    else if(list->current == list->size-1) list->current--;
    list->size--;
}
