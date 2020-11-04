#include <stdio.h>

typedef struct Something {
  int values[5];
} Something;

typedef struct Nothing {
  void *values;
} Nothing;

typedef struct Maybe {
  union {
    struct Something;
    struct Nothing;
  };
} Maybe;

void loop_with_goto(int matrix[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = 5;
      printf("%d\n", matrix[i][j]);
      if (j == 2) goto leave;
    }
  }
leave:
  printf("We're out of the matrix.\n");
}

void loop_with_break(int matrix[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = 5;
      printf("%d\n", matrix[i][j]);
      if (j == 2) break;
    }
    break;
  }
  printf("We're out of the matrix.\n");
}

int main() {
  int matrix[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  loop_with_goto(matrix);
  loop_with_break(matrix);
}
