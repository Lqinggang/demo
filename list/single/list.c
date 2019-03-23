#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * 未定义头结点时，在链表的第index个元素之前插入新的结点，
 * 结点值等于value,当head等于NULL或者index等于1时，表示
 * 在head前插入新的结点
 * 成功，返回指向新的结点的指针
 * 出错，1)要插入的位置不存在，2)创建新的结点出错, 返回NULL
 * 注意:
 *      1)保存好第一个结点的指针，不然可能导致内存泄露
 */
static plist
insert_before_list_index_no_lead_node(plist head, int index, int value)
{
    if (index <= 0)
    {
        return (NULL);
    }

    /* 当head == NULL时，index == 1:表示创建新的节点，否则出错 */
    if (head == NULL || index == 1)
    {
        plist new_node = NULL;
        if ((new_node = create_empty_list()) == NULL)
        {
            return (NULL);
        }
        new_node->element = value;
        
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
        return (head);
    }

    /* 创建新的结点 */
    plist new_node = NULL;
    if ((new_node = create_empty_list()) == NULL)
    {
        return (NULL);
    }
    new_node->element = value;
       

    /* 查找index的前驱节点 */
    plist tmp;
    tmp = head;
    int index_count = 1;
    while (tmp != NULL && index_count < index - 1)  /* -1: 前驱*/
    {
        tmp = tmp->next;
        index_count++;
    }

    /* index的前驱结点不存在 */
    if (tmp == NULL)
    {
        free_list(new_node);
        new_node = NULL;
        return (NULL);
    }

    new_node->next = tmp->next;
    tmp->next = new_node;
    return (new_node);
}

/*
 * 定义头结点时，在链表的第index个元素之前插入新的结点，
 * 结点值等于value
 * index: 不包括头结点，从1开始
 */
static plist
insert_before_list_index_lead_node(plist head, int index, int value)
{
    /* 头结点为空或者要插入的位置不存在 */
    if (head == NULL || index < 1 || head->element < index)
    {
        return (NULL);
    }

    /* 创建新的结点 */
    plist new_node = NULL;
    if ((new_node = create_empty_list()) == NULL)
    {
        return (NULL);
    }
    head->element++;
    new_node->element = value;

    /* 查找第index个元素的前驱位置 */
    plist tmp;
    if (index == 1)
    {
        tmp = head;
    }
    else
    {
        tmp = head->next;
    }
    int index_count = 1;
    while (tmp != NULL && index_count < index - 1)  /* -1: 前驱 */
    {
        tmp = tmp->next;
        index_count++;
    }
    
    new_node->next = tmp->next;
    tmp->next = new_node;
    return(new_node);
}




#ifdef LEADNODE
plist
create_head_node(void)
{
    plist head = NULL;
    if ((head = create_empty_list()) == NULL)
    {
        return (NULL);
    }
    head->element = 0;
    return (head);
}
#else

plist
create_head_node(void)
{
    return (create_empty_list());
}
//#define create_head_node(void)  create_empty_list(void)

#endif


/*
 * 创建一个空的单链表
 * 成功，返回单链表指针
 * 出错，1)申请内存失败，返回NULL
 */
plist
create_empty_list(void)
{
    plist new_list = NULL;
    if ((new_list = (plist)malloc(sizeof(struct list))) == NULL)
    {
        printf("list.c: create_empty_list: failed to apply for memory");
        return (NULL);
    }
    new_list->next = NULL;
    new_list->element = 0;

    return (new_list);
}

/*
 * 释放单链表
 */
void
free_list(plist head)
{
    plist free_item = NULL;
    while (head != NULL)
    {
        free_item = head;
        head = head->next;
        free_item->next = NULL;
        free(free_item);
    }
}

/*
 * 输出单链表数据
 * 成功，返回输出数据的个数
 * 出错，返回-1
 */
int
print_list(plist head)
{
#ifdef LEADNODE  /* 带头结点 */
    if (head == NULL)
    {
        return (-1);
    }
    head = head->next;
#endif 

    int out_count = 0;
    while (head != NULL)
    {
        printf("%d ", head->element);
        head = head->next;
        out_count++;
    }
    if (out_count != 0)
    {
        printf("\n");
    }
    return (out_count);
}

/*
 * 尾插法
 * 成功，返回指向新插入的链表的指针
 * 出错，返回NULL
 */
plist
insert_after_list(plist head, int value)
{
#ifdef LEADNODE
    if (head == NULL)
    {
        return (NULL);
    }
#endif

    plist new_node = NULL;
    if ((new_node = create_empty_list()) == NULL)
    {
        printf("list.c: insert_after_list: create_empty_list error\n");
        return (NULL);
    }
    new_node->element = value;

    plist tmp;
    tmp = head;

#ifdef LEADNODE
    if (head->next == NULL)
    {
        head->element = 1;
        head->next = new_node;
        return (new_node);
    }
    tmp = head->next;
    head->element++;
#else
    if (head == NULL)
    {
        head = new_node;
        return (new_node);
    }
#endif

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_node;

    return (new_node);
}

/*
 * 头插法
 * 成功，返回新的头结点
 * 出错，返回NULL
 */
plist
insert_before_list(plist head, int value)
{
#ifdef LEADNODE
    if (head == NULL)
    {
        return (NULL);
    }
#endif

    plist new_node;
    if ((new_node = create_empty_list()) == NULL)
    {
        printf("list.c: insert_before_list: create_empty_list error\n");
        return (NULL);
    }
    new_node->element = value;

#ifdef LEADNODE
    head->element++;
    new_node->next = head->next;
    head->next = new_node;
#else
    new_node->next = head;
    head = new_node;
#endif
    return (new_node);
}

/*
 * 在index位置前插入新的节点，节点值为value
 * 成功，返回新插入的节点的指针
 * 出错，1) 申请内存出错，2)插入的位置不存在, 返回NULL
 */
plist
insert_before_list_index(plist head, int index, int value)
{
#ifdef LEADNODE
    return (insert_before_list_index_lead_node(head, index, value));
#else
    return (insert_before_list_index_no_lead_node(head, index, value));
#endif
}

/*
 * 查找第一个值为value的结点
 */
plist
get_node_by_value(const plist head, int value)
{
}




/*
 * 删除head指向的链表中所有值为value的结点
 * 成功，返回删除的结点数
 * 出错，返回-1
 */
int
delete_list_by_value(plist *head, int value)
{
    if (head == NULL || *head == NULL)
    {
        return (-1);
    }
    
    plist tmp;
    tmp = *head;

#ifdef LEADNODE
    tmp = tmp->next;
#endif

    while (tmp != NULL)
    {
        if (tmp->element == value)
        {
        }
    }
    


    return (-1);
}

/*
 * 删除head中指向的链表第index个(从1开始)结点
 * 成功，返回1
 * 出错，返回0
 */
int
delete_list_by_index(plist *head, int index)
{
}
