#include <stdio.h>
#include <stdlib.h>

#include "./list.h"
#include "./list_algos.h"

void mergeLinkedLists(List *list_a, List *list_b, List *list_c) {
  mergeSort(list_a->head);
}

void mergeSort(Node *head) {
  if(head == NULL || head->next == NULL) {
    return;
  }
  Node *a = createNode();
  Node *b = createNode();
  getMiddle(head, &a, &b);
  mergeSort(a);
  mergeSort(b);
  mergeLists(a, b);
}

Node *mergeLists(Node *a, Node *b) {
  Node *tail = createNode();
  Node dummy;
  dummy.value = 0;
  dummy.next = NULL;
  tail = &dummy;
  while(1) {
    if(a == NULL) {
      tail->next = b;
      break;
    } else if(b == NULL) {
      tail->next = a;
      break;
    }
    if(a->value < b->value) {
      MoveNode(&(tail->next), &a);
    }
    else {
      MoveNode(&(tail->next), &b);
    }
    tail = tail->next;
  }
  return dummy.next;
}

void MoveNode(Node **destRef, Node **sourceRef) {
  Node *newNode = *sourceRef;
  *sourceRef = newNode->next; //advance the source node
  newNode->next = *destRef;
  *destRef = newNode;
}

void getMiddle(Node *source, Node **frontRef, Node **backRef) {
  Node *slow = createNode();
  Node *fast = createNode();
  if(source == NULL || source->next == NULL) {
    *frontRef = source;
    *backRef = NULL;
  }
  else {
    slow = source;
    fast = source->next;
    while(fast != NULL) {
      fast = fast->next;
      if(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}
