#ifndef LIST
#define LIST

#include <stdlib.h>
#include <stdio.h>

typedef struct ll {
    int data;
    struct ll *next;
} intlist;

intlist* newlist(int data);
intlist* iarrtolist(int *data, size_t len);
int freelist(intlist *list);
int car(intlist *list);
intlist* cdr(intlist *list);
intlist* cons(intlist *a, intlist *b);
intlist* listref(intlist *list, size_t i);
size_t length(intlist *list);
int append(intlist *list, int value);
int tail(intlist *list);
intlist* map(intlist *list, int (*func)(int));
int listinsert(intlist *list, size_t i, int val);
int listremove(intlist *list, size_t i);
int foreach(intlist *list, int (*func)(int));
int printlist(intlist *list);

#endif
