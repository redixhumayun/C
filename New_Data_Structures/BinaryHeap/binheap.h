#ifndef _binheap_h
#define _binheap_h

#define PQ_SIZE 10

typedef struct priority_queue {
    int arr[PQ_SIZE + 1];
    int size;
} priority_queue;

priority_queue *pq_init();
void make_heap(priority_queue *, int *, int);
int pq_parent(int);
int pq_left_child(int);
int pq_right_child(int);
void pq_insert(priority_queue *, int);
void bubble_up(priority_queue *, int);
void bubble_down(priority_queue *, int);
void swap(priority_queue *, int, int);
void print_queue(priority_queue *);
int extract_min(priority_queue *);

#endif