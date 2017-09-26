#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*compare_cb)(int a, int b);

void die(char *message) {
    printf("%s\n", message);
    exit(1);
}

int sorted_order(int a, int b) {
    return a - b;
}

int *bubble_sort(int *numbers, int count, compare_cb cmp) {
    int temp = 0;
    int i = 0; 
    int j = 0;
    int *target = malloc(count * sizeof(int));
    if(!target) {
        die("Memory error");
    }
    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count-1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }
    return target;
}

int test_sorting(int *numbers, int count, compare_cb cmp) {
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);
    for(i = 0; i < count; i++) {
        printf("%d\n", sorted[i]);
    }
    free(sorted);
    return 0;
}

int main(int argc, char *argv[]) {
    int count = argc - 1;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) {
        die("Memory error");
    }
    for(int i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }
    test_sorting(numbers, count, sorted_order);
    free(numbers);
    return 0;
}