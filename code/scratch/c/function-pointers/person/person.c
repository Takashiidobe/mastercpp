#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  const char *name;
  size_t age;
  const char *(*get_name)(struct Person *self);
  void (*set_name)(struct Person *self, const char *name);
  const size_t (*get_age)(struct Person *self);
  void (*set_age)(struct Person *self, size_t age);
};

static const char *get_name(struct Person *self) {
  assert(self != NULL);
  return self->name;
}

static void set_name(struct Person *self, const char *name) {
  assert(self != NULL);
  self->name = name;
}

static const size_t get_age(struct Person *self) {
  assert(self != NULL);
  return self->age;
}

static void set_age(struct Person *self, size_t age) {
  assert(self != NULL);
  self->age = age;
}

struct Person *new_person(const char *name, const size_t age) {
  struct Person *p = malloc(sizeof(struct Person));
  p->name = name;
  p->age = age;
  p->get_name = get_name;
  p->set_name = set_name;
  p->get_age = get_age;
  p->set_age = set_age;
  return p;
}
