---
id: "051"
title: "Field Width Specifier"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - formatting
  - width
  - alignment
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 051 — Field Width Specifier

## Concept

The **field width** specifies the minimum number of characters to output. If the value is shorter, it's padded with spaces. If longer, it prints in full (width is minimum, not maximum).

**Syntax:** `%[flags][width]specifier`

```c
printf("%10d", 42);   // "        42" (right-aligned)
printf("%-10d", 42);  // "42        " (left-aligned)
```

**Key behaviors:**
| Width | Value | Output | Notes |
|-------|-------|--------|-------|
| `%5d` | 42 | `"   42"` | Padded to 5 chars |
| `%5d` | 12345 | `"12345"` | Exact fit |
| `%5d` | 123456 | `"123456"` | Exceeds, still prints |
| `%-5d` | 42 | `"42   "` | Left-aligned |

**Dynamic width with `*`:**
```c
int w = 10;
printf("%*d", w, 42);  // Width from variable
```

**Common use cases:**
- Creating aligned tables and columns
- Formatting reports
- Right-aligning numbers
- Creating fixed-width output

**Width vs Precision:**
- Width: Minimum total characters
- Precision (.n): Decimal places (floats) or max chars (strings)

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Field Width Specifier ===\n\n");
    
    printf("Integer field width:\n");
    printf("  [%d]\n", 42);
    printf("  [%5d]\n", 42);
    printf("  [%10d]\n", 42);
    printf("  [%5d]\n", 12345);
    printf("  [%3d] (exceeds width)\n", 12345);
    
    printf("\nLeft alignment with -:\n");
    printf("  [%10d] (right-aligned, default)\n", 42);
    printf("  [%-10d] (left-aligned)\n", 42);
    
    printf("\nString field width:\n");
    printf("  [%s]\n", "Hello");
    printf("  [%10s]\n", "Hello");
    printf("  [%-10s]\n", "Hello");
    printf("  [%3s] (exceeds width)\n", "Hello");
    
    printf("\nFloat field width:\n");
    printf("  [%f]\n", 3.14);
    printf("  [%12f]\n", 3.14);
    printf("  [%-12f]\n", 3.14);
    
    printf("\nCreating aligned tables:\n");
    printf("  %10s %10s %10s\n", "Name", "Age", "Score");
    printf("  %10s %10s %10s\n", "----", "---", "-----");
    printf("  %10s %10d %10.1f\n", "Alice", 25, 95.5);
    printf("  %10s %10d %10.1f\n", "Bob", 30, 87.3);
    printf("  %10s %10d %10.1f\n", "Charlie", 22, 92.0);
    
    printf("\nLeft-aligned table:\n");
    printf("  %-10s %-10s %-10s\n", "Name", "Age", "Score");
    printf("  %-10s %-10s %-10s\n", "----", "---", "-----");
    printf("  %-10s %-10d %-10.1f\n", "Alice", 25, 95.5);
    printf("  %-10s %-10d %-10.1f\n", "Bob", 30, 87.3);
    printf("  %-10s %-10d %-10.1f\n", "Charlie", 22, 92.0);
    
    printf("\nDynamic width with *:\n");
    int width = 15;
    printf("  [%*d]\n", width, 42);
    printf("  [%*s]\n", width, "Dynamic");
    printf("  [%*d]\n", 8, 123);
    
    printf("\nMixed alignment:\n");
    printf("  %-20s: %10d\n", "Population", 1000000);
    printf("  %-20s: %10.2f\n", "Temperature", 98.6);
    printf("  %-20s: %10s\n", "Status", "Active");
    
    return 0;
}
```

## Output

```
=== Field Width Specifier ===

Integer field width:
  [42]
  [   42]
  [        42]
  [12345]
  [12345] (exceeds width)

Left alignment with -:
  [        42] (right-aligned, default)
  [42        ] (left-aligned)

String field width:
  [Hello]
  [     Hello]
  [Hello     ]
  [Hello] (exceeds width)

Float field width:
  [3.140000]
  [    3.140000]
  [3.140000    ]

Creating aligned tables:
        Name        Age      Score
        ----        ---      -----
       Alice         25       95.5
         Bob         30       87.3
     Charlie         22       92.0

Left-aligned table:
  Name       Age        Score     
  ----       ---        -----     
  Alice      25         95.5      
  Bob        30         87.3      
  Charlie    22         92.0      

Dynamic width with *:
  [             42]
  [        Dynamic]
  [     123]

Mixed alignment:
  Population          :    1000000
  Temperature         :      98.60
  Status              :     Active
```

## Compilation

```bash
gcc 051-field-width.c -o 051-field-width
./051-field-width
```

## Key Takeaways

- Width specifies minimum output characters
- Default alignment is right; use `-` for left
- Width never truncates — value prints in full if wider
- Use `*` to get width from an argument
- Essential for creating aligned tables and reports
- Combine with precision for full control

## Challenge

Write a program that formats a bank statement with transaction descriptions left-aligned and amounts right-aligned with proper decimal places.

## Related

- [[052-precision]] — Decimal precision control
- [[053-flags-minus-plus-space]] — Flag modifiers
