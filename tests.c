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
      return -1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  
  /* ******************************************************
   *
   * 1) gll_get
   *    - list is empty
   *    - invalid position
   *    - get with one element
   *    - first element 
   *    - middle element 
   *    - last element 
   *
   * 2) gll_add
   *    - list is empty
   *    - invalid position
   *    - first position
   *    - middle position
   *    - last position
   *
   * 3) gll_remove
   *    - list is empty
   *    - invalid position
   *    - remove last remaining element
   *    - remove from first position
   *    - remove from middle position
   *    - remove from last position
   *     
   * 4) gll_each
   *    - empty list
   *    - check elements are in order
   *
   * 5) gll_eachReverse
   *    - empty list
   *    - check elements are in reverse order
   *
   * 6) gll_deallocList
   *    - empty list
   *
   * ****************************************************** */


  //Initialize linked list
  LinkedListType *list = gll_init(); 

  //test data
  int data[10] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
  //reference array
  int reference[4];
  int errorCount = 0;
  int *res = NULL;

  int i;


  printf("##########################################################\n");
    
  /* 
   *  1)  gll_get
   */

  //list is empty
  printf("gll_get:  empty list...");
  if (gll_get(0, list) == NULL) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }

  //invalid position
  printf("gll_get:  invalid position...");
  if (gll_get(99, list) == NULL) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }

  //get with one element
  printf("gll_get:  one element...");
  gll_add(&data[0], 0, list);
  reference[0] = data[0];

  res = (int *) gll_get(0, list);

  if (*res == reference[0]) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }

  //get first element
  printf("gll_get:  frist element...");
  
  gll_add(&data[1], 1, list);
  reference[1] = data[1];
 
  res = (int *) gll_get(0, list);

  if (*res == reference[0]) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }

  //get middle element
  printf("gll_get:  middle element...");
  
  gll_add(&data[2], 2, list);
  reference[2] = data[2];
 
  res = (int *) gll_get(1, list);

  if (*res == reference[1]) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


  //get last element
  printf("gll_get:  last element...");
  
  gll_add(&data[3], 3, list);
  reference[3] = data[3];
 
  res = (int *) gll_get(3, list);

  if (*res == reference[3]) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


  printf("\n");

  gll_deallocList(list);
  list = gll_init(); 

     
  /* 
   *  2)  gll_add
   */

  int reference2[5];
  
  //list is empty a.k.a. add the first element
  printf("gll_add:  empty list...");
  
  gll_add(&data[0], 0, list);
  reference2[0] = data[0];
 
  res = (int *) gll_get(0, list);

  if (checkList(list, reference2) == 0 && 
      list->first != NULL && 
      list->last != NULL &&
      list->size == 1) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }

  //invalid position
  printf("gll_add:  invalid position...");
   if (gll_get(99, list) == NULL &&
       list->size == 1) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


  //first position
  printf("gll_add:  in first position...");
  
  gll_add(&data[1], 0, list);
  reference2[0] = data[1];
  reference2[1] = data[0];
 
  if (checkList(list, reference2) == 0 &&
      list->size == 2) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


  //middle position
  printf("gll_add:  in middle position...");
  
  gll_add(&data[2], 1, list);
  reference2[0] = data[1];
  reference2[1] = data[2];
  reference2[2] = data[0];
 
  if (checkList(list, reference2) == 0 &&
      list->size == 3) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


  //last position
  printf("gll_add:  in last position...");
  
  gll_add(&data[3], 3, list);
  reference2[0] = data[1];
  reference2[1] = data[2];
  reference2[2] = data[0];
  reference2[3] = data[3];
 
  if (checkList(list, reference2) == 0 &&
      list->size == 4) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


printf("\n");

/*
  3) gll_remove
*/
  gll_deallocList(list);
  list = gll_init();
  int reference3[5];

  
  //list is empty
  printf("gll_remove:  empty list...");
  
  if (gll_remove(0, list) < 0 &&
      list->first == NULL &&
      list->last == NULL &&
      list->size == 0) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


  //remove last remaining element
  printf("gll_remove:  last remaining element...");

  gll_add(&data[0], 0, list);
  gll_remove(0, list);

  if(list->size == 0 &&
      list->first == NULL &&
      list->last == NULL) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }



  //invalid position
  printf("gll_remove:  invalid position...");
  
  if (gll_remove(99, list) < 0 &&
      list->first == NULL &&
      list->last == NULL &&
      list->size == 0) {
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


  //add sample data
  for(i = 0; i < 5; i++) { 
    gll_add(&data[i], i, list);
  }


  //remove from first position
  printf("gll_remove:  first element...");
  
  gll_remove(0, list);

  reference3[0] = data[1];
  reference3[1] = data[2];
  reference3[2] = data[3];
  reference3[3] = data[4];

  if (checkList(list, reference3) == 0 &&
      list->first != NULL &&
      list->last != NULL &&
      list->size == 4) {
      
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }


  //remove from middle position
  printf("gll_remove:  middle element...");
  
  gll_remove(2, list);

  reference3[0] = data[1];
  reference3[1] = data[2];
  reference3[2] = data[4];

  if (checkList(list, reference3) == 0 &&
      list->first != NULL &&
      list->last != NULL &&
      list->size == 3) {
      
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }



  //remove from end position
  printf("gll_remove:  last element...");
  
  gll_remove(2, list);

  reference3[0] = data[1];
  reference3[1] = data[2];

  if (checkList(list, reference3) == 0 &&
      list->first != NULL &&
      list->last != NULL &&
      list->size == 2) {
      
    printf("pass\n");
  }
  else {
    errorCount++;
    printf("FAIL\n");
  }

  gll_deallocList(list);

  printf("##########################################################\n");
  printf("\nErrors: %d\n\n", errorCount);
  printf("##########################################################\n");


  return 0;
}


