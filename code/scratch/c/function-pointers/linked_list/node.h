#ifndef NODE_H
#define NODE_H

struct Node {
  int value;
  struct Node* next;
};

struct Node* new_node(int value);

#endif
