#include <assert.h>
#include <stdlib.h>
#include <string.h>

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

static void push(struct Array *self, const int value) {
  if (self->size == self->capacity) {
    self->capacity *= 2;
    int *old_array = malloc(sizeof(size_t) * self->capacity);
    memcpy(old_array, self->array, sizeof(size_t) * self->capacity);
    old_array[self->size] = value;
    memcpy(self->array, old_array, sizeof(size_t) * self->capacity);
  } else {
    self->array[self->size] = value;
  }
  self->size++;
}

static const int pop(struct Array *self) {
  assert(self->size > 0);
  if (self->capacity / 2 > self->size) {
    self->capacity /= 2;
    int *old_array = malloc(sizeof(size_t) * self->size);
    memcpy(old_array, self->array, sizeof(size_t) * self->size);
    memcpy(self->array, old_array, sizeof(size_t) * self->size);
  }
  int value_to_pop = self->array[self->size - 1];
  self->size--;
  return value_to_pop;
}

static const int get(struct Array *self, const size_t index) {
  assert(index < self->capacity);
  return self->array[index];
}

static void set(struct Array *self, const size_t index, const int value) {
  assert(self->size > index);
  self->array[index] = value;
}

static void free_arr(const struct Array *self) {
  if (self != NULL) {
    free(self->array);
    free(self);
  }
}

struct Array *new_array() {
  struct Array *a = malloc(sizeof(struct Array));
  a->size = 0;
  a->capacity = 8;
  a->push = push;
  a->set = set;
  a->pop = pop;
  a->free = free_arr;
  a->get = get;
  a->array = malloc(sizeof(int) * a->capacity);
  return a;
}
