#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static struct list_hooks global_hooks = { NULL, NULL, NULL};

/*
 *
 *
 */
void 
list_init(plist_hooks hooks)
{
    if (hooks != NULL)
    {
        global_hooks.print_func = hooks->print_func;
        global_hooks.malloc_func = hooks->malloc_func;
        global_hooks.free_func = hooks->free_func;
    }
}

/*
 * create an empty doubly linked list.
 * return NULL is fails,otherwise return
 * a pointer.
 */
plist
create_list(void)
{
    plist list = NULL;
    if ((list = (plist)malloc(sizeof(struct list))) == NULL)
    {
        return (NULL);
    }
    list->prev = NULL;
    list->next = NULL;
    list->value = NULL;
    return (list);
}

/*
 * release a doubly linked list.
 */
void
free_list(plist head)
{
    if (head == NULL)
    {
        return;
    }

    plist node = head->next;
    while (node != NULL)
    {
        plist free_node = node;
        node = free_node->next;

        free_node->prev = NULL;
        free_node->next = NULL;
        if (global_hooks.free_func != NULL)
        {
            global_hooks.free_func(free_node->value);
        }

        free(free_node);
    }
    free(head);
}

/*
 * doubly linked list output.
 * on success, return number of output nodes,
 * return -1 when an error occurs.
 */
int
print_list(plist head)
{
    if (head == NULL)
    {
        return (-1);
    }

    unsigned int node_number = 0;
    plist print_node = head->next;
    while (print_node != NULL)
    {
        if (global_hooks.print_func != NULL)
        {
            global_hooks.print_func(print_node->value);
        }
        else
        {
            printf("%d", (int)(*(int *)print_node->value));
        }
        print_node = print_node->next;
    }
    return (node_number);
}

/*
 * insert before the head node.
 * on success return a pointer to the new node, otherwise,
 * return NULL.
 */
plist
insert_into_before_list(plist head, void *value)
{
    if (head == NULL || value == NULL)
    {
        return (NULL);
    }

    /* create a new node */
    plist new_node = NULL;
    if ((new_node = create_list()) == NULL)
    {
        return (NULL);
    }
    new_node->value = value;    
    /* insert before head */
    new_node->next = head->next;
    new_node->prev = head;
    
    if (head->next != NULL)
    {
        head->next->prev = new_node;
    }
    head->next = new_node;

    return (new_node);
}

/*
 * insert after the head node.
 * on success return a pointer to the new node, otherwise,
 * return NULL.
 */
plist 
insert_into_after_list(plist head, void *value)
{
    if (head == NULL || value == NULL)
    {
        return (NULL);
    }

    /* create a new node */
    plist new_node = NULL;
    if ((new_node = create_list()) == NULL)
    {
        return (NULL);
    }
    new_node->value = value;
    
    /* insert after head */
    plist before_node =  head;
    while (before_node->next != NULL)
    {
        before_node = before_node->next;
    }

    new_node->prev = before_node;
    before_node->next = new_node;

    return (new_node);
}

/*
 * get the index(starting from 1) node.
 * return the node pointer on success,
 * or NULL on error.
 */
plist
get_node_by_index(plist head, unsigned int index)
{
    if (head == NULL || index <= 0)
    {
        return (NULL);
    }
    
    plist node = NULL;
    node = head;
    while ((node = node->next) != NULL && index-- > 1)
    ;
   
    return (node);
}

/*
 * get the node by value.
 * return the node pointer on success,
 * or NULL on error.
 */
plist
get_node_by_value(plist head, void *value, int (*compare)(void *value1, void *value2))
{
    if (head == NULL || value == NULL || compare == NULL)
    {
        return (NULL);
    }

    plist find_node = NULL;
    find_node = head->next;

    /* find the node */
    while (find_node != NULL)
    {
        if (compare(value, find_node->value) == 0)
        {
            break;
        }
        find_node = find_node->next;
    }
    return (find_node);
}

/*
 * delete index(starting from 1) node.
 * returns the number of nodes deleted on success,
 * or -1 on error.
 */
int
delete_node_by_index(plist head, unsigned int index)
{
    if (head == NULL || index <= 0)
    {
        return (-1);
    }
    
    /* find the precursor node. */
    plist precursor_node = NULL;
    precursor_node = head;
    while ((precursor_node != NULL) && index-- > 1)
    {
        precursor_node = precursor_node->next;
    }

    /* the predecessor node is not NULL and the deleted node exists */
    if (precursor_node == NULL || precursor_node->next == NULL)
    {
        return (-1);
    }

    /* change the link to the doubly linked list. */
    plist delete_node = NULL;
    delete_node = precursor_node->next;
    precursor_node->next = delete_node->next;
    if (delete_node->next != NULL)
    {
        delete_node->next->prev = precursor_node;
    }
    delete_node->next = NULL;
    delete_node->prev = NULL;
    
    /* delete node */
    if (global_hooks.free_func != NULL && delete_node->value != NULL)
    {
        global_hooks.free_func(delete_node->value);
    }
    free(delete_node);
    delete_node = NULL;
    return (1); 
}
