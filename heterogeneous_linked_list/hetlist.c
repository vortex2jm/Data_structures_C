#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "hetlist.h"

typedef struct cell Cell;

struct hetlist{

    Cell * first;
    Cell * last;
    
};  

struct cell{

    Cell * next;
    void * tipo;
    char * type;
};


HetList * InitHetList(void){

    HetList * list = malloc(sizeof(HetList));

    list->first = NULL;
    list->last = NULL;

    return list;
}

HetList * Push(HetList * list, char * type, void * structure){

    Cell * newCell = malloc(sizeof(Cell));
    newCell->next = NULL;
    newCell->tipo = structure;
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


