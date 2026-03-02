---
id: "053"
title: "Flags: -, +, and space"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - formatting
  - flags
  - alignment
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 053 — Flags: -, +, and space

## Concept

Printf flags modify how values are formatted. The `-`, `+`, and space flags control alignment and sign display.

**Flag summary:**
| Flag | Effect |
|------|--------|
| `-` | Left-align within field width |
| `+` | Always show sign (+ or -) |
| ` ` (space) | Space before positive numbers |

**Syntax:** `%[flags][width][.precision]specifier`

**The `-` flag (left-align):**
```c
printf("[%10d]", 42);   // "[        42]" (right)
printf("[%-10d]", 42);  // "[42        ]" (left)
```

**The `+` flag (show sign):**
```c
printf("%+d", 42);   // "+42"
printf("%+d", -42);  // "-42"
```

**The space flag:**
```c
printf("% d", 42);   // " 42" (space before positive)
printf("% d", -42);  // "-42" (minus sign, no extra space)
```

**Why use space flag?**
- Aligns positive and negative numbers
- Numbers line up without explicit +
- Cleaner than always showing +

**Flag precedence:** `+` overrides space (if both specified)

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Flags: -, +, and space ===\n\n");
    
    printf("Minus flag (-) for left alignment:\n");
    printf("  [%10d] (default right)\n", 42);
    printf("  [%-10d] (left aligned)\n", 42);
    printf("  [%10s] (default right)\n", "Hi");
    printf("  [%-10s] (left aligned)\n", "Hi");
    
    printf("\nPlus flag (+) shows sign:\n");
    printf("  Positive without +: %d\n", 42);
    printf("  Positive with +: %+d\n", 42);
    printf("  Negative without +: %d\n", -42);
    printf("  Negative with +: %+d\n", -42);
    printf("  Zero with +: %+d\n", 0);
    
    printf("\nPlus with floats:\n");
    printf("  %f\n", 3.14);
    printf("  %+f\n", 3.14);
    printf("  %+f\n", -3.14);
    
    printf("\nSpace flag ( ) reserves sign position:\n");
    printf("  Positive with space: [% d]\n", 42);
    printf("  Negative with space: [% d]\n", -42);
    printf("  Aligns positive and negative:\n");
    printf("    % d\n", 123);
    printf("    % d\n", -45);
    printf("    % d\n", 6);
    
    printf("\nComparing + and space:\n");
    printf("  %%+d:  [%+d] [%+d]\n", 42, -42);
    printf("  %% d:  [% d] [% d]\n", 42, -42);
    printf("  %%d:   [%d] [%d]\n", 42, -42);
    
    printf("\nCombining flags:\n");
    printf("  %%-+10d: [%-+10d]\n", 42);
    printf("  %%+10d: [%+10d]\n", 42);
    printf("  %%- 10d: [%- 10d]\n", 42);
    
    printf("\nPractical example - aligned numbers:\n");
    printf("  Temperature readings:\n");
    int temps[] = {23, -5, 0, 15, -12, 8};
    int n = sizeof(temps) / sizeof(temps[0]);
    for (int i = 0; i < n; i++) {
        printf("    Day %d: %+4d°C\n", i + 1, temps[i]);
    }
    
    printf("\nProfit/Loss report:\n");
    printf("    %-15s %+10s\n", "Category", "Amount");
    printf("    %-15s %+10.2f\n", "Sales", 15000.50);
    printf("    %-15s %+10.2f\n", "Expenses", -8500.25);
    printf("    %-15s %+10.2f\n", "Net", 6500.25);
    
    printf("\nSpace for alignment without sign:\n");
    printf("    Revenue: % 10.2f\n", 50000.00);
    printf("    Cost:    % 10.2f\n", -30000.00);
    printf("    Profit:  % 10.2f\n", 20000.00);
    
    return 0;
}
```

## Output

```
=== Flags: -, +, and space ===

Minus flag (-) for left alignment:
  [        42] (default right)
  [42        ] (left aligned)
  [        Hi] (default right)
  [Hi        ] (left aligned)

Plus flag (+) shows sign:
  Positive without +: 42
  Positive with +: +42
  Negative without +: -42
  Negative with +: -42
  Zero with +: +0

Plus with floats:
  3.140000
  +3.140000
  -3.140000

Space flag ( ) reserves sign position:
  Positive with space: [ 42]
  Negative with space: [-42]
  Aligns positive and negative:
     123
    -45
     6

Comparing + and space:
  %+d:  [+42] [-42]
  % d:  [ 42] [-42]
  %d:   [42] [-42]

Combining flags:
  %-+10d: [+42       ]
  %+10d: [       +42]
  %- 10d: [ 42       ]

Practical example - aligned numbers:
  Temperature readings:
    Day 1:  +23°C
    Day 2:   -5°C
    Day 3:   +0°C
    Day 4:  +15°C
    Day 5:  -12°C
    Day 6:   +8°C

Profit/Loss report:
    Category            Amount
    Sales            +15000.50
    Expenses          -8500.25
    Net               +6500.25

Space for alignment without sign:
    Revenue:   50000.00
    Cost:     -30000.00
    Profit:    20000.00
```

## Compilation

```bash
gcc 053-flags-minus-plus-space.c -o 053-flags-minus-plus-space
./053-flags-minus-plus-space
```

## Key Takeaways

- `-` flag left-aligns output within field width
- `+` flag always shows sign (+ for positive, - for negative)
- Space flag shows space for positive, - for negative
- Use space flag for subtle alignment of mixed signs
- Flags can be combined: `%-+10d`
- `+` takes precedence over space if both are used

## Challenge

Write a program that displays a stock portfolio showing gains in green (with +) and losses in red (with -), properly aligned.

## Related

- [[051-field-width]] — Width specifier
- [[054-flags-zero-hash]] — Zero and hash flags
