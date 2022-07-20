#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "student_list.h"


int main(){

    Aluno * student1, * student2, * student3, * student4;
    Glist * studentList = CreateVoidStudentList();

    student1 = IniciaAluno("Joao", 2021, 10.0);
    student2 = IniciaAluno("Jhonatan", 2020, 9.8);
    student3 = IniciaAluno("Lucas", 2019, 9.3);
    student4 = IniciaAluno("Bruno", 2018, 10.0);
    
    PushStudentList(studentList, student1);
    PushStudentList(studentList, student2);
    PushStudentList(studentList, student3);
    PushStudentList(studentList, student4);

    printf("======Imprimindo a lista de estudantes======\n\n");
    PrintStudentList(studentList);

    printf("##Removento Lucas##\n\n");
    StudentListRemove(studentList, 2019);

    printf("======Imprimindo a lista de estudantes======\n\n");
    PrintStudentList(studentList);

    DestroiAluno(student1);
    DestroiAluno(student2);
    DestroiAluno(student3);
    DestroiAluno(student4);

    DestructStudentList(studentList);

    return 0;
}