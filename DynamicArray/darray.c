#include <stdlib.h>
#include <stdio.h>
#include "./darray.h"

int testcmp (int a, int b) {
  return (a-b);
}

DArray *DArray_create(int capacity) {
  DArray *array = (DArray *)malloc(sizeof(DArray)); //this is the dynamic array struct
  array->size = 0;
  array->capacity = capacity;
  array->end = 0;
  void *arr = malloc(capacity * sizeof(*arr));
  array->contents = arr;
  return array;
}

void DArray_push(DArray *array, int el) {
  array->contents[array->end] = el;
  array->end++;
  return;
}

int DArray_pop(DArray *array) {
  int el;
  if(array->end - 1 >= 0) {
    el = array->contents[array->end - 1];
    array->contents[array->end] = 0;
    array->end--;
    return el;
  }
  return 0;
}

void DArray_print(DArray *array) {
  int i = 0;
  for(i = 0; i < array->end; i++) {
    printf("Value: %d\n", array->contents[i]);
  }
}

void DArray_qsort(DArray *array) {
  quicksort(array->contents, 0, array->end - 1);
}

void DArray_msort(DArray *array) {
  msort(array->contents, 0, array->end - 1);
}

void msort(int *contents, int low, int high) {
  int mid = (low + high) / 2;
  if(low < high) {
    msort(contents, low, mid);
    msort(contents, mid+1, high);
    merge(contents, low, mid, high);
  }
}

void merge(int *contents, int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;

  //initializing two temp arrays here
  int left[n1];
  int right[n2];

  int i = 0;
  for(i = 0; i < n1; i++) {
    left[i] = contents[i];
  }
  for(i = 0; i < n2; i++) {
    right[i] = contents[i+n1];
  }

  i = 0;
  int j = 0;
  int k = 0;

  while(i < n1 && j < n2) {
    if(left[i] < right[j]) {
      contents[k] = left[i];
      i++;
    } else {
      contents[k] = right[j];
      j++;
    }
    k++;
  }

  while(i < n1) {
    contents[k] = left[i];
    i++;
    k++;
  }

  while(j < n2) {
    contents[k] = right[j];
    j++;
    k++;
  }
}

void quicksort(int *contents, int low, int high) {
  int pi;
  if(low < high) {
    pi = partition(contents, low, high);
    quicksort(contents, low, pi - 1);
    quicksort(contents, pi+1, high);
  }
}

int partition(int *contents, int low, int high) {
  int j = low;
  int i = low - 1;
  int pivot = contents[high];
  for(j = low; j <= high - 1; j++) {
    if(contents[j] < pivot) {
      i++;
      swap(contents, i, j);
    }
  }
  swap(contents, i+1, high);
  return (i+1);
}

void swap(int *arr, int index_1, int index_2) {
  int temp = arr[index_1];
  arr[index_1] = arr[index_2];
  arr[index_2] = temp;
}

int main(int argc, char *argv[]) {
  DArray *array = DArray_create(5);
  int i = 0;
  int initial[] = {4,5,2,1,3};
  for(i = 0; i < 5; i++) {
    DArray_push(array, initial[i]);
  }
  DArray_msort(array);
  DArray_print(array);
}
