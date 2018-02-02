#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "../LinkedList/list.h"

List *createStack() {
  return createList();
}

void push(List *list, int num) {
  appendList(list, num);
}

int pop(List *list) {
  return popList(list);
}

int peek(List *list) {
  return list->tail->value;
}

bool isEmpty(List *list) {
  return list->size == 0;
}
