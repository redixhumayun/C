#ifndef _Queue_h
#define _Queue_h

#include <stdlib.h>
#include <stdio.h>
#include "../LinkedList/list.h"

List *createQueue();
void enqueue(List *, int);
int dequeue(List *);
int front(List *);
int rear(List *);

#endif
