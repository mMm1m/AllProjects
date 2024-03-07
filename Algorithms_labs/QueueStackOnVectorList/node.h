#include <stdio.h>
#include <stdlib.h>
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct Node
{
   int data;
   struct Node* next;
} Node;

typedef struct LinkedList
{
   int size_;
   struct Node* head;
   struct Node* tail;
} LinkedList;

struct LinkedList* createLinkedList()
{
   struct LinkedList* tmp = (struct LinkedList*)malloc(sizeof(struct LinkedList));
   if(tmp == NULL) printf("Ошибка выделения памяти\n");
   tmp->head = NULL;
   tmp->size_ = 0;
   tmp->tail = NULL;
   return tmp;
}

struct Node* createNode(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(node == NULL) printf("Ошибка выделения памяти\n");
    node->next = NULL;
    node->data = val;
    return node;
}

void push_back_node(struct LinkedList * list , struct Node ** list_node, struct Node** tail_node, int val)
{
   struct Node* node = createNode(val);
   if(list->size_ == 0) {
      *list_node = node;
      *tail_node = node;
   }
   else {
        (*tail_node)->next = node;
        *tail_node = node;
    }
   ++list->size_;
}

void pop_front_node(struct LinkedList* list, struct Node ** head_node, struct Node** tail_node)
{
   if(list->size_ == 0) printf("You try delete element from empty list\n");
   else if(list->size_ == 1){
      *head_node = NULL;
      *tail_node = NULL;
   }
   else{
      struct Node* tmp = (*head_node);
      *head_node = (*head_node)->next;
      free(tmp);
   }
   --list->size_;
}

void pop_back_node(struct LinkedList * list , struct Node ** head_node, struct Node** tail_node)
{
   if(list->size_ == 0) printf("You try delete element from empty list\n");
   else if(list->size_ == 1){
      *head_node = NULL;
      *tail_node = NULL;
   }
   else{
      struct Node* tmp = *head_node;
      while(tmp->next->next != NULL) tmp = tmp->next;
      tmp->next = NULL;
      *tail_node = tmp;
   }
   --list->size_;
}

void free_list(struct LinkedList **list) {
    struct Node* prev = NULL;
	while ((*list)->head->next) {
		prev = (*list)->head->next;
		(*list)->head = (*list)->head->next;
		free(prev);
	}
	free((*list)->head);
	free(*list);
	*list = NULL;
}

#endif
