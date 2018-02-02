#include <stdio.h>
#include "minunit.h"
#include "./list.h"

int tests_run = 0;

static char *test_list_create(List *list) {
    mu_assert("List not created properly", list != NULL);
    return 0;
}

static char *test_list_push(List *list) {
    mu_assert("List values not pushed properly", list->size == 6);
    return 0;
}

static char *test_list_pop(List *list) {
    int num = popList(list);
    mu_assert("List value not popped properly", num == 3);
    mu_assert("List size not reflected properly after pop", list->size == 5);
    return 0;
}

static char *test_list_shift(List *list) {
    shiftList(list);
    mu_assert("List not shifted properly", list->head->value == 5);
    mu_assert("List size not reflected properly after shift", list->size == 4);
    return 0;
}

static char *test_list_insert(List *list) {
    insertNode(list, 10, 1);
    mu_assert("Node not inserted properly", list->size == 5);
    return 0;
}

static char *test_list_delete(List *list) {
    deleteNode(list, 2);
    mu_assert("Node not deleted properly", list->size == 4);
    return 0;
}

static char *test_list_swap(List *list) {
  Node *a = createNode();
  Node *b = createNode();
  a->value = 1;
  b->value = 2;
  swapNodes(a, b);
  mu_assert("Nodes not swapped properly", (a->value == 2 && b->value == 1));
  return 0;
}

static char *test_list_reverse(List *list) {
  reverseList(list, 0);
  mu_assert("List not reversed properly", list->size == 4);
  return 0;
}

static char *test_list_addAtBeg(List *list) {
  addAtBeg(list, 9);
  mu_assert("Value not added properly at beginning", list->head->value == 9);
  return 0;
}

static char *all_tests() {
    List *list = createList();
    int arr[] = {4,5,6,2,1,3};
    int i = 0;
    for(i = 0; i < 6; i++) {
        appendList(list, arr[i]);
    };
    mu_run_test(test_list_create, list);

    mu_run_test(test_list_push, list);
    printf("****\n");
    printf("Printing result of test_list_push\n");
    printList(list);
    printf("****\n");

    mu_run_test(test_list_pop, list);
    printf("****\n");
    printf("Printing result of test_list_pop\n");
    printList(list);
    printf("****\n");

    mu_run_test(test_list_shift, list);
    printf("****\n");
    printf("Printing result of test_list_shift\n");
    printList(list);
    printf("****\n");

    mu_run_test(test_list_insert, list);
    printf("****\n");
    printf("Printing result of test_list_insert\n");
    printList(list);
    printf("****\n");

    mu_run_test(test_list_delete, list);
    printf("****\n");
    printf("Printing result of test_list_delete\n");
    printList(list);
    printf("****\n");

    mu_run_test(test_list_swap, list);
    printf("****\n");
    printf("Printing result of test_list_swap\n");
    printList(list);
    printf("****\n");

    mu_run_test(test_list_reverse, list);
    printf("****\n");
    printf("Printing result of test_list_reverse\n");
    printList(list);
    printf("****\n");

    mu_run_test(test_list_addAtBeg, list);
    printf("****\n");
    printf("Printing result of test_list_addAtBeg\n");
    printList(list);
    printf("****\n");

    return 0;
}

RUN_TESTS(all_tests);
