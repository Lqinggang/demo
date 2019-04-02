#include "list.h"
#include <stdio.h>


static void
test_leadnode()
{
    plist head = NULL;
    if ((head = create_head_node()) == NULL)
    {
        printf("main.c: test_leadnode: create_head_node error\n");
        return ;
    }
    
    int i;

    /* 在链表尾插入(i) */
    printf("insert_after_list: \n");
    for (i = 0; i < 5; i++)
    {
        insert_after_list(head, i);
        print_list(head);
    }
    printf("Number of linked list nodes: %d\n", head->element);

    /* 在链表前插入(i) */
    printf("\ninsert_before_list: \n");
    for (i = 10; i < 15; i++)
    {
        insert_before_list(head, i);
        print_list(head);
    }
    printf("Number of linked list nodes: %d\n", head->element);


    /* 在特定位置(i * 4)插入(i * 100) */
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

    /* 查找特定值 */
    printf("\nfind value on list: \n");
    printf("list: \n");
    print_list(head);
    plist find_node = NULL;
    int find_value = 2000;
    if ((find_node = get_node_by_value(head, find_value)) == NULL)
    {
        printf("mainc.c: test_leadnode； can't find value: %d\n", find_value);
    }
    else
    {
        printf("find the value: ");
        print_node(find_node);
    }

    int find_no_value = -2000;
    if ((find_node = get_node_by_value(head, find_no_value)) == NULL)
    {
        printf("mainc.c: test_leadnode: can't find value: %d\n", find_no_value);
    }
    else
    {
        printf("find the value: ");
        print_node(find_node);
    }

    /* 查找第index个节点 */
    printf("\nfind the index node: \n");
    printf("list: \n");
    print_list(head);
    plist find_index_node = NULL;
    int find_index = 5;
    if ((find_index_node = get_node_by_index(head, find_index)) == NULL)
    {
        printf("mainc.c: test_leadnode: %d non't exists\n", find_index);
    }
    else
    {
        printf("%dst node value is: ", find_index);
        print_node(find_index_node);
    }

    int find_no_index = -1;
    if ((find_index_node = get_node_by_index(head, find_no_index)) == NULL)
    {
        printf("mainc.c: test_leadnode； %d non't exists\n", find_no_index);
    }
    else
    {
        printf("%dst node value is: ", find_no_index);
        print_node(find_index_node);
    }

   
    free_list(head);
    /*
     * 不能简单地判断head是否等于NULL，判断head是否被释放,
     * 释放资源后应该将它们置空, 否则此时的head将是一个野
     * 指针，可能指向任何地址，会出现释放了的资源还可以输出
     * 的错误现象
     */
    head = NULL; 
}

static void
test_no_leadnode()
{
    plist head = NULL;

#if 0
   if ((head = create_empty_list ()) == NULL)
    {
        printf("main.c: test_no_leadnode: create_empty_list error\n");
        return ;
    }
    head->element = -1;
#endif

    int i;
    /* 在链表后插入(i) */
    printf("insert_after_list: \n");
    for (i = 0; i < 5; i++)
    {
       if (head == NULL)
        {
            head = insert_after_list(head, i);
        }
        else
        {
            insert_after_list(head, i);
        }
        print_list(head);
    }

    /* 在链表前插入(i) */
    printf("\ninsert_before_list: \n");
    for (i = 10; i < 15; i++)
    {
       /* 在链表前插入第一个结点被改变，保存好第一个结点 */
       head = insert_before_list(head, i);
       print_list(head);
    }

    /* 在特定位置(i * 4)插入(i * 100) */
    printf("\ninsert_before_list_index: \n");
    for (i = 0; i < 5; i++)
    {
        int index, value;
        index = i * 4;
        value = i * 100;
        printf("\nInsert the value %d before the %dth position: \n", value, index);

        /* head等于NULL时，创建新的结点
         * i等于1时，第一个结点变成新插入的结点
         * head指向新的结点
         */
        if (head == NULL || index == 1)
        {
            if ((head = insert_before_list_index(head, index, value)) == NULL)
            {
                printf("Insert failed at specified location: %d\n", index);
            }
        }
        else
        {
            if (insert_before_list_index(head, index, value) == NULL)
            {
                printf("Insert failed at specified location: %d\n", index);
            }
        }
        print_list(head);
    }

    /*
     * 在第一个结点前插入, 这会导致第一个结点发生变化，
     * 应该保存新的第一个结点的指针,否则会导致内存溢出
     */
    printf("\nInsert the value 1000 before the 1st position: \n");
    plist new_head = NULL;
    if ((new_head = insert_before_list_index(head, 1, 1000)) == NULL)
    {
        printf("Insert failed at specified location: 1\n");
    }
    head = new_head;
    print_list(head);

     /* 查找特定值 */
    printf("\nfind value on list: \n");
    printf("list: \n");
    print_list(head);
    plist find_node = NULL;
    int find_value = 300;
    if ((find_node = get_node_by_value(head, find_value)) == NULL)
    {
        printf("mainc.c: test_leadnode； can't find value: %d\n", find_value);
    }
    else
    {
        printf("find the value: ");
        print_node(find_node);
    }

    int find_no_value = -2000;
    if ((find_node = get_node_by_value(head, find_no_value)) == NULL)
    {
        printf("mainc.c: test_leadnode； can't find value: %d\n", find_no_value);
    }
    else
    {
        printf("find the value: ");
        print_node(find_node);
    }

    /* 查找第index个节点 */
    printf("\nfind the index node: \n");
    printf("list: \n");
    print_list(head);
    plist find_index_node = NULL;
    int find_index = 5;
    if ((find_index_node = get_node_by_index(head, find_index)) == NULL)
    {
        printf("mainc.c: test_leadnode； %d non't exists\n", find_value);
    }
    else
    {
        printf("%dst node value is: ", find_index);
        print_node(find_index_node);
    }

    int find_no_index = -1;
    if ((find_index_node = get_node_by_index(head, find_no_index)) == NULL)
    {
        printf("mainc.c: test_leadnode； %d non't exists\n", find_no_index);
    }
    else
    {
        printf("%dst node value is: ", find_no_index);
        print_node(find_index_node);
    }




    free_list(head);
    /*
     * 不能简单地判断head是否等于NULL，判断head是否被释放,
     * 释放资源后应该将它们置空, 否则此时的head将是一个野
     * 指针，可能指向任何地址，会出现释放了的资源还可以输出
     * 的错误现象
     */
    head = NULL; 
}


static void
test_null_list(void)
{
    printf("\ninsert_before_list(NULL, 100): \n");
    /* 
     * 头结点不能为空, 当定义头结点时，返回NULL, 没有定义头
     * 结点, 则返回新的结点，并赋值为100
     */
    plist null_insert_list = NULL;
    if ((null_insert_list = insert_before_list(NULL, 100)) == NULL)
    {
        printf("main.c: test_null_list: insert_before_list error\n");
    }

    print_list(null_insert_list);
    free_list(null_insert_list);
    null_insert_list = NULL;
}



int
main(void)
{
#ifdef LEADNODE
    test_leadnode();
#else
    test_no_leadnode();
#endif

    test_null_list();

        return (0);
}
