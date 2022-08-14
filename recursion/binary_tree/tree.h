#ifndef tree_h
#define tree_h
#include "aluno.h"

typedef struct tree Tree;

Tree * CreateVoidTree(void);

Tree * CreateTree(Aluno * aluno, Tree * left, Tree * right);

int IsVoidTree(Tree * tree);

void PrintTree(Tree * tree);

int IsInTree(Tree * tree, char * nome);

Tree * DestructTree(Tree * tree);

int LeafAmount(Tree * tree);

int NameOcurrences(Tree * tree, char * name);

int Height(Tree * tree);

#endif