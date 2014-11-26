#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GenericLinkedList.h"

static float start();
static void stop(float);
static void run_gll_push();
static void run_gll_pop();
static void run_gll_pushFront();
static void run_gll_popFront();

static void run_gll_add();
static void run_gll_get();
static void run_gll_remove();

static void run_gll_each();
static void run_gll_eachReverse();

static int NUM_NODES;
LinkedListType *LIST;

int main(int argc, char **argv) {
  NUM_NODES = 10000000;
  LIST = gll_init();

  if(argc == 2) {
    int x = -1;
    x = strtoul(argv[1], NULL, 10);
    if(x > 0)
      NUM_NODES = x;
  }

  printf("\nNumber of Nodes: %d\n\n", NUM_NODES);


  printf("  gll_push() (All):            ");
  run_gll_push(); 

  printf("  gll_pop() (All):             ");
  run_gll_pop(); 


  gll_destroy(LIST);
  LIST = gll_init();
  
  printf("  gll_pushFront() (All):       ");
  run_gll_pushFront(); 
  
  printf("  gll_popFront() (All):        ");
  run_gll_popFront(); 
  

  gll_destroy(LIST);
  LIST = gll_init();
   
  printf("\n");
  printf("  gll_push() (All):            ");
  run_gll_push(); 


  printf("\n");
  printf("  1 * gll_get() (middle):      ");
  run_gll_get(NUM_NODES/2);

  printf("  1 * gll_get() (end):         ");
  run_gll_get(NUM_NODES-1); 

  printf("  1 * gll_get() (begin):       ");
  run_gll_get(0); 

  printf("\n");


  printf("  1 * gll_add() (middle):      ");
  run_gll_add(NUM_NODES/2);

  printf("  1 * gll_add() (end):         ");
  run_gll_add(NUM_NODES-1);

  printf("  1 * gll_add() (begin):       ");
  run_gll_add(0);


  printf("\n");

  printf("  1 * gll_remove() (middle):   ");
  run_gll_remove(NUM_NODES/2); 

  printf("  1 * gll_remove() (end):      ");
  run_gll_remove(NUM_NODES-1); 

  printf("  1 * gll_remove() (begin):    ");
  run_gll_remove(0); 

  printf("\n");

  printf("  gll_each():                  ");
  run_gll_each();

  printf("  gll_eachReverse():           ");
  run_gll_eachReverse();

  
  printf("\n");
    


  return 0;

}


static float start() {
  return clock();
}

static void stop(float startTime) {
  float time = ((clock() - startTime) / CLOCKS_PER_SEC) * 1000.0;
  printf("%.4fms\n", time);
}

static void run_gll_push() {
  volatile int i;
  volatile void *ptr = &i;
  float startT = start();

  for(i = 0; i < NUM_NODES; i++)
    gll_push(&ptr, LIST);

  stop(startT);
}

static void run_gll_pop() {
  volatile int i;
  float startT = start();

  for(i = 0; i < NUM_NODES; i++)
    gll_pop(LIST);

  stop(startT);
}

static void run_gll_pushFront() {
  volatile int i;
  volatile void *ptr = &i;
  float startT = start();

  for(i = 0; i < NUM_NODES; i++)
    gll_pushFront(&ptr, LIST);

  stop(startT);
}

static void run_gll_popFront() {
  volatile int i;
  float startT = start();

  for(i = 0; i < NUM_NODES; i++)
    gll_popFront(LIST);

  stop(startT);
}

static void run_gll_add(int pos) {
  int i = 10;
  float startT = start();

  gll_add(&i, pos, LIST);

  stop(startT);
}

static void run_gll_get(int pos) {
  float startT = start();
  gll_get(pos, LIST);
  stop(startT);
}


static void run_gll_remove(int pos) {
  float startT = start();
  gll_remove(pos, LIST);
  stop(startT);
}

void dummyFunction(void* ptr) {}

static void run_gll_each() {
  float startT = start();
  gll_each(dummyFunction, LIST);
  stop(startT);
}

static void run_gll_eachReverse() {
  float startT = start();
  gll_eachReverse(dummyFunction, LIST);
  stop(startT);
}


