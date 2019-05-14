#ifndef QUEUE_CHAIN_QUEUE_H
#define QUEUE_CHAIN_QUEUE_H

typedef int QUEUE_TYPE;

typedef struct list {
    struct list *next;
    QUEUE_TYPE value;
} *plist;

typedef struct queue {
    struct list *front;
    struct list *rear;
} *pqueue;

#define QUEUEOK         0
#define QUEUEERROR      -1

extern int queue_status;

extern struct queue *create_queue(void);
extern void destroy_queue(struct queue *queue);
extern int insert(struct queue *queue, QUEUE_TYPE value);
extern int delete(struct queue *queue);
extern QUEUE_TYPE first(const struct queue *queue);
extern int is_empty(const struct queue *queue);
extern int is_full(const struct queue *queue);

#endif  /* QUEUE_CHAIN_QUEUE_H */
