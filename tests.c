#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "src/gll.h"

#define MAX_STR 32
#define C_OK    0
#define C_NOK   -1


static void test_gll_add();
static void test_gll_remove();
static void test_gll_get();
static void test_gll_first();
static void test_gll_last();
static void test_gll_push();
static void test_gll_pushBack();
static void test_gll_pop();
static void test_gll_popBack();
static void test_gll_each();
static void test_gll_eachReverse();
static void test_gll_clear();

void each_test_function(void *);

/* Global variables */
int each_a;
int each_b;
int each_c;
gll_t *each_list;


int main(int argc, char *argv) 
{
  printf("Running tests:\n");

  printf(" gll_get\n");
  test_gll_get();
  printf(" gll_first\n");
  test_gll_first();
  printf(" gll_last\n");
  test_gll_last();
  printf(" gll_add\n");
  test_gll_add();
  printf(" gll_remove\n");
  test_gll_remove();
  printf(" gll_push\n");
  test_gll_push();
  printf(" gll_pushBack\n");
  test_gll_pushBack();
  printf(" gll_pop\n");
  test_gll_pop();
  printf(" gll_popBack\n");
  test_gll_popBack();
  printf(" gll_each\n");
  test_gll_each();
  printf(" gll_eachReverse\n");
  test_gll_eachReverse();
  printf(" gll_clear\n");
  test_gll_clear();


  printf("\nCompleted.\n");

  return C_OK;
}

static void test_gll_get() 
{
  gll_t *list = gll_init();
  
  /* Get from an empty list */
  assert(gll_get(list, 0) == NULL);  
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  gll_pushBack(list, &a);
  gll_pushBack(list, &b);
  gll_pushBack(list, &c);

  /* Get from an unused position */
  assert(gll_get(list, 3) == NULL);
  /* Get from an invalid position */
  assert(gll_get(list, -1) == NULL); 

  /* Get valid elements */
  assert(gll_get(list, 0) == &a);
  assert(gll_get(list, 1) == &b);
  assert(gll_get(list, 2) == &c); 

  gll_destroy(list);
}

static void test_gll_first() 
{
  gll_t *list = gll_init();
  
  /* empty list */
  assert(gll_first(list) == NULL);  
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  gll_pushBack(list, &a);
  gll_pushBack(list, &b);
  gll_pushBack(list, &c);

  assert(gll_first(list) == &a);
  gll_pop(list);
  assert(gll_first(list) == &b);

  gll_destroy(list);
}

static void test_gll_last()
{ 
  gll_t *list = gll_init();
  
  /* empty list */
  assert(gll_last(list) == NULL);  
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  gll_pushBack(list, &a);
  gll_pushBack(list, &b);
  gll_pushBack(list, &c);

  assert(gll_last(list) == &c);
  gll_popBack(list);
  assert(gll_last(list) == &b);

  gll_destroy(list);
}

static void test_gll_add() 
{
  gll_t *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";
  float d = 0.5;
  
  /* Add at an invalid position */
  assert(gll_add(list, &a, 1) == C_NOK);
  assert(gll_add(list, &a, -1) == C_NOK);

  assert(list->size == 0);

  /* add to an empty list */
  assert(gll_add(list, &c, 0) == C_OK);
  assert(list->size == 1);
  assert(list->first->data == &c);
  assert(list->last->data  == &c);
  assert(list->first->prev == NULL);
  assert(list->first->next == NULL);

  /* add to the front */
  assert(gll_add(list, &a, 0) == C_OK);
  assert(list->size == 2);
  assert(list->first->data == &a);
  assert(list->last->data  == &c);
  assert(list->first->next->data == &c);
  assert(list->last->prev->data == &a);
  assert(list->first->prev == NULL);
  assert(list->last->next == NULL);
  
  /* add in the middle */
  assert(gll_add(list, &b, 1) == C_OK);
  assert(list->size == 3);
  assert(list->first->data == &a);
  assert(list->first->next->data == &b);
  assert(list->first->prev == NULL);

  assert(list->first->next->next->data == &c);
  assert(list->last->prev->prev->data == &a);

  assert(list->last->data  == &c);
  assert(list->last->next == NULL);
  assert(list->last->prev->data == &b);

  /* add at the end */
  assert(gll_add(list, &d, 3) == C_OK);
  assert(list->size == 4);
  assert(list->last->data == &d);
  assert(list->last->next == NULL);
  assert(list->last->prev->data == &c);
  assert(list->last->prev->next->data == &d);
  assert(list->first->data == &a);
 

  gll_destroy(list);
}

static void test_gll_remove() 
{
  gll_t *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";
  float d = 0.5;
  int   e = 5;

  /* remove from an empty list */
  assert(gll_remove(list, 0) == NULL);

  gll_pushBack(list, &a);
  gll_pushBack(list, &b);
  gll_pushBack(list, &c);
  gll_pushBack(list, &d);

  assert(list->size == 4);

  /* remove from front */
  assert(gll_remove(list, 0) == &a);
  assert(list->size == 3);
  assert(list->first->data == &b);
  assert(list->first->prev == NULL);
  assert(list->first->next->data == &c);

  /* remove from middle */
  assert(gll_remove(list, 1) == &c);
  assert(list->size == 2);
  assert(list->first->data == &b);
  assert(list->first->prev == NULL);
  assert(list->first->next->data == &d);
  assert(list->last->data = &d);
  assert(list->last->prev->data == &b);  
  assert(list->last->next == NULL);  

  /* remove from end */
  gll_pushBack(list, &e);

  assert(gll_remove(list, 2) == &e);
  assert(list->size == 2);
  assert(list->first->data == &b);
  assert(list->first->next->data == &d);
  assert(list->first->prev == NULL);
  assert(list->last->data == &d);
  assert(list->last->prev->data == &b);
  assert(list->last->next == NULL);

  /* remove last remaining element */
  assert(gll_remove(list, 1) == &d);
  assert(list->size == 1);

  assert(gll_remove(list, 0) == &b);
  assert(list->size == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);

  gll_destroy(list);
}

