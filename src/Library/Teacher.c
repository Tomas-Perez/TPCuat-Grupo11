#include <malloc.h>
#include "Teacher.h"

/*
 * Function: newTeacher
 * Description: Creates a new Teacher with the given data.
 * Returns: Teacher pointer.
 */
Teacher* newTeacher(int idTeacher, int idPerson){
    Teacher* teacher = malloc(sizeof(Teacher));
    teacher->idTeacher = idTeacher;
    teacher->idPerson = idPerson;
    return teacher;
}

/*
 * Function: destroyTeacher
 * Description: Deallocates all memory related to the Teacher.
 * Returns: --
 */
void destroyTeacher(Teacher* teacher){
    free(teacher);
}
