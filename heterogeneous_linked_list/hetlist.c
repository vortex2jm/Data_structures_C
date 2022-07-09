#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "hetlist.h"
#include "car.h"
#include "motorcycle.h"

typedef struct cell Cell;

struct hetlist{

    Cell * first;
    Cell * last;    
};  

struct cell{

    Cell * next;
    void * veiculo;
    char * type;
};


HetList * InitHetList(void){

    HetList * list = malloc(sizeof(HetList));

    list->first = NULL;
    list->last = NULL;

    return list;
}


HetList * Push(HetList * list, char * type, void * veiculo){

    Cell * newCell = malloc(sizeof(Cell));
    newCell->next = NULL;
    newCell->veiculo = veiculo;
    newCell->type = strdup(type);

    if(!list->first){

        list->first = newCell;
        list->last = newCell;       
    }

    else{

        list->last->next = newCell;
        list->last = newCell;
    }
    
    return list;
}

void PrintHetList(HetList * list){

    Cell * current = list->first;
    
    printf("\n====Imprimindo Lista====\n\n");

    while(current){

        if(!strcmp(current->type, "motorcycle")) PrintMotorcyle(current->veiculo); 
        else if(!strcmp(current->type, "car")) PrintCar(current->veiculo);
        current = current->next;
    }    
}

void RemoveById(HetList * list, int id){

    Cell * current = list->first;
    Cell * previous;
    int flag=0; //pra indicar se foi carro ou moto

    if(!list->first){
        printf("void list :(\n\n");
        return;
    }

    while(current){

        if(!strcmp(current->type, "motorcycle")){
            if(MotoId(current->veiculo) == id){
                flag = 1;
                break;
            } 
        }
        else if(!strcmp(current->type, "car")){
            if(CarId(current->veiculo) == id){
                flag = 2;
                break;
            } 
        }
        previous = current;
        current = current->next;
    }

    //reencadeando a lista
    if(current == list->first){

        list->first = current->next;
    }
    else if(current == list->last){

        list->last = previous;
        previous->next = NULL;
    }
    else{

        previous->next = current->next;
    }

    //liberando a memoria alocada pelo veiculo
    if(flag == 1){

        DestructMotorcyle(current->veiculo);
    }
    else if(flag == 2){

        DestructCar(current->veiculo);
    }

    //liberando a string tipo e a celula
    free(current->type);
    free(current);
}

void DestructList(HetList * list){

    if(!list) printf("This list do not exists!\n\n");

    Cell * current = list->first;
    Cell * aux;

    while(current){

        if(!strcmp(current->type,"motorcycle")){
            DestructMotorcyle(current->veiculo);
            free(current->type);           
        }
        else if(!strcmp(current->type, "car")){
            DestructCar(current->veiculo);
            free(current->type);
        }
        aux = current->next;
        free(current);
        current = aux;       
    }

    free(list);
}