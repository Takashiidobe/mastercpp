#include <assert.h>
#include <stdlib.h>

#include "node.h"

struct LinkedList {
  struct Node* head;
  size_t length;
  void (*push_front)(struct LinkedList* self, const int value);
  const int (*pop_front)(struct LinkedList* self);
  void (*free)(struct LinkedList* self);
};

static void push_front(struct LinkedList* self, const int value) {
  struct Node* node = new_node(value);
  node->next = self->head;
  self->head = node;
  self->length++;
}

static const int pop_front(struct LinkedList* self) {
  assert(self->head != NULL);
  int popped = self->head->value;
  self->head = self->head->next;
  self->length--;
  return popped;
}

static void free_list(struct LinkedList* self) {
  struct Node* tmp;

  while (self->head != NULL) {
    tmp = self->head;
    self->head = self->head->next;
    free(tmp);
  }

  self->length = 0;
}

struct LinkedList* new_ll(const int value) {
  struct Node* head = new_node(value);
  struct LinkedList* ll = malloc(sizeof(struct LinkedList));
  ll->head = head;
  ll->length = 0;
  ll->push_front = push_front;
  ll->free = free_list;
  ll->pop_front = pop_front;
  return ll;
}
