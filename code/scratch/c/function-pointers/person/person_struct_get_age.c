#include <assert.h>
#include <stdlib.h>

struct Person {
  char *name;
  size_t age;
  const size_t (*get_age)(struct Person *self);
};

static const size_t get_age(struct Person *self) {
  assert(self != NULL);
  return self->age;
}
