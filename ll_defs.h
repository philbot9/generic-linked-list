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
} HeadType;

int addNode(void *, int, HeadType **);
int removeNode(int, HeadType **);
void each(void (*f)(void *), HeadType **list);
void deallocNode(NodeType *);
void deallocList(HeadType **);

