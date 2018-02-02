#include <stdio.h>
#include "../LinkedList/minunit.h"
#include "./stack.h"
#include "../LinkedList/list.h"


int tests_run = 0;

static char *test_stack_create() {
  List *list = createStack();
  mu_assert("Stack not created properly", list != NULL);
  return 0;
}

static char *test_stack_push(List *list) {
  mu_assert("Data not pushed properly on stack", list->size == 5);
  return 0;
}

static char *test_stack_pop(List *list) {
  int value = pop(list);
  mu_assert("Correct value not popped", value == 6);
  return 0;
}

static char *test_stack_peek(List *list) {
  int value = peek(list);
  mu_assert("Last value is not correctly peeked", value == 1);
  mu_assert("Value should not be removed", list->size == 4);
  return 0;
}

static char *all_tests() {
  mu_run_test_noargs(test_stack_create);

  List *list = createStack();
  int arr[] = {3,5,2,1,6};
  int i = 0;
  for(i = 0; i < 5; i++) {
    push(list, arr[i]);
  }
  mu_run_test(test_stack_push, list);
  mu_run_test(test_stack_pop, list);
  mu_run_test(test_stack_peek, list);
  return 0;
}

RUN_TESTS(all_tests);
