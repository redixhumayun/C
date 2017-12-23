#include "minunit.h"
#include <lcthw/darray.h>

static DArray *array = NULL;
static int *val1 = NULL;
static int *val2 = NULL;

char *test_create() {
  array = DArray_create(sizeof(int), 100);
  mu_assert(array != NULL, "DArray creation failed");
  mu_assert(array->contents != NULL, "Array contents not set properly");
  mu_assert(array->end == 0, "end isn't at the right spot");
  mu_assert(array->element_size == sizeof(int), "element size is wrong");
  mu_assert(array->max == 100, "wrong max length on initial size");

  return NULL;
}

char *test_destroy() {
  DArray_destroy(array);

  return NULL;
}

char *test_new() {
  val1 = DArray_new(array);
  mu_assert(val1 != NULL, "Failed to make a new element");

  val2 = DArray_new(array);
  mu_assert(val2 != NULL, "Failed to make a new element");

  return NULL;
}

char *test_set() {
  DArray_set(array, 0, val1);
  DArray_set(array, 1, val2);

  return NULL;
}

char *test_get() {
  mu_assert(DArray_get(array, 0) == val1, "Wrong first value");
  mu_assert(DArray_get(array, 1) == val2, "Wrong second value");

  return NULL;
}

char *test_remove() {
  mu_assert(DArray_remove(array, 0) == val1, "Wrong first value removed");
  mu_assert(DArray_remove(array, 1) == val2, "Wrong second value removed");

  return NULL;
}

char *test_expand_contract() {
  int old_max = array->max;
  DArray_expand(array);
  mu_assert((unsigned int)array->max == old_max + array->expand_rate, "Wrong size after expand");

  return NULL;
}

char *test_push_pop() {
  int i = 0;
  for(i = 0; i < 1000; i++) {
    int *val = DArray_new(array);
    *val = i * 333;
    DArray_push(array, val);
  }
  // printf("Printing array values\n");
  // for(i = 0; i < 1000; i++) {
  //   printf("%d\n", ((int)(array->contents[i])));
  // }
  // printf("End of printing array values\n");

  mu_assert(array->max == 1000, "Wrong max size");

  for(i = 999; i >= 0; i--) {
    int *val = DArray_pop(array);
    mu_assert(val != NULL, "Shouldn't get a NULL");
    mu_assert(*val == i * 333, "Wrong value");
    DArray_free(val);
  }

  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_create);
  mu_run_test(test_new);
  mu_run_test(test_set);
  mu_run_test(test_get);
  mu_run_test(test_remove);
  mu_run_test(test_expand_contract);
  mu_run_test(test_push_pop);
  mu_run_test(test_destroy);

  return NULL;
}

RUN_TESTS(all_tests);
