#include "queue.h"
#include <stdio.h>

#define QUEUE_SIZE	10               /* 队列可以中元素的最大数量 */
#define ARRAY_SIZE  (QUEUE_SIZE + 1) /* 数组长度 */

static QUEUE_TYPE   queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

int queue_status = 0;

void
insert(QUEUE_TYPE value)
{
    if (is_full() == 0)
    {
        rear = (rear + 1) % ARRAY_SIZE;
        queue[rear] = value;
    }
}

void
delete(void)
{
    if (is_empty() == 0)
    {
        front = (front + 1) % ARRAY_SIZE;
    }
}

QUEUE_TYPE
first(void)
{
    if (is_empty() == 0)
    {
        return (queue[front]);
    }
    queue_status  = -1;
    return ((QUEUE_TYPE)-1);
}

int
is_empty(void)
{
    return ((rear + 1) % ARRAY_SIZE == front);
}

int
is_full(void)
{
    return ((rear + 2) % ARRAY_SIZE == front);
}
