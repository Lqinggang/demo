#ifndef STACK_CHAIN_STACK_H
#define STACK_CHAIN_STACK_H

#include "list.h"

typedef struct stack {
    struct list *node;
} *pstack;

extern struct stack *create_stack(void);
extern void destroy_stack(struct stack *stack);
extern int push(struct stack *stack, STACK_TYPE value);
extern void pop(struct stack *stack);
extern STACK_TYPE *top(const struct stack *stack);
extern int is_empty(const struct stack *stack);
extern int is_full(const struct stack *stack);

#endif  /* STACK_CHAIN_STACK_H */
