#include "ex22.h"
#include <stdio.h>
#include <stdlib.h>

const char *MY_NAME = "Zaid Humayun";

void scope_demo(int count) {
    printf("Count is: %d\n", count);

    if(count > 10) {
        int count = 100;

        printf("Count in this scope is: %d\n", count);
    } 

    printf("Count at exit is: %d\n", count);

    count = 3000;

    printf("Count after assign: %d\n", count);
}

int main(int argc, char *argv[]) {
    printf("My name is: %s, age: %d\n", MY_NAME, get_age());

    set_age(100);

    printf("My age is now: %d\n", get_age());

    printf("The size is: %d\n", THE_SIZE);
    print_size();

    THE_SIZE = 9;

    printf("THE_SIZE is now: %d\n", THE_SIZE);
    print_size();

    printf("Ratio at first: %f\n", update_ratio(2.0));
    printf("Ratio again: %f\n", update_ratio(10.0));
    printf("Ration once more: %f\n", update_ratio(300.0));

    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);

    printf("Count after calling scope_demo: %d\n", count);

    return 0;
}