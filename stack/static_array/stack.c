#include "stack.h"
#include <stdio.h>

static STACK_TYPE  stack[STACK_SIZE];
static int top_element = -1;

void
push(STACK_TYPE value)
{
    if (is_full() == 0)
    {
        stack[++top_element] = value;
    }
}

STACK_TYPE *
pop(void)
{
    if (is_empty() == 0)
    {
        return (&stack[top_element--]);
    }
    return (NULL);
}

STACK_TYPE *
top(void)
{
   if (is_empty() == 0)
   {
        return (&stack[top_element]);
   }
   return (NULL);
}

int
is_empty(void)
{
    return (top_element == -1);
}

int
is_full(void)
{
    return (top_element == STACK_SIZE - 1);
}
