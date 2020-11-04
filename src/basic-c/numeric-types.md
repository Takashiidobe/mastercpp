# Numeric Types

Now that we know how to compile and run our C code, let's learn a bit more about C data types.

C is a statically typed language, which means that we have to declare what type our variables are to the compiler.
Let's start out with some numbers.

Here are a few numeric data types, which we hold in a variable.

a variable is assigned in C in the following form:

$type $variable_name = \$value;

Likewise, let's say we want a value of 5 with a type of int to be assigned to a variable we call integer.

That would go like this:

```c,editable
{{#include ../../code/basic-c/data_types.c:4}}
```

The `int` is the most basic numeric type. It can only hold numbers whole numbers, and they can be positive or negative.

That being said, how much they can hold is dependent on both your computer and your compiler.

You can see the size of `ints` on your computer and using your compiler by running the following program:

```c,editable
{{#include ../../code/basic-c/int_size.c}}
```

On my computer, this prints out:

```sh
INT_SIZE: 4 byte(s)
INT_MAX: 2147483647
INT_MIN: -2147483648
```

On my computer, ints can be from -2147483648 to 2147483647. This might be different for you.

Let's see what happens when we add one to the maximum integer we can get.

```c,editable
{{#include ../../code/basic-c/max_int_plus_one.c}}
```

On my computer I get the minimum number.
This might come as a bit of a shock, but it makes sense when you think about how numbers are represented in binary.

```sh
-2147483648
```

## Binary Representations

### Binary Representation of Unsigned Types

Let's take a look at the binary representation of a 1-byte type, the unsigned char.

