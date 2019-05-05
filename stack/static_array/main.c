#include "stack.h"
#include <stdio.h>

int
main(void)
{
    /* push */
    int i;
    for (i = 0; i < 10; i++)
    {
        push((STACK_TYPE)i);
    }

    int j;
    for (j = 0; j < 11; j++)
    {
        STACK_TYPE *ptmp = NULL;
        ptmp = top();
        if (ptmp != NULL)
        {
            printf("top: %d\n", *ptmp);
        }
        else
        {
            printf("get value error\n");
        }
        pop();
    }
    return (0);
}
