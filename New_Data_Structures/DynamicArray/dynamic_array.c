#include <stdio.h>
#include <stdlib.h>
#include "./dynamic_array.h"

Array *createArray(int capacity) {
    Array *array = malloc(sizeof(Array));
    if(array == NULL) {
        exit(1);
    }
    array->capacity = capacity;
    array->size = 0;
    void **items = malloc(sizeof(void *) * array->capacity *  sizeof *items);
    if(items == NULL) {
        exit(1);
    }
    array->items = items;
    return array;
}

void initArray(Array *array, void *pointer) {
    //first check the length of the array
    int length = 0;
    void *temp = pointer;
    while(*(int *)(temp) != -1) {
        length++;
        temp++;
    }
    if(length > array->capacity) {
        doubleArray(array);
    }
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
    void **items = realloc(array->items, array->capacity * sizeof *items);
    if(items == NULL) {
        exit(1);
    }
    array->items = items;
}

void push(Array *array, void *value) {
    if(array->capacity - array->size == 2) {
        doubleArray(array);
    }
    printf("String: %s\n", (char *)(value));
    void *temp = array->items[array->size - 1];
    array->items[array->size - 1] = value;
    array->items[array->size] = temp;
    array->size++;
}

void *pop(Array *array) {
    void *item = array->items[array->size - 2]; //array->size - 2 to get value before -1
    void *temp = array->items[array->size - 1];
    array->items[array->size - 2] = temp;
    array->size--;
    return item;
}

void *get(Array *array, int index) {
    if(index >= array->size - 1) {
        printf("Out of bounds exception");
        exit(1);
    }
    void *item = array->items[index];
    return item;
}

void set(Array *array, int index, void *item) {
    if(index >= array->size - 1) {
        printf("Out of bounds exception");
        exit(1);
    }
    array->items[index] = item;
}