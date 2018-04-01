#include <stdio.h>
#include <stdlib.h>
#include "./quicksort.h"

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
    return;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; //pick rightmost element as pivot
    int i = low - 1;
    int j = 0;
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void swap(int *arr, int i, int j)
{
    int temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;
    return;
}

void printArray(int arr[], int size) {
    int i = 0;
    for(i = 0; i < size; i++) {
        printf("Value: %d\n", arr[i]);
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    quicksort(arr, 0, 6);
    printArray(arr, 7);
    return 0;
}