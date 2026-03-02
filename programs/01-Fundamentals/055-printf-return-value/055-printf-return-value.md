---
id: "055"
title: "printf() Return Value"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - return-value
  - error-handling
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 055 — printf() Return Value

## Concept

`printf()` returns the **number of characters printed** on success, or a **negative value** on error. This is often ignored but can be useful for:

**Return value:**
- Success: Number of characters transmitted
- Error: Negative value (typically -1)

**When to use the return value:**
1. Building dynamic output with alignment
2. Error checking (though stderr errors are rare)
3. Calculating total output length
4. Creating progress indicators

**Common pattern:**
```c
int count = printf("Hello\n");  // count = 6
```

**Error conditions (rare):**
- Output stream error
- Encoding error
- Disk full when writing to file

**Related functions return values:**
| Function | Returns |
|----------|---------|
| `printf()` | Characters printed |
| `sprintf()` | Characters written (excludes null) |
| `snprintf()` | Characters that would be written |
| `fprintf()` | Characters printed to file |

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== printf() Return Value ===\n\n");
    
    int count;
    
    count = printf("Hello\n");
    printf("Characters printed: %d\n\n", count);
    
    count = printf("Hello, World!\n");
    printf("Characters printed: %d\n\n", count);
    
    count = printf("");
    printf("Empty string printed: %d characters\n\n", count);
    
    printf("Counting formatted output:\n");
    int num = 42;
    count = printf("  Number: %d\n", num);
    printf("  That was %d characters\n\n", count);
    
    double pi = 3.14159;
    count = printf("  Pi: %.2f\n", pi);
    printf("  That was %d characters\n\n", count);
    
    printf("Comparing output lengths:\n");
    int c1 = printf("  [%d]\n", 5);
    int c2 = printf("  [%5d]\n", 5);
    int c3 = printf("  [%10d]\n", 5);
    printf("  Lengths: %d, %d, %d\n\n", c1, c2, c3);
    
    printf("Using return value for alignment:\n");
    char *items[] = {"Apple", "Banana", "Cherry Pie"};
    int prices[] = {150, 75, 350};
    int n = 3;
    
    for (int i = 0; i < n; i++) {
        int printed = printf("  %s", items[i]);
        int padding = 20 - printed;
        while (padding-- > 0) printf(" ");
        printf("$%d.%02d\n", prices[i] / 100, prices[i] % 100);
    }
    
    printf("\nBuilding dynamic output:\n");
    int total = 0;
    total += printf("  Part 1");
    total += printf(" + Part 2");
    total += printf(" + Part 3");
    total += printf("\n");
    printf("  Total characters: %d\n\n", total);
    
    printf("Practical: Progress indicator\n");
    printf("  [");
    int progress_chars = 0;
    for (int i = 0; i <= 100; i += 10) {
        progress_chars += printf("#");
    }
    printf("] %d chars for progress bar\n\n", progress_chars);
    
    printf("Checking for errors (negative = error):\n");
    int result = printf("  Normal output\n");
    if (result < 0) {
        printf("  Error occurred!\n");
    } else {
        printf("  Success: %d characters\n", result);
    }
    
    printf("\nCounting with sprintf isn't printf but similar:\n");
    char buffer[100];
    int len = sprintf(buffer, "Value: %d", 12345);
    printf("  Buffer: '%s' (%d chars)\n", buffer, len);
    
    return 0;
}
```

## Output

```
=== printf() Return Value ===

Hello
Characters printed: 6

Hello, World!
Characters printed: 14

Empty string printed: 0 characters

Counting formatted output:
  Number: 42
  That was 13 characters

  Pi: 3.14
  That was 11 characters

Comparing output lengths:
  [5]
  [    5]
  [         5]
  Lengths: 5, 9, 14

Using return value for alignment:
  Apple               $1.50
  Banana              $0.75
  Cherry Pie          $3.50

Building dynamic output:
  Part 1 + Part 2 + Part 3
  Total characters: 26

Practical: Progress indicator
  [###########] 11 chars for progress bar

Checking for errors (negative = error):
  Normal output
  Success: 16 characters

Counting with sprintf isn't printf but similar:
  Buffer: 'Value: 12345' (12 chars)
```

## Compilation

```bash
gcc 055-printf-return-value.c -o 055-printf-return-value
./055-printf-return-value
```

## Key Takeaways

- `printf()` returns the number of characters printed
- Count includes all characters: text, spaces, newlines
- Negative return indicates an error
- Useful for dynamic alignment and progress tracking
- Usually ignored in simple programs
- Critical for robust systems programming

## Challenge

Write a program that creates a text-based progress bar where the percentage display is right-aligned using printf's return value.

## Related

- [[041-printf-basics]] — printf fundamentals
- [[060-scanf-return-value]] — scanf's return value
