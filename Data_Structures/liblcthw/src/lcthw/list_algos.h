#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include <stdlib.h>
#include <lcthw/list.h>

typedef int (*List_compare)(const void *a, const void *b);

int List_bubble_sort(List *list, List_compare cmp);

List *Merge(List *list, int begin, int middle, int end, List_compare cmp);

List *TopDownMergeSort(List *list, int begin, int end, List_compare cmp);

List *List_merge_sort(List *list, List_compare cmp);

List *List_insert_sort(List *list, List_compare cmp, char *values[], int NUM_VALUES);

void List_push_custom(List *list, List_compare cmp, void *value);


#endif
