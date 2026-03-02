---
id: "048"
title: "Format Specifier: %s"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - strings
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 048 — Format Specifier: %s (String)

## Concept

`%s` is the format specifier for printing **strings** (null-terminated character arrays). It reads characters from the memory address until it encounters `\0` (null terminator).

**Key facts:**
- Argument must be pointer to null-terminated string
- Prints until null terminator is found
- Passing NULL is undefined behavior (some systems print "(null)")
- Width and precision work like other specifiers

**Width and precision:**
```c
printf("%20s", str);    // Right-align in 20-char field
printf("%-20s", str);   // Left-align in 20-char field  
printf("%.5s", str);    // Print only first 5 chars
printf("%10.5s", str);  // 5 chars, right-aligned in 10-char field
```

**Precision meaning:**
- For `%s`: Maximum characters to print
- Useful for truncating long strings
- Does NOT pad with spaces (only width does that)

**Common uses:**
- Displaying messages and labels
- Building formatted output (tables, reports)
- Logging and debugging output

> **Security Warning:** Never use user input as the format string. `printf(user_input)` is a format string vulnerability. Always use `printf("%s", user_input)`.

## Code

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("=== Format Specifier: %%s (String) ===\n\n");
    
    char greeting[] = "Hello, World!";
    char name[] = "Alice";
    char empty[] = "";
    
    printf("Basic string output:\n");
    printf("  Greeting: %s\n", greeting);
    printf("  Name: %s\n", name);
    printf("  Empty: [%s]\n", empty);
    
    printf("\nString literals directly:\n");
    printf("  %s\n", "This is a string literal");
    printf("  %s %s!\n", "Hello", "there");
    
    printf("\nString with width specifier:\n");
    printf("  [%20s] (right-aligned, width 20)\n", name);
    printf("  [%-20s] (left-aligned, width 20)\n", name);
    printf("  [%5s] (width 5, string exceeds)\n", name);
    
    printf("\nPrecision limits characters printed:\n");
    char longstr[] = "The quick brown fox";
    printf("  Full: %s\n", longstr);
    printf("  %%.5s: %.5s\n", longstr);
    printf("  %%.10s: %.10s\n", longstr);
    printf("  %%10.5s: [%10.5s]\n", longstr);
    
    printf("\nMultiple strings:\n");
    char first[] = "John";
    char last[] = "Doe";
    printf("  Name: %s %s\n", first, last);
    printf("  Reversed: %s, %s\n", last, first);
    
    printf("\nFormatting a table:\n");
    printf("  %-15s %-10s %10s\n", "Product", "Category", "Price");
    printf("  %-15s %-10s %10s\n", "-------", "--------", "-----");
    printf("  %-15s %-10s %10s\n", "Laptop", "Tech", "$999.99");
    printf("  %-15s %-10s %10s\n", "Coffee Mug", "Kitchen", "$12.50");
    printf("  %-15s %-10s %10s\n", "USB Cable", "Tech", "$8.99");
    
    printf("\nNULL pointer behavior (undefined, avoid!):\n");
    printf("  Some compilers print: (null)\n");
    
    printf("\nCombining with other specifiers:\n");
    printf("  User %s has ID %d and balance $%.2f\n", "Bob", 42, 150.75);
    
    char path[] = "/home/user/documents";
    char file[] = "report.txt";
    printf("\nBuilding paths:\n");
    printf("  Full path: %s/%s\n", path, file);
    
    return 0;
}
```

## Output

```
=== Format Specifier: %s (String) ===

Basic string output:
  Greeting: Hello, World!
  Name: Alice
  Empty: []

String literals directly:
  This is a string literal
  Hello there!

String with width specifier:
  [               Alice] (right-aligned, width 20)
  [Alice               ] (left-aligned, width 20)
  [Alice] (width 5, string exceeds)

Precision limits characters printed:
  Full: The quick brown fox
  %.5s: The q
  %.10s: The quick 
  %10.5s: [     The q]

Multiple strings:
  Name: John Doe
  Reversed: Doe, John

Formatting a table:
  Product         Category        Price
  -------         --------        -----
  Laptop          Tech           $999.99
  Coffee Mug      Kitchen         $12.50
  USB Cable       Tech             $8.99

NULL pointer behavior (undefined, avoid!):
  Some compilers print: (null)

Combining with other specifiers:
  User Bob has ID 42 and balance $150.75

Building paths:
  Full path: /home/user/documents/report.txt
```

## Compilation

```bash
gcc 048-format-specifier-s.c -o 048-format-specifier-s
./048-format-specifier-s
```

## Key Takeaways

- `%s` prints null-terminated strings
- Width specifier pads with spaces for alignment
- Precision limits maximum characters printed
- Left-align with `-` flag: `%-20s`
- Never pass NULL to %s (undefined behavior)
- Never use user input as format string directly

## Challenge

Write a program that creates a formatted table with names, ages, and cities, properly aligned in columns.

## Related

- [[047-format-specifier-c]] — Single character format
- [[051-field-width]] — Width specifiers in depth
