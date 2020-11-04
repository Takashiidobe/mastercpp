#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

struct LinkedList {
  struct Node* head;
  size_t length;
  void (*push_front)(struct LinkedList* self, const int value);
  const int (*pop_front)(struct LinkedList* self);
  void (*free)(const struct LinkedList* self);
};

struct LinkedList* new_ll(const int value);

#endif
