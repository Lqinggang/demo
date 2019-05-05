#ifndef STACK_STACK_H
#define STACK_STACK_H

#define STACK_SIZE	100

typedef  int    STACK_TYPE;

extern void push(STACK_TYPE value);
extern STACK_TYPE *pop(void);
extern STACK_TYPE *top(void);
extern int is_empty(void);
extern int is_full(void);



#endif  /* STACK_STACK_H */
