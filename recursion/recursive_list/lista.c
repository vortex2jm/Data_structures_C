#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct cell Cell;

struct cell{

    Cell * prox;
    int elemento;
};

struct lista {

    Cell * primeira;
    Cell * ultima;
};


//=====================================================================//
Lista * InitLista(){

    Lista * lista = malloc(sizeof(Lista));

    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}

//=====================================================================//
Lista * InsereLista(Lista * lista, int elemento){

    Cell * nova = malloc(sizeof(Cell));
    nova->elemento = elemento;
    nova->prox = NULL;

    if(lista->primeira){

        lista->ultima->prox = nova;
        lista->ultima = nova;
    }

    else{

        lista->primeira = nova;
        lista->ultima = nova;
    }

    return lista;
}

//=====================================================================//
void ImprimeCelulas(Cell * cel){

    if(cel){

        printf("elemento = %d\n", cel->elemento);

        return ImprimeCelulas(cel->prox);
    }

    printf("===fim da lista!===\n");
}

//=====================================================================//
void ImprimeLista(Lista * lista){

    if(lista){

        ImprimeCelulas(lista->primeira);
    }

    printf("lista vazia!");
}

//=====================================================================//
Cell * RetiraCelula(Cell * cell, int elemento){

    Cell * aux;

    if(cell){

        if(cell->elemento == elemento){

            aux = cell;
            free(cell);
            cell = aux->prox;
        }
    }
    else{

        cell->prox = RetiraCelula(cell->prox, elemento);
    }

    return cell;
}

//=====================================================================//
void RetiraLista(Lista * lista, int elemento){

    
}

//=====================================================================//
void LiberaLista(Lista * lista){



}