#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>

struct Person {
  char *name;
  size_t age;
  const char *(*get_name)(struct Person *self);
  void (*set_name)(struct Person *self, char *name);
  const size_t (*get_age)(struct Person *self);
  void (*set_age)(struct Person *self, size_t age);
};

struct Person *new_person(char *name, size_t age);

#endif
