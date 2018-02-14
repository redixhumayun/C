#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList/minunit.h"
#include "./dynamic_array.h"

int tests_run = 0;

static char *test_array_create(Array *array) {
    mu_assert("Array not created properly", array != NULL);
    return 0;
}

static char *test_array_initArray(Array *array) {
    int arr[] = {5,6,2,4,1, -1};
    initArray(array, &arr);
    mu_assert("Array does not contain requisite number of elements", array->size == 6);
    return 0;
}

static char *test_array_push(Array *array) {
    int arr[] = {5,6,2,4,1, -1};
    initArray(array, &arr);
    int value = 10;
    void *ptr = &value;
    push(array, ptr);
    mu_assert("Array value not pushed properly", *(int *)(array->items[array->size - 2]) == 10);
    return 0;
}

static char *test_array_pop(Array *array) {
    int arr[] = {5,6,2,4,1, -1};
    initArray(array, &arr);
    void *ptr = pop(array);
    mu_assert("Array value not popped properly", *(int *)ptr == 1);
    mu_assert("Size not updated properly", array->size == 5);
    return 0;
}

static char *test_array_get(Array *array) {
    int arr[] = {5,6,2,4,1, -1};
    initArray(array, &arr);
    void *ptr = get(array, 2);
    mu_assert("Array value not got properly", *(int *)(ptr) == 2);
    return 0;
}

static char *test_array_set(Array *array){
    int arr[] = {5,6,2,4,1, -1};
    initArray(array, &arr);
    int num = 11;
    void *ptr = &num;
    int index = 1;
    set(array, index, ptr);
    int valueToCheck = *(int *)(array->items[index]);
    mu_assert("Array value not set properly", valueToCheck == num);
    return 0;
}

static char *test_array_massiveValueTest(Array *array) {
    int arr[] = {5,6,2,4,1, -1};
    initArray(array, &arr);
    int i = 0;
    for(i = 0; i < 100; i++) {
        void *ptr = &i;
        push(array, ptr);
    }
    mu_assert("Massive value test failed", array->size == 106);
    return 0;
}

static char *all_tests() {
    Array *array = createArray(10);
    mu_run_test(test_array_create, array);
    mu_run_test(test_array_initArray, array);
    mu_run_test(test_array_push, array);
    mu_run_test(test_array_pop, array);
    mu_run_test(test_array_get, array);
    mu_run_test(test_array_set, array);
    mu_run_test(test_array_massiveValueTest, array);
    return 0;
}

RUN_TESTS(all_tests);

