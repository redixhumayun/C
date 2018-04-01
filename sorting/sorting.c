#include <stdio.h>
#include <stdlib.h>

void quick_sort(int s[], int n);
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

int findPivot(int s[], int n) {
    int min = 1000;
    int i = 0;
    //find the smallest positive number in the array and use that as the pivot
    for(i = 0; i < n; i++) {
        if(s[i] > 0 && s[i] < min) {
            min = s[i];
        }
    }
    return min;
}

void quick_sort(int s[], int n) {
    int pivot = findPivot(s, n);
    int i = 0;
    int j = n - 1;
    while(i < j) {
        if(s[i] < pivot) {
            i++;
        }
        if(s[j] > pivot) {
            j--;
        }
        if(s[i] >= pivot && s[j] < pivot) {
            swap(&s[i], &s[j]);
            i++;
            j--;
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    int arr[] = {7, 3, 8, -1, -9, 11, -15};
    quick_sort(arr, 7);
    print_array(arr, 7);
}