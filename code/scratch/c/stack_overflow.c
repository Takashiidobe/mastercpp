#include <stdio.h>
#include <sys/resource.h>

int main() {
  struct rlimit limit;

  getrlimit(RLIMIT_STACK, &limit);
  printf("\nStack Limit = %lld and %lld max\n", limit.rlim_cur, limit.rlim_max);

  int arr[1000000];

  printf("%lu\n", sizeof(arr));
}
