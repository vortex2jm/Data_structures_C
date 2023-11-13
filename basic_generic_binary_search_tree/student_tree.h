#ifndef student_tree_h
#define student_tree_h
#include "generic_tree.h"
#include "aluno.h"

Tree * CreateVoidStudentTree();

Tree * CreateStudentNode(Tree * left, Tree * right, Aluno * student);

Tree * PushStudentTree(Tree * tree, Aluno * student);

void PrintStudentTree(Tree * tree);

Tree * RemoveStudentTree(Tree * tree, void * key, char * type);

Aluno * SearchStudentTree(Tree * tree, void * key, char * type);

void DeleteStudentTree(Tree * tree);

#endif