#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack *
create_stack(void)
{
    struct stack *stack = NULL;
    if ((stack = (struct stack *)malloc(sizeof(struct stack))) != NULL)
    {
        stack->node = NULL;
    }
    return (stack);
}

void
destroy_stack(struct stack *stack)
{
    if (stack != NULL)
    {
        destroy_list(stack->node);
        free(stack);
        stack = NULL;
    }
}

int
push(struct stack *stack, STACK_TYPE value)
{
    if (stack != NULL)
    {
        struct list *new_node = NULL;
//        if (create_list(new_node, value) != NULL)   //Error!!
        if ((new_node = create_list(new_node, value)) != NULL)
        {
            new_node->next = stack->node;
            stack->node = new_node;
            return (0);
        }
    }
    return (-1);
}

void
pop(struct stack *stack)
{
    if (stack != NULL && stack->node != NULL)
    {
        struct list *free_list = NULL;
        free_list = stack->node;
        stack->node = free_list->next;
        free(free_list);
        free_list = NULL;
    }
}

STACK_TYPE *
top(const struct stack *stack)
{
    if (stack != NULL && stack->node != NULL)
    {
        return (&stack->node->value);
    }
    return (NULL);
}

int
is_empty(const struct stack *stack)
{
   if (stack != NULL && stack->node != NULL)
   {
       return (0);
   }
   return (1);
}

int
is_full(const struct stack *stack)
{
    if (stack != NULL)
    {
        return (0);
    }
    return (-1);
}
