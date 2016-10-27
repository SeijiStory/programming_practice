#ifndef STACK
#define STACK

#include <stdbool.h>
#include <stdlib.h>

typedef struct intstack {
    int *origin;
    int *pointer;
    size_t length;
} intstack;

typedef enum {
    STACK_OK,
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    STACK_NULL
} stackresult_t;

intstack* newstack(size_t size);
intstack* iarrtostack(int *arr, size_t arrlen, size_t size);
int freestack(intstack *stack);
stackresult_t push(intstack *stack, int value);
stackresult_t pop(intstack *stack, int *dest);
int clearstack(intstack *stack);
int peek(intstack *stack, int *dest);
stackresult_t duplicate(intstack *stack);

#endif
