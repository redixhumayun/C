#include <stdio.h>
#include <stdlib.h>

#include "./list.h"
#include "./list_algos.h"
#include "./minunit.h"

int tests_run = 0;

static char *test_list_mergesort() {
  List *a = createList();
  int arr_a[] = {6,5,3,11,9};
  int i = 0;
  for(i = 0; i < 5; i++) {
    appendList(a, arr_a[i]);
  }
  Node *retHead = mergeLinkedLists(a);
  while(retHead != NULL) {
    printf("Value: %d\n", retHead->value);
    retHead = retHead->next;
  }
  return 0;
}

static char *test_list_mergeLists() {
  List *a = createList();
  List *b = createList();
  int arr_a[] = {5,7,9};
  int arr_b[] = {6,8,10};
  int i = 0;
  for(i = 0; i < 3; i++) {
    appendList(a, arr_a[i]);
  }
  for(i = 0; i < 3; i++) {
    appendList(b, arr_b[i]);
  }
  Node *newHead = createNode();
  newHead = mergeLists(a->head, b->head);
  while(newHead != NULL) {
    printf("Value: %d\n", newHead->value);
    newHead = newHead->next;
  }
  mu_assert("Lists not merged properly", newHead->value == 5); //just checking the head of the list
  return 0;
}

static char *all_tests() {
  mu_run_test_noargs(test_list_mergesort);
  // mu_run_test_noargs(test_list_mergeLists);
  return 0;
}

RUN_TESTS(all_tests);
