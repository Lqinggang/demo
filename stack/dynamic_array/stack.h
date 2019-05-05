#ifndef STACK_DYNAMIC_ARRAY_H
#define STACK_DYNAMIC_ARRAY_H

#include <stdio.h>

typedef int STACK_TYPE;

typedef struct stack {
    STACK_TYPE *stack; 
    int top_element;
    size_t stack_size;
} *pstack;

extern pstack create_stack(size_t size);
extern int destroy_stack(pstack stack);
extern int push(pstack stack, STACK_TYPE value);
extern STACK_TYPE *pop(pstack stack);
extern STACK_TYPE *top(const pstack stack);
extern int is_empty(const pstack stack);
extern int is_full(const pstack stack);

#endif  /* STACK_DYNAMIC_ARRAY_H */
