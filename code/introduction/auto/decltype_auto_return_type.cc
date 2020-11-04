template <typename Container, typename Index>
auto get_item(Container& c, Index i) -> decltype(c[i]) {
  return c[i];
}
