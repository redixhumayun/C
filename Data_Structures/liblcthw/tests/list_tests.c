#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

static List *list = NULL;
char *test1 = "test 1 data";
char *test2 = "test 2 data";
char *test3 = "test 3 data";

char *test_create() {
  printf("Running test_create\n");
  list = List_create();
  mu_assert(list != NULL, "Failed to create list.");

  return NULL;
}

char *test_push_pop() {
  printf("Running test_push_pop\n");
  List_push(list, test1);
  mu_assert(List_last(list) == test1, "Wrong last value");

  List_push(list, test2);
  mu_assert(List_last(list) == test2, "Wrong last value");

  List_push(list, test3);
  mu_assert(List_last(list) == test3, "Wrong last value");
  mu_assert(List_count(list) == 3, "Wrong value on push");

  char *val = List_pop(list);
  mu_assert(val == test3, "Wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == test2, "Wrong value on pop");

  val = List_pop(list);
  mu_assert(val == test1, "Wrong value on pop");
  mu_assert(List_count(list) == 0, "Wrong count after pop");

  return NULL;
}

char *test_shift() {
  printf("Running test_shift\n");
  List_shift(list, test1);
  mu_assert(List_first(list) == test1, "Wrong first value");

  List_shift(list, test2);
  mu_assert(List_first(list) == test2, "Wrong first value");

  List_shift(list, test3);
  mu_assert(List_first(list) == test3, "Wrong first value");
  mu_assert(List_count(list) == 3, "Wrong count on shift");

  return NULL;
}

char *test_remove() {
  printf("Running test_remove\n");
  char *val = List_remove(list, list->first->next);
  mu_assert(val == test2, "Removed wrong element");
  mu_assert(List_count(list) == 2, "Wrong count after remove");
  mu_assert(List_first(list) == test3, "Wrong first after remove");
  mu_assert(List_last(list) == test1, "Wrong last after remove");
}

char *test_unshift() {
  printf("Running test_unshift\n");
  char *val = List_unshift(list);
  mu_assert(val == test3, "Wrong value on unshift first");

  val = List_unshift(list);
  mu_assert(val == test2, "Wrong value on unshift second");
  mu_assert(List_count(list) == 1, "Wrong count after unshift");

  return NULL;
}

char *test_destroy() {
  printf("Running test_destroy\n");
  List_clear_destroy(list);

  return NULL;
}

char *all_tests() {
  printf("Running all_tests\n");
  mu_suite_start();

  mu_run_test(test_create);
  mu_run_test(test_push_pop);
  mu_run_test(test_shift);
  // mu_run_test(test_remove);
  mu_run_test(test_unshift);
  mu_run_test(test_destroy);

  return NULL;
}

RUN_TESTS(all_tests);
