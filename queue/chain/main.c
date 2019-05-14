#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    struct queue *q = NULL;
    if ((q = create_queue()) == NULL)
    {
        printf("create_queue error\n");
        exit(1);
    }

    printf("is empty(after create)? %s\n", is_empty(q) != 0? "Yes" : "No");
    printf("is full(before insert)? %s\n", is_full(q) != 0? "Yes" : "No");

    /* insert */
    int i;
    for (i = -5; i < 6; i++)
    {
        insert(q, (QUEUE_TYPE)i);
    }

    printf("is empty(after insert)? %s\n", is_empty(q) != 0? "Yes" : "No");
    printf("is full(after insert)? %s\n", is_full(q) != 0? "Yes" : "No");

    /* delete */
    while (1)
    {
        if (is_empty(q) != 0)
        {
            break;
        }

        QUEUE_TYPE value;
        if ((value = first(q)) == -1 && queue_status != 0)
        {
            printf("first error\n");
            exit(-1);
        }
        printf("first: %d\n", value);
        delete(q);
    }

    printf("is empty(before destroy)? %s\n", is_empty(q) != 0? "Yes" : "No");
    printf("is full(before destroy)? %s\n", is_full(q) != 0? "Yes" : "No");

    destroy_queue(q);
    q = NULL;

    printf("is empty(after destroy)? %s\n", is_empty(q) != 0? "Yes" : "No");
    printf("is full(after destroy)? %s\n", is_full(q) != 0? "Yes" : "No");

    return (0);
}
