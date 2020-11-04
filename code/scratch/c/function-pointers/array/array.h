#ifndef ARRAY_H
#define ARRAY_H

struct Array {
  size_t size;
  size_t capacity;
  int *array;
  void (*push)(struct Array *self, const int value);
  const int (*pop)(struct Array *self);
  const int (*get)(struct Array *self, const size_t index);
  void (*set)(struct Array *self, const size_t index, const int value);
  void (*free)(const struct Array *self);
};

struct Array *new_array();

#endif
