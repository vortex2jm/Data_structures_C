#ifndef stack_h
#define stack_h

typedef struct stack Stack;

Stack *InitStack(void);

Stack *StackPush(Stack *stack, int number);

int StackPop(Stack *stack);

void PrintStack(Stack *stack);

void DeleteStack(Stack *stack);

#endif // !stack_h
