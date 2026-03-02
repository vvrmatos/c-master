# 154 - String Printing: `printf %s` and `puts`

## Overview
C provides several functions for printing strings. Understanding their differences helps you choose the right tool for each situation.

## printf with %s

```c
char str[] = "Hello";
printf("%s\n", str);      // Hello
printf("Say: %s!\n", str); // Say: Hello!
```

### Format Specifiers

| Format | Description | Example Output |
|--------|-------------|----------------|
| `%s` | Normal string | `Hello` |
| `%10s` | Right-align, min width 10 | `     Hello` |
| `%-10s` | Left-align, min width 10 | `Hello     ` |
| `%.3s` | Max 3 characters | `Hel` |
| `%10.3s` | Width 10, max 3 chars | `       Hel` |

```c
char name[] = "Alice";
printf("[%s]\n", name);      // [Alice]
printf("[%10s]\n", name);    // [     Alice]
printf("[%-10s]\n", name);   // [Alice     ]
printf("[%.3s]\n", name);    // [Ali]
```

## puts Function

```c
#include <stdio.h>

puts("Hello");  // Prints: Hello\n
// Automatically adds newline!
```

### puts vs printf

| Feature | printf | puts |
|---------|--------|------|
| Newline | Manual `\n` | Automatic |
| Format specifiers | Yes | No |
| Return value | Chars written | Non-negative or EOF |
| Speed | Slower | Faster |

## fputs Function

```c
fputs("Hello", stdout);  // No automatic newline
fputs("Hello", stderr);  // To error stream
fputs("Hello\n", file);  // To file
```

## putchar Function

```c
putchar('H');
putchar('i');
putchar('\n');
// Output: Hi
```

## Comparison

```c
// These produce the same output:
printf("Hello\n");
puts("Hello");
fputs("Hello\n", stdout);

// Character by character:
char *s = "Hi";
while (*s) putchar(*s++);
putchar('\n');
```

## Return Values

```c
int n = printf("Hello");  // n = 5 (chars written)
int r = puts("Hello");    // r >= 0 on success, EOF on error
int c = putchar('A');     // c = 'A' on success, EOF on error
```

---

# Kata Challenge

## Challenge: String Printer Toolkit
Create a program that demonstrates all string printing methods and builds utility functions.

## Requirements
Implement:
1. `void print_centered(const char *str, int width)` - center string in field
2. `void print_box(const char *str)` - print string in ASCII box
3. `void print_hex(const char *str)` - print string with hex values
4. Compare performance of printf vs puts (optional)

## Expected Output
```
=== String Printing Demo ===

printf basics:
  "Hello, World!"
  Name: Alice

printf formatting:
  [Alice     ] (left-aligned, width 10)
  [     Alice] (right-aligned, width 10)
  [Ali       ] (max 3 chars, left-aligned)

puts (auto newline):
  Hello from puts!

fputs (manual newline):
  Line 1 - continued
  Line 2

=== Custom Functions ===

Centered (width 20):
|      Hello       |

Box:
+-------+
| Hello |
+-------+

Hex dump:
H  e  l  l  o  
48 65 6c 6c 6f
```

## Function Signatures
```c
void print_centered(const char *str, int width);
void print_box(const char *str);
void print_hex_dump(const char *str);
```

## Bonus
- Add color output using ANSI escape codes
- Implement word wrapping for long strings
- Create a progress bar using `\r` (carriage return)
