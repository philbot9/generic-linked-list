#define C_OK 0
#define C_NOK -1

typedef struct Node {
  void *data;
  struct Node *prev;
  struct Node *next;
} NodeType;

typedef struct {
  int size;
  NodeType *first;
  NodeType *last;
} LinkedListType;

LinkedListType *gll_init();
int gll_add(void *, int, LinkedListType **);
int gll_remove(int, LinkedListType **);
void gll_each(void (*f)(void *), LinkedListType **list);
void gll_deallocNode(NodeType *);
void gll_deallocList(LinkedListType **);

