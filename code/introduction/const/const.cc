int main() {
  int i;  // we can instantiate this.
  i++;    // we can mutate this unintialized value,

  const int i;      // compiler error, must be initialized.
  const int j = 0;  // ok
  j++;              // compiler error, j cannot be mutated.
}
