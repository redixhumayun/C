#ifndef _Dynamic_Array_h_
#define _Dynamic_Array_h_

typedef struct Array {
    int capacity;
    int size;
    void **items;
} Array;

Array *createArray(int capacity);
void initArray(Array *, void *);
void printArray(Array *);
void doubleArray (Array *);
void checkCapacity(Array *);
void push(Array *, void *);
void *pop(Array *);
void *get(Array *, int);
void set(Array *, int, void *);

#endif
