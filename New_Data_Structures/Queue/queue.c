#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "../LinkedList/list.h"

List *createQueue() {
  return createList();
}

void enqueue(List *list, int num) {
  appendList(list, num);
}

int dequeue(List *list) {
  return shiftList(list);
}

int front(List *list) {
  return list->head->value;
}

int rear(List *list) {
  return list->tail->value;
}
