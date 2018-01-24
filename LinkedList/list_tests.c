#include <stdio.h>
#include "minunit.h"
#include "./list.h"

int tests_run = 0;

static char *test_list_create(List *list) {
    mu_assert("List not created properly", list != NULL);
    return 0;
}

static char *test_list_push(List *list) {
    // List *list = createList();
    // int arr[] = {1,2,3,4};
    // int i = 0;
    // for(i = 0; i < 4; i++) {
    //     appendList(list, arr[i]);
    // }
    mu_assert("List values not pushed properly", list->size == 4);
    return 0;
}

static char *test_list_pop(List *list) {
    // List *list = createList();
    // int arr[] = {4,5,6,2,1,3};
    // int i = 0;
    // for(i = 0; i < 6; i++) {
    //     appendList(list, arr[i]);
    // }
    int num = popList(list);
    mu_assert("List value not popped properly", num == 3);
    return 0;
}

static char *all_tests() {
    List *list = createList();
    int arr[] = {4,5,6,2,1,3};
    int i = 0;
    for(i = 0; i < 6; i++) {
        appendList(list, arr[i]);
    };
    mu_run_test(test_list_create, list);
    mu_run_test(test_list_push, list);
    mu_run_test(test_list_pop, list);
    return 0;
}

int main(int argc, char *argv[]) {
    char *result = all_tests();
    printf("Tests run: %d\n", tests_run);
    printf("result: %s\n", result);
    return result != 0;
}