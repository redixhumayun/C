#include <stdio.h>
#include "../LinkedList/minunit.h"
#include "./queue.h"
#include "../LinkedList/list.h"

int tests_run = 0;

static char *test_queue_create() {
  List *list = createQueue();
  mu_assert("Queue not created properly", list != NULL);
  return 0;
}

static char *test_queue_enqueue(List *queue) {
  enqueue(queue, 9);
  mu_assert("Queue value not added correctly", queue->tail->value == 9);
  return 0;
}

static char *test_queue_dequeue(List *queue) {
  int num = dequeue(queue);
  mu_assert("Queue not dequeued correctly", num == 5);
  return 0;
}

static char *test_queue_front(List *queue) {
  int num = front(queue);
  mu_assert("Queue front not retrieved properly", num == 1);
  return 0;
}

static char *test_queue_rear(List *queue) {
  int num = rear(queue);
  mu_assert("Queue rear not retrieved properly", num ==9);
  return 0;
}

static char *all_tests() {
  mu_run_test_noargs(test_queue_create);
  List *queue = createQueue();
  int arr[] = {5,1,2,6,3};
  int i = 0;
  for(i = 0; i < 5; i++) {
    enqueue(queue, arr[i]);
  }
  mu_run_test(test_queue_enqueue, queue);
  mu_run_test(test_queue_dequeue, queue);
  mu_run_test(test_queue_front, queue);
  mu_run_test(test_queue_rear, queue);
  return 0;
}

RUN_TESTS(all_tests);
