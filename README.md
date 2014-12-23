Generic Doubly Linked List
=================
A doubly linked list implementation in C. The list stores (void) pointers to the data. The actual data is never copied, modified or deleted in this implementation. This allows for the same data to be stored in multiple different lists.

###Features
* Fast Stack operations (push/pop)
* Fast queue operations (push/popBack)
* Fast Deque operations (push/pushBack and pop/popBack)
* Forward/Backward iteration with function parameter

###API
#####__Types__
---
**gll_t** - Generic Linked List Type

| *Type & Name* |  *Description* |
|-----|-----|
|`unsigned int size` | _number of elements_ |
|`gll_node_t *first`|  _pointer to head node_ |
|`gll_node_t *last`| _pointer to tail node_ |
___
**gll_node_t** - List Node Type     

| *Type & Name* |  *Description* |
|-----|-----|
|`void *data` | _pointer to data stored at node_ |
|`gll_node_t *prev` | _pointer to previous node_ |
|`gll_node_t *last` | _pointer to next node_ |
_ _ _
#####__Functions__
- - -

#####*gll_init*
Allocate and initialize a new list.

|Prototype:|`gll_t *gll_init()`|
|-----|-----|
| __Return:__   | _pointer to new list_ |
___


#####*gll_get*
Gets the pointer to the data stored at the node at the position. Returns NULL if position does not exist.

|Prototype:|`void *gll_get(gll_t *list, int position)`|
|-----|-----|
| ___list___ | _pointer to list to retrieve data from_ |
| ___position___| _position of data in the list_ |
| __Return:__   | _void pointer to data_ |
___


#####*gll_first*
Gets the pointer to the data at the head of the list (position 0). Returns NULL if list is empty.

|Prototype:|`void *gll_last(gll_t *list)`|
|-----|-----|
| ___list___ | _pointer to list to retrieve data from_ |
| __Return:__   | _void pointer to data_ |
___


#####*gll_last*
Gets the pointer to the data stored at the tail of the list (last position). Returns NULL if list is empty.

|Prototype:|`void *gll_last(gll_t *list)`|
|-----|-----|
| ___list___ | _pointer to list to retrieve data from_ |
| __Return:__   | _void pointer to data_ |
___


#####*gll_add*
Add a new element at an arbitrary position. Returns -1 if unsuccessful.

|Prototype:|`int gll_add(gll_t *list, void *data, int postion)`|
|-----|-----|
| ___list___ | _pointer to list to add data to_|
| ___data___ | _pointer to data to be stored_ |
| ___position___| _position of data in the list_ |
| __Return:__   | _0 on success, -1 on failure_ |
___


#####*gll_push*
Add a new element at the head of the list (position 0).

|Prototype:|`int gll_push(gll_t *list, void *data)`|
|-----|-----|
| ___list___ | _pointer to list to add data to_|
| ___data___ | _pointer to data to be stored_ |
| __Return:__   | _0 on success, -1 on failure_ |
___


#####*gll_pushBack*
Add a new element at the tail of the list (last position).

|Prototype:|`int gll_pushBack(gll_t *list, void *data)`|
|-----|-----|
| ___list___ | _pointer to list to add data to_|
| ___data___ | _pointer to data to be stored_ |
| __Return:__   | _0 on success, -1 on failure_ |
___


#####*gll_remove*
Remove an element at an arbitrary position. Returns the pointer to the data stored at the removed node, or NULL if unsuccessful.

|Prototype:|`int gll_remove(gll_t *list, int position)`|
|-----|-----|
| ___list___ | _pointer to list to remove data from_|
| ___position___| _position of element to remove_ |
| __Return:__   | _pointer to data or NULL if not found_ |
___


/*
 * remove the head of the list and return its value
 * in:        pointer to list
 * returns:   pointer to data of first node/NULL if empty
 */
void *gll_pop(gll_t *list) 
{
  gll_node_t *node = list->first;
  if(node == NULL)
    return NULL;

  void *data = node->data;

  if(gll_remove(list, 0) != C_OK)
    return NULL;

  return data;
}

/*
 * remove the tail of the list and return its value
 * in:        pointer to list
 * returns:   pointer to data of last node/NULL if empty
 */ 
void *gll_popBack(gll_t *list) 
{
  gll_node_t *node = list->last;
  if(node == NULL)
    return NULL;

  void *data = node->data;

  if(gll_remove(list, (list->size-1)) != C_OK)
    return NULL;

  return data;
}

/*
 * iterates over the entire list from the beginning and 
 * calls the specified function with with each element.
 * in:        pointer to list
 * in:        pointer to function
 *            ** function must be of return type void and
 *            ** take void pointer as parameter
 */
void gll_each(gll_t *list, void (*f)(void *)) 
{
  gll_node_t *currNode = list->first;

  while(currNode != NULL) {
    (*f)(currNode->data);
    currNode = currNode->next;
  }
}

/*
 * iterates over the entire list from the end and
 * calls the specified function with each element.
 * in:        pointer to list
 * in:        pointer to function
 *            ** function must be of return type void and
 *            ** take void pointer as parameter
 */
void gll_eachReverse(gll_t *list, void (*f)(void *)) 
{
  gll_node_t *currNode = list->last;

  while(currNode != NULL) {
    (*f)(currNode->data);
    currNode = currNode->prev;
  }
}

/*
 * destroys the list and allocates a new (empty)
 * in its memory location
 * in:        pointer to list
 */
void gll_clear(gll_t *list) 
{
  gll_node_t *currNode = list->first;
  gll_node_t *nextNode;

  while(currNode != NULL) {
    nextNode = currNode->next;
    free(currNode);
    currNode = nextNode;
  }

  list->first = NULL;
  list->last = NULL;
  list->size = 0;
}

/*
 * destroys a list and frees all list related memory
 * Does not touch the data stored at the nodes!
 * in:        pointer to list
 */
void gll_destroy(gll_t *list) 
{
  gll_node_t *currNode = list->first;
  gll_node_t *nextNode;
  
  while(currNode != NULL) {
    nextNode = currNode->next;
    free(currNode);
    currNode = nextNode;  
  }
  free(list);
} 