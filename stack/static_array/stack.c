#include "stack.h"

static STACK_TYPE  stack[STACK_SIZE];
static int top_element = -1;

void
push(STACK_TYPE value)
{
}

void
pop(void)
{
}

STACK_TYPE
top(void)
{
   if (is_empty() == 0)
   {
        return (stack[top_element]);
   }
   return (-1);
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
