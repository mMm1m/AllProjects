#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Stack
{
   struct Vector vector;
};

void pop(struct Stack* stack)
{
   if(stack->vector.size == 0) return;
   --stack->vector.size;
}

void push_back(struct Stack* stack, int val)
{
   vector_push_back(&stack->vector , val);
}

void create_stack(struct Stack * stack)
{
    stack->vector.data = (int*)malloc(INITIAL*sizeof(int));
    stack->vector.capacity = INITIAL;
    stack->vector.size = 0;
    if(stack == NULL)
    {
        printf("Ошибка выделения памяти");
        exit(0);
    }
}

void free_stack(struct Stack* a)
{
    a->vector.size = 0;
    a->vector.capacity=0;
    free(a->vector.data);
}

#endif // STACK_H_INCLUDED
