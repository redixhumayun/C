#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./binary_tree.h"

Node *createNode(int data) {
    Node *node = malloc(sizeof(*node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(Node *root, Node *node) {
    if(root == NULL) {
        printf("The root of the tree cannot be null");
        exit(1);
    }
    if(node->data <= root->data) {
        if(root->left == NULL) {
            root->left = node;
        } else {
            insertNode(root->left, node);
        }
    } else {
        if(root->right == NULL) {
            root->right = node;
        } else {
            insertNode(root->right, node);
        }
    }
}

void inOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("Value: %d\n", root->data);
    inOrder(root->right);
}

void postOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("Value: %d\n", root->data);
}

void deleteNode(Node *node) {
    free(node->left);
    free(node->right);
    free(node);
}

Node *findNode(Node *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == data) {
        return root;
    }
    if(data <= root->data) {
        return findNode(root->left, data);
    } else {
        return findNode(root->right, data);
    }
}

int findTreeCount(Node *root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + findTreeCount(root->left) + findTreeCount(root->right);
}

int findLongestPath(Node *root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + (MAX(findLongestPath(root->left), findLongestPath(root->right)));
}

bool hasPathSum(Node *root, int value) {
    if(root == NULL) {
        return (value == 0);
    }
    int subSum = value - root->data;
    return (hasPathSum(root->left, subSum) || hasPathSum(root->right, subSum));
}

void printPathsHelper(Node *root, int path[], int pathLen) {
    if(root == NULL) {
        return;
    }
    path[pathLen] = root->data;
    pathLen++;
    if(root->left == NULL && root->right == NULL) {
        int i = 0;
        printf("The path is\n");
        for(i = 0; i < pathLen; i++) {
            printf("%d\n", path[i]);
        }
        printf("The path length is: %d\n", pathLen);
        printf("*******\n");
    } else {
        printPathsHelper(root->left, path, pathLen);
        printPathsHelper(root->right, path, pathLen);
    }
    return;
}

void printPaths(Node *root) {
    int path[1000];
    int pathLen = 0;
    printPathsHelper(root, path, pathLen);
    return;
}

void mirror(Node *root) {
    if(root == NULL) {
        return;
    }
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
    return;
}

void doubleTree(Node *root) {
    if(root == NULL) {
        return;
    }
    doubleTree(root->left);
    doubleTree(root->right);
    if(root->left == NULL) {
        root->left = createNode(root->data);
    }
    else {
        Node *temp = root->left;
        root->left = createNode(root->data);
        root->left->left = temp;
    }
    return;
}

int sameTree(Node *root_a, Node *root_b) {
    if(root_a == NULL && root_b == NULL) {
        return true;
    }
    else if(root_a != NULL & root_b != NULL) {
        return (
            root_a->data == root_b->data &&
            sameTree(root_a->left, root_b->left) &&
            sameTree(root_a->right, root_b->right)
        );
    } else {
        return false;
    }
}

// int main (int argc, char *argv[]) {
//     Node *root = createNode(2);
//     int arr[] = {1, 3};
//     int i = 0;
//     int size = 2;
//     for(i = 0; i < size; i++) {
//         Node *node = createNode(arr[i]);
//         insertNode(root, node);
//     }
//     Node *root_2 = createNode(2);
//     int arr_2[] = {1, 3};
//     i = 0;
//     for(i = 0; i < size; i++) {
//         Node *node = createNode(arr_2[i]);
//         insertNode(root_2, node);
//     }
//     int result = sameTree(root, root_2);
//     printf("Result: %d\n", result);
//     return 0;
// }
