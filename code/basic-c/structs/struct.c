#include <stdio.h>

struct Person {
  char *name;
  int age;
};

int main() {
  struct Person p;
  p.name = "Person";
  p.age = 20;

  printf("My name is: %s, and my age is: %d\n", p.name, p.age);
}
