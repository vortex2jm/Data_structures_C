#include <stdio.h>
#include <stdlib.h>
#include "pilhaDeAluno.h"

struct pilha_aluno{

    Aluno ** alunos;
    int max;
    int topo;
};  

PilhaAluno * InitPilhaAlunos(int qtdElementos){

    PilhaAluno * pilha = malloc(sizeof(PilhaAluno));
    
    pilha->alunos = malloc(sizeof(Aluno*) * qtdElementos);
    pilha->max = qtdElementos;
    pilha->topo = 0;
    
    return pilha;
}

void PilhaAlunos_Push(PilhaAluno * pilha, Aluno * aluno){

    if(pilha->topo == pilha->max){

        printf("Pilha cheia, retire um aluno!\n\n");
        return;
    }

    pilha->alunos[pilha->topo] = aluno;
    pilha->topo++;
}

Aluno * PilhaAlunos_Pop(PilhaAluno * pilha){

    if(!pilha->topo){

        printf("Impossivel retirar aluno de uma pilha vazia. Insira um aluno!\n\n");
        return NULL;
    }

    pilha->topo -= 1;

    return pilha->alunos[pilha->topo];
}

void PrintPilhaAlunos(PilhaAluno * pilha){

    if(!pilha->topo){

        printf("Impossivel imprimir uma pilha vazia. Insira um aluno!\n\n");
        return;
    } 

    printf("####Imprimindo pilha####\n\n");
    for(int x=(pilha->topo - 1); x>=0; x--){

        ImprimeAluno(pilha->alunos[x]);
    }
    printf("\n");
}

void DestructPilhaAlunos(PilhaAluno * pilha){

    if(pilha){

        if(pilha->alunos){

            for(int x=0; x<pilha->max; x++){

                if(pilha->alunos[x])
                    DestroiAluno(pilha->alunos[x]);
            }
            free(pilha->alunos);
        }
        free(pilha);
    }
}

int PilhaAlunoTopo(PilhaAluno * pilha){

    return pilha->topo;
}

PilhaAluno * InvertPilhaAlunos(PilhaAluno * pilha){

    Aluno * aux;

    for(int x=0, y=(pilha->topo-1) ; x<=((pilha->topo/2)-1); x++, y--){

        aux = pilha->alunos[x];
        pilha->alunos[x] = pilha->alunos[y];
        pilha->alunos[y] = aux; 
    }

    return pilha;
}