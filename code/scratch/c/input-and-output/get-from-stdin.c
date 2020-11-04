#include <stdio.h>

int main() {
  char buf[40];  // please dont give me more than 40 characters.
  printf(
      "Type a string less than 40 characters and I will log it. If you type "
      "more than 40 characters, I crash.");
  scanf("%s", buf);
  printf("%s\n", buf);
}
