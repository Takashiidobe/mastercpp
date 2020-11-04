#include <stdio.h>

#include "person_getter_setter_age.c"

int main() {
  struct Person *p = new_person();
  p->set_age(p, 20);
  printf("%ld\n", p->age);
}
