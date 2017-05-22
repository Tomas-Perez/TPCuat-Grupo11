#include <malloc.h>
#include "Teacher.h"

Teacher* newTeacher(int idTeacher, int idPerson){
    Teacher* teacher = malloc(sizeof(Teacher));
    teacher->idTeacher = idTeacher;
    teacher->idPerson = idPerson;
    return teacher;
}
void destroyTeacher(Teacher* teacher){
    free(teacher);
}
