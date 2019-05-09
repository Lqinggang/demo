#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    printf("is empty? %s\n", is_empty() != 0? "Yes" : "No");

    /* insert */
    int i;
    for (i = -5; i < 6; i++)
    {
        insert((QUEUE_TYPE)i);
    }

    printf("is empty(insert)? %s\n", is_empty() != 0? "Yes" : "No");
    printf("is full(insert)? %s\n", is_full() != 0? "Yes" : "No");

    /* delete */
    while (1)
    {
        if (is_empty() != 0)
        {
            break;
        }

        QUEUE_TYPE value;
        if ((value = first()) == -1 && queue_status != 0)
        {
            printf("first error\n");
            exit(-1);
        }
        printf("first: %d\n", value);
        delete();
    }

    printf("is empty()? %s\n", is_empty() != 0? "Yes" : "No");
    printf("is full()? %s\n", is_full() != 0? "Yes" : "No");

    return (0);
}
