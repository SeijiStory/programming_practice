#include <stdlib.h>
#include <string.h>
#include "stack.h"

struct stack_struct {
    byte *origin;
    byte *pointer;
    size_t maxlen;
    size_t len;
};

stack *newstack(size_t size)
{
    stack *new = malloc(sizeof(stack));
    if (!new) return NULL;
    new->maxlen = size;
    new->len = 0;
    new->origin = malloc(size);
    if (!new->origin) {
	free(new);
	return NULL;
    }
    new->pointer = new->origin;
    return new;
}

int freestack(stack *target) {
    target->pointer = NULL;
    free(target->origin);
    free(target);
    return 0;
}

void *push(stack *target, void *value, size_t size, size_t len)
{
    if (!target)
	return NULL;
    if (target->len+(size*len) > target->maxlen)
	return NULL;
    memcpy((byte *)target->pointer, (byte *)value, size*len);
    void *temp = target->pointer;
    target->pointer = (byte *)target->pointer+(size*len);
    target->len += size*len;
    return temp;
}

stackresult_t pop(stack *target, void *dest, size_t size, size_t len)
{
    if (!target)
	return STACK_NULL;
    if (target->len <= 0)
	return STACK_UNDERFLOW;
    target->pointer = (byte *)target->pointer-(size*len);
    target->len -= size*len;
    if (dest)
	memcpy((byte *)dest, (byte *)target->pointer, size*len);
    return STACK_OK;
}

int clearstack(stack *target)
{
    while (pop(target, NULL, sizeof(char), 1) != STACK_UNDERFLOW);
    return 0;
}

int peek(stack *target, void *dest, size_t size, size_t len)
{
    target->pointer = (byte *)target->pointer - (size*len);
    memcpy((byte *)dest, (byte *)target->pointer, size*len);
    target->pointer = (byte *)target->pointer + (size*len);
    return 0;
}

stackresult_t duplicate(stack *target, size_t size, size_t len)
{
    void *temp = malloc(size*len);
    if (!temp)
	return 1;
    if (pop(target, temp, size, len) != STACK_OK)  goto failure;
    if (push(target, temp, size, len) != STACK_OK) goto failure;
    if (push(target, temp, size, len) != STACK_OK) goto failure;
    free(temp);
    return 0;
failure:
    free(temp);
    return 1;
}

size_t length(stack *target)
{
    return target->len;
}
