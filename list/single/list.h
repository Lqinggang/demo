#ifndef LIST_SINGLE_LIST_H
#define LIST_SINGLE_LIST_H

typedef struct list {
    struct list *next;
    int element;
//    void *element;
} *plist;

extern plist create_empty_list(void);
extern plist create_head_node(void);

extern plist insert_after_list(plist head, int value);
extern plist insert_before_list(plist head, int value);
extern plist insert_before_list_index(plist head, int index, int value);

extern int print_list(plist head);

extern void free_list(plist head);

#endif  /* LIST_SINGLE_LIST_H */
