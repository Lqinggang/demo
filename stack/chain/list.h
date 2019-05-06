#ifndef STACK_CHAIN_LIS_H
#define STACK_CHAIN_LIST_H

typedef int STACK_TYPE;

typedef struct list {
    struct list *next;
    STACK_TYPE value;
} *plist;


extern struct list *create_list(struct list *head);  /* for create_stack */
extern struct list *insert_before_list(struct list *head);  /* for push() */
extern struct list *get_first_node(struct list *head);  /* for top() */
extern struct list *delete_first_node(struct list *head);  /* for pop() */


#endif  /* STACK_CHAIN_LIST_H */
