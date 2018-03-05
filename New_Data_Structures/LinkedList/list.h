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
int shiftList(List *);
void printList(List *);
void insertNode(List *, int, int);
void deleteNode(List *, int);
void reverseList(List *, int);
void reverseListInPlace(Node *, Node *);
void reverseListInPlaceHelper(Node *);
void swapNodes(Node *, Node *);
Node *findMiddleNode(Node *);
void addAtBeg(List *, int);

#endif
