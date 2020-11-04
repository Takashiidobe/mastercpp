// static const int _add(int a, int b) { return a + b; }
// static const int _sub(int a, int b) { return a - b; }

static const int b_add(int a, int b) {
  return b == 0 ? a : b_add(a ^ b, (a & b) << 1);
}

static const int b_sub(int a, int b) { return a + (~b + 1); }

const int add(int a, int b) { return b_add(a, b); }
const int sub(int a, int b) { return b_sub(a, b); }
