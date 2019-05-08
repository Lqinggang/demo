#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    /* create a stack */
    if(create_stack(100) == NULL)
    {
        printf("can't create stack\n");
        exit(1);
    }

    printf("is empty(create)? %s\n", is_empty() != 0? "Yes" : "No");

    /* push */
    int i;
    for (i = 0; i < 10; i++)
    {
        push((STACK_TYPE)i);
    }

    printf("is empty(push)? %s\n", is_empty() != 0? "Yes" : "No");
    printf("is full(push)? %s\n", is_full() != 0? "Yes" : "No");

    /* get the top element of the stack */
    STACK_TYPE *ptmp = NULL;
    while ((ptmp = top()) != NULL)
    {
        printf("top: %d\n", *ptmp);
        pop();  /* pop */
    }

    printf("is empty(pop)? %s\n", is_empty() != 0? "Yes" : "No");

    /* must be destroyed after creating the stack */
    if (destroy_stack() < 0)
    {
        printf("destroy stack error\n");
        exit(1);
    }

    return (0);
}
