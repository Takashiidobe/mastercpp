void increment_int_and_delete(int *x) {
  if (x != nullptr) {
    *x = *x + 1;
    delete x;
  }
}
