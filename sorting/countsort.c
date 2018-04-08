#include <stdio.h>
#include <stdlib.h>

void count_sort(int *, int, int);

void count_sort(int arr[], int size, int range) {
    int *count = malloc(sizeof(int) * (range + 1));
    int i = 0;
    //initialize count array
    for(i = 0; i <= (range+1); i++) {
        count[i] = 0;
    }

    //increment count array to correct values
    for(i = 0; i < size; i++) {
        ++count[arr[i]];
    }

    //consecutively sum up count array
    for(i = 1; i < (range+1); i++) {
        count[i] += count[i-1];
    }  

    printf("Printing count array\n");
    //print count array
    for(i = 0; i < (range + 1); i++) {
        printf("Value: %d\n", count[i]);
    }

    //create output array and initialize it
    int *output = malloc(sizeof(int) * (size));
    for(i = 0; i < size; i++) {
        output[i] = 0;
    }

    //set output to correct values
    for(i = 0; i < (range+1); i++) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    //print output array
    printf("Printing output array\n");
    for(i = 0; i < size; i++) {
        printf("Value: %d\n", output[i]);
    }

    return;
}

int main(int argc, char *argv[]) {
    int arr[] = { 1, 4, 1, 2, 7, 5, 2 };
    int size = 7;
    count_sort(arr, size, 7);
}
