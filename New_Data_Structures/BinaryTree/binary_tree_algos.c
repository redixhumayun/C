#include <stdio.h>
#include <stdlib.h>
#include "./binary_tree.h"
#define MAXdata 100000000

int findMin(int arr[], int beg, int end) {
  int i = 0;
  int min = MAXdata;
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

//function to check whether two binary trees are identical
int checkSameTrees(Node *root_1, Node *root_2) {
  //both are empty
  if(root_1 == NULL && root_2 == NULL) {
    return 1;
  }
  //both are not empty
  else if(root_1 != NULL && root_2 != NULL) {
    return (
      root_1->data == root_2->data &&
      checkSameTrees(root_1->left, root_2->left) && 
      checkSameTrees(root_1->right, root_2->right)
    );
  }
  //one is empty and one is not
  else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int arr[] = {4, 5, 7, 2, 3, 9, 10};
  int arr_2[] = {2,4,5,7};
  Node *root_1 = createNode(1);
  Node *root_2 = createNode(1);
  int i = 0;
  for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    insertNode(root_1, createNode(arr[i]));
  }
  for(i = 0; i < sizeof(arr_2) / sizeof(arr_2[0]); i++) {
    insertNode(root_2, createNode(arr_2[i]));
  }
  int result = checkSameTrees(root_1, root_2);
  printf("Value: %d\n", result);
}
