#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "GenericLinkedList.h"

#define MAX_STR 32
#define C_OK    0
#define C_NOK   -1


static void test_gll_add();
static void test_gll_remove();
static void test_gll_get();
static void test_gll_push();
static void test_gll_pushFront();
static void test_gll_pop();

static void test_gll_each();
static void test_gll_eachReverse();

void each_test_function(void *);

//Global variables
int each_a;
int each_b;
int each_c;
LinkedListType *each_list;


int main(int argc, char *argv) {
  printf("Running tests...");
  test_gll_get();
  test_gll_add();
  test_gll_remove();
  test_gll_push();
  test_gll_pushFront();
  test_gll_pop();

  test_gll_each();
  test_gll_eachReverse();

  printf("complete\n");

  return C_OK;
}

static void test_gll_get() {
  LinkedListType *list = gll_init();
  
  //Get from an empty list
  assert(gll_get(0, list) == NULL);  
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  gll_push(&a, list);
  gll_push(&b, list);
  gll_push(&c, list);

  //Get from an unused position
  assert(gll_get(3, list) == NULL);
  //Get from an invalid position
  assert(gll_get(-1, list) == NULL); 

  //Get valid elements
  assert(gll_get(0, list) == &a);
  assert(gll_get(1, list) == &b);
  assert(gll_get(2, list) == &c); 

  gll_destroy(list);
}

static void test_gll_add() {
  LinkedListType *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";
  float d = 0.5;
  
  //Add at an invalid position
  assert(gll_add(&a, 1, list) == C_NOK);
  assert(gll_add(&a, -1, list) == C_NOK);

  assert(list->size == 0);

  //add to an empty list
  assert(gll_add(&c, 0, list) == C_OK);
  assert(list->size == 1);
  assert(list->first->data == &c);
  assert(list->last->data  == &c);
  assert(list->first->prev == NULL);
  assert(list->first->next == NULL);

  //add to the front
  assert(gll_add(&a, 0, list) == C_OK);
  assert(list->size == 2);
  assert(list->first->data == &a);
  assert(list->last->data  == &c);
  assert(list->first->next->data == &c);
  assert(list->last->prev->data == &a);
  assert(list->first->prev == NULL);
  assert(list->last->next == NULL);
  
  //add in the middle
  assert(gll_add(&b, 1, list) == C_OK);
  assert(list->size == 3);
  assert(list->first->data == &a);
  assert(list->first->next->data == &b);
  assert(list->first->prev == NULL);

  assert(list->first->next->next->data == &c);
  assert(list->last->prev->prev->data == &a);

  assert(list->last->data  == &c);
  assert(list->last->next == NULL);
  assert(list->last->prev->data == &b);

  //add at the end
  assert(gll_add(&d, 3, list) == C_OK);
  assert(list->size == 4);
  assert(list->last->data == &d);
  assert(list->last->next == NULL);
  assert(list->last->prev->data == &c);
  assert(list->last->prev->next->data == &d);
  assert(list->first->data == &a);
 

  gll_destroy(list);
}

static void test_gll_remove() {
  LinkedListType *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";
  float d = 0.5;
  int   e = 5;

  //remove from an empty list
  assert(gll_remove(0, list) == C_NOK);

  gll_push(&a, list);
  gll_push(&b, list);
  gll_push(&c, list);
  gll_push(&d, list);

  assert(list->size == 4);

  //remove from front
  assert(gll_remove(0, list) == C_OK);
  assert(list->size == 3);
  assert(list->first->data == &b);
  assert(list->first->prev == NULL);
  assert(list->first->next->data == &c);

  //remove from middle
  assert(gll_remove(1, list) == C_OK);
  assert(list->size == 2);
  assert(list->first->data == &b);
  assert(list->first->prev == NULL);
  assert(list->first->next->data == &d);
  assert(list->last->data = &d);
  assert(list->last->prev->data == &b);  
  assert(list->last->next == NULL);  

  //remove from end
  gll_push(&e, list);

  assert(gll_remove(2, list) == C_OK);
  assert(list->size == 2);
  assert(list->first->data == &b);
  assert(list->first->next->data == &d);
  assert(list->first->prev == NULL);
  assert(list->last->data == &d);
  assert(list->last->prev->data == &b);
  assert(list->last->next == NULL);

  //remove last remaining element
  assert(gll_remove(1, list) == C_OK);
  assert(list->size == 1);

  assert(gll_remove(0, list) == C_OK);
  assert(list->size == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);

  gll_destroy(list);
}

