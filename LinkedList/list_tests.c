#include <stdio.h>
#include "minunit.h"
#include "./list.h"

int tests_run = 0;

static char *test_list_create() {
    List *list = createList();
    mu_assert("List not created properly", list != NULL);
    return 0;
}

static char *test_list_push() {
    List *list = createList();
    int arr[] = {1,2,3,4};
    int i = 0;
    for(i = 0; i < 4; i++) {
        appendList(list, arr[i]);
    }
    mu_assert("List values not pushed properly", list->size != 4);
}

static char *all_tests() {
    mu_run_test(test_list_create);
    mu_run_test(test_list_push);
    return 0;
}

int main(int argc, char *argv[]) {
    char *result = all_tests();
    printf("Tests run: %d\n", tests_run);
    return result != 0;
}