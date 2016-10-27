#ifndef STACK
#define STACK

#include <stdlib.h>

typedef char byte;

typedef struct stack_struct stack;

typedef enum {
    STACK_OK,
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    STACK_NULL
} stackresult_t;

stack *newstack(size_t size);
int freestack(stack *target);
void *push(stack *target, void *value, size_t size, size_t len);
stackresult_t pop(stack *target, void *dest, size_t size, size_t len);
int clearstack(stack *target);
int peek(stack *target, void *dest, size_t size, size_t len);
stackresult_t duplicate(stack *target, size_t size, size_t len);
size_t length(stack *target);

#endif
