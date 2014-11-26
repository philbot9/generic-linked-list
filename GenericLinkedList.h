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
void *gll_get(int, LinkedListType *);

int gll_add(void *, int, LinkedListType *);
int gll_push(void *, LinkedListType *);
int gll_pushFront(void *, LinkedListType *);

int gll_remove(int, LinkedListType *);
void *gll_pop(LinkedListType *);
void *gll_popFront(LinkedListType *);

void gll_each(void (*f)(void *), LinkedListType *);
void gll_eachReverse(void (*f)(void *), LinkedListType *);

void gll_destroy(LinkedListType *);

static NodeType *gll_findNode(int, LinkedListType *);
