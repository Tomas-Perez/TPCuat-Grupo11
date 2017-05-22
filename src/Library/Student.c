#include <malloc.h>
#include "Student.h"

Student* newStudent(int idStudent, int idPerson){
    Student* student = malloc(sizeof(student));
    student->idStudent = idStudent;
    student->idPerson = idPerson;
    return student;
}
void destroyStudent(Student* student){
    free(student);
}
