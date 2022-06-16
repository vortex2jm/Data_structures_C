#ifndef fila_h
#define fila_h
#include "pilhaDeAluno.h"

typedef struct fila Fila;

Fila * InitFila(int qtd);

void Fila_Push(Fila * fila, Aluno * aluno);

Aluno * Fila_Pop(Fila * fila);

void PrintFila(Fila * fila);

void Destructfila(Fila * fila);

int TemAlguemNaFila(Fila * fila);

#endif