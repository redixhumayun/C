#include <stdio.h>
#include <stdlib.h>

#include "./list.h"

void printList(List *list) {
    Node *current = list->head;
    while(current != NULL) {
        printf("Value: %d\n", current->value);
        current = current->next;
    }
}

Node *createNode() {
    Node *node = malloc(sizeof(Node));
    if(node == NULL) {
        free(node);
        return NULL;
    }
    node->value = 0;
    node->next = NULL;
    return node;
}

List *createList() {
    List *list = malloc(sizeof(List));
    if(list == NULL) {
        return NULL;
    }

    list->head = createNode();
    list->tail = createNode();
    if(list->head == NULL || list->tail == NULL) {
        free(list);
        return NULL;
    }

    list->size = 0;
    return list;
}

void appendList(List *list, int num) {
    if(list->head->value == 0) {
        list->head->value = num;
        list->tail->value = num;
        list->size += 1;
        return;
    }
    Node *current = createNode();
    current = list->head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = createNode();
    if(current->next == NULL) {
        free(current->next);
        printf("Failed to allocate memory");
        exit(1);
    }
    current->next->value = num;
    list->tail = current->next;
    list->size += 1;
}

int popList(List *list) {
  //remove only node present and return
    if(list->size == 1) {
      int valueRemoved = list->head->value;
      list->head->value = 0;
      list->tail->value = 0;
      return valueRemoved;
    }
    int count = 0;
    Node *t;
    Node *temp = list->head;
    while(count < list->size - 2) {
        t = temp;
        temp = temp->next;
        count++;
    }
    int valueRemoved = temp->next->value;
    list->tail->value = temp->value;
    list->tail->next = NULL;
    t->next = list->tail;
    free(temp);
    list->size -= 1;
    return valueRemoved;
}

void shiftList(List *list) {
    Node *temp = list->head->next;
    list->head->value = temp->value;
    list->head->next = temp->next;
    free(temp);
    list->size -= 1;
    return;
}

void insertNode(List *list, int value, int index) {
    if(index > list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    Node *newNode = createNode();
    newNode->value = value;
    Node *c = list->head;
    Node *current = list->head;
    int count = 0;
    while(count < index) {
        c = current;
        current = current->next;
        count++;
    }
    c->next = newNode;
    newNode->next = current;
    list->size += 1;
    return;
}

void deleteNode(List *list, int index) {
    if(index > list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    int count = 0;
    Node *c = list->head;
    Node *current = list->head;
    while(count < index) {
        c = current;
        current = current->next;
        count++;
    }
    c->next = current->next;
    free(current);
    list->size -= 1;
    return;
}

void reverseList(List *list, int offset) {
    int retVal = offset;
    int offset_2 = (list->size - 1) - offset;
    //base condition
    if(offset > offset_2) {
      return;
    }
    Node *a = createNode();
    a = list->head;
    Node *b = createNode();
    b = list->head;
    while(offset != 0) {
      a = a->next;
      offset--;
    }
    while(offset_2 != 0) {
      b = b->next;
      offset_2--;
    }
    swapNodes(a, b);
    return reverseList(list, retVal + 1);
}

void swapNodes(Node *a, Node *b) {
  int temp = a->value;
  a->value = b->value;
  b->value = temp;
  return;
}

void addAtBeg(List *list, int num) {
  Node *temp = createNode();
  Node *h = list->head;
  temp->value = num;
  temp->next = h;
  list->head = temp;
  free(temp);
  return;
}
