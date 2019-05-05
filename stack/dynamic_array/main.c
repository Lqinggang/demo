#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    /* create a stack */
    pstack stack = NULL;
    if((stack = create_stack(100)) == NULL)
    {
        printf("can't create stack\n");
        exit(1);
    }

    printf("is empty(create)? %s\n", is_empty(stack) != 0? "Yes" : "No");

    /* push */
    int i;
    for (i = 0; i < 10; i++)
    {
        push(stack, (STACK_TYPE)i);
    }

    printf("is empty(push)? %s\n", is_empty(stack) != 0? "Yes" : "No");
    printf("is full(push)? %s\n", is_full(stack) != 0? "Yes" : "No");

    /* get the top element of the stack */
    STACK_TYPE *ptmp = NULL;
    while ((ptmp = top(stack)) != NULL)
    {
        printf("top: %d\n", *ptmp);
        pop(stack);  /* pop */
    }

    printf("is empty(pop)? %s\n", is_empty(stack) != 0? "Yes" : "No");

    /* must be destroyed after creating the stack */
    if (destroy_stack(stack) < 0)
    {
        printf("destroy stack error\n");
        exit(1);
    }
    stack = NULL;

    return (0);
}