static void test_gll_push() {
  LinkedListType *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  assert(list->size == 0);
  
  assert(gll_push(&a, list) == C_OK);
  assert(list->size == 1);
  assert(list->first->data == &a);
  assert(list->first->prev == NULL);
  assert(list->first->next == NULL);
  assert(list->last->data == &a);

  assert(gll_push(&b, list) == C_OK);
  assert(list->size == 2);
  assert(list->first->data == &a);
  assert(list->first->next->data == &b);
  assert(list->last->data == &b);
  assert(list->last->prev->data == &a);
  assert(list->last->next == NULL);

  assert(gll_push(&c, list) == C_OK);
  assert(list->size == 3);
  assert(list->last->data == &c);
  assert(list->last->prev->data == &b);
  assert(list->last->prev->next->data == &c);

  gll_destroy(list);
}

static void test_gll_pushFront() {
  LinkedListType *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  assert(list->size == 0);
  
  assert(gll_pushFront(&c, list) == C_OK);
  assert(list->size == 1);
  assert(list->first->data == &c);
  assert(list->first->prev == NULL);
  assert(list->first->next == NULL);
  assert(list->last->data == &c);

  assert(gll_pushFront(&b, list) == C_OK);
  assert(list->size == 2);
  assert(list->first->data == &b);
  assert(list->first->next->data == &c);
  assert(list->first->prev == NULL);
  assert(list->last->data == &c);
  assert(list->last->prev->data == &b);
  assert(list->last->next == NULL);

  assert(gll_pushFront(&a, list) == C_OK);
  assert(list->size == 3);
  assert(list->first->data = &a);
  assert(list->first->next->data = &b);
  assert(list->first->next->prev->data = &a);
  assert(list->last->data == &c);
  assert(list->last->prev->data == &b);

  gll_destroy(list);
}


static void test_gll_pop() {
  LinkedListType *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  gll_push(&a, list);
  gll_push(&b, list);
  gll_push(&c, list);
  assert(list->size == 3);

  assert(gll_pop(list) == &c);
  assert(list->first->data == &a);
  assert(list->first->next->data == &b);
  assert(list->last->data == &b);
  assert(list->last->prev->data == &a);
  assert(list->last->next == NULL);
  assert(list->size == 2);

  assert(gll_pop(list) == &b);
  assert(list->size == 1);

  assert(gll_pop(list) == &a);
  assert(list->first == NULL);
  assert(list->last == NULL);
  assert(list->size == 0);

  gll_destroy(list);
}

void each_test_function(void *x) {
  gll_push(x, each_list);
}

static void test_gll_each() {
  each_list = gll_init();
  LinkedListType *list = gll_init();

  each_a = 1;
  each_b = 2;
  each_c = 3;

  gll_push(&each_a, list);
  gll_push(&each_b, list);
  gll_push(&each_c, list);

  gll_each(each_test_function, list);

  assert(gll_get(0, each_list) == &each_a);
  assert(gll_get(1, each_list) == &each_b);
  assert(gll_get(2, each_list) == &each_c);
  
  gll_destroy(each_list);
  gll_destroy(list);
}

static void test_gll_eachReverse() {
  each_list = gll_init();
  LinkedListType *list = gll_init();

  each_a = 1;
  each_b = 2;
  each_c = 3;

  gll_push(&each_a, list);
  gll_push(&each_b, list);
  gll_push(&each_c, list);

  gll_eachReverse(each_test_function, list);

  assert(gll_get(2, each_list) == &each_a);
  assert(gll_get(1, each_list) == &each_b);
  assert(gll_get(0, each_list) == &each_c);
  
  gll_destroy(each_list);
  gll_destroy(list);
}

