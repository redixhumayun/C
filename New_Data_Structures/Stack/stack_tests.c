#include <stdio.h>
#include "../LinkedList/minunit.h"
#include "./stack.h"


int tests_run = 0;

static char *test_stack_create() {
  List *list = createStack();
  mu_assert("Stack not created properly", list != NULL);
  return 0;
}

static char *all_tests() {
  mu_run_test_noargs(test_stack_create);
  return 0;
}

RUN_TESTS(all_tests);
