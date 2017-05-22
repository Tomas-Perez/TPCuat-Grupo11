#ifndef TPCUAT_GRUPO11_STUDENT_H
#define TPCUAT_GRUPO11_STUDENT_H

typedef struct Student Student;
struct Student{
    int idStudent;
    int idPerson;
};
Student* newStudent(int idStudent, int idPerson);
void destroyStudent(Student* student);

#endif //TPCUAT_GRUPO11_STUDENT_H
