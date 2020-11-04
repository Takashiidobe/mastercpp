#include <stdio.h>

int main() {
  // create a file called test.txt, and if it doesn't exist, create it, if it
  // does exist, overwrite it. (this is what the "w+" does).
  FILE* test_file = fopen("test.txt", "w+");

  // make sure test_file != NULL, otherwise there was an error.
  if (test_file != NULL) {
    // try to write to file.
    int write_response = fprintf(test_file, "Test text");
    // if there's an error, log.
    if (write_response == -1)
      fprintf(stderr, "There was an error writing to the file.");

    // otherwise, close file and terminate program.
    fclose(test_file);
    return 0;
  }

  // otherwise, error opening file. log error and close file.
  fprintf(stderr, "There was an error opening the file.");
  fclose(test_file);
}
