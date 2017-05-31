#include <malloc.h>
#include "Student.h"

/*
 * Function: newStudent
 * Description: Creates a new Student with the given data.
 * Returns: Student pointer.
 */
Student* newStudent(int idStudent, int idPerson){
    Student* student = malloc(sizeof(student));
    student->idStudent = idStudent;
    student->idPerson = idPerson;
    return student;
}

/*
 * Function: destroyStudent
 * Description: Deallocates all memory related to the Student.
 * Returns: --
 */
void destroyStudent(Student* student){
    free(student);
}
