#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * output student information.
 * used for output list of the value member.
 */
static void
print_stu(void *value)
{
    struct student *stu = (struct student *)value;
    if (stu != NULL)
    {
        const char *gender = stu->stu_gender == 1? "man" : "woman";
        printf("%-6u\t%-16s\t%-5u\t%-5s\n", stu->stu_id, stu->stu_name, stu->stu_age, gender);
    }
}

/*
 * test insert_into_before_list() 
 */
int
test_insert_into_before_list(plist head)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        struct student *stu = NULL;
        if ((stu = malloc(sizeof(struct student))) == NULL)
        {
            return (-1);;
        }
        stu->stu_id = i;
        snprintf(stu->stu_name, sizeof(stu->stu_name), "name[%d]", i);
        stu->stu_age = i * 10;
        stu->stu_gender = i % 2;
        if (insert_into_before_list(head, stu) == NULL)
        {
            free(stu);
        }
    }
    return (0);
}

int
test_insert_into_after_list(plist head)
{
    int i;
    for (i = 10; i > 5; i--)
    {
        struct student *stu = NULL;
        if ((stu = malloc(sizeof(struct student))) == NULL)
        {
            return (-1);;
        }
        stu->stu_id = i;
        snprintf(stu->stu_name, sizeof(stu->stu_name), "name[%d]", i);
        stu->stu_age = i * 2;
        stu->stu_gender = i % 2;
        if (insert_into_after_list(head, stu) == NULL)
        {
            free(stu);
        }
    }
    return (0);
}

static struct list_hooks global_hooks = { print_stu, malloc, free };

int
test_print_list(plist head)
{
    list_init(&global_hooks);
    return (print_list(head));
}

int
test_get_node_by_index(plist head)
{
    int index;
    for (index = 0; index < 5; index++)
    {
        plist find_node = NULL; 
        if ((find_node = get_node_by_index(head, index * 3)) != NULL)  /* get 0, 3, 6, 9, 12 nodes. */
        {
            printf("the %dth node: \n", index * 3);
            print_stu(find_node->value);
        }
        else
        {
           printf("can't find node: %d\n", index * 3); 
        }
    }
}

/*
 * find the node by value.
 */
static int
compare(void *value1, void *value2)
{
    struct student *stu[2];
    stu[0] = (struct student *)value1;
    stu[1] = (struct student *)value2;

    if (stu[0]->stu_id == stu[1]->stu_id
        && strcmp(stu[0]->stu_name, stu[1]->stu_name) == 0
        && stu[0]->stu_age == stu[1]->stu_age
        && stu[0]->stu_gender == stu[1]->stu_gender)
    {
        return (0);
    }
    return (-1); 
}

void
test_get_node_by_value(plist head)
{
    struct student stu[2];
    stu[0].stu_id = 0;
    strcpy(stu[0].stu_name, "name[0]");
    stu[0].stu_age = 0;
    stu[0].stu_gender = 0;

    stu[1].stu_id = -1;
    strcpy(stu[1].stu_name, "name[-1]");
    stu[1].stu_age = -1;
    stu[1].stu_gender = -1;

    plist find_node = NULL;
    /* it will be found */
    if ((find_node = get_node_by_value(head, &stu[0], compare)) != NULL)
    {
        printf("find the node: \n");
        print_stu(find_node->value);
    }
    else
    {
        printf("can't find the node: \n");
        print_stu(&stu[0]);
    }

    /* the node could not be found */
    if ((find_node = get_node_by_value(head, &stu[1], compare)) != NULL)
    {
        printf("find the node: \n");
        print_stu(find_node->value);
    }
    else
    {
        printf("can't find the node: \n");
        print_stu(&stu[1]);
    }
}

/* test delete_node_by_index() */
int
test_delete_node_by_index(plist head)
{
    int index;
    for (index = 0; index < 5; index++)
    {
        if (delete_node_by_index(head, index * 2) < 0)
        {
            printf("delete node error: %d\n", index * 2);
        }
        else
        {
            printf("delete node success: %d\n", index * 2);
        }
    }
}
