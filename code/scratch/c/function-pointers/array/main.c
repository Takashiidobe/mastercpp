#include <stdio.h>

#include "array.h"

int main() {
  struct Array *a = new_array();
  for (int i = 0; i < 33; i++) {
    a->push(a, i + 1);
  }
  a->set(a, 27, 50);
  printf("Element at position 27: %d\n", a->get(a, 27));
  printf("Array Size: %ld\n", a->size);
  printf("Array Capacity: %ld\n", a->capacity);
  for (int i = 32; i > 0; i--) {
    a->pop(a);
  }
  printf("Element at position 0: %d\n", a->get(a, 0));
  printf("Array Size: %ld\n", a->size);
  printf("Array Capacity: %ld\n", a->capacity);
  a->free(a);
}
