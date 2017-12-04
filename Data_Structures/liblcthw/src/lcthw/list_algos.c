#include <lcthw/list_algos.h>
#include <lcthw/dbg.h>

void ListNode_swap(ListNode *a, ListNode *b) {
  char *temp = a->value;
  a->value = b->value;
  b->value = temp;
}

int List_bubble_sort(List *list, List_compare cmp) {
  int sorted = 0;
  do {
    sorted = 1;
    LIST_FOREACH(list, first, next, curr) {
      if(curr->next) {
        int ret = cmp(curr->value, curr->next->value);
        if(ret > 0) {
          ListNode_swap(curr, curr->next);
          sorted = 0;
        }
      }
    }
  } while(!sorted);
  return 0;
}

List *Merge(List *list, int begin, int middle, int end, List_compare cmp) {
  List *left = List_create();
  List *right = List_create();
  List *result = List_create();

  int n1 = middle - begin + 1; //this is the index first half of the array
  int n2 = end - middle; // this is the index second half of the array

  //Creating the left half of the list
  ListNode *node = list->first;
  int i = 0;
  while(node != NULL && i < n1) {
    List_push(left, node->value);
    node = node->next;
    i++;
  }
  //Done creating the left half of the list

  //Creating the right half of the list (Assuming node is at the correct position)
  int j = 0;
  while(node != NULL && j < n2) {
    List_push(right, node->value);
    node = node->next;
    j++;
  }
  //Done creating the right half of the list

  //Run through both lists and add it to result
  i = 0, j = 0;
  //grab first nodes from both left and right lists
  ListNode *l = left->first;
  ListNode *r = right->first;

  printf("Printing left list\n");
  ListNode *curr = left->first;
  while(curr != NULL) {
    printf("%s\n", curr->value);
    curr = curr->next;
  }
  printf("Done printing left list\n");

  printf("Printing right list\n");
  curr = right->first;
  while(curr != NULL) {
    printf("%s\n", curr->value);
    curr = curr->next;
  }
  printf("Done printing right list\n");

  while(i < n1 && j < n2) {
    if(cmp(l->value, r->value) <= 0) {
      List_push(result, l->value);
      l = l->next;
      i++;
    } else {
      List_push(result, r->value);
      r = r->next;
      j++;
    }
  }

  while(l != NULL && i < n1) {
    List_push(result, l->value);
    l = l->next;
    i++;
  }
  while(r != NULL && j < n2) {
    List_push(result, r->value);
    r = r->next;
    j++;
  }

  printf("result after this iteration: \n");
  LIST_FOREACH(result, first, next, cur) {
    printf("%s\n", cur->value);
  }
  return result;
}

List *TopDownMergeSort(List *list, int begin, int end, List_compare cmp) {
  if(begin < end) {
    int middle = (begin + end) / 2;
    TopDownMergeSort(list, begin, middle, cmp);
    TopDownMergeSort(list, middle+1, end, cmp);
    return Merge(list, begin, middle, end, cmp);
  }
}

List *List_merge_sort(List *list, List_compare cmp) {
  List *result = List_create();
  List *res = TopDownMergeSort(list, 0, List_count(list), cmp);
  return res;
}

void List_push_custom(List *list, List_compare cmp, void *value) {
  printf("Entering value: %s\n", value);
  ListNode *node = calloc(1, sizeof(ListNode));
  node->value = value;

  if(list->first == NULL) {
    list->first = node;
    list->last = node;
    List_print(list);
    return;
  }

  //iterate over list to find where to insert given value
  int swap_flag = 0;
  LIST_FOREACH(list, first, next, cur) {
    if(cmp(cur->value, node->value) > 0) { //cur is greater than value
      swap_flag = 1;
      ListNode *temp = cur->next;
      cur->next = node;
      node->prev = cur;
      node->next = temp;
      ListNode_swap(cur, node);
    }
  }

  if(swap_flag == 0) { //insert value in the last position
    printf("Need to insert: %s\n", node->value);
    printf("The last value is: %s\n", list->last->value);
  }

  List_print(list);
  return;
}

List *List_insert_sort(List *list, List_compare cmp, char *values[], int NUM_VALUES) {
  int i = 0;
  for(i = 0; i < NUM_VALUES; i++) {
    List_push_custom(list, cmp, values[i]);
  }
  return list;
}
