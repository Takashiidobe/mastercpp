#include <atomic>
#include <cstdio>

int main() {
  std::atomic<int> votes = {0};
  for (int i = 0; i < 10'000'000; i++)
    votes++;

  printf("%d\n", votes.load());
}
