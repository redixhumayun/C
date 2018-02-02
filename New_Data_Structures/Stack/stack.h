#ifndef _Stack_h
#define _Stack_h

#include <stdlib.h>
#include <stdbool.h>
#include "../LinkedList/list.h"

List *createStack();
void push(List *, int);
int pop(List *);
int peek(List *);
bool isEmpty(List *);

#endif
