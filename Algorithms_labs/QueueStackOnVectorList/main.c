#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "queue.h"

int main()
{
   //Task D
   /*struct LinkedList* list = createLinkedList();
   int n;
   char str[1000000];
   scanf("%d", &n);
   getchar();

    // Ввод n строк
    for (int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin);
        if (str[0] == '+') {
            int num1;
            sscanf(str+1, " %d", &num1);
            push_back_to_list(list, &num1);
        }
        else{
           pop_from_list_queue(list);
        }
    }
    }
    //free_list(list);*/

   //Task C
   /*struct Queue queue;
   create_queue(&queue);
   int n;
   char str[1000000];
   scanf("%d", &n);
   getchar();

    // Ввод n строк
    for (int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin);
        if (str[0] == '+') {
            int number;
            sscanf(str + 1, " %d", &number);
            stack_push_back(&queue, number);
        }
        else{
           queue_pop(&queue);
        }
    }
   free_queue(&queue);*/
     //TASK B
   //struct LinkedList* list = createLinkedList();
   /*int n;
   char str[1000000];
   scanf("%d", &n);
   getchar();

    // Ввод n строк
    for (int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin);
        if (str[0] == '+') {
            int number;
            sscanf(str + 1, " %d", &number);
            push_back_to_list(list, number);
        }
        else{
           pop_from_list_stack(list);
        }
    }
    free_list(list);*/

    //TASK A
   /*struct Stack stack;
   create_stack(&stack);
   int n;
   char str[1000000];
   scanf("%d", &n);
   getchar();

    // Ввод n строк
    for (int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin);
        if (str[0] == '+') {
            int number;
            sscanf(str + 1, " %d", &number);
            stack_push_back(&stack, number);
        }
        else{
           pop(&stack);
        }
    }
   free_stack(&stack);*/
   }
