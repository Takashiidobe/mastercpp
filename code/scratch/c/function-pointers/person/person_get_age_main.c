#include <stdio.h>

#include "person_struct_init.c"

int main() {
  struct Person *p = new_person();
  printf("%ld\n", p->age);
}
