#include <unistd.h>

int main() {
  char buf[40];  // please dont give me more than 40 characters.
  write(0,
        "Type a string less than 40 characters and I will log it. If you type "
        "more than 40 characters, I crash.",
        103);
  if (read(0, buf, 128) < 0) {
    write(2, "An error occurred in the read.\n", 31);
  }
  write(0, buf, 40);
}
