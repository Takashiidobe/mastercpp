#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
  int value;
} Data;

typedef struct Maybe {
  bool set;
  Data data;
} Maybe;

void set_data(Maybe* m, int data) {
  if (!m->set) {
    m->data.value = data;
    m->set = true;
  }
}

int get_data(Maybe* m) {
  if (!m->set) return -1;

  return m->data.value;
}

int main() {
  Maybe* m = malloc(sizeof(Maybe));
  set_data(m, 10);
  if (get_data(m) != -1) {
    printf("%d\n", get_data(m));
  }
  free(m);
}
