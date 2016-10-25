#include <stdlib.h>
#include "list.h"

intlist* list(int data)
{
    intlist* new = malloc(sizeof(intlist));
    new->data = data;
    new->next = NULL;
    return new;
}

intlist* iarrtolist(int *data, size_t len)
{
    intlist* new = list(*data);
    if (len == 0)
	return new;
    new->next = iarrtolist(data+1, len-1);
    return new;
}

int freelist(intlist *list)
{
    if (list == NULL)
	return 0;
    freelist(cdr(list));
    free(list);
    list = NULL;
    return 0;
}

int car(intlist *list)
{
    return list->data;
}

intlist* cdr(intlist *list)
{
    return list->next;
}

intlist* cons(intlist *a, intlist *b)
{
    if (a == NULL)
	return b;
    a->next = cons(cdr(a), b);
    return a;
}

intlist* listref(intlist *list, size_t i)
{
    if (list == NULL && i > 0)
	return NULL;
    if (i == 0)
	return list;
    return listref(cdr(list), i-1);
}
