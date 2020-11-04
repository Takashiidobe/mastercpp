#include <fcntl.h>
#include <unistd.h>

int main() {
  char buf[40];
  int file_to_read = open("test.txt", O_RDONLY);
  // file opened successfully.
  if (file_to_read > -1) {
    int read_response = read(file_to_read, buf, sizeof(buf) - 1);
    int buf_size = 0;
    while (buf[buf_size] != '\0') buf_size++;

    if (read_response == buf_size)
      write(1, buf, sizeof(buf) - 1);
    else
      write(2, "An error occurred in reading test.txt.\n", 39);

    close(file_to_read);
    return 0;
  }
  write(2, "There was an error opening test.txt", 35);
}
