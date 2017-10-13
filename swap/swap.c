#include <stdio.h>
#include <stdlib.h>

void swap(int *nums) {
  int temp = *nums;
  int *next = nums + 1;
  *nums = *next;
  *next = temp;
}

int main(int argc, char *argv[]) {
  int array[3] = {1,2};
  printf("Before swapping\n");
  printf("first: %d, second: %d\n", array[0], array[1]);
  swap(array);
  printf("After swapping\n");
  printf("first: %d, second: %d\n", array[0], array[1]);
}
