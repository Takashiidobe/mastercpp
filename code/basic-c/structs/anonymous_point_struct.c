#include <stdio.h>

struct Point {
  struct {
    int x;
  };
  struct {
    int y;
  };
  struct {
    int z;
  };
};

int main() {
  struct Point point = {.x = 10, .y = 20, .z = 30};

  printf("x: %d, y: %d, z: %d\n", point.x, point.y, point.z);
}
