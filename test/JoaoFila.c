#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

typedef struct cell Cell;

struct cell {

    char * procedimento;
    Cell * proxima;
};

struct fila{

    Cell * primeira;
    Cell * ultima;
};

// =================================================//

Fila* criaFila(){

    Fila * fila = malloc(sizeof(Fila));

    fila->primeira = NULL;
    fila->ultima = NULL;

    return fila;
}



void insereFila (Fila* f, char* string){

    Cell * newCell = malloc(sizeof(Cell));

    newCell->procedimento = strdup(string);
    newCell->proxima = NULL;

    if(!f->primeira){

        f->primeira = newCell;
        f->ultima = newCell;
    }

    else{

        f->ultima->proxima = newCell;
        f->ultima = newCell;
    }
}



void imprimeFila (Fila* f){

    Cell * aux = f->primeira;

    int x=0;
    while(aux){

        printf("%d -> %s\n",x, aux->procedimento);
        aux = aux->proxima;
        x++;
    }
}



int vaziaFila (Fila* f){

    if(!f->primeira) return 1;
    return 0;
}



char* retiraFila (Fila* f){

    if(vaziaFila(f)) return NULL;

    Cell * aux = f->primeira->proxima;
    char * auxproced = f->primeira->procedimento;
    
    if(f->primeira) free(f->primeira);
    f->primeira = aux;

    return auxproced;
}