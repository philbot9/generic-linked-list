#include <stdio.h>
#include <stdlib.h>

#include "gll_defs.h"

LinkedListType *gll_init() {
  LinkedListType *list = (LinkedListType *) malloc(sizeof(LinkedListType));
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
}

void *gll_get(int pos, LinkedListType *list) {
  return gll_findNode(pos, list)->data;
}

NodeType *gll_findNode(int pos, LinkedListType *list) {
  if(pos > list->size || pos < 0)
    return NULL;  

  NodeType *currNode;
  int currPos;
  int reverse;
  
  if(pos > ((list->size-1) / 2)) {
    reverse  = 1;
    currPos  = list->size - 1;
    currNode = list->last;
  }
  else {
    reverse  = 0;
    currPos  = 0;
    currNode = list->first;
  }  

  while(currNode != NULL) {
    if(currPos == pos)
      break;

    currNode = (reverse ? (currNode->prev) : (currNode->next));
    currPos  = (reverse ? (currPos-1) : (currPos+1));
  }

  return currNode;
}

int gll_add(void *data, int pos, LinkedListType *list) {

  if(pos > list->size || pos < 0)
    return C_NOK;

  NodeType *newNode;
  NodeType *currNode;

  //Create the new node
  newNode = (NodeType *) malloc(sizeof(NodeType));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  //list is empty
  if(list->size == 0) {
    list->first = newNode;
    list->last = newNode;

    list->size++;
    return C_OK;
  }
  
  currNode = gll_findNode(pos, list);

  //adding at the front or in the middle
  if(currNode != NULL) {
    newNode->prev = currNode->prev;
    newNode->next = currNode;  
    
    if(currNode->prev == NULL) {
      list->first = newNode;
    }
    else {
      currNode->prev->next = newNode;
    }
    currNode->prev = newNode;
  } 
  //adding at the end
  else {
    list->last->next = newNode;
    newNode->prev = list->last;
    list->last = newNode;    
  }
  
  list->size++;
  return C_OK;
}

int gll_remove(int pos, LinkedListType *list) {
  //pos is out of range
  if(pos >= list->size)
    return C_NOK;

  //list is empty
  if( list->size == 0)
    return C_NOK;
  
  NodeType *currNode = NULL;

  //remove last remaining node
  if( list->size == 1) {
    gll_deallocNode(list->first);  
    list->first = NULL;
    list->last = NULL;

    list->size--;
    return C_OK;
  }
    
  //remove node in position 0
  if(pos == 0) {
    currNode = list->first;    
    list->first = currNode->next;
    list->first->prev = NULL;
    gll_deallocNode(currNode);

    list->size--;
    return C_OK;
  }

  //remove node in last position
  if(pos == ( list->size - 1) ) {
    currNode = list->last;
    list->last = currNode->prev;
    list->last->next = NULL;
    gll_deallocNode(currNode);

    list->size--;
    return C_OK;
  }

  //remove node from the middle
  int currPos;
  int reverse;
  
  //decide whether to traverse forward or backward
  if( pos <= (list->size / 2) ) {
    currNode = list->first;
    reverse = 0;
    currPos = 0;
  }
  else {
    currNode = list->last;
    reverse = 1;
    currPos = list->size-1;
  }

  while(currNode != NULL) {
    if(currPos == pos)
      break;

    currPos = (reverse) ? (currPos - 1) : (currPos + 1);
    currNode = (reverse) ? currNode->prev : currNode->next;
  }

  currNode->prev->next = currNode->next;
  currNode->next->prev = currNode->prev;
  gll_deallocNode(currNode);

  list->size--;
  return C_OK;
}

void gll_each(void (*f)(void *), LinkedListType *list) {
  NodeType *currNode = list->first;

  while(currNode != NULL) {
    (*f)(currNode->data);
    currNode = currNode->next;
  }
}

void gll_deallocNode(NodeType *node) {
  free(node);
}

void gll_deallocList(LinkedListType *list) {
  NodeType *currNode = list->first;
  NodeType *nextNode;
  
  while(currNode != NULL) {
    nextNode = currNode->next;
    gll_deallocNode(currNode);
    currNode = nextNode;  
  }

  free(list);
} 