(`<limits.h>` does not have a UCHAR_MIN, since all unsigned types have a minimum of 0. Since we know that numbers wrap around, we can add 1 to the max to get the minimum of a type as well, so that's what we do here.)

```c,editable
{{#include ../../code/basic-c/unsigned_char_size.c}}
```

```sh
UNSIGNED_CHAR_SIZE: 1 byte(s)
UNSIGNED_CHAR_MAX: 255
UNSIGNED_CHAR_MIN: 0
```

One byte is equivalent to 8 bits, and a bit can only hold two values, 0 or 1.
Since an unsigned char has 8 bits, imagine 8 slots that can hold either 0 or 1.
We call a bit that is set to 1 a set bit, and a bit that is set to 0 to be unset.

Let's see the binary representation of the minimum `unsigned char`.

Every bit is unset, and this corresponds to the number 0.

```
[0][0][0][0][0][0][0][0]
```

You read a binary number from right to left, and assume that each digit is 2 to the power of (n). The rightmost slot is for the 0th power, and the last slot is for the 7th power.

If a slot is set, we add that number to the total.

Let's go from right to left.

We start off with a total of 0.

Our first slot is 0, so we don't add anything to our total.
If it was set to 1, we would add (2 ^ 0) to our total, or 1.

Our second slot is 0, so we don't add anything to our total.
If it was set to 1, we would add (2 ^ 1) to our total, or 2.

Our third slot is 0, so we don't add anything to our total.
If it was set to 1, we would add (2 ^ 2) to our total, or 4.

Our fourth slot is 0, so we don't add anything to our total.
If it was set to 1, we would add (2 ^ 3) to our total, or 8.

Our fifth slot is 0, so we don't add anything to our total.
If it was set to 1, we would add (2 ^ 4) to our total, or 16.

Our sixth slot is 0, so we don't add anything to our total.
If it was set to 1, we would add (2 ^ 5) to our total, or 32.

Our seventh slot is 0, so we don't add anything to our total.
If it was set to 1, we would add (2 ^ 6) to our total, or 64.

Our eighth slot is 0, so we don't add anything to our total.
If it was set to 1, we would add (2 ^ 7) to our total, or 128.

Thus, we find that the base 10 representation of `[0][0][0][0][0][0][0][0]` is 0.

Maybe you've noticed that if we sum the totals of the previous steps, you get to `255`, the max of the unsigned chars. Interesting, isn't it?

Let's find out how to get the maximum unsigned char in binary.

To convert a base 10 number to binary, I find it easier to go from left to right, so let's do that.

Let's convert `255` to binary.

First, we need to find the bit that we would start at, which is the power of 2 that 255 is between, and the lower power is the number of bits that number can be represented by.

In our case, we know that (2 ^ 7) is 128, and (2 ^ 8) is 256, so 255 fits in the middle.

Let's start off at the 7th bit, and move our way to the 0th bit.

Let's create a set of 8 bits (7,6,5,4,3,2,1,0) that are all unset. If we can subtract the power of 2 that corresponds to the power of two that is unset, we decide to set it to 1 instead.

```
[0][0][0][0][0][0][0][0]
```

First, we know that we can subtract 128 from 255, since 255 is larger than 128.

Let's do that, and set the 7th bit, because 128 is (2 ^ 7).

Next, let's subtract 128 from 255, and call that our new number. (255 - 128) is 127, so let's call that our new number and bring that to the next step.

```
[1][0][0][0][0][0][0][0]
```

Now we have the 7th bit set.

The next bit is the 6th bit, so let's try to subtract (2 ^ 6), which is 64 from 127.

127 - 64 = 63.

Since we could subtract 64 from 127, let's set the 6th bit.

```
[1][1][0][0][0][0][0][0]
```

Now we have the 6th bit set.

The next bit is the 5th bit, so let's try to subtract (2 ^ 5), which is 32 from 63.

63 - 32 = 31.

Since we could subtract 32 from 64, let's set the 5th bit.

```
[1][1][1][0][0][0][0][0]
```

Now we have the 5th bit set.

The next bit is the 4th bit, so let's try to subtract (2 ^ 4), which is 16 from 31.

31 - 16 = 15.

Since we could subtract 16 from 31, let's set the 4th bit.

```
[1][1][1][1][0][0][0][0]
```

Now we have the 4th bit set.

The next bit is the 3rd bit, so let's try to subtract (2 ^ 3), which is 8 from 15.

15 - 8 = 7.

Since we could subtract 16 from 31, let's set the 3rd bit.

```
[1][1][1][1][1][0][0][0]
```

Now we have the 3rd bit set.

The next bit is the 2nd bit, so let's try to subtract (2 ^ 2), which is 4 from 7.

7 - 4 = 3.

Since we could subtract 4 from 7, let's set the 2nd bit.

```
[1][1][1][1][1][1][0][0]
```

Now we have the 2nd bit set.

The next bit is the 1st bit, so let's try to subtract (2 ^ 1), which is 2 from 3.

3 - 2 = 1.

Since we could subtract 2 from 3, let's set the 1st bit.

```
[1][1][1][1][1][1][1][0]
```

Now we have the 1st bit set.

The next bit is the 0th bit, so let's try to subtract (2 ^ 0), which is 1 from 1.

1 - 1 = 0.

Since we could subtract 1 from 1, let's set the 0th bit.

As well, since our total is now 0, we can stop now.

```
[1][1][1][1][1][1][1][1] // binary representation of 255
```

You'll notice that every bit is set. This means that this is the maximum number that this amount of bits can hold, which we saw was true according to our compiler.

You might've noticed that we learned how to count in binary using an unsigned type first, which can not hold negative numbers, but `int` types can hold negative numbers.

What gives?

### Binary Representation of Signed Types

Let's try a signed type this time. We'll try out the plain old char type, which is a signed type.

Compile and run the code below.

```c,editable
{{#include ../../code/basic-c/char_size.c}}
```

For me this returns the following:

```sh
CHAR_SIZE: 1 byte(s)
CHAR_MAX: 127
CHAR_MIN: -128
```

You might notice that a char and unsigned char hold the same amount of values, 256 of them.

0 - 255 = 256 and -128 - 127 = 256.

This is because there are 2 ^ (number of bits) values in any given type.
Because unsigned chars and chars are both 8 bits, they can hold (2 ^ 8) or 256 values.

For unsigned types, the minimum is always 0 and the maximum is always 2 ^ (number of bits).

For signed types, the minimum is `-(2 ^ (number of bits - 1)) - 1`, and the maximum is always `(2 ^ (number of bits - 1))`.

This is a bit more complicated, so bear with me. To calculate a number, like -128, `CHAR_MIN`, we first write out the positive number in binary.

```
[1][0][0][0][0][0][0][0]
```

Next, we flip all of the digits. All the bits that are set become unset, and all the bits that are unset become set.

```
[0][1][1][1][1][1][1][1]
```

Then, we add 1.

```
[1][0][0][0][0][0][0][0]
```

Thus, -128 is represented in Binary as:

```
[1][0][0][0][0][0][0][0]
```

Let's try 127.

Write this out in binary.

```
[0][1][1][1][1][1][1][1]
```

Flip the digits

```
[1][0][0][0][0][0][0][0]
```

Add one

```
[0][0][0][0][0][0][0][0]
```

Here we find that 127 is represented with 8 0s in Two's complement.

It's a bit of a funky scheme, but it allows numbers from -128 to 127 to be represented by a signed number.

## Exercises

- What is the number 28 in binary as an unsigned char?

- What is the number 28 in binary as a signed char?

## More Resources

- [Reading Binary](https://medium.com/@LindaVivah/learn-how-to-read-binary-in-5-minutes-dac1feb991e)

- [Two's Complement, Cornell](https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html)
