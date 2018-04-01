#include <stdio.h>
#include <stdlib.h>
#include "./binheap.h"

priority_queue *pq_init()
{
    priority_queue *q = malloc(sizeof(*q));
    q->size = 0;
    return q;
}

void print_queue(priority_queue *q)
{
    int i = 0;
    for (i = 1; i <= q->size; i++)
    {
        printf("Value: %d\n", q->arr[i]);
    }
}

void make_heap(priority_queue *q, int *arr, int n)
{
    int i = 0;
    for (i = 1; i < n; i++)
    {
        pq_insert(q, arr[i]);
    }
}

void pq_insert(priority_queue *q, int value)
{
    if (q->size >= PQ_SIZE)
    {
        printf("IndexError: Out of bounds\n");
    }
    else
    {
        q->size += 1;
        q->arr[q->size] = value;
        bubble_up(q, q->size);
    }
}

void bubble_up(priority_queue *q, int p)
{
    if (pq_parent(p) == -1)
    {
        return;
    }
    if (q->arr[p] < q->arr[pq_parent(p)])
    {
        swap(q, p, pq_parent(p));
        printf("After swap\n");
        printf("*******\n");
        print_queue(q);
        bubble_up(q, pq_parent(p));
    }
    return;
}

void bubble_down(priority_queue *q, int p)
{
    int left = pq_left_child(q->arr[p]);
    int right = pq_right_child(q->arr[p]);
    int minChild = -1;
    if(left < right) {
        minChild = left;
    } else {
        minChild = right;
    }
}

void swap(priority_queue *q, int a, int b)
{
    //function to swap a & b
    int temp = q->arr[a];
    q->arr[a] = q->arr[b];
    q->arr[b] = temp;
    return;
}

int pq_parent(int n)
{
    if (n == 1)
    { //this is the root node
        return -1;
    }
    return n / 2;
};

int pq_left_child(int n)
{
    return 2 * n;
}

int pq_right_child(int n)
{
    return (2 * n) + 1;
}

int extract_min(priority_queue *q)
{
    int min = -1;
    if (q->size == 0)
    {
        printf("Empty priority queue\n");
        return -1;
    }
    min = q->arr[1];
    q->arr[1] = q->arr[q->size];
    q->size -= 1;
    bubble_down(q, 1);
    return min;
}

int main(int argc, char *argv[])
{
    priority_queue *q = pq_init();
    int arr[] = {0, 9, 5, 6, 2, 3};
    make_heap(q, arr, 6);
    return 0;
}