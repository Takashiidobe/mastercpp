static const long long _add(long long a, long long b) { return a + b; }
static const long long _sub(long long a, long long b) { return a - b; }

const long long add(long long a, long long b) { return _add(a, b); }
const long long sub(long long a, long long b) { return _sub(a, b); }
