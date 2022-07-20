#include <stdio.h>
#include <stdlib.h>
#include "student_list.h"

//==============callbacks===============================//
void print_sudent(void * student){
    printf("nome -> %s\n", RetornaNome(student));
    printf("matricula -> %d\n", RetornaMatricula(student));
    printf("media -> %.2f\n", RetornaMedia(student));
    printf("\n");
}

int remove_student(void * student, void * key){
    int convertedKey = *((int*)key);
    return RetornaMatricula(student) == convertedKey;
}


//==============public functions========================//
Glist * CreateVoidStudentList(){
    return CreateVoidList();
}

Glist * PushStudentList(Glist * list, Aluno * aluno){
    return PushList(list, aluno);
}

void PrintStudentList(Glist * list){
    PrintList(list, print_sudent);
}

void StudentListRemove(Glist * list, int matricula){
    ListRemove(list, remove_student, &matricula);
}

void DestructStudentList(Glist * list){
    DestructList(list);
}