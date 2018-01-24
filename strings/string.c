#include <stdio.h>
#include <stdlib.h>

void print_strings(char *ptr);
void swap(char **a, char **b);

int main(int argc, char *argv[]) {
    char *arr[] = {
        "Akshay", 
        "Bharath", 
        "Rajath", 
        "Parth", 
        "Zaid"
    };
    int i = 0;
    for(i = 0; i < 5; i++) {
        print_strings(arr[i]);
    }
    printf("*******\n");
    swap(&arr[1], &arr[2]);
    for(i = 0; i < 5; i++) {
        print_strings(arr[i]);
    }
}

void swap(char **a, char **b) {
    // printf("%u\n", a);
    // printf("%u\n", b);
    char *temp = malloc(sizeof(char *));
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void print_strings(char *ptr) {
    int j = 0;
    while(*(ptr + j) != '\0') {
        printf("%c", *(ptr + j));
        j++;
    }
    printf("\n");
    return;
}
