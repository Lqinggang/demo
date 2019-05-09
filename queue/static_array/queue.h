#ifndef QUEUE_STATIC_ARRAY_QUEUE_H 
#define QUEUE_STATIC_ARRAY_QUEUE_H 

typedef  int    QUEUE_TYPE;

extern int queue_status;

extern void insert(QUEUE_TYPE value);
extern void delete(void);
extern QUEUE_TYPE first(void);
extern int is_empty(void);
extern int is_full(void);

#endif  /* QUEUE_STATIC_ARRAY_QUEUE_H */
