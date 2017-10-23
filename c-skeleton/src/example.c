#include <stdio.h>
#include <stdlib.h>
#include "example.h"

int add(int num1, int num2) {
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

int sumArray(int *arr, int length) {
    int sum = 0;
    int i = 0;
    for(i = 0; i < length; i++) {
        sum += *arr++;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    printf("Please enter a number\n");
    int a = 0;
    fscanf(stdin, "%d", &a);
    if(a == 0) {
        printf("Please enter a valid number");
        exit(1);
    }


    printf("Please enter another number\n");
    int b = 0;
    fscanf(stdin, "%d", &b);
    if(b == 0) {
        printf("Please enter a valid number\n");
        exit(1);
    }

    printf("Adding the two numbers: \n");
    printf("%d\n", add(a, b));

    printf("Subtracting the two number: \n");
    printf("%d\n", sub(a, b));

    char *prog = argv[0];
    (void)argc;
    (void)prog;

    return 0;
}