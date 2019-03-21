#include <stdio.h>
#include "list.h"

int main(void)
{
    pList head;
    if ((head = create_empty_list()) == NULL)
    {
        printf("can't create a empty list\n");
        return (0);
    }
    head->value = 1;

    int i;
    for (i = 0; i < 5; i++)
    {
        if (insert_value_on_list(head, i) == NULL)
        {
            printf("can't insert value");
            break;
        }
        print_list(head);
    }
    print_list(head);

    delete_list(head);

    return (0);
}
