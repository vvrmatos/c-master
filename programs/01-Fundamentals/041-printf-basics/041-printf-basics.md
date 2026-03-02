---
id: "041"
title: "printf() Basics"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - output
  - stdio
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 041 — printf() Basics

## Concept

`printf()` (print formatted) is C's primary output function. It writes formatted text to **stdout** (standard output, typically the terminal). The function is declared in `<stdio.h>`.

**Basic syntax:**
```c
printf("format string", arg1, arg2, ...);
```

**Key features:**
- Format string contains literal text and format specifiers
- Format specifiers (`%d`, `%f`, etc.) are replaced by argument values
- Does NOT automatically add newlines — you must use `\n`
- Returns number of characters printed (or negative on error)

**Common escape sequences:**
| Sequence | Output |
|----------|--------|
| `\n` | Newline |
| `\t` | Tab |
| `\\` | Backslash |
| `\"` | Double quote |
| `%%` | Percent sign |

**Basic format specifiers:**
| Specifier | Type |
|-----------|------|
| `%d` | Signed integer |
| `%f` | Float/double |
| `%c` | Character |
| `%s` | String |

> **Security Note:** Never pass user input directly as the format string — this creates a format string vulnerability. Always use `printf("%s", user_input)` not `printf(user_input)`.

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== printf() Basics ===\n\n");
    
    printf("Simple text output\n");
    printf("Multiple ");
    printf("printf calls ");
    printf("on same line\n");
    
    printf("\nUsing escape sequences:\n");
    printf("Line 1\nLine 2\nLine 3\n");
    printf("Column1\tColumn2\tColumn3\n");
    printf("Value1\tValue2\tValue3\n");
    
    printf("\nPrinting special characters:\n");
    printf("Backslash: \\\n");
    printf("Double quote: \"\n");
    printf("Percent sign: %%\n");
    
    int count = 42;
    float price = 19.99;
    char grade = 'A';
    
    printf("\nFormatted output with variables:\n");
    printf("Integer: %d\n", count);
    printf("Float: %f\n", price);
    printf("Character: %c\n", grade);
    printf("All together: Count=%d, Price=%.2f, Grade=%c\n", count, price, grade);
    
    printf("\nMultiple values in one printf:\n");
    printf("x=%d, y=%d, z=%d\n", 10, 20, 30);
    
    return 0;
}
```

## Output

```
=== printf() Basics ===

Simple text output
Multiple printf calls on same line

Using escape sequences:
Line 1
Line 2
Line 3
Column1	Column2	Column3
Value1	Value2	Value3

Printing special characters:
Backslash: \
Double quote: "
Percent sign: %

Formatted output with variables:
Integer: 42
Float: 19.990000
Character: A
All together: Count=42, Price=19.99, Grade=A

Multiple values in one printf:
x=10, y=20, z=30
```

## Compilation

```bash
gcc 041-printf-basics.c -o 041-printf-basics
./041-printf-basics
```

## Key Takeaways

- `printf()` outputs formatted text to stdout
- Format specifiers are placeholders replaced by argument values
- Use `\n` for newlines — printf doesn't add them automatically
- Use `%%` to print a literal percent sign
- Arguments are matched to specifiers left-to-right
- Type mismatch between specifier and argument causes undefined behavior

## Challenge

Write a program that prints a formatted receipt with item names, quantities, and prices aligned in columns using tabs.

## Related

- [[042-format-specifier-d-i]] — Integer format specifiers
- [[055-printf-return-value]] — Using printf's return value
