#include <stdio.h>
#include <stdlib.h>
#include "./dynamic_array.h"

Array *createArray(int capacity) {
    Array *array = malloc(sizeof(Array *));
    array->capacity = capacity;
    array->size = 0;
    void **items = malloc(sizeof(void *) * array->capacity);
    if(items == NULL) {
        exit(1);
    }
    array->items = items;
    return array;
}

void initArray(Array *array, void *pointer) {
    int i = 0;
    array->size = 0;
    while(*(int *)(pointer) != -1) {
        array->items[i] = pointer;
        pointer += sizeof(int);
        array->size++;
        i++;
    }
    array->items[i] = pointer;
    array->size++;
}

void printArray(Array *array) {
    printf("Array size: %d\n", array->size);
    int i = 0;
    for(i = 0; i < array->size - 1; i++) {
        printf("Value at: %d is: %d\n", i, *(int *)(array->items[i]));
    }
}

void doubleArray(Array *array) {
    array->capacity *= 2;
    void **items = realloc(array->items, array->capacity);
    if(items == NULL) {
        exit(1);
    }
    array->items = items;
}

void push(Array *array, void *value) {
    if(array->capacity - array->size == 2) {
        doubleArray(array);
    }
    array->items[array->size - 1] = value;
    int temp = -1;
    void *ptr = &temp;
    array->items[array->size] = ptr;
    array->size++;
}

void *pop(Array *array) {
    void *item = array->items[array->size - 2]; //array->size - 2 to get value before -1
    int end = -1;
    void *ptr = &end;
    array->items[array->size - 1] = ptr;
    array->size--;
    return item;
}

void *get(Array *array, int index) {
    if(index > array->size - 1) {
        printf("Out of bounds exception");
        exit(1);
    }
    void *item = array->items[index];
    return item;
}

void set(Array *array, int index, void *item) {
    if(index > array->size - 1) {
        printf("Out bounds exception");
        exit(1);
    }
    array->items[index] = item;
}

// int main(int argc, char *argv[]) {
//     Array *array = createArray(100);
//     int arr[] = {1,2,3,4,5, -1};
//     initArray(array, &arr);
//     printArray(array);
// }