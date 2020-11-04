#include <chrono>
#include <ctime>
#include <iostream>
#include <map>
#include <mutex>
#include <random>
#include <thread>

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 10000);
std::uniform_int_distribution<std::mt19937::result_type> dist2(1, 2);

std::map<int, const char*> votes;

// std::mutex votes_mutex;

// w/ mutex, 5.634 seconds. w/o mutex, 4.48 seconds. We made it 20% slower :)

void task() {
  for (int i = 0; i < 50'000; i++) {
    auto vote_id = dist6(rng);
    auto vote = dist2(rng) == 1 ? "PERSON_1" : "PERSON_2";
    // get mutex
    // const std::lock_guard<std::mutex> lock(votes_mutex);
    if (!votes.contains(vote_id)) {
      votes.insert({vote_id, vote});
    }
    // unlock mutex here

    std::cout << vote_id << '\n' << vote << '\n';
  }
}

int main() {
  const auto start = std::chrono::system_clock::now();

  // for (int i = 0; i < 5; i++) task();
  std::thread t1{task};
  std::thread t2{task};
  std::thread t3{task};
  std::thread t4{task};
  std::thread t5{task};

  for (const auto& [id, vote] : votes) {
    std::cout << id << '\n' << vote << '\n';
  }

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();

  const auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;

  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
