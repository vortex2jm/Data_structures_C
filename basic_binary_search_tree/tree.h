#ifndef tree_h
#define tree_h
#include "aluno.h"

typedef struct tree Tree;

Tree * CreateVoidTree();

Tree * CreateNode(Tree * left, Tree * right, Aluno * student);

Aluno * SearchStudent(Tree * tree, int matricula);

void PrintTree(Tree * tree);

Tree * PushTree(Tree * tree, Aluno * student);

Tree * RemoveNode(Tree * tree, int matricula);

void DeleteTree(Tree * tree);

#endif