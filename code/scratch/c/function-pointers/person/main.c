#include <stdio.h>

#include "person.h"

int main() {
  struct Person *p = new_person("Pumpkin", 11);
  printf("My name is: %s\n", p->name);
  printf("My age is: %ld\n", p->age);
  p->set_name(p, "Takashi");
  printf("My name is: %s\n", p->name);
  printf("My age is: %ld\n", p->age);
}
