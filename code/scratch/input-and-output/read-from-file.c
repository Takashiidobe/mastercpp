#include <stdio.h>

int main() {
  char buf[40];  // this buffer can only hold 39 characters.
  // try to open test.txt to read in.
  FILE* file_to_read = fopen("test.txt", "r");
  // we successfully opened the file.
  if (file_to_read != NULL) {
    int read_response = fread(buf, sizeof(buf) - 1, 1, file_to_read);
    // success! print buffer.
    if (read_response != -1) {
      printf("%s\n", buf);
    } else {
      fprintf(stderr, "there was an error reading from test.txt");
    }
    // close file.
    fclose(file_to_read);
    return 0;
  }
  // error opening file. log to stderr.
  fprintf(stderr, "test.txt could not be opened.");
}
