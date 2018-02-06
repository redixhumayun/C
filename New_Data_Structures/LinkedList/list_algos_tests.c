#include <stdio.h>
#include <stdlib.h>

#include "./list.h"
#include "./list_algos.h"
#include "./minunit.h"

int tests_run = 0;

static char *test_list_mergesort() {
  List *a = createList();
  List *b = createList();
  List *c = createList();
  int arr_a[] = {6,5,3,11,9};
  int i = 0;
  for(i = 0; i < 5; i++) {
    appendList(a, arr_a[i]);
  }
  int arr_b[] = {8,4,6,7,2,12};
  for(i = 0; i < 6; i++) {
    appendList(b, arr_b[i]);
  }
  mergeLinkedLists(a, b, c);
  return 0;
}

static char *test_list_mergeLists() {
  List *a = createList();
  List *b = createList();
  int arr_a[] = {1,2,3};
  int arr_b[] = {4,5,6};
  int i = 0;
  for(i = 0; i < 3; i++) {
    appendList(a, arr_a[i]);
  }
  for(i = 0; i < 3; i++) {
    appendList(b, arr_b[i]);
  }
  Node *newHead = createNode();
  newHead = mergeLists(a->head, b->head);
  mu_assert("Lists not merged properly", newHead->value == 1); //just checking the head of the list
  return 0;
}

static char *all_tests() {
  // mu_run_test_noargs(test_list_mergesort);
  mu_run_test_noargs(test_list_mergeLists);
  return 0;
}

RUN_TESTS(all_tests);
