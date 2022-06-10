#include <stdio.h>
#include <stdlib.h>
#include "pilhaDePrato.h"

struct pilha_prato {

    int * itens;
    int topo;
    int max;
};

PilhaPrato * InitPilha(int qtdElementos){

    PilhaPrato * pilha = malloc(sizeof(PilhaPrato));
    
    pilha->itens = malloc(sizeof(int) * qtdElementos);
    pilha->max = qtdElementos;
    pilha->topo = 0;
    
    return pilha;
}

void Pilha_Push(PilhaPrato * pilha, int elemento){

    if(pilha->topo == pilha->max){

        printf("Pilha cheia, retire um prato!\n\n");
        return;
    }

    pilha->itens[pilha->topo] = elemento;
    pilha->topo++;
}

int Pilha_Pop(PilhaPrato * pilha){

    if(!pilha->topo){

        printf("Impossivel retirar prato de uma pilha vazia. Insira um prato!\n\n");
        return -1;
    }

    pilha->topo -= 1;

    return pilha->itens[pilha->topo];
}

void PrintPilha(PilhaPrato * pilha){

    if(!pilha->topo){

        printf("Impossivel imprimir uma pilha vazia. Insira um prato!\n\n");
        return;
    } 

    printf("####Imprimindo pilha####\n\n");
    for(int x=(pilha->topo - 1); x>=0; x--){

        printf("prato -> %d\n", pilha->itens[x]);
    }
    printf("\n");
}

void DestructPilha(PilhaPrato * pilha){

    if(pilha){

        if(pilha->itens) free(pilha->itens);
        free(pilha);
    }
}

int TemPratoNaPilha(PilhaPrato * pilha){

    if(pilha->topo) return 1;
    return 0;
}