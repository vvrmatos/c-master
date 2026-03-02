---
id: "075"
title: "Modulus Operator"
category: "01-Fundamentals"
tags: ["arithmetic", "operators", "modulus", "remainder"]
difficulty: "beginner"
---

# Modulus Operator

## Concept

The `%` operator returns the remainder after integer division. It only works with integer operands (not floating-point).

**Common uses**:
- Check if a number is even or odd: `n % 2`
- Wrap values around (clock arithmetic): `(value + delta) % max`
- Extract digits: `n % 10` gives last digit
- Check divisibility: `a % b == 0` means b divides a evenly

**Sign behavior** (C99+): The result has the same sign as the dividend (left operand).

## Code

```c
// Modulus (remainder) operator

#include <stdio.h>

int main(void) {
    // Basic modulus
    printf("17 %% 5 = %d\n", 17 % 5);
    printf("20 %% 5 = %d\n", 20 % 5);
    printf("3 %% 5 = %d\n", 3 % 5);
    
    // Check even/odd
    int n = 7;
    printf("\n%d is %s\n", n, (n % 2 == 0) ? "even" : "odd");
    
    // Negative operands
    printf("\n-17 %% 5 = %d\n", -17 % 5);
    printf("17 %% -5 = %d\n", 17 % -5);
    
    // Wrap around (clock arithmetic)
    int hour = 23;
    printf("\n%d + 3 hours = %d o'clock\n", hour, (hour + 3) % 24);
    
    return 0;
}
```

## Output

```
17 % 5 = 2
20 % 5 = 0
3 % 5 = 3

7 is odd

-17 % 5 = -2
17 % -5 = 2

23 + 3 hours = 2 o'clock
```

## Key Takeaways

1. `%` only works with integers, not floats (use `fmod()` for floats)
2. `a % b == 0` means `a` is divisible by `b`
3. Result sign matches the dividend in C99+
4. Same precedence as `*` and `/`
5. Modulus is often used for cycling/wrapping values

## Kata Challenge

**FizzBuzz Checker**

Write a program that checks a number and prints:
- "Fizz" if divisible by 3
- "Buzz" if divisible by 5
- "FizzBuzz" if divisible by both
- The number itself otherwise

```c
// Your solution here
// Test with: 9, 10, 15, 7
// Expected output:
// 9: Fizz
// 10: Buzz
// 15: FizzBuzz
// 7: 7
```

Hint: Use `%` to check divisibility. Order of checks matters for FizzBuzz!
