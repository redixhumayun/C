#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int s[], int n);
void swap(int *, int *);
void print_array(int *, int);

void print_array(int *p, int n) {
    int i = 0;
    for(i = 0; i < n; i++) {
        printf("Value: %d\n", *(p+i));
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void insertion_sort(int s[], int n) {
    int j = 0;
    int i = 0;
    for(i = 1; i < n; i++) {
        j = i;
        while((j > 0) && (s[j] < s[j-1])) {
            swap(&s[j], &s[j-1]);
            j--;
        }
    }   
}

int main(int argc, char *argv[]) {
    int arr[] = {9,5,2,1,8};
    insertion_sort(arr, 5);
    print_array(arr, 5);
}