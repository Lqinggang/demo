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

    printf("test_insert_into_before_list:\n");
    test_insert_into_before_list(head);
    test_print_list(head);

    printf("test_insert_into_after_list:\n");
    test_insert_into_after_list(head);
    test_print_list(head);
    
    free_list(head);
    head = NULL;

    return (0);
}
