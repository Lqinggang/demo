#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define DEBUG   1


static void
delete_list_on_head(pList head, int value)
{
    pList free_list = NULL;
    while (head != NULL && head->value == value)
    {
        free_list = head;
        head = free_list->next;
        head->prev = free_list->prev;
        free_list->prev->next = free_list->next;

        free_list->next = NULL;
        free_list->prev = NULL;

        if (head == free_list)
        {
            head = NULL;
        }

        free(free_list);
        free_list = NULL;
    }
}

/**
 * create a empty list.
 */
pList
create_empty_list()
{
    pList head = NULL;
    if ((head = (pList)malloc(sizeof(struct List))) == NULL)
    {
        printf("list.c: create_empty_list: can't malloc memony\n");
        return (NULL);
    }

    head->prev = head;
    head->next = head;
    head->value = 0;
    return (head);
}

/*
 * delete list
 */
void
delete_list(pList head)
{
    if (head != NULL)
    {
        pList free_list;
        head->prev->next = NULL;

        while (head != NULL)
        {
            free_list = head;
            head = free_list->next;
            free_list->next = NULL;
            free_list->prev = NULL;
            free(free_list);
        }
    }
}

pList
insert_value_on_list(pList head, int value)
{

    pList new_list = NULL;
    if ((new_list = create_empty_list()) == NULL)
    {
        return (NULL);
    }
    new_list->value = value;


    if (head != NULL)
    {
        new_list->prev = head->prev;
        new_list->next = head;
        head->prev->next = new_list;
        head->prev = new_list;
    }
    return (new_list); 
}

/*
 * print list
 */
void
print_list(pList head)
{
    if (head != NULL)
    {
        pList tmp;
        tmp = head;
        do {

            printf("%d ", tmp->value);
            tmp = tmp->next;

        } while (head != tmp);
        printf("\n");
    }
}

//int
//delete_list_by_value(pList head, int value)
//{
//    int delete_count = 0;
//    if (head != NULL)
//    {
//        delete_list_on_head(&head, value);
// 
//        pList tmp = NULL;
//        if ((tmp = head) != NULL)
//        {
//            while (head != tmp->next)
//            {
//                if (tmp->value != value)
//                {
//                    tmp = tmp->next;
//                }
//                else
//                {
//                    pList free_list = NULL;
//                    free_list = tmp;
//                    tmp = free_list->next;
//                    free_list->prev->next = free_list->next;
//                    free_list->next->prev = free_list->prev;
//                    free_list->next = NULL;
//                    free_list->prev = NULL;
//                    free(free_list);
//                    free_list = NULL;
//                }
//
//            }
//        }
//
//    }
//
//    return (delete_count);
//}
//
//    int
//delete_list_on_index(pList head, int index)
//{
//    int delete_count = -1;
//    if (head != NULL)
//    {
//        int count = 0;
//        pList tmp;
//        tmp = head;
//        while (head->next != tmp && count != index)
//        {
//            count++;
//            head = head->next;
//        }
//
//        if (count == index)
//        {
//            pList free_list;
//            free_list->prev->next = free_list->next;
//            free_list->next->prev = free_list->prev;
//            free_list->prev = NULL;
//            free_list->next = NULL;
//
//            free(free_list);
//            delete_count = 1;
//
//            if (head->next == NULL)
//            {
//                head = NULL;
//            }
//        }
//
//    }
//    return (delete_count);
//}


