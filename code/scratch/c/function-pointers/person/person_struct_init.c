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

struct Person *new_person() {
  struct Person *p = malloc(sizeof(struct Person));
  p->get_age = get_age;
  return p;
}
