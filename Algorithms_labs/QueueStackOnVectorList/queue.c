#include <stddef.h>
#include "vector.h"
#include "queue.h"

void create_queue(struct Queue * queue)
{
    queue->vector.data = (int*)malloc(INITIAL*sizeof(int));
    queue->vector.capacity = INITIAL;
    queue->vector.size = 0;
    if(queue == NULL)
    {
        printf("Ошибка выделения памяти");
        exit(0);
    }
}

void free_queue(struct Queue* a)
{
    a->vector.size = 0;
    a->vector.capacity=0;
    free(a->vector.data);
}
