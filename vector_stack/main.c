#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{

  Stack * stack = InitStack();

  for(int x=0; x<7; x++){

    StackPush(stack, x);
  }

  StackPop(stack);
  StackPop(stack);
  PrintStack(stack);
  DeleteStack(stack);
  
  return 0;
}
