#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

intstack* newstack(size_t size)
{
    intstack *new = malloc(sizeof(intstack));
    if (!new)
	return NULL;
    new->origin = malloc(size * sizeof(int));
    if (!new->origin) {
	free(new);
	return NULL;
    }
    new->pointer = new->origin;
    new->length = size;
    return new;
}

intstack* iarrtostack(int *arr, size_t arrlen, size_t size)
{
    intstack *new = newstack(size);
    if (!new)
	return NULL;
    size_t i;
    for (i = 0; i < arrlen && i < size; ++i)
	push(new, arr[i]);
    return new;
}

int freestack(intstack *stack)
{
    if (!stack)
	return 0;
    if (stack)
	free(stack->origin);
    free(stack);
    return 0;
}

stackresult_t push(intstack *stack, int value)
{
    if (!stack)
	return STACK_NULL;
    if ((stack->pointer) + 1 >= ((stack->origin) + stack->length))
	return STACK_OVERFLOW;
    stack->pointer += 1;
    *(stack->pointer) = value;
    return STACK_OK;
}

stackresult_t pop(intstack *stack, int *dest)
{
    if (!stack)
	return STACK_NULL;
    if ((stack->pointer) - 1 < stack->origin)
	return STACK_UNDERFLOW;
    if (dest)
	*dest = *(stack->pointer);
    stack->pointer -= 1;
    return STACK_OK;
}

int clearstack(intstack *stack)
{
    if (!stack)
	return 0;
    while ((pop(stack, NULL)) != STACK_UNDERFLOW);
    return 0;
}

int peek(intstack *stack, int *dest)
{
    if (!stack)
	return 0;
    if (dest)
	*dest = *(stack->pointer);
    return 0;
}

stackresult_t duplicate(intstack *stack)
{
    if (!stack)
	return STACK_NULL;
    int temp;
    pop(stack, &temp);
    if (push(stack, temp) == STACK_OVERFLOW)
	return STACK_OVERFLOW;
    return STACK_OK;
}
