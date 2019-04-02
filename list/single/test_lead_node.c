#include "test_lead_node.h"
#include <stdio.h>

void
test_insert_after_lsit(plist head)
{
    /* 在链表尾插入(i) */
    int i;
    printf("insert_after_list: \n");
    for (i = 0; i < 5; i++)
    {
        insert_after_list(head, i);
        print_list(head);
    }
    printf("Number of linked list nodes: %d\n", head->element);
}


void
test_insert_before_list(plist head)
{
    /* 在链表前插入(i) */
    int i;
    printf("\ninsert_before_list: \n");
    for (i = 10; i < 15; i++)
    {
        insert_before_list(head, i);
        print_list(head);
    }
    printf("Number of linked list nodes: %d\n", head->element);
}

void
test_insert_before_list_index(plist head)
{
    /* 在特定位置(i * 4)插入(i * 100) */
    int i;
    printf("\ninsert_before_list_index: \n");
    for (i = 0; i < 5; i++)
    {
        int index, value;
        index = i * 4;
        value = i * 100;
        printf("\nInsert the value %d before the %dth position: \n", value, index);

        if (insert_before_list_index(head, index, value) == NULL)
        {
            printf("Insert failed at specified location: %d\n", index);
        }
        print_list(head);
    }
    printf("Number of linked list nodes: %d\n", head->element);

    /* 在第一个结点前(头结点之后)插入 */
    printf("\nInsert the value 1000 before the 1st position: \n");
    if (insert_before_list_index(head, 1, 1000) == NULL)
    {
        printf("Insert failed at specified location: 1\n");
    }
    print_list(head);
    printf("Number of linked list nodes: %d\n", head->element);


    /* 在最后一个结点前插入 */
    printf("\nInsert the value 2000 before the last position: \n");
    if (insert_before_list_index(head, head->element, 2000) == NULL)
    {
        printf("Insert failed at specified location: 1\n");
    }
    print_list(head);
    printf("Number of linked list nodes: %d\n", head->element);


}


void
test_get_node_by_value(plist head)
{
    /* 查找特定值 */
    printf("\nfind value on list: \n");
    printf("list: \n");
    print_list(head);
    plist find_node = NULL;
    int find_value = 2000;
    if ((find_node = get_node_by_value(head, find_value)) == NULL)
    {
        printf("test_lead_nodec.c: test_get_node_by_value: can't find value: %d\n", find_value);
    }
    else
    {
        printf("find the value: ");
        print_node(find_node);
    }

    int find_no_value = -2000;
    if ((find_node = get_node_by_value(head, find_no_value)) == NULL)
    {
        printf("test_lead_nodec.c: test_leadnode； can't find value: %d\n", find_no_value);
    }
    else
    {
        printf("find the value: ");
        print_node(find_node);
    }
}


void 
test_get_node_by_index(plist head)
{
    /* 查找第index个节点 */
    printf("\nfind the index node: \n");
    printf("list: \n");
    print_list(head);
    plist find_index_node = NULL;
    int find_index = 5;
    if ((find_index_node = get_node_by_index(head, find_index)) == NULL)
    {
        printf("test_lead_nodec.c: test_get_node_by_index: %d non't exists\n", find_index);
    }
    else
    {
        printf("%dst node value is: ", find_index);
        print_node(find_index_node);
    }

    int find_no_index = -1;
    if ((find_index_node = get_node_by_index(head, find_no_index)) == NULL)
    {
        printf("test_lead_nodec.c: test_leadnode； %d non't exists\n", find_no_index);
    }
    else
    {
        printf("%dst node value is: ", find_no_index);
        print_node(find_index_node);
    }
}
