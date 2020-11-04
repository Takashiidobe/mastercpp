#include <stdio.h>

typedef enum point_t { int_point, float_point } point_t;

typedef struct point {
  point_t t;
  union {
    struct {
      int a;
      int b;
      int c;
    };
    struct {
      float x;
      float y;
      float z;
    };
  };
} point;

void print_point(point p) {
  if (p.t == int_point) {
    printf("(%d, %d, %d)\n", p.a, p.b, p.c);
  } else if (p.t == float_point) {
    printf("(%f, %f, %f)\n", p.x, p.y, p.z);
  }
  printf("not a valid point");
}

int main() {
  point p;
  p.t = int_point;
  p.a = 10;
  p.b = 20;
  p.c = 30;

  print_point(p);

  point fp;
  fp.t = float_point;
  fp.x = 0.1;
  fp.y = 0.2;
  fp.z = 0.3;

  print_point(fp);
}
