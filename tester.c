#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ll_defs.h"

void printFunction(void *i) {
  int *num = (int *) i;
  printf("%d, ", *num);
}

int main(int argc, char *argv[]) {
  
  HeadType *list = (HeadType *) malloc(sizeof(HeadType));   
  list->first = NULL;
  list->last  = NULL;
  list->size  = 0;

  int data[10] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99};

  printf("[");
  addNode(&data[0], 0, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  addNode(&data[1], 1, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  addNode(&data[2], 2, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  addNode(&data[3], 3, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  addNode(&data[4], 2, &list);  
  each(printFunction, &list);
  printf("]\n");


  printf("[");
  addNode(&data[5], 99, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  addNode(&data[5], 0, &list);  
  each(printFunction, &list);
  printf("]\n");


  printf("[");
  addNode(&data[6], 3, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  addNode(&data[7], 4, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  addNode(&data[8], 1, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  addNode(&data[9], 4, &list);  
  each(printFunction, &list);
  printf("]\n");
  


  /* DELETIONS */ 
  printf("[");
  removeNode(0, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  removeNode(1, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  removeNode(7, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  removeNode(99, &list);  
  each(printFunction, &list);
  printf("]\n");

  printf("[");
  removeNode(4, &list);  
  each(printFunction, &list);
  printf("]\n");



  return 0;
}


