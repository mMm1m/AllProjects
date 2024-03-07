#include <stdio.h>
#include <malloc.h>
#include "vector.h"

void vector_push_back(struct Vector *a,int val)
{
    if(a->capacity  == a->size)
    {
        a->capacity *= 2;
        a->data = (int*)realloc(a->data, sizeof(int)*a->capacity);
    }
    a->data[a->size++] = val;
}

void vector_del(struct Vector *a,int index)
{
   printf("%d\n", a->data[index]);
   for (size_t j = index; j < a->size - 1; ++j)
   {
      if(a->size == 1) break;
      a->data[j] = a->data[j + 1];
   }
   --a->size;
}

void create_vector(struct Vector * vector)
{
    vector->data = (int*)malloc(INITIAL*sizeof(int));
    vector->capacity = INITIAL;
    vector->size = 0;
    if(vector == NULL)
    {
        printf("Ошибка выделения памяти");
        exit(0);
    }
}

void free_(struct Vector* a)
{
    a->size = 0;
    a->capacity=0;
    free(a->data);
}
