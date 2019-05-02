Generic Doubly Linked List
=================
A doubly linked list implementation in C. The list stores (void) pointers to the data. The actual data is never copied, modified or deleted in this implementation. This allows for the same data to be stored in multiple different lists.

### Features
* Fast Stack operations (push/pop)
* Fast Queue operations (pushBack/pop)
* Fast Deque operations (push/pushBack and pop/popBack)
* Forward/Backward iteration with function parameter

### Performance

| Function | Running Time |
|---|---|
|gll_get / gll_set | O(1 + min{size-i, i} ) |
|gll_first / gll_last | O(1) |
|gll_add | O(1 + min{size-i, i} ) |
|gll_pop / gll_popBack| O(1) |
|gll_push / gll_pushBack| O(1) |
_ _ _

###### Performance Test

```
Number of Nodes: 10000000

  gll_pushBack() (All):        1016.8580 ms
  gll_popBack() (All):          803.8800 ms
  gll_push() (All):             655.6550 ms
  gll_pop() (All):              793.6100 ms

  gll_pushBack() (All):         660.2480 ms

  1 * gll_get() (middle):        55.3450 ms
  1 * gll_get() (end):            0.0030 ms
  1 * gll_get() (begin):          0.0010 ms

  1 * gll_set() (middle):        56.5100 ms
  1 * gll_set() (end):            0.0010 ms
  1 * gll_set() (begin):          0.0010 ms

  1 * gll_add() (middle):        54.9220 ms
  1 * gll_add() (end):            0.0040 ms
  1 * gll_add() (begin):          0.0020 ms

  1 * gll_remove() (middle):     55.1510 ms
  1 * gll_remove() (end):         0.0030 ms
  1 * gll_remove() (begin):       0.0010 ms

  gll_each():                   122.4990 ms
  gll_eachReverse():            123.8290 ms

```

### Usage
###### Library

```
make
make install
make uninstall
```

###### Tests
```
make tests
./tests
```

###### Performance Tests
```
make performance
./performance
./performance [number of nodes]
```



