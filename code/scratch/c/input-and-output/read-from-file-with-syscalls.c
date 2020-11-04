#include <fcntl.h>
#include <unistd.h>

int main() {
  char buf[40];  // allocate a buffer of 39 characters.
  int file_to_read = open("test.txt", O_RDONLY);
  // file opened successfully.
  if (file_to_read > -1) {
    // read up to 39 characters into buf.
    int read_response = read(file_to_read, buf, sizeof(buf) - 1);
    // calculate how much we read into buf.
    int buf_size = 0;
    while (buf[buf_size] != '\0') buf_size++;

    // success! log stdout.
    if (read_response == buf_size) write(1, buf, sizeof(buf) - 1);
    // failure. log stderr.
    else
      write(2, "An error occurred in reading test.txt.\n", 39);

    // close file and terminate program.
    close(file_to_read);
    return 0;
  }
  // file failed to open.
  write(2, "There was an error opening test.txt", 35);
}
