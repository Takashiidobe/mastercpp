# Control Flow

Let's move onto control flow. Control flow means that the program can make a choice of two different paths to take, and can make a choice between them.

That's a little abstract, let's see it in action.

We'll do this by introducing two new keywords, `if` and `else`.

```c,editable
{{#include ../../code/basic-c/control-flow/if_else.c}}
```

For an if condition, you put your condition between parentheses, and if the condition is met, then the code executes what's inside the brackets.

If the condition is not met, then it completely ignores this code, and moves on.

In our case, we have 3 apples. 3 apples is greater than 0, so the code within the `if` is executed. This prints out "You have apples", when compiled and run.

Let's see an example where the else is taken.

```c,editable
{{#include ../../code/basic-c/control-flow/if_else_execute_else.c}}
```

We have the same amount of apples, but now, to execute the code in the `if` block, we need to have more than 5 apples. We don't, so we execute the code in the else block, and so this prints out "You have less than 5 apples." when run.

You can see how this gives us some dynamism in our programs. We're no longer bound to only executing commands sequentially in our programs, we can skip parts of our program at will.

But what happens when we have more than two conditions to match?
Enter the `else if` keyword. `else if` is valid after an `if` statement. We sandwich it after an if but before an else.

```c,editable
{{#include ../../code/basic-c/control-flow/if_elseif_else.c}}
```

It is perfectly valid to have an `else if` with no `else`.

```c,editable
{{#include ../../code/basic-c/control-flow/if_elseif_without_else.c}}
```

## Exercises

- Make a program that prints out "You have a lot of pets" if you have more than one pet, "You have one pet" if you have one pet, and "You have no pets :(" if you have no pets.
