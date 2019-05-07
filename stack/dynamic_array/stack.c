#include "stack.h"
#include <stdlib.h>

static STACK_TYPE  *stack = NULL;
static int top_element = -1;
static size_t stack_size = 0;

pstack
create_stack(size_t size)
{
    if ((stack = (STACK_TYPE *)malloc(size)) != NULL)
    {
        stack_size = size;
    }

    return (stack);
}

int
destroy_stack(void)
{
    if (stack != NULL)
    {
        stack_size = 0;
        free(stack);
        stack = NULL;
        return (0);
    }
    return (-1);
}

int
push(STACK_TYPE value)
{
    if (stack != NULL && is_full() == 0)
    {
        stack[++top_element] = value;
        return (0);
    }
    return (-1);
}

STACK_TYPE *
pop(void)
{
    if (stack != NULL && is_empty() == 0)
    {
        return (&stack[top_element--]);
    }
    return (NULL);
}

STACK_TYPE *
top(void)
{
    if (stack != NULL && is_empty() == 0)
    {
        return (&stack[top_element]);
    }
    return (NULL);
}

int
is_empty(void)
{
    if (stack != NULL)
    {
        return (top_element == -1);
    }
    return (-1);
}

int
is_full(void)
{
    if (stack != NULL)
    {
        // Warning
        return (top_element == stack_size - 1);
    }
    return (-1);
}
