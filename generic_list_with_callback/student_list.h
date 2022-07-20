#ifndef aluno_list_h
#define aluno_list_h
#include "generic_list.h"
#include "aluno.h"

Glist * CreateVoidStudentList();

Glist * PushStudentList(Glist * list, Aluno * aluno);

void PrintStudentList(Glist * list);

void StudentListRemove(Glist * list, int matricula);

void DestructStudentList(Glist * list);

#endif