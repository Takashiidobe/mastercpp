# Const

`const` is a keyword that forces items to be initialized and immutable.

```cpp
int i; // we can instantiate this.
i++; // we can mutate this unintialized value,

const int i; // compiler error, must be initialized.
i++; // compiler error
```
