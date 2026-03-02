---
id: "056"
title: "scanf() Basics"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - scanf
  - input
  - stdio
difficulty: beginner
source: "C11 Standard 7.21.6.2"
---

# 056 — scanf() Basics

## Concept

`scanf()` (scan formatted) reads formatted input from **stdin** (standard input, typically keyboard). It's the complement to `printf()` for input.

**Basic syntax:**
```c
scanf("format string", &var1, &var2, ...);
```

**Critical: The `&` operator:**
```c
int x;
scanf("%d", &x);  // & gets the ADDRESS of x
```
- scanf needs memory addresses, not values
- `&` means "address of"
- Arrays don't need `&` (array name is already an address)

**Common format specifiers:**
| Specifier | Type | Example |
|-----------|------|---------|
| `%d` | int | `scanf("%d", &num)` |
| `%f` | float | `scanf("%f", &flt)` |
| `%lf` | double | `scanf("%lf", &dbl)` |
| `%c` | char | `scanf(" %c", &ch)` |
| `%s` | string | `scanf("%49s", str)` |

**Whitespace handling:**
- scanf skips leading whitespace for most specifiers
- `%c` does NOT skip whitespace — use `" %c"` (space before %c)
- `%s` stops at whitespace

> **Security Warning:** Always specify width for `%s` to prevent buffer overflow: `scanf("%49s", buffer)` not `scanf("%s", buffer)`.

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== scanf() Basics ===\n\n");
    
    int number;
    
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("You entered: %d\n\n", number);
    
    float decimal;
    printf("Enter a decimal number: ");
    scanf("%f", &decimal);
    printf("You entered: %.2f\n\n", decimal);
    
    char letter;
    printf("Enter a character: ");
    scanf(" %c", &letter);
    printf("You entered: '%c'\n\n", letter);
    
    int a, b;
    printf("Enter two integers (space-separated): ");
    scanf("%d %d", &a, &b);
    printf("You entered: %d and %d\n", a, b);
    printf("Sum: %d\n\n", a + b);
    
    int x;
    float y;
    char z;
    printf("Enter int, float, char (space-separated): ");
    scanf("%d %f %c", &x, &y, &z);
    printf("Got: int=%d, float=%.2f, char='%c'\n\n", x, y, z);
    
    char word[50];
    printf("Enter a single word: ");
    scanf("%49s", word);
    printf("You entered: %s\n\n", word);
    
    printf("Important notes:\n");
    printf("  - Always use & before variables (except arrays)\n");
    printf("  - %%s stops at whitespace\n");
    printf("  - Always limit string width: %%49s not %%s\n");
    printf("  - Space before %%c skips whitespace\n");
    printf("  - Check return value in real programs\n");
    
    return 0;
}
```

## Output

```
=== scanf() Basics ===

Enter an integer: 42
You entered: 42

Enter a decimal number: 3.14
You entered: 3.14

Enter a character: A
You entered: 'A'

Enter two integers (space-separated): 10 20
You entered: 10 and 20
Sum: 30

Enter int, float, char (space-separated): 5 2.5 X
Got: int=5, float=2.50, char='X'

Enter a single word: Hello
You entered: Hello

Important notes:
  - Always use & before variables (except arrays)
  - %s stops at whitespace
  - Always limit string width: %49s not %s
  - Space before %c skips whitespace
  - Check return value in real programs
```

## Compilation

```bash
gcc 056-scanf-basics.c -o 056-scanf-basics
./056-scanf-basics
```

## Key Takeaways

- `scanf()` reads formatted input from stdin
- Use `&` to pass variable addresses (not for arrays)
- `%s` stops at whitespace — can't read full lines
- Always limit `%s` width to prevent buffer overflow
- Use `" %c"` (with space) to skip leading whitespace
- `%lf` is required for double (not %f like printf)
- Always check return value in real programs

## Challenge

Write a program that safely reads a person's age, name, and height (in meters), validating each input.

## Related

- [[057-scanf-integers]] — Reading integers with scanf
- [[060-scanf-return-value]] — Checking scanf success
