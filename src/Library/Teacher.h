#ifndef TPCUAT_GRUPO11_TEACHER_H
#define TPCUAT_GRUPO11_TEACHER_H

typedef struct Teacher Teacher;
struct Teacher{
    int idTeacher;
    int idPerson;
};

Teacher* newTeacher(int idTeacher, int idPerson);
void destroyTeacher(Teacher* teacher);

#endif //TPCUAT_GRUPO11_TEACHER_H