### API

 **Types**
 * [gll_t - Generic Linked List Type](#anch_gll_t)
 * [gll_node_t - List Node Type](#anch_gll_node_t)
 
**Functions**
 * [gll_init](#anch_gll_init)
 * [gll_get](#anch_gll_get)
 * [gll_set](#anch_gll_set)
 * [gll_first](#anch_gll_first)
 * [gll_last](#anch_gll_last)
 * [gll_add](#anch_gll_add)
 * [gll_push](#anch_gll_push)
 * [gll_pushBack](#anch_gll_pushBack)
 * [gll_remove](#anch_gll_remove)
 * [gll_pop](#anch_gll_pop)
 * [gll_popBack](#anch_gll_popBack)
 * [gll_each](#anch_gll_each)
 * [gll_eachReverse](#anch_gll_eachReverse)
 * [gll_clear](#anch_gll_clear)
 * [gll_destroy](#anch_gll_destroy)


#### __Types__
---
<a name="anch_gll_t"></a>
##### *gll_t* - *Generic Linked List Type*

| *Type & Name* |  *Description* |
|-----|-----|
|`int size` | _number of elements_ |
|`gll_node_t *first`|  _pointer to head node_ |
|`gll_node_t *last`| _pointer to tail node_ |
___

<a name="anch_gll_node_t"></a>
##### *gll_node_t* - *List Node Type*

| *Type & Name* |  *Description* |
|-----|-----|
|`void *data` | _pointer to data stored at node_ |
|`gll_node_t *prev` | _pointer to previous node_ |
|`gll_node_t *next` | _pointer to next node_ |
_ _ _
#### __Functions__
- - -
<a name="anch_gll_init"></a>
##### *gll_init* 
Allocates and initializes a new list.

|Prototype:|`gll_t *gll_init()`|
|-----|-----|
| __Return:__   | _pointer to new list_ |
___

<a name="anch_gll_get"></a>
##### *gll_get*
Gets the pointer to the data stored at the node in an arbitrary position. Returns NULL if position does not exist.

|Prototype:|`void *gll_get(gll_t *list, int position)`|
|-----|-----|
| ___list___ | _pointer to list to retrieve data from_ |
| ___data___| _pointer to new data to be stored_ |
| ___position___| _position of node in the list_ |
| __Return:__   | _void pointer to previous data or NULL if not found_ |
___

<a name="anch_gll_set"></a>
##### *gll_set*
Sets the data pointer of a node at an arbitrary position. Returns pointer that was previously stored at that node or NULL if position does not exist.

|Prototype:|`void *gll_get(gll_t *list, int position)`|
|-----|-----|
| ___list___ | _pointer to list to retrieve data from_ |
| ___position___| _position of data in the list_ |
| __Return:__   | _void pointer to data or NULL if not found_ |
___


<a name="anch_gll_first"></a>
##### *gll_first*
Gets the pointer to the data at the head of the list (position 0). Returns NULL if list is empty.

|Prototype:|`void *gll_last(gll_t *list)`|
|-----|-----|
| ___list___ | _pointer to list to retrieve data from_ |
| __Return:__   | _void pointer to data or NULL if list is empty_ |
___

<a name="anch_gll_last"></a>
##### *gll_last*
Gets the pointer to the data stored at the tail of the list (last position). Returns NULL if list is empty.

|Prototype:|`void *gll_last(gll_t *list)`|
|-----|-----|
| ___list___ | _pointer to list to retrieve data from_ |
| __Return:__   | _void pointer to data or NULL if list is empty_ |
___

<a name="anch_gll_add"></a>
##### *gll_add*
Adds a new element at an arbitrary position. Returns -1 if unsuccessful.

|Prototype:|`int gll_add(gll_t *list, void *data, int position)`|
|-----|-----|
| ___list___ | _pointer to list to add data to_|
| ___data___ | _pointer to data to be stored_ |
| ___position___| _position of data in the list_ |
| __Return:__   | _0 on success, -1 on failure_ |
___

<a name="anch_gll_push"></a>
##### *gll_push*
Adds a new element at the head of the list (position 0).

|Prototype:|`int gll_push(gll_t *list, void *data)`|
|-----|-----|
| ___list___ | _pointer to list to add data to_|
| ___data___ | _pointer to data to be stored_ |
| __Return:__   | _0 on success, -1 on failure_ |
___

<a name="anch_gll_pushBack"></a>
##### *gll_pushBack*
Adds a new element at the tail of the list (last position).

|Prototype:|`int gll_pushBack(gll_t *list, void *data)`|
|-----|-----|
| ___list___ | _pointer to list to add data to_|
| ___data___ | _pointer to data to be stored_ |
| __Return:__   | _0 on success, -1 on failure_ |
___

<a name="anch_gll_remove"></a>
##### *gll_remove*
Removes an element at an arbitrary position. Returns the pointer to the data stored at the removed node, or NULL if unsuccessful.

|Prototype:|`int gll_remove(gll_t *list, int position)`|
|-----|-----|
| ___list___ | _pointer to list to remove data from_|
| ___position___| _position of element to remove_ |
| __Return:__   | _pointer to data or NULL if not found_ |
___


<a name="anch_gll_pop"></a>
##### *gll_pop*
Removes the head of the list (position 0) and return the pointer stored at that position. Returns NULL if list is empty.

|Prototype:|`void *gll_pop(gll_t *list)`|
|-----|-----|
| ___list___ | _pointer to list to remove data from_|
| __Return:__   | _pointer to data or NULL if list is empty_ |
___


<a name="anch_gll_popBack"></a>
##### *gll_popBack*
Removes the tail of the list (last position) and return the pointer stored at that position. Returns NULL if list is empty.

|Prototype:|`void *gll_popBack(gll_t *list)`|
|-----|-----|
| ___list___ | _pointer to list to remove data from_|
| __Return:__   | _pointer to data or NULL if list is empty_ |
___

<a name="anch_gll_each"></a>
##### *gll_each*
Iterates over the entire list from beginning to end and calls the specified function with each element as a parameter. The function must be of return type void and take a void pointer (void *) parameter.

|Prototype:|`void gll_each(gll_t *list, void (*function)(void *))`|
|-----|-----|
| ___list___ | _pointer to list_|
| ___function___ | _pointer to function_|
___

<a name="anch_gll_eachReverse"></a>
##### *gll_eachReverse*
Iterates over the entire list from end to beginning and calls the specified function with each element as a parameter. The function must be of return type void and take a void pointer (void *) parameter.

|Prototype:|`void gll_eachReverse(gll_t *list, void (*function)(void *))`|
|-----|-----|
| ___list___ | _pointer to list_|
| ___function___ | _pointer to function_|
___

<a name="anch_gll_clear"></a>
##### *gll_clear*
Clears the entire list and deallocates all **nodes**. The data that is referenced by each node is not touched.

|Prototype:|`void *gll_clear(gll_t *list)`|
|-----|-----|
| ___list___ | _pointer to list_|
___

<a name="anch_gll_destroy"></a>
##### *gll_destroy*
Clears the list and deallocates all list-related memory. The data referenced by each node is not touched.

|Prototype:|`void *gll_destroy(gll_t *list)`|
|-----|-----|
| ___list___ | _pointer to list_|
___
