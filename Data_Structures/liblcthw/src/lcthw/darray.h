#ifndef _DArray_h
#define _DArray_h
#include <stdlib.h>
#include <assert.h>
#include <lcthw/dbg.h>

typedef struct DArray {
  int end;
  int max;
  size_t element_size;
  size_t expand_rate;
  void **contents;
} DArray;

DArray *DArray_create(size_t element_size, size_t initial_max);

void DArray_Destroy(DArray *array);

void DArray_clear(DArray *array);

void DArray_expand(DArray *array);

int DArray_push(DArray *array, void *el);

void *DArray_pop(DArray *array);

void DArray_clear_destroy(DArray *array);

#define DArray_last(A) ((A)->contents[(A)->end - 1])
#define 
