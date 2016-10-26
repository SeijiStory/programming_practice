#include <stdlib.h>
#include <stdio.h>
#include "list.h"

intlist* newlist(int data)
{
    intlist* new = malloc(sizeof(intlist));
    new->data = data;
    new->next = NULL;
    return new;
}

intlist* iarrtolist(int *data, size_t len)
{
    intlist* new = newlist(*data);
    if (len == 1)
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

size_t length(intlist *list)
{
    intlist *index = list;
    size_t i = 0;
    while (index != NULL) {
	index = cdr(index);
	i++;
    }
    return i;
}

int append(intlist *list, int value)
{
    cons(list, newlist(value));
    return 0;
}

int tail(intlist *list)
{
    size_t i = length(list) - 1;
    return car(listref(list, i));
}

intlist* map(intlist *list, int (*func)(int))
{
    if (list == NULL)
	return list;
    intlist *temp = newlist(func(car(list)));
    return cons(temp, map(cdr(list), func));
}

int listinsert(intlist *list, size_t i, int val)
{
    intlist *temp = listref(list, i);
    intlist *insert = newlist(val);
    (listref(list, i-1))->next = insert;
    insert->next = temp;
    return 0;
}

int listremove(intlist *list, size_t i)
{
    intlist *temp = listref(list, i);
    (listref(list, i-1))->next = listref(list, i+1);
    free(temp);
    return 0;
}

int foreach(intlist *list, int (*func)(int))
{
    if (list == NULL)
	return 0;
    func(car(list));
    return foreach(cdr(list), func);
}

static int printint(int data)
{
    return printf("%d ", data);
}

int printlist(intlist *list)
{
    foreach(list, printint);
    return 0;
}
