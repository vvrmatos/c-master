---
id: "037"
title: "#define Macros"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - preprocessor
  - macros
  - define
difficulty: beginner
source: "C11 Standard Section 6.10.3"
---

# 037 — #define Macros

## Concept

The `#define` directive creates macros — text substitutions performed by the preprocessor before compilation. Macros can define constants, create function-like constructs, and enable conditional compilation.

Types of macros:
- **Object-like**: `#define PI 3.14159` — simple text replacement
- **Function-like**: `#define SQUARE(x) ((x) * (x))` — parameterized replacement
- **Stringification**: `#var` converts parameter to string literal
- **Token pasting**: `a##b` concatenates tokens

Best practices:
- Use ALL_CAPS for macro names
- Parenthesize parameters: `((x) * (x))` not `x * x`
- Parenthesize entire expression: `((a) > (b) ? (a) : (b))`
- Avoid side effects in macro arguments

> **Why Macros Matter**: Macros are powerful but dangerous. They're text substitution, not functions — no type checking, no scope, evaluated at call site. Understanding macros is essential for reading system headers and legacy code.

## Code

```c
#include <stdio.h>

#define PI 3.14159265358979
#define E 2.71828182845904
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 100
#define VERSION "1.0.0"
#define DEBUG_MODE 1

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define PRINT_INT(var) printf("  " #var " = %d\n", var)
#define PRINT_VAR(var) printf("  " #var " = %d\n", var)

#define CONCAT(a, b) a##b

#define KILOBYTE 1024
#define MEGABYTE (KILOBYTE * 1024)
#define GIGABYTE (MEGABYTE * 1024)

int main(void) {
    printf("=== #define Macros ===\n\n");
    
    printf("Constant macros:\n");
    printf("  PI = %.14f\n", PI);
    printf("  E = %.14f\n", E);
    printf("  BUFFER_SIZE = %d\n", BUFFER_SIZE);
    printf("  MAX_CONNECTIONS = %d\n", MAX_CONNECTIONS);
    printf("  VERSION = %s\n", VERSION);
    
    printf("\nFunction-like macros:\n");
    int x = 5;
    printf("  SQUARE(5) = %d\n", SQUARE(5));
    printf("  SQUARE(x) = %d\n", SQUARE(x));
    printf("  MAX(10, 20) = %d\n", MAX(10, 20));
    printf("  MIN(10, 20) = %d\n", MIN(10, 20));
    printf("  ABS(-42) = %d\n", ABS(-42));
    
    printf("\nStringification operator (#):\n");
    int count = 42;
    PRINT_INT(count);
    int value = 100;
    PRINT_VAR(value);
    
    printf("\nToken concatenation (##):\n");
    int var1 = 10, var2 = 20;
    printf("  CONCAT(var, 1) = %d\n", CONCAT(var, 1));
    printf("  CONCAT(var, 2) = %d\n", CONCAT(var, 2));
    
    printf("\nSize calculations:\n");
    printf("  KILOBYTE = %d\n", KILOBYTE);
    printf("  MEGABYTE = %d\n", MEGABYTE);
    printf("  GIGABYTE = %d\n", GIGABYTE);
    
    printf("\nConditional compilation:\n");
#if DEBUG_MODE
    printf("  DEBUG_MODE is enabled\n");
#else
    printf("  DEBUG_MODE is disabled\n");
#endif
    
    printf("\nPredefined macros:\n");
    printf("  __FILE__ = %s\n", __FILE__);
    printf("  __LINE__ = %d\n", __LINE__);
    printf("  __DATE__ = %s\n", __DATE__);
    printf("  __TIME__ = %s\n", __TIME__);
    
    printf("\nMacro pitfall - side effects:\n");
    int a = 5;
    printf("  a = 5, SQUARE(a++) = %d\n", SQUARE(a++));
    printf("  a is now %d (incremented twice!)\n", a);
    
    return 0;
}
```

## Output

```
=== #define Macros ===

Constant macros:
  PI = 3.14159265358979
  E = 2.71828182845904
  BUFFER_SIZE = 1024
  MAX_CONNECTIONS = 100
  VERSION = 1.0.0

Function-like macros:
  SQUARE(5) = 25
  SQUARE(x) = 25
  MAX(10, 20) = 20
  MIN(10, 20) = 10
  ABS(-42) = 42

Stringification operator (#):
  count = 42
  value = 100

Token concatenation (##):
  CONCAT(var, 1) = 10
  CONCAT(var, 2) = 20

Size calculations:
  KILOBYTE = 1024
  MEGABYTE = 1048576
  GIGABYTE = 1073741824

Conditional compilation:
  DEBUG_MODE is enabled

Predefined macros:
  __FILE__ = 037-define-macros.c
  __LINE__ = 50
  __DATE__ = Mar  2 2026
  __TIME__ = 12:00:00

Macro pitfall - side effects:
  a = 5, SQUARE(a++) = 30
  a is now 7 (incremented twice!)
```

## Key Takeaways

- `#define` creates text substitution macros
- Object-like: `#define NAME value`
- Function-like: `#define FUNC(x) expression`
- Always parenthesize macro parameters and expressions
- `#` stringifies, `##` concatenates tokens
- Avoid expressions with side effects in macro arguments
- Predefined: `__FILE__`, `__LINE__`, `__DATE__`, `__TIME__`

## Challenge

Create a debug logging macro that prints file, line number, and a custom message. Make it conditionally compile based on a DEBUG flag.

## Related

- [[038-const-vs-define]] — Comparison with const
- [[005-preprocessor-and-include]] — Preprocessor basics
- [[039-enumeration-enum]] — Alternative for integer constants
