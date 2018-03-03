#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList/minunit.h"
#include "./hash_table.h"

int tests_run = 0;

static char *test_table_create(Array **table) {
    mu_assert("Hash table not created properly", table != NULL);
    return 0;
}

static char *test_table_init(Array **table) {
    
}