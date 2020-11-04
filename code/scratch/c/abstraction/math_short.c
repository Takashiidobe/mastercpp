static const short _add(short a, short b) { return a + b; }
static const short _sub(short a, short b) { return a - b; }

const short add(short a, short b) { return _add(a, b); }
const short sub(short a, short b) { return _sub(a, b); }
