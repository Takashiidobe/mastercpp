#include <fcntl.h>
#include <unistd.h>

int main() {
  // create a file called test.txt, and if it doesn't exist, create it, if it
  // does exist, overwrite it. (this is what the O_WRONLY | O_CREAT does).
  int test_file = open("test.txt", O_WRONLY | O_CREAT, 0644);

  printf("%d\n", test_file);

  // make sure test_file > -1, otherwise there was an error opening/creating
  // file.
  if (test_file > -1) {
    // try to write to the test file
    int write_response = write(test_file, "Test text\n", 10);
    printf("%d\n", write_response);

    // success! close the file and terminate program.
    if (write_response == 10) {
      close(test_file);
      return 0;
    }

    // otherwise, there was an error.
    // close file we opened.
    close(test_file);
    // and log stderr.
    write(2, "There was an error writing to the file.", 39);
    return 0;
  }
  // error opening file. log stderr and terminate program.
  write(2, "There was an error opening the file.", 36);
}
