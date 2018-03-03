#include <stdio.h>
#include <stdlib.h>
#include "./binary_tree.h"
#define MAXVALUE 100000000

int findMin(int arr[], int beg, int end) {
  int i = 0;
  int min = MAXVALUE;
  for(i = beg; i < end; i++) {
    if(arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

void createTree(int arr[], int beg, int middle, int end, Node *parent) {
  int left_min = findMin(arr, beg, middle);
  int right_min = findMin(arr, middle, end);
  printf("******\n");
  printf("Beginning: %d\n", beg);
  printf("Middle: %d\n", middle);
  printf("End: %d\n", end);
  printf("Left min: %d\n", left_min);
  printf("Right min: %d\n", right_min);
  parent->left = createNode(left_min);
  parent->right = createNode(right_min);
}

void createTreeHelper(int arr[], int beg, int end, Node *parent) {
  //base case
  if(end - beg > 1) {
    int middle = (beg + end) / 2;
    createTree(arr, beg, middle, end, parent);
    createTreeHelper(arr, beg, middle, parent->left);
    createTreeHelper(arr, middle, end, parent->right);
  }
}

int getMin(Node *root, int beg, int end, int arr_size) {
  if(end - beg < 1) {
    return 0;
  }
  int middle = arr_size / 2;
  if(middle >= beg && middle < end) {
    return root->data;
  }
  if(middle >= end) {
    return getMin(root->left, beg, end, middle);
  } else if(middle < beg) {
    return getMin(root->right, beg, end, middle);
  }
}

int main(int argc, char *argv[]) {
  int arr[] = {4, 5, 7, 2, 3, 1, 9, 10};
  Node *root = createNode(1);
  createTreeHelper(arr, 0, 8, root);
  int result = getMin(root, 0, 1, 8);
  printf("Result: %d\n", result);
}
