#ifndef List_h
#define List_h

#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} List;

List *createList();
Node *createNode();
void appendList(List *, int num);
int popList(List *);
void shiftList(List *);
void printList(List *);

#endif