#include "test.h"
#include <stdio.h>
#include <stdlib.h>

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
