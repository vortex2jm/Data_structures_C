#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaTarefas.h"
#include "Fila.h"

typedef struct cell Cell;

struct cell{

    Tarefa * tarefa;
    Cell * proxima;

};

struct tarefa {

    char * nome;
    Fila * fila;
};

struct listatarefas{

    Cell * primeira;
    Cell * ultima;
};

// ================================================//

Tarefa* criaTarefa(char* nome){

    Tarefa * tarefa = malloc(sizeof(Tarefa));

    tarefa->nome = strdup(nome);
    tarefa->fila = criaFila();

    return tarefa;
}

void insereProcedimentoTarefa (Tarefa* tarefa, char* procedimento){

    insereFila(tarefa->fila, procedimento);
}

// ==================================================//

ListaTarefas* criaListaTarefas (){

    ListaTarefas * lista = malloc(sizeof(ListaTarefas));

    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}


void insereTarefaLista (ListaTarefas* lista, Tarefa* tarefa){

    Cell * newCell = malloc(sizeof(Cell));
    newCell->tarefa = tarefa;
    newCell->proxima = NULL;
    

    if(!lista->primeira){

        lista->primeira = newCell;
        lista->ultima = newCell;
    }

    else{

        lista->ultima->proxima = newCell;
        lista->ultima = newCell;
    }
}

void imprimeListaTarefas (ListaTarefas* lista){

    Cell * aux = lista->primeira;

    while(aux){

        printf("Nome da tarefa: %s\n", aux->tarefa->nome);
        printf("Procedimentos:\n");
        imprimeFila(aux->tarefa->fila);

        aux = aux->proxima;
    } 
}

Tarefa* retiraTarefaLista (ListaTarefas* lista, char* nome){

    Cell * aux = lista->primeira;
    Cell * anterior = lista->primeira;
    Tarefa * auxTarefa;

    int x=0;
    while(aux && strcmp(aux->tarefa->nome, nome)){

        if(!x){

            aux = aux->proxima;
        }
        
        else{

            aux = aux->proxima;
            anterior = anterior->proxima;
        }

        x++;
    }

    // se não existe a tarefa, retorna nulo
    if(!aux) return NULL;

    // atribuindo o endereço da tarefa à variável auxiliar
    auxTarefa = aux->tarefa;

    
    if(lista->ultima == aux){
        lista->ultima = anterior;
    }   
    if(lista->primeira == aux){
        lista->primeira = NULL;
    }

    anterior->proxima = aux->proxima;
    
    // liberando a célula após reencadear a lista e salvar a tarefa
    free(aux);

    return auxTarefa;
}


void DeletaTarefa(Tarefa * tarefa){

    if(tarefa){

        if(tarefa->nome) free(tarefa->nome);

        if(tarefa->fila); liberaFila(tarefa->fila);

        free(tarefa);
    }
}


ListaTarefas* liberaListaTarefas(ListaTarefas* lista){

    Cell * atual, * proxima;
    
    if(lista){

        atual = lista->primeira;

        while(atual){

            if(atual->tarefa) DeletaTarefa(atual->tarefa);

            proxima = atual->proxima;
            free(atual);
            atual = proxima;
        }
        free(lista);
    }
}