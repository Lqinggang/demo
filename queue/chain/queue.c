#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int queue_status = 0;

/*
 * 创建一个队列
 * 成功: 指向创建的队列的指针
 * 出错: NULL
 */
struct queue *
create_queue(void)
{
    struct queue *q = NULL;
    if ((q = (struct queue *)malloc(sizeof(struct queue))) != NULL)
    {
            q->front = NULL;
            q->rear = NULL;
    }
    queue_status = QUEUEOK;
    return (q);
}

/*
 * 销毁一个队列
 */
void
destroy_queue(struct queue *queue)
{
    if (queue != NULL)
    {
        while (queue->front != NULL)
        {
            struct list *free_node = NULL;
            free_node = queue->front;
            queue->front = free_node->next;
            free(free_node);
            free_node = NULL;
        }
        free(queue);
    }
    queue_status = QUEUEOK;
}

/*
 * 入队
 * 成功: 0
 * 出错: <0
 */
int
insert(struct queue *queue, QUEUE_TYPE value)
{
    if (queue == NULL)
    {
        return (-1);
    }

    /* 创建新的节点 */
    struct list *new_node = NULL;
    if ((new_node = (struct list *)malloc(sizeof(struct list))) == NULL)
    {
        return (-2);
    }
    new_node->next = NULL;
    new_node->value = value;

    if (queue->rear == NULL || queue->front == NULL)  /* 队列为空 */ 
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else  /* 在队尾插入 */
    {
        queue->rear->next =  new_node;
        queue->rear = new_node;
    }
    queue_status = QUEUEOK;
    return (0);
}

/*
 * 出队
 * 成功: 0
 * 出错: <0
 */
int
delete(struct queue *queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        return (-1);
    }

    struct list *free_node = NULL;
    free_node = queue->front;
    if (queue->front == queue->rear)  /* 队列中只有一个元素 */
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = free_node->next;
    }
    free(free_node);
    free_node = NULL;
    queue_status = QUEUEOK;
    return (0);
}

/*
 * 获取队列头元素
 * 出错: -1,并设置queue_status
 * 成功: 返回队列头元素的值(可能返回-1)
 */
QUEUE_TYPE
first(const struct queue *queue)
{
    if (queue == NULL || queue->front == NULL)
    {
        queue_status = QUEUEERROR;
        return (-1);
    }
    return (queue->front->value);
}

/*
 * 判断队列是否为空
 * 0:否
 * 非0: 是
 */
int 
is_empty(const struct queue *queue)
{
    queue_status = QUEUEOK;
    return (queue == NULL || queue->front == NULL || queue->rear == NULL);
}

/*
 * 判断队列queue是否已满
 * 0:否
 * 非0:是
 */
int
is_full(const struct queue *queue)
{
    queue_status = QUEUEOK;
    return (queue == NULL);
}
