# Input and Output

One of unix's enduring idioms is `Everything is a file`. In fact, the function we've been using, `printf`, is really just writing to a special file and showing that file to you, so it looks "printed".

For input and output in C, we use `scanf` to receive input from stdin, `printf` to write to stdout, and `fprintf` to print to `stderr`.

```c,editable
{{#include ../../code/scratch/input-and-output/print-to-stdout.c}}
```

```c,editable
{{#include ../../code/scratch/input-and-output/print-to-stderr.c}}
```

```c,editable
{{#include ../../code/scratch/input-and-output/get-from-stdin.c}}
```

We can go one level deeper and use some system calls to do the exact same thing.

In unix, stdin is the 0th file descriptor, stdout is the 1st file descriptor, and stderr is the 2nd.

Let's do the same thing as above but with the `<unistd.h>` library.

```c,editable
{{#include ../../code/scratch/input-and-output/print-to-stdout-with-syscalls.c}}
```

```c,editable
{{#include ../../code/scratch/input-and-output/print-to-stderr-with-syscalls.c}}
```

```c,editable
{{#include ../../code/scratch/input-and-output/get-from-stdin-with-syscalls.c}}
```

Now that we've learned that `stdout`, `stdin`, and `stderr` are just `file descriptors`, and thus are files, it shouldn't be much of a leap to read and write from a normal file, right?

Let's do that.

Writing to a file:

```c,editable
{{#include ../../code/scratch/input-and-output/write-to-file.c}}
```

Writing to a file with system calls:

```c,editable
{{#include ../../code/scratch/input-and-output/write-to-file-with-syscalls.c}}
```
