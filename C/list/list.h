#ifndef LIST
#define LIST

#include <stdlib.h>

typedef struct ll {
    int data;
    struct ll *next;
} intlist;

intlist* list(int data);
intlist* iarrtolist(int *data, size_t len);
int freelist(intlist *list);
int car(intlist *list);
intlist* cdr(intlist *list);
intlist* cons(intlist *a, intlist *b);
intlist* listref(intlist *list, size_t i);

#endif
