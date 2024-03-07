#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void pop_from_list_stack(struct LinkedList* list)
{
    if(list->size_ == 0) return;
    printf("%d\n", list->tail->data);
    pop_back_node(list, &(list->head), &(list->tail));
}

void pop_from_list_queue(struct LinkedList* list)
{
    if(list->size_ == 0) return;
    printf("%d\n", list->head->data);
    pop_front_node(list, &(list->head), &(list->tail));
}

void push_back_to_list(struct LinkedList* list, int val)
{
    push_back_node(list, &(list->head), &(list->tail), val);
}

void printList(struct LinkedList* list)
{
    struct Node* curr = list->head;
    while(curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}
