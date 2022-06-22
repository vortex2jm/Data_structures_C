#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(void){


    Queue * queue = InitQueue();

    for(int x=0; x<3; x++){

        QueuePush(queue, x+1);
    }

    PrintQueue(queue);

    QueuePop(queue);
    QueuePop(queue);

    PrintQueue(queue);

    QueuePush(queue, 20);
    QueuePush(queue, 49);
    QueuePush(queue, 31);

    PrintQueue(queue);

    QueuePush(queue, 57);
    QueuePop(queue);

    PrintQueue(queue);

    DeleteQueue(queue);

    return 0;
}