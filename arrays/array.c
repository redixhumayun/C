#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arvgv[]) {
    int arr[] = {1,2,3,4};
    int *p[4];
    int i = 0;
    for(i = 0; i < 4; i++) {
        p[i] = &arr[i];
    }
    for(i = 0; i < 4; i++) {
        printf("Value: %u\n", p[i]);
    }
}