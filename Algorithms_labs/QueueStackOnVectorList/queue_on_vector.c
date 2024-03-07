#include <stdio.h>
#include "queue.h"
#include "vector.h"

void queue_pop(struct Queue* queue)
{
   if(queue->vector.size == 0) return;
   vector_del(&queue->vector, 0);
}

void queue_push_back(struct Queue* queue, int val)
{
   vector_push_back(&queue->vector , val);
}
