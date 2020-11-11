# The Stack and the Heap

We've gone through most of basic C at this point, and its syntax, and it's time to look at the most powerful function in C.

It's not the main function, it's `malloc`.

Malloc stands for "Memory Allocation", and it is a function defined in `<stdlib.h>` that does just that, it allocates as much memory as you ask of it.

That's a bit of a head scratcher. We've already been allocating memory, and the compiler takes care of that for us. Why do we need to explicitly allocate memory?

To explain why malloc exists, we have to explain the stack and the heap.

## The Stack

The stack is what we've been using for allocating memory in all of our examples so far.

In the example below, we allocate an int on the stack and an array of characters on the stack in order to get it to print out our slogan x amount of times.

```c,editable
{{#include ../../code/basic-c/stack-and-heap/stack_allocation.c}}
```

This is also convenient because when the variable exits scope, it is automatically cleaned up; there's no need for us to do anything.

If we create a new scope that contains our previous code, you'll notice that all the variables are cleaned up for us afterwards. Items that we use on the stack are of `automatic` storage duration, where the program creates the necessary variables every time it enters the scope and destroys the variables, freeing up the memory to be used when it leaves scope.

```c,editable
{{#include ../../code/basic-c/stack-and-heap/stack_cleanup.c}}
```

While variables on the stack are convenient (it's like having a custodian clean up after you), there are some times when you need some more control over the variables you allocate.

One such case is when you want to create a variable that doesn't have a fixed size at compile time.

You can still do this on the stack -- let's say you want an array that always increases in size, you can hold an array on the stack, and when it outgrows its old array, you just copy it to a larger array allocated on the stack.

But if you do this enough, you'll eventually hit what's called a `stack overflow`, where your program doesn't have enough memory on the stack to continue, and terminates immediately.

This is a problem.

Let's say you run this program that allocates a string with 10,000,000 h's in it.

You get a segmentation fault due to a stack overflow. There's not enough space to carry our string here.

```c,editable
{{#include ../../code/basic-c/stack-and-heap/stack_cleanup.c}}
```

Let's do that same example, but on the heap:

We'll instead defer to a pointer of chars, and use malloc to allocate memory on the heap.
We want to allocate 10,000,000 bytes, as that is the size of our allocation. We do so by providing malloc an argument that tells us the size of the memory we want, which is (the size of a char \* 10,000,000). Luckily, the sizeof operator is useful for figuring out that information.

Malloc returns something called a pointer, which we'll discuss in more detail later on.

Finally, we have to delete our pointer by using the `free` function, otherwise we'll have a memory leak. This happens because variables allocated on the heap no longer have automatic storage duration -- they're something that we have to manage, and `free` is used when we no longer need a variable.

```c,editable
{{#include ../../code/basic-c/stack-and-heap/heap_allocation.c}}
```

Now that we're allocating on the heap, we have a lot more memory at our disposal, and _hopefully_ your code compiles.

We've figured out what a stack is, but we still don't know about the `heap`, or `pointers`.
