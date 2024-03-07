#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "stack.h"

void stack_pop(struct Stack* stack)
{
   if(stack->vector.size == 0) return;
   vector_del(&stack->vector, stack->vector.size-1);
}

void stack_push_back(struct Stack* stack, int val)
{
   vector_push_back(&stack->vector , val);
}

