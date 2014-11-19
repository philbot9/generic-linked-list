#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gll_defs.h"

void printFunction(void *i) {
  int *num = (int *) i;
  printf("%d, ", *num);
}

void printList(LinkedListType *list) {
  printf("[");
  gll_each(printFunction, list);
  printf("]\n");
}

int checkList(LinkedListType *list, int *correct) {
  int i;
  for(i = 0; i < list->size; i++) {
    int *l = (int *) gll_get(i, list);

    if(correct[i] != *l) {
      printf("ERROR!\n\n");
      return -1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  
  LinkedListType *list = gll_init(); 

  int data[10] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
  
  int correct[10];

  printf("Adding: %d\n", data[0]);
  gll_add(&data[0], 0, &list);  
  printf("List:   "); 
  printList(list);
  
  correct[0] = data[0];
  checkList(list, correct);
  printf("\n");

  printf("Adding: %d\n", data[1]);
  gll_add(&data[1], 1, &list);  
  printf("List:   "); 
  printList(list);
  
  correct[0] = data[0];
  correct[1] = data[1];
  checkList(list, correct);
  printf("\n");


  printf("Adding: %d\n", data[2]);
  gll_add(&data[2], 2, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[0];
  correct[1] = data[1];
  correct[2] = data[2];
  checkList(list, correct);
  printf("\n");


  printf("Adding: %d\n", data[3]);
  gll_add(&data[3], 3, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[0];
  correct[1] = data[1];
  correct[2] = data[2];
  correct[3] = data[3];
  checkList(list, correct);
  printf("\n");


  printf("Adding: %d\n", data[4]);
  gll_add(&data[4], 2, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[0];
  correct[1] = data[1];
  correct[2] = data[4];
  correct[3] = data[2];
  correct[4] = data[3];
  checkList(list, correct);
  printf("\n");



  printf("Adding: %d\n", data[5]);
  gll_add(&data[5], 99, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[0];
  correct[1] = data[1];
  correct[2] = data[4];
  correct[3] = data[2];
  correct[4] = data[3];
  checkList(list, correct);
  printf("\n");


  printf("Adding: %d\n", data[5]);
  gll_add(&data[5], 0, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[5];
  correct[1] = data[0];
  correct[2] = data[1];
  correct[3] = data[4];
  correct[4] = data[2];
  correct[5] = data[3];
  checkList(list, correct);
  printf("\n");



  printf("Adding: %d\n", data[6]);
  gll_add(&data[6], 3, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[5];
  correct[1] = data[0];
  correct[2] = data[1];
  correct[3] = data[6];
  correct[4] = data[4];
  correct[5] = data[2];
  correct[6] = data[3];
  checkList(list, correct);
  printf("\n");


  printf("Adding: %d\n", data[7]);
  gll_add(&data[7], 4, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[5];
  correct[1] = data[0];
  correct[2] = data[1];
  correct[3] = data[6];
  correct[4] = data[7];
  correct[5] = data[4];
  correct[6] = data[2];
  correct[7] = data[3];
  checkList(list, correct);
  printf("\n");


  printf("Adding: %d\n", data[8]);
  gll_add(&data[8], 1, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[5];
  correct[1] = data[8];
  correct[2] = data[0];
  correct[3] = data[1];
  correct[4] = data[6];
  correct[5] = data[7];
  correct[6] = data[4];
  correct[7] = data[2];
  correct[8] = data[3];
  checkList(list, correct);
  printf("\n");


  printf("Adding: %d\n", data[9]);
  gll_add(&data[9], 4, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[5];
  correct[1] = data[8];
  correct[2] = data[0];
  correct[3] = data[1];
  correct[4] = data[9];
  correct[5] = data[6];
  correct[6] = data[7];
  correct[7] = data[4];
  correct[8] = data[2];
  correct[9] = data[3];
  checkList(list, correct);
  printf("\n");



  /* DELETIONS */ 
  printf("Deleting from pos: 0 (first)\n");
  gll_remove(0, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[8];
  correct[1] = data[0];
  correct[2] = data[1];
  correct[3] = data[9];
  correct[4] = data[6];
  correct[5] = data[7];
  correct[6] = data[4];
  correct[7] = data[2];
  correct[8] = data[3];
  checkList(list, correct);
  printf("\n");


  printf("Deleting from pos: 1 (middle)\n");
  gll_remove(1, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[8];
  correct[1] = data[1];
  correct[2] = data[9];
  correct[3] = data[6];
  correct[4] = data[7];
  correct[5] = data[4];
  correct[6] = data[2];
  correct[7] = data[3];
  checkList(list, correct);
  printf("\n");


  printf("Deleting from pos: 7 (last)\n");
  gll_remove(7, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[8];
  correct[1] = data[1];
  correct[2] = data[9];
  correct[3] = data[6];
  correct[4] = data[7];
  correct[5] = data[4];
  correct[6] = data[2];
  checkList(list, correct);
  printf("\n");


  printf("Deleting from pos: 99 (invalid)\n");
  gll_remove(99, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[8];
  correct[1] = data[1];
  correct[2] = data[9];
  correct[3] = data[6];
  correct[4] = data[7];
  correct[5] = data[4];
  correct[6] = data[2];
  checkList(list, correct);
  printf("\n");

  printf("Deleting from pos: 3 (middle)\n");
  gll_remove(3, &list);
  printf("List:   ");
  printList(list);

  correct[0] = data[8];
  correct[1] = data[1];
  correct[2] = data[9];
  correct[3] = data[7];
  correct[4] = data[4];
  correct[5] = data[2];
  checkList(list, correct);
  printf("\n");


  //deallocate the list
  gll_deallocList(&list);

  return 0;
}


