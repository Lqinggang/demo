#ifndef LIST_H
#define LIST_H

typedef struct List {
    struct List *prev;
    struct List *next;
    int value;
} *pList;

extern pList create_empty_list();
extern void delete_list(pList head);
extern void print_list(pList head);
extern pList insert_value_on_list(pList head, int value);
//extern int delete_list_by_value(pList head, int value);
//extern int delete_list_on_index(pList head, int index);

#endif  /* LIST_H */
