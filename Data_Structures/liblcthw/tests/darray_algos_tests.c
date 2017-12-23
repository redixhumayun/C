#include "./minunit.h"
#include "../src/lcthw/darray.h"
#include "../src/lcthw/darray.c"
#include "../src/lcthw/darray_algos.h"
#include "../src/lcthw/darray_algos.c"

int testcmp(int *a, int *b) {
  return a - b;
}

DArray *create_array() {
  DArray *result = DArray_create(sizeof(int), 5);
  int initial[] = {4,1,3,2,0};

  void *arr = (void *)(malloc(sizeof(void *) * 5));
  int i = 0;
  for(i = 0; i < 5; i++) {
    *(int *)(arr+i) = initial[i];
  }

  for(i = 0; i < 5; i++) {
    printf("Pushing: %d\n", *(int *)(arr+i));
    DArray_push(result, (arr+i));
  }

  return result;
}

int is_sorted(DArray *array) {
  int i = 0;
  int result[] = {0,1,2,3,4};

  for(i = 0; i < DArray_count(array) - 1; i++) {
    if(*(int *)DArray_get(array, i) != result[i]) {
      return 0;
    }
  }
  return 1;
}

void *run_sort_test(int (*func)(DArray *, DArray_compare), const char *name) {
  DArray *array = create_array();

  printf("Testing sorting algorithm: %s\n", name);

  int rc = func(array, (DArray_compare)testcmp);
  if(rc != 0) {
    printf("Test failed\n");
  }
  if(!is_sorted(array)) {
    printf("Array is not sorted\n");
  }

  DArray_destroy(array);
  return NULL;
}

void *test_qsort() {
  return run_sort_test(DArray_qsort, "qsort");
}

char *all_tests() {
  mu_suite_start();
  test_qsort();
}

RUN_TESTS(all_tests);
