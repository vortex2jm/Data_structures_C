#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

//structure
struct stack
{

  int itens[TAM];
  int top;
};

//init function ====================================//
Stack *InitStack(void)
{

  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = 0;

  return stack;
}

//push function ====================================//
Stack *StackPush(Stack *stack, int number)
{

  if(stack->top > TAM){

    printf("Full stack! Remove one item to insert another\n\n");
    return stack;
  } 

  stack->itens[stack->top] = number;
  stack->top++;

  return stack;
}

//pop function ====================================//
int StackPop(Stack *stack){

  if(!stack->top){

    printf("Void stack! Insert one item!\n\n");
    return 0;
  }

  stack->top--;
  return 1;
}


void PrintStack(Stack *stack){

  for(int x=0; x<stack->top; x++){

    printf("%d\n", stack->itens[x]);
  }
}


void DeleteStack(Stack *stack){

  if(stack) free(stack);
}