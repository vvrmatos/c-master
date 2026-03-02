---
id: "015"
title: "Character as Integer"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - char
  - ascii
  - arithmetic
  - conversion
difficulty: beginner
source: "K&R Chapter 2"
---

# 015 — Character as Integer

## Concept

In C, `char` is fundamentally an **integer type**. Characters are stored as numbers, and you can do arithmetic on them. This is powerful for text processing.

**Key operations:**

```c
// Convert digit character to number
char c = '7';
int n = c - '0';  // n = 7

// Convert lowercase to uppercase
char lower = 'a';
char upper = lower - 32;  // Or: lower - ('a' - 'A')

// Check if character is a digit
if (c >= '0' && c <= '9') { /* it's a digit */ }

// Check if character is a letter
if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) { /* letter */ }
```

**ASCII relationships:**
- Uppercase `'A'`-`'Z'` are 65-90
- Lowercase `'a'`-`'z'` are 97-122
- Difference: `'a' - 'A' = 32`
- Digits `'0'`-`'9'` are 48-57
- So `'5' - '0' = 5` (the actual number)

**This is crucial for:**
- Parsers and lexers
- Encryption (Caesar cipher, XOR)
- String manipulation
- Input validation

## Code

```c
#include <stdio.h>

int main(void) {
    char c = 'A';
    
    printf("=== Character as Integer ===\n\n");
    
    printf("char c = 'A'\n");
    printf("As character: %c\n", c);
    printf("As integer:   %d\n\n", c);
    
    printf("Character arithmetic:\n");
    printf("  'A' + 1 = %d = '%c'\n", 'A' + 1, 'A' + 1);
    printf("  'A' + 25 = %d = '%c'\n", 'A' + 25, 'A' + 25);
    printf("  'a' - 'A' = %d (difference between cases)\n", 'a' - 'A');
    
    printf("\nConvert lowercase to uppercase:\n");
    char lower = 'h';
    char upper = lower - 32;
    printf("  '%c' - 32 = '%c'\n", lower, upper);
    
    printf("\nConvert digit char to actual number:\n");
    char digit = '7';
    int value = digit - '0';
    printf("  '%c' - '0' = %d\n", digit, value);
    
    printf("\nLoop through alphabet:\n");
    printf("  ");
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        printf("%c ", ch);
    }
    printf("\n");
    
    return 0;
}
```

## Output

```
=== Character as Integer ===

char c = 'A'
As character: A
As integer:   65

Character arithmetic:
  'A' + 1 = 66 = 'B'
  'A' + 25 = 90 = 'Z'
  'a' - 'A' = 32 (difference between cases)

Convert lowercase to uppercase:
  'h' - 32 = 'H'

Convert digit char to actual number:
  '7' - '0' = 7

Loop through alphabet:
  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
```

## Key Takeaways

- Characters ARE integers in C
- `'0'` is 48, not 0
- `digit - '0'` converts char digit to int
- `'a' - 'A'` = 32 (case difference)
- You can loop through characters: `for (char c = 'A'; c <= 'Z'; c++)`
- Character arithmetic enables simple encryption/encoding

## Challenge

Write a ROT13 encoder: shift each letter by 13 positions, wrapping from Z to A. ('A' becomes 'N', 'N' becomes 'A')

## Related

- [[014-character-type-char]] — char basics
- [[175-toupper-tolower]] — Standard case conversion
- [[171-ctype-h-overview]] — isdigit, isalpha, etc.
