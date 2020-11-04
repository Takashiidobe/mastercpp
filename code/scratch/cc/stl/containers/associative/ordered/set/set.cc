#include <iostream>
#include <set>

int main() {
  // use operator= with an initializer list
  std::set<int> s = {1, 2, 3, 4, 4, 4};
  // iterate over each item
  for (const int item : s) std::cout << item << " ";  // prints out 1 2 3 4
  // get the first iterator
  std::set<int>::iterator first_item = s.begin();

  // returns a boolean determining if the container is empty
  const bool is_empty = s.empty();

  // return size of container
  const size_t set_size = s.size();

  // return maximum size of container
  const size_t set_max_size = s.max_size();

  // clear the contents of the set.
  s.clear();

  // insert some items into the set.
  s.insert(1);
  // initializer list works too
  s.insert({2, 3, 4});

  // emplace works without constructing the element
  // returns std::pair<T*, bool> where T* points to where T was inserted and
  // bool is if the insertion succeeded.
  // const auto result = s.emplace(5);
  // we can use a variadic constructor too
  // s.emplace(6, 7, 8);

  // erase the element 8.
  // s.erase(8);

  std::set<int> swap_set = {1, 2, 3};
  // swap the values of s with the values in swap_set.
  s.swap(swap_set);

  std::set<int> s1 = {1, 2, 3};
  auto value_to_extract = s1.extract(1).value();
  value_to_extract += 4;
  s1.insert(value_to_extract);

  // merge two sets into one
  std::set<int> s2 = {1, 2, 3};
  std::set<int> s3 = {3, 4, 5};
  s2.merge(s3);

  for (const auto elem : s1) std::cout << elem << '\n';

  // find the count of an element (0 or 1)
  const auto count_of_ones = s2.count(1);
  const auto count_of_tens = s2.count(10);

  // find an element if it is in the set, otherwise return .end()
  auto search = s2.find(2);
  if (search != s2.end()) {
    std::cout << "Found " << (*search) << '\n';
  } else {
    std::cout << "Not found\n";
  }

  // check if a set contains an element: return true if so, otherwise false.
  const auto has_six = s2.contains(6);

  // you can use comparions operators on sets as well:
  const auto s2_is_smaller_than_s1 = s2 < s1;
  const auto s2_is_greater_than_s1 = s2 > s1;
  const auto s2_is_equal_to_s1 = s2 == s1;
  const auto s2_does_not_equal_s1 = s2 != s1;
  const auto s2_is_greater_than_or_equal_to_s1 = s2 >= s1;
  const auto s2_is_less_than_or_equal_to_s1 = s2 <= s1;
}
