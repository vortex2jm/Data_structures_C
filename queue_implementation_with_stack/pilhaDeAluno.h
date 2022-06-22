#ifndef pilha_de_aluno_h
#define pilha_de_aluno_h
#include "aluno.h"

typedef struct pilha_aluno PilhaAluno;

PilhaAluno * InitPilhaAlunos(int qtdElementos);

void PilhaAlunos_Push(PilhaAluno * pilha, Aluno * aluno);

Aluno * PilhaAlunos_Pop(PilhaAluno * pilha);

void PrintPilhaAlunos(PilhaAluno * pilha);

void DestructPilhaAlunos(PilhaAluno * pilha);

int PilhaAlunoTopo(PilhaAluno * pilha);

PilhaAluno * InvertPilhaAlunos(PilhaAluno * pilha);

#endif