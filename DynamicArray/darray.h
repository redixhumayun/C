#include <stdlib.h>

typedef struct DArray {
  int size;
  int capacity;
  int *contents;
  int end;
} DArray;


DArray *DArray_create(int capacity);
void DArray_push(DArray *array, int el);
int DArray_pop(DArray *array);
void DArray_print(DArray *array);

void swap(int *contents, int index_1, int index_2);

void DArray_qsort(DArray *array);
void quicksort(int *contents, int low, int high);
int partition(int *contents, int low, int high);

void DArray_msort(DArray *array);
void msort(int *contents, int low, int high);
void merge(int *result, int low, int mid, int high);

int DArray_binarySearch(DArray *array, int toFind);
int binarySearch(int *contents, int low, int high, int toFind);
