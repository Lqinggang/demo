#ifndef STACK_CHAIN_STACK_H
#define STACK_CHAIN_STACK_H

#include "list.h"

typedef struct stack {
    struct list *node;
} *pstack;

extern pstack create_stack(void);
extern int destroy_stack(pstack stack);
extern int push(pstack stack, STACK_TYPE value);
extern STACK_TYPE *pop(pstack stack);
extern STACK_TYPE *top(const pstack stack);
extern int is_empty(const pstack stack);
extern int is_full(const pstack stack);

#endif  /* STACK_CHAIN_STACK_H */
