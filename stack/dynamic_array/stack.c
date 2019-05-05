#include "stack.h"
#include <stdlib.h>

pstack
create_stack(size_t size)
{
    pstack stack = NULL;
    if ((stack = (pstack)malloc(sizeof(pstack))) == NULL)
    {
        return (NULL);
    }

    if ((stack->stack = (STACK_TYPE *)malloc(size)) == NULL)
    {
        free(stack);
        return (NULL); }
    stack->top_element = -1;
    stack->stack_size = size;

    return (stack);
}

int
destroy_stack(pstack stack)
{
    if (stack != NULL)
    {
        if (stack->stack != NULL)
        {
            free(stack->stack);
        }
        free(stack);
        return (0);
    }
    return (-1);
}

int
push(pstack stack, STACK_TYPE value)
{
    if (stack != NULL && stack->stack != NULL && is_full(stack) == 0)
    {
        stack->stack[++stack->top_element] = value;
        return (0);
    }
    return (-1);
}

STACK_TYPE *
pop(pstack stack)
{
    if (stack != NULL && stack->stack != NULL && is_empty(stack) == 0)
    {
        return (&stack->stack[stack->top_element--]);
    }
    return (NULL);
}

STACK_TYPE *
top(const pstack stack)
{
    if (stack != NULL && stack->stack != NULL && is_empty(stack) == 0)
    {
        return (&stack->stack[stack->top_element]);
    }
    return (NULL);
}

int
is_empty(const pstack stack)
{
    if (stack != NULL)
    {
        return (stack->top_element == -1);
    }
    return (-1);
}

int
is_full(const pstack stack)
{
    if (stack != NULL)
    {
        //Warning
        return ((size_t)stack->top_element == stack->stack_size);
    }
    return (-1);
}
