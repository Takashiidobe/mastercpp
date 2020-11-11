#include <stdio.h>

struct X {
  int x;
};

struct Y {
  int y;
};

struct Z {
  int z;
};

struct Point {
  struct X x;
  struct Y y;
  struct Z z;
};

int main() {
  struct Point point = {.x = {.x = 10}, .y = {.y = 20}, .z = {.z = 30}};

  printf("x: %d, y: %d, z: %d\n", point.x.x, point.y.y, point.z.z);
}
