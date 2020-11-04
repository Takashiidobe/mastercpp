#include <assert.h>
#include <stdlib.h>

struct Person {
  char *name;
  size_t age;
  const size_t (*get_age)(struct Person *self);
  void (*set_age)(struct Person *self, size_t age);
};

static const size_t get_age(struct Person *self) {
  assert(self != NULL);
  return self->age;
}

static void set_age(struct Person *self, size_t age) {
  assert(self != NULL);
  self->age = age;
}

struct Person *new_person() {
  struct Person *p = malloc(sizeof(struct Person));
  p->get_age = get_age;
  p->set_age = set_age;
  return p;
}
