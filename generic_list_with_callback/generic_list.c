#include <stdio.h>
#include <stdlib.h>
#include "generic_list.h"

typedef struct cell Cell;

struct glist{

    Cell * first;
    Cell * last;
};

struct cell{

    Cell * next;
    void * content; 
};

//=================================================================//
Glist * CreateVoidList(){

    Glist * list = malloc(sizeof(Glist));
    list->first = NULL;
    list->last = NULL;

    return list;
}

//=================================================================//
Glist * PushList(Glist * list, void * element){

    Cell * newCell = malloc(sizeof(Cell));
    newCell->content = element;
    newCell->next = NULL;

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

//=================================================================//
void PrintList(Glist * list, print_list print_callback){

    if(!list) return;

    Cell * current = list->first;

    while(current){
        print_callback(current->content);
        current = current->next;
    }
}

//=================================================================//
void ListRemove(Glist * list, list_remove remove_callback, void * key){

    if(!list) return;

    Cell * current = list->first;
    Cell * next = NULL;
    Cell * previous = NULL;

    while(current){
        
        next = current->next;

        if(remove_callback(current->content, key)){
            
            if(current == list->first){
                list->first = list->first->next;
            }
            else if(current == list->last){
                list->last = previous;
                previous->next = NULL;
            }
            else{
                previous->next = current->next;
            }

            free(current);
        }
        previous = current;
        current = next;
    }
}

//=================================================================//
void DestructList(Glist * list){

    Cell * current = list->first;
    Cell * aux;

    if(list){
        while(current){
            aux = current->next;
            free(current);
            current = aux;
        }
        free(list);
    }
}