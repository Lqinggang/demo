#include <stdio.h>
#include "list.h"
#include "test.h"

int
main(void)
{
    plist head = NULL;
    if ((head = create_list()) == NULL)
    {
        printf("create_list error\n");
        return (-1);
    }

    /* insert before list */
    printf("test_insert_into_before_list:\n");
    test_insert_into_before_list(head);
    test_print_list(head);

    /* insert after list */
    printf("test_insert_into_after_list:\n");
    test_insert_into_after_list(head);
    test_print_list(head);

    /* get the node by index */
    printf("test_get_node_by_index: \n");
    test_get_node_by_index(head);

    /* delete the node by index */ 
    printf("test_delete_node_by_index: \n");
    test_delete_node_by_index(head);
    printf("after delete: \n");
    test_print_list(head);
    
    /* free the doubly linked list */
    free_list(head);
    head = NULL;

    return (0);
}
