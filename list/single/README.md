## single linked list  
### 1.definition  
```
typedef struct list {  
    struct list *next;  
    int element;  
} *plist;
```
### 2.schematic diagram  
![single linked list](https://github.com/Lqinggang/demo/blob/master/list/single/list.png?raw=true)
### 3.description
1)When defining the head node, the first list structure is used as the head node, and the element holds the number of nodes, otherwise the first list structure is part of the single linked list.
