#ifndef _binary_tree_h
#define _binary_tree_h

#include <stdio.h>
#include <stdlib.h> 

#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#define MIN(x, y) ((x) < (y)) ? (y) : (x)

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
} Node;

Node *createNode(int);
void insertNode(Node *, Node *);
void deleteNode(Node *);
void inOrder(Node *);
void postOrder(Node *);
Node *findNode(Node *, int);
int findTreeCount(Node *);
int longestPath(Node *);
bool hasPathSum(Node *, int);
void printPaths(Node *);
void printPathsHelper(Node *, int [], int);

#endif