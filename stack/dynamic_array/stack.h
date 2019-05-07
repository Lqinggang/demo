#ifndef STACK_DYNAMIC_ARRAY_H
#define STACK_DYNAMIC_ARRAY_H

#include <stdio.h>

typedef int STACK_TYPE;
typedef STACK_TYPE * pstack;

extern pstack create_stack(size_t size);
extern int destroy_stack(void);
extern int push(STACK_TYPE value);
extern STACK_TYPE *pop(void);
extern STACK_TYPE *top(void);
extern int is_empty(void);
extern int is_full(void);

#endif  /* STACK_DYNAMIC_ARRAY_H */
