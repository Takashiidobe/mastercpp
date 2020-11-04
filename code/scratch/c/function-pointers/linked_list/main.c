#include <stdio.h>

#include "linked_list.h"
#include "node.h"

int main() {
  struct LinkedList* ll = new_ll(30);
  ll->push_front(ll, 20);
  ll->push_front(ll, 10);
  printf("%d\n", ll->head->value);
  printf("%d\n", ll->head->next->value);
  printf("%d\n", ll->head->next->next->value);
  printf("%ld\n", ll->length);
  ll->free(ll);
}