static void test_gll_pushBack() 
{
  gll_t *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  assert(list->size == 0);
  
  assert(gll_pushBack(list, &a) == C_OK);
  assert(list->size == 1);
  assert(list->first->data == &a);
  assert(list->first->prev == NULL);
  assert(list->first->next == NULL);
  assert(list->last->data == &a);

  assert(gll_pushBack(list, &b) == C_OK);
  assert(list->size == 2);
  assert(list->first->data == &a);
  assert(list->first->next->data == &b);
  assert(list->last->data == &b);
  assert(list->last->prev->data == &a);
  assert(list->last->next == NULL);

  assert(gll_pushBack(list, &c) == C_OK);
  assert(list->size == 3);
  assert(list->last->data == &c);
  assert(list->last->prev->data == &b);
  assert(list->last->prev->next->data == &c);

  gll_destroy(list);
}

static void test_gll_push() 
{
  gll_t *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  assert(list->size == 0);
  
  assert(gll_push(list, &c) == C_OK);
  assert(list->size == 1);
  assert(list->first->data == &c);
  assert(list->first->prev == NULL);
  assert(list->first->next == NULL);
  assert(list->last->data == &c);

  assert(gll_push(list, &b) == C_OK);
  assert(list->size == 2);
  assert(list->first->data == &b);
  assert(list->first->next->data == &c);
  assert(list->first->prev == NULL);
  assert(list->last->data == &c);
  assert(list->last->prev->data == &b);
  assert(list->last->next == NULL);

  assert(gll_push(list, &a) == C_OK);
  assert(list->size == 3);
  assert(list->first->data = &a);
  assert(list->first->next->data = &b);
  assert(list->first->next->prev->data = &a);
  assert(list->last->data == &c);
  assert(list->last->prev->data == &b);

  gll_destroy(list);
}


static void test_gll_popBack() 
{
  gll_t *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  gll_pushBack(list, &a);
  gll_pushBack(list, &b);
  gll_pushBack(list, &c);
  assert(list->size == 3);

  assert(gll_popBack(list) == &c);
  assert(list->first->data == &a);
  assert(list->first->next->data == &b);
  assert(list->last->data == &b);
  assert(list->last->prev->data == &a);
  assert(list->last->next == NULL);
  assert(list->size == 2);

  assert(gll_popBack(list) == &b);
  assert(list->size == 1);

  assert(gll_popBack(list) == &a);
  assert(list->first == NULL);
  assert(list->last == NULL);
  assert(list->size == 0);

  gll_destroy(list);
}

static void test_gll_pop() 
{
  gll_t *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  gll_pushBack(list, &a);
  gll_pushBack(list, &b);
  gll_pushBack(list, &c);
  assert(list->size == 3);

  assert(gll_pop(list) == &a);
  assert(list->first->data == &b);
  assert(list->first->prev == NULL);
  assert(list->first->next->data == &c);
  assert(list->size == 2);

  assert(gll_pop(list) == &b);
  assert(list->size == 1);

  assert(gll_pop(list) == &c);
  assert(list->first == NULL);
  assert(list->last == NULL);
  assert(list->size == 0);

  gll_destroy(list);
}


void each_test_function(void *x) 
{
  gll_pushBack(each_list, x);
}

static void test_gll_each() 
{
  each_list = gll_init();
  gll_t *list = gll_init();

  each_a = 1;
  each_b = 2;
  each_c = 3;

  gll_pushBack(list, &each_a);
  gll_pushBack(list, &each_b);
  gll_pushBack(list, &each_c);

  gll_each(list, each_test_function);

  assert(gll_get(each_list, 0) == &each_a);
  assert(gll_get(each_list, 1) == &each_b);
  assert(gll_get(each_list, 2) == &each_c);
  
  gll_destroy(each_list);
  gll_destroy(list);
}

static void test_gll_eachReverse() 
{
  each_list = gll_init();
  gll_t *list = gll_init();

  each_a = 1;
  each_b = 2;
  each_c = 3;

  gll_pushBack(list, &each_a);
  gll_pushBack(list, &each_b);
  gll_pushBack(list, &each_c);

  gll_eachReverse(list, each_test_function);

  assert(gll_get(each_list, 2) == &each_a);
  assert(gll_get(each_list, 1) == &each_b);
  assert(gll_get(each_list, 0) == &each_c);
  
  gll_destroy(each_list);
  gll_destroy(list);
}

static void test_gll_clear() 
{
  gll_t *list = gll_init();
  
  char  a = 'A';
  int   b = 15;
  char *c = "str";

  gll_pushBack(list, &a);
  gll_pushBack(list, &b);
  gll_pushBack(list, &c);

  assert(list->size == 3);
  gll_clear(list);
  assert(list->size == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);

  gll_destroy(list);
}
