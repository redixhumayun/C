#include "./darray.h"
#include <assert.h>

DArray *DArray_create(size_t element_size, size_t initial_max) {
  DArray *array = (DArray *)malloc(sizeof(DArray));
  check_mem(array);
  array->max = initial_max;
  check(array->max > 0, "Initial max must be greater than 0");

  array->contents = calloc(initial_max, sizeof(void *));
  check_mem(array->contents);

  array->end = 0;
  array->element_size = element_size;
  array->expand_rate = DEFAULT_EXPAND_RATE;

  return array;

error:
  if(array) free(array);
  return NULL;
}

void DArray_clear(DArray *array) {
  int i = 0;
  if(array->element_size > 0) {
    for(i = 0; i < array->max; i++) {
      if(array->contents[i] != NULL) {
        free(array->contents[i]);
      }
    }
  }
  return;
}

int DArray_expand(DArray *array) {
  size_t new_size = array->max + array->expand_rate;
  array->max = new_size;
  void *contents = realloc(array->contents, array->max * sizeof(void *));
  check_mem(contents);
  array->contents = &contents;
  return 0;
error:
  return -1;
}

int DArray_contract(DArray *array) {
  return 1;
}

void DArray_destroy(DArray *array) {
  if(array) {
    if(array->contents) free(array->contents);
    free(array);
  }
}

void DArray_clear_destroy(DArray *array) {
  DArray_clear(array);
  if(array->contents) free(array->contents);
  free(array);
}

int DArray_push(DArray *array, void *el) {
    array->contents[array->end] = el;
    array->end++;
    // printf("Value being pushed: %d\n", *(int *)(el));
    // printf("***Printing array***\n");
    // for(int i = 0; i < array->end; i++) {
    //   printf("Printing value: %d\n", *(int *)(array->contents[i]));
    // }
    // printf("***Done printing array***\n");

    if(DArray_end(array) > DArray_max(array)) {
      return DArray_expand(array);
    } else {
      return 0;
    }
}

void *DArray_pop(DArray *array) {
  if(array->end - 1 >= 0) {
    void *el = DArray_remove(array, array->end - 1);
    array->end--;
    return el;
  }
error:
  return NULL;
}
