#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gll.h"

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
gll_t *LIST;

int main(int argc, char **argv) 
{
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
  fflush(stdout);
  run_gll_push(); 

  printf("  gll_pop() (All):             ");
  fflush(stdout);
  run_gll_pop(); 

  gll_destroy(LIST);
  LIST = gll_init();
  

  printf("  gll_pushFront() (All):       ");
  fflush(stdout);
  run_gll_pushFront(); 
  
  printf("  gll_popFront() (All):        ");
  fflush(stdout);
  run_gll_popFront(); 

  gll_destroy(LIST);
  LIST = gll_init();
   

  printf("\n");
  printf("  gll_push() (All):            ");
  fflush(stdout);
  run_gll_push(); 


  printf("\n");
  printf("  1 * gll_get() (middle):      ");
  fflush(stdout);
  run_gll_get(NUM_NODES/2);

  printf("  1 * gll_get() (end):         ");
  fflush(stdout);
  run_gll_get(NUM_NODES-1); 

  printf("  1 * gll_get() (begin):       ");
  fflush(stdout);
  run_gll_get(0); 


  printf("\n");
  printf("  1 * gll_add() (middle):      ");
  fflush(stdout);
  run_gll_add(NUM_NODES/2);

  printf("  1 * gll_add() (end):         ");
  fflush(stdout);
  run_gll_add(NUM_NODES-1);

  printf("  1 * gll_add() (begin):       ");
  fflush(stdout);
  run_gll_add(0);


  printf("\n");
  printf("  1 * gll_remove() (middle):   ");
  fflush(stdout);
  run_gll_remove(NUM_NODES/2); 

  printf("  1 * gll_remove() (end):      ");
  fflush(stdout);
  run_gll_remove(NUM_NODES-1); 

  printf("  1 * gll_remove() (begin):    ");
  fflush(stdout);
  run_gll_remove(0); 


  printf("\n");
  printf("  gll_each():                  ");
  fflush(stdout);
  run_gll_each();

  printf("  gll_eachReverse():           ");
  fflush(stdout);
  run_gll_eachReverse();

  printf("\n");

  gll_destroy(LIST);
  return 0;
}


static float start() 
{
  return clock();
}

static void stop(float startTime) 
{
  float time = ((clock() - startTime) / CLOCKS_PER_SEC) * 1000.0;
  printf("%8.4f ms\n", time);
}

static void run_gll_push() 
{
  volatile int i;
  volatile void *ptr = &i;
  float startT = start();

  for(i = 0; i < NUM_NODES; i++)
    gll_push(LIST, &ptr);

  stop(startT);
}

static void run_gll_pop() 
{
  volatile int i;
  float startT = start();

  for(i = 0; i < NUM_NODES; i++)
    gll_pop(LIST);

  stop(startT);
}

static void run_gll_pushFront() 
{
  volatile int i;
  volatile void *ptr = &i;
  float startT = start();

  for(i = 0; i < NUM_NODES; i++)
    gll_pushFront(LIST, &ptr);

  stop(startT);
}

static void run_gll_popFront() 
{
  volatile int i;
  float startT = start();

  for(i = 0; i < NUM_NODES; i++)
    gll_popFront(LIST);

  stop(startT);
}

static void run_gll_add(int pos) 
{
  int i = 10;
  float startT = start();

  gll_add(LIST, &i, pos);

  stop(startT);
}

static void run_gll_get(int pos) 
{
  float startT = start();
  gll_get(LIST, pos);
  stop(startT);
}


static void run_gll_remove(int pos) 
{
  float startT = start();
  gll_remove(LIST, pos);
  stop(startT);
}

void dummyFunction(void* ptr) 
{}

static void run_gll_each() 
{
  float startT = start();
  gll_each(LIST, dummyFunction);
  stop(startT);
}

static void run_gll_eachReverse() 
{
  float startT = start();
  gll_eachReverse(LIST, dummyFunction);
  stop(startT);
}

