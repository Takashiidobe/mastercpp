#include <stdio.h>

struct Person {
  char *name;
  int age;
};

int main() {
  struct Person p1 = {"Person", 20};
  struct Person p2 = {.name = "Person", .age = 20};
  struct Person p3 = {name : "Person", age : 20};

  printf("My name is: %s, and my age is: %d\n", p1.name, p1.age);
  printf("My name is: %s, and my age is: %d\n", p2.name, p2.age);
  printf("My name is: %s, and my age is: %d\n", p3.name, p3.age);
}
