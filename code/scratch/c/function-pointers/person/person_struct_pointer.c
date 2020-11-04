#include <stdlib.h>

struct Person {
  char *name;
  size_t age;
  const size_t (*get_age)(struct Person *self);
};
