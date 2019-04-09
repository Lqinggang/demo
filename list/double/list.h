#ifndef LIST_DOUBLE_LIST_H
#define LIST_DOUBLE_LIST_H

#include <stddef.h>

/* doubly linked list */
typedef struct list {
    struct list     *prev;

    void            *value; 

    struct list     *next;
} *plist;

typedef struct list_hooks {
    void     (*print_func)(void *value);        /* output value(plist->value) */
    void     *(*malloc_func)(size_t size);      /* allocated memory for value */
    void     (*free_func)(void *ptr);           /* frees the memory space pointed to by ptr */
} *plist_hooks;


extern void list_init(plist_hooks hooks);

extern plist create_list(void);
extern void free_list(plist head);
extern int print_list(plist head);

extern plist insert_into_before_list(plist head, void *value);
extern plist insert_into_after_list(plist head, void *value);

extern plist get_node_by_index(plist head, unsigned int index);

extern int delete_node_by_index(plist head, unsigned int index);

#endif  /* LIST_DOUBLE_LIST_H */
