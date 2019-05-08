#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    /* create a stack */
    struct stack *stack = NULL;
    if ((stack = create_stack()) == NULL)
    {
        printf("create_stack error\n");
        exit(1);
    }
    printf("is empty(create)? %s\n", is_empty(stack) != 0? "Yes" : "No");

    /* push */
    int i;
    for (i = 0; i < 5; i++)
    {
        push(stack, (STACK_TYPE)i); 
    }
    for (i = -5; i < 0; i++)
    {
        push(stack, (STACK_TYPE)i);
    }
    printf("is empty(push)? %s\n", is_full(stack) != 0? "Yes" : "No");
    printf("is full(push)? %s\n", is_full(stack) != 0? "Yes" : "No");

    /* get the top element and pop */
    int j;
    for (j = 0; j < 11; j++)
    {
        STACK_TYPE *ptmp = NULL;
        ptmp = top(stack);
        if (ptmp != NULL)
        {
            printf("top: %d\n", *ptmp);
        }
        else
        {
            printf("get value error\n");
        }
        pop(stack);
    }

    printf("is empty(pop)? %s\n", is_empty(stack) != 0? "Yes" : "No");

    /* destroy stack */
    destroy_stack(stack);
    stack = NULL;
    return (0);
}
