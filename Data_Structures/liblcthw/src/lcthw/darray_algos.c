#include "./darray_algos.h"
#include <stdlib.h>

int DArray_qsort(DArray *array, DArray_compare cmp) {
  quicksort(array->contents, DArray_count(array), sizeof(void *), cmp);
  return 0;
}

int DArray_heapsort(DArray *array, DArray_compare cmp) {
  hsort(array->contents, DArray_count(array), sizeof(void *), cmp);
  return 0;
}

int DArray_mergesort(DArray *array, DArray_compare cmp) {
  return mergesort(array->contents, DArray_count(array), sizeof(void *), cmp);
}

void quicksort(void *contents, int count, size_t elem, DArray_compare cmp) {
  int i = 0;
  return;
}

void hsort(void *contents, int count, size_t elem, DArray_compare cmp) {
  return;
}

void msort(void *contents, int count, size_t elem, DArray_compare cmp) {
  return;
}
