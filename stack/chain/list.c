#include "list.h"
#include <stdio.h>
#include <stdlib.h>


struct list *
create_list(struct list *head, STACK_TYPE value)
{
    if ((head = (struct list *)malloc(sizeof(struct list))) != NULL)
    {
       head->next = NULL;
       head->value = value;
    }
    return (head);
}

void
destroy_list(struct list *head)
{
    while (head != NULL)
    {
        struct list *free_list = NULL;
        free_list = head;
        head = head->next;
        free(free_list);
        free_list = NULL;
    }
}
