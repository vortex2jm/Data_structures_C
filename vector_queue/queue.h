#ifndef queue_h
#define queue_h

typedef struct queue Queue;

Queue * InitQueue(void);

Queue * QueuePush(Queue * queue, int number);

int QueuePop(Queue *queue);

void PrintQueue(Queue * queue);

void DeleteQueue(Queue * queue);

#endif