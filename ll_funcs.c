#include <stdio.h>
#include <stdlib.h>

#include "ll_defs.h"

int addNode(void *data, int pos, HeadType **list) {

  //if the position is out of range
  if(pos > (*list)->size || pos < 0)
    return C_NOK;

  NodeType *newNode;
  NodeType *currNode;

  //Create the new node
  newNode = (NodeType *) malloc(sizeof(NodeType));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  //list is empty
  if((*list)->size == 0) {
    (*list)->first = newNode;
    (*list)->last = newNode;

    (*list)->size++;
    return C_OK;
  }

  //add in position 0
  if(pos == 0) {
    (*list)->first->prev = newNode;
    newNode->next = (*list)->first;
    (*list)->first = newNode;

    (*list)->size++;
    return C_OK;
  }
     
  //add in last position
  if(pos == (*list)->size) {
    (*list)->last->next = newNode;
    newNode->prev = (*list)->last;
    (*list)->last = newNode;

    (*list)->size++;
    return C_OK;
  }

  //add somewhere in the middle of the list
  int currPos;
  int reverse;
 
  //decide whether to traverse forward or backward
  if( pos <= ((*list)->size / 2) ) {
    currNode = (*list)->first;
    reverse = 0;
    currPos = 0;
  }
  else {
    currNode = (*list)->last;
    reverse = 1;
    currPos = (*list)->size-1;
  }

  while(currNode != NULL) {
    if(currPos == pos)
      break;

    currPos = (reverse) ? (currPos - 1) : (currPos + 1);
    currNode = (reverse) ? currNode->prev : currNode->next;
  }

  currNode->prev->next = newNode;
  newNode->prev = currNode->prev;
  newNode->next = currNode;
  currNode->prev = newNode;

  (*list)->size++;
  return C_OK;  
}

int removeNode(int pos, HeadType **list) {
  //pos is out of range
  if(pos >= (*list)->size)
    return C_NOK;

  //list is empty
  if( (*list)->size == 0)
    return C_NOK;
  
  NodeType *currNode = NULL;

  //remove last remaining node
  if( (*list)->size == 1) {
    deallocNode((*list)->first);  
    (*list)->first = NULL;
    (*list)->last = NULL;

    (*list)->size--;
    return C_OK;
  }
    
  //remove node in position 0
  if(pos == 0) {
    currNode = (*list)->first;    
    (*list)->first = currNode->next;
    (*list)->first->prev = NULL;
    deallocNode(currNode);

    (*list)->size--;
    return C_OK;
  }

  //remove node in last position
  if(pos == ( (*list)->size - 1) ) {
    currNode = (*list)->last;
    (*list)->last = currNode->prev;
    (*list)->last->next = NULL;
    deallocNode(currNode);

    (*list)->size--;
    return C_OK;
  }

  //remove node from the middle
  int currPos;
  int reverse;
  
  //decide whether to traverse forward or backward
  if( pos <= ((*list)->size / 2) ) {
    currNode = (*list)->first;
    reverse = 0;
    currPos = 0;
  }
  else {
    currNode = (*list)->last;
    reverse = 1;
    currPos = (*list)->size-1;
  }

  while(currNode != NULL) {
    if(currPos == pos)
      break;

    currPos = (reverse) ? (currPos - 1) : (currPos + 1);
    currNode = (reverse) ? currNode->prev : currNode->next;
  }

  currNode->prev->next = currNode->next;
  currNode->next->prev = currNode->prev;
  deallocNode(currNode);

  (*list)->size--;
  return C_OK;
}

void each(void (*f)(void *), HeadType **list) {
  NodeType *currNode = (*list)->first;

  while(currNode != NULL) {
    (*f)(currNode->data);
    currNode = currNode->next;
  }
}

void deallocNode(NodeType *node) {
  free(node);
}

void deallocList(HeadType **list) {
  NodeType *currNode = (*list)->first;
  NodeType *nextNode;
  
  while(currNode != NULL) {
    nextNode = currNode->next;
    deallocNode(currNode);
    currNode = nextNode;  
  }
} 
