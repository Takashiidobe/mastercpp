#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buf = malloc(sizeof(char) * 10000000);

  for (int i = 0; i < 10000000; i++)
    buf[i] = 'h';

  printf("%s\n", buf);

  free(buf);
}
