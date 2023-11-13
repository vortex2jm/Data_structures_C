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
void ImprimeCelulasCrescente(Cell * cell){

    if(cell){
        printf("elemento = %d\n", cell->elemento);
        ImprimeCelulasCrescente(cell->prox);
    }
}

void ImprimeCelulasDecrescente(Cell * cell){

    if(cell){
        ImprimeCelulasDecrescente(cell->prox);
        printf("elemento = %d\n", cell->elemento);
    }
}

void ImprimeUltima(Lista * lista){

    printf("ultimo elemento -> %d\n", lista->ultima->elemento);
}

//=====================================================================//
void ImprimeLista(Lista * lista, int param){

    if(!param){
        printf("====Imprimindo a lista em ordem crescente====\n\n");
        if(lista){
            ImprimeCelulasCrescente(lista->primeira);
        }
        printf("\n");
    }

    else if(param){
        printf("====Imprimindo a lista em ordem decrescente====\n\n");
        if(lista){
            ImprimeCelulasDecrescente(lista->primeira);
        }
        printf("\n");
    }
}

//===============================OUTRO JEITO DE RETIRAR DA LISTA==================================//

// Cell * RetiraCelula(Cell * cell, int elemento, Lista * lista){

//     Cell * proxima;

//     if(cell){
        
//         if(cell != lista->ultima && !cell->prox->prox && elemento == cell->prox->elemento){
//             lista->ultima = cell;
//             free(cell->prox);
//             cell->prox = NULL;
//             return cell;
//         }
//         if(cell->elemento == elemento){
//             proxima = cell->prox;
//             free(cell);
//             cell = proxima;
//         }
//         else{
//             cell->prox = RetiraCelula(cell->prox, elemento, lista);
//         }
//     }
//     return cell;
// }


//=====================================================================//
Cell * RetiraCelula(Cell * atual, Cell * proxima, int elemento, Lista * lista){

    if(atual){
        
        if(proxima == lista->ultima && elemento == proxima->elemento){

            lista->ultima = atual;
            atual->prox = NULL;
            free(proxima);
        }

        if(atual->elemento == elemento){
            free(atual);
            atual = proxima;
        }

        else{
            atual->prox = RetiraCelula(atual->prox, proxima->prox, elemento, lista);
        }
    }

    return atual;
}

//=====================================================================//
void RetiraLista(Lista * lista, int elemento){

    Cell * next = lista->primeira->prox;
    Cell * aux = NULL;

    if(lista){

        // Mudar os parametros caso escolha a outra função de retirada
        aux = RetiraCelula(lista->primeira, lista->primeira->prox, elemento, lista);
        if(aux == next){
            lista->primeira = next;
        }
    }
}

//=====================================================================//
void LiberaCelulas(Cell * cell){

    Cell * next = NULL;
    if(cell){
        next = cell->prox;
        free(cell);
        LiberaCelulas(next);
    }   
}

//=====================================================================//
void LiberaLista(Lista * lista){

    if(lista){
        LiberaCelulas(lista->primeira);
        free(lista);
    }
}