static const int _add(int a, int b) { return a + b; }
static const int _sub(int a, int b) { return a - b; }

const int add(int a, int b) { return _add(a, b); }
const int sub(int a, int b) { return _sub(a, b); }
