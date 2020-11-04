#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
};

const struct Node* new_node(int value) {
  struct Node* n = malloc(sizeof(struct Node));
  n->value = value;
  return n;
}
