## doubly linked list
### 1.definition  
```
typedef struct list {  
    struct list *prev;  

    void        *element;  

    struct list *next;
} *plist;
```
### 2.schematic diagram  
![double linked list](https://github.com/Lqinggang/demo/blob/master/list/double/images/list.png?raw=true)
