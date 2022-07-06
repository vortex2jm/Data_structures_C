#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define TAM 4

struct queue {

    int start;
    int amount;
    int itens[TAM];
}; 

//======================================================================//
Queue * InitQueue(void){

    Queue * queue = malloc(sizeof(Queue));

    queue->start = 0;
    queue->amount = 0;

    return queue;
}

//======================================================================//
Queue * QueuePush(Queue * queue, int number){

    if(!queue || queue->amount >= TAM){

        printf("Queue's full! Remove one item to insert another!\n\n");
        return queue;
    }

    int end = (queue->start + queue->amount) % TAM;
    queue->itens[end] = number;
    queue->amount ++;

    return queue;
}

//======================================================================//
int QueuePop(Queue *queue){

    if(!queue->amount){

        printf("Void queue! Insert one item!\n\n");
        return 0;
    }

    queue->start = (queue->start + 1) % TAM;
    queue->amount--;

    return 1;
}

//======================================================================//
void PrintQueue(Queue * queue){

    int current;

    for(int x=0; x<queue->amount;x++){

        current = (queue->start + x)%TAM;
        printf("%d ", queue->itens[current]);
    }    

    printf("\n");
}

//======================================================================//
void DeleteQueue(Queue * queue){

    if(queue) free(queue);
}