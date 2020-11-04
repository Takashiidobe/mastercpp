#include <stdio.h>

typedef enum error_t { NO_MEMORY, DIVIDE_BY_ZERO, STACK_OVERFLOW } error_t;

void print_error(error_t* error_list, size_t err_len) {
  static const struct {
    int code;
    const char* str;
  } errors[] = {
      {NO_MEMORY, "out of memory"},
      {DIVIDE_BY_ZERO, "divide by zero"},
      {STACK_OVERFLOW, "stack overflow"},
      {0, NULL},
  };

  for (int j = 0; j < err_len; j++) {
    for (int i = 0; errors[i].str != NULL; i++) {
      if (errors[i].code == error_list[j]) {
        printf("%s\n", errors[i].str);
        break;
      }
    }
  }
}

int main() {
  error_t errors[] = {NO_MEMORY, NO_MEMORY, DIVIDE_BY_ZERO, STACK_OVERFLOW};
  print_error(errors, 4);
}
