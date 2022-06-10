#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    
    PilhaAluno * p1;
    int max;
};


Fila * InitFila(int qtd){

    Fila * fila = malloc(sizeof(Fila));
    
    fila->p1 = InitPilhaAlunos(qtd);
    fila->max = qtd;

    return fila;
}

void Fila_Push(Fila * fila, Aluno * aluno){

    if(PilhaAlunoTopo(fila->p1) == fila->max){

        printf("Impossivel inserir aluno. A fila esta cheia!\n\n");
        return;
    }

    // fila->p2 = fila->p1;
    InvertPilhaAlunos(fila->p1);

    PilhaAlunos_Push(fila->p1, aluno);
    InvertPilhaAlunos(fila->p1);

    // fila->p1 = fila->p2;
}

Aluno * Fila_Pop(Fila * fila){

    if(!PilhaAlunoTopo(fila->p1)){

        printf("Impossivel retirar aluno de uma fila vazia. Insira um aluno!\n\n");
        return NULL;
    }

    return PilhaAlunos_Pop(fila->p1);
}

void PrintFila(Fila * fila){

    PrintPilhaAlunos(fila->p1);
}

void Destructfila(Fila * fila){

    if(fila){

        if(fila->p1) DestructPilhaAlunos(fila->p1);
        free(fila);
    } 
}

int TemAlguemNaFila(Fila * fila){

    if(PilhaAlunoTopo(fila->p1)) return 1;
    return 0;
}