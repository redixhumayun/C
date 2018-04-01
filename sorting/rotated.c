#include <stdio.h>
#include <stdlib.h>

int findMin(int *, int);
int findNumberOfRotations(int *, int, int);

int findNumberOfRotations(int arr[], int low, int high)
{
    if(arr[0] < arr[high]) {
        return 0;
    }
    int mid = (low + high) / 2;
    if(arr[mid] < arr[high]) {
        //transition lies in left half of array
        if(arr[mid - 1] > arr[mid]) {
            return mid;
        } else {
            findNumberOfRotations(arr, low, mid - 1);
        }
    } else {
        //transition lies in right half of array
        if(arr[mid + 1 ] < arr[mid]) {
            return mid + 1;
        } else {
            findNumberOfRotations(arr, mid + 1, high);
        }
    }
}

int findMin(int arr[], int size)
{
    int k = findNumberOfRotations(arr, 0, size - 1);
    return arr[k];
}

int main(int argc, char *argv[])
{
    int arr = {35, 42, 5, 15, 27, 29};
    int size = 6;
    int result = findMin(arr, size);
    printf("Result: %d\n", result);
}