#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gll.c"

void printFunction(void *i) {
  int *num = (int *) i;
  printf("%d, ", *num);
}

int main(int argc, char *argv[]) {
  
  LinkedListType *list = gll_init(); 

  int data[10] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99};

  printf("[");
  gll_add(&data[0], 0, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_add(&data[1], 1, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_add(&data[2], 2, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_add(&data[3], 3, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_add(&data[4], 2, &list);  
  gll_each(printFunction, &list);
  printf("]\n");


  printf("[");
  gll_add(&data[5], 99, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_add(&data[5], 0, &list);  
  gll_each(printFunction, &list);
  printf("]\n");


  printf("[");
  gll_add(&data[6], 3, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_add(&data[7], 4, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_add(&data[8], 1, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_add(&data[9], 4, &list);  
  gll_each(printFunction, &list);
  printf("]\n");
  


  /* DELETIONS */ 
  printf("[");
  gll_remove(0, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_remove(1, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_remove(7, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_remove(99, &list);  
  gll_each(printFunction, &list);
  printf("]\n");

  printf("[");
  gll_remove(4, &list);  
  gll_each(printFunction, &list);
  printf("]\n");


  gll_deallocList(&list);

  return 0;
}


