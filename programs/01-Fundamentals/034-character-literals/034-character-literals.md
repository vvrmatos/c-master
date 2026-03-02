---
id: "034"
title: "Character Literals"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - literals
  - char
  - ascii
difficulty: beginner
source: "C11 Standard Section 6.4.4.4"
---

# 034 — Character Literals

## Concept

Character literals are single characters enclosed in single quotes (`'A'`). In C, character literals actually have type `int`, not `char`, though they're typically assigned to `char` variables. The value is the character's numeric code in the execution character set (usually ASCII).

Key points:
- **Single quotes** — `'A'` (double quotes `"A"` create a string)
- **Type is `int`** — `sizeof('A')` equals `sizeof(int)`, not 1
- **ASCII values** — characters map to numbers: 'A' = 65, '0' = 48
- **Character arithmetic** — `'A' + 1` = 'B', `'7' - '0'` = 7

Important ASCII ranges:
- `'0'` to `'9'` → 48-57 (digits)
- `'A'` to `'Z'` → 65-90 (uppercase)
- `'a'` to `'z'` → 97-122 (lowercase)

> **Security Application**: Character manipulation is fundamental for string processing, buffer handling, and encoding/decoding. Converting `'7' - '0'` to get digit value 7 is a common pattern in parsers.

## Code

```c
#include <stdio.h>

int main(void) {
    char letter = 'A';
    char lowercase = 'a';
    char digit = '7';
    char space = ' ';
    char newline = '\n';
    
    printf("=== Character Literals ===\n\n");
    
    printf("Basic character literals:\n");
    printf("  'A' = %c (ASCII %d)\n", letter, letter);
    printf("  'a' = %c (ASCII %d)\n", lowercase, lowercase);
    printf("  '7' = %c (ASCII %d)\n", digit, digit);
    printf("  ' ' = '%c' (ASCII %d)\n", space, space);
    
    printf("\nCharacter arithmetic:\n");
    printf("  'A' + 1 = '%c'\n", 'A' + 1);
    printf("  'a' - 'A' = %d (case difference)\n", 'a' - 'A');
    printf("  '7' - '0' = %d (digit value)\n", '7' - '0');
    printf("  'Z' - 'A' + 1 = %d letters in alphabet\n", 'Z' - 'A' + 1);
    
    printf("\nASCII ranges:\n");
    printf("  '0'-'9' = %d-%d\n", '0', '9');
    printf("  'A'-'Z' = %d-%d\n", 'A', 'Z');
    printf("  'a'-'z' = %d-%d\n", 'a', 'z');
    
    printf("\nSpecial ASCII values:\n");
    printf("  '\\0' (null) = %d\n", '\0');
    printf("  ' ' (space) = %d\n", ' ');
    printf("  '\\n' (newline) = %d\n", '\n');
    printf("  '\\t' (tab) = %d\n", '\t');
    
    printf("\nCharacter vs integer:\n");
    int as_int = 'A';
    char as_char = 65;
    printf("  int x = 'A'; x = %d\n", as_int);
    printf("  char c = 65; c = '%c'\n", as_char);
    
    printf("\nPrintable range:\n");
    printf("  ");
    for (char c = '!'; c <= '~'; c++) {
        printf("%c", c);
    }
    printf("\n");
    
    return 0;
}
```

## Output

```
=== Character Literals ===

Basic character literals:
  'A' = A (ASCII 65)
  'a' = a (ASCII 97)
  '7' = 7 (ASCII 55)
  ' ' = ' ' (ASCII 32)

Character arithmetic:
  'A' + 1 = 'B'
  'a' - 'A' = 32 (case difference)
  '7' - '0' = 7 (digit value)
  'Z' - 'A' + 1 = 26 letters in alphabet

ASCII ranges:
  '0'-'9' = 48-57
  'A'-'Z' = 65-90
  'a'-'z' = 97-122

Special ASCII values:
  '\0' (null) = 0
  ' ' (space) = 32
  '\n' (newline) = 10
  '\t' (tab) = 9

Character vs integer:
  int x = 'A'; x = 65
  char c = 65; c = 'A'

Printable range:
  !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
```

## Key Takeaways

- Character literals use single quotes: `'A'`
- Characters are numbers (ASCII codes)
- Character literal type is `int`, not `char`
- Convert digit character to value: `'7' - '0'` = 7
- Convert case: add/subtract 32 (`'a' - 'A'`)
- Printable ASCII: 32 (space) to 126 (~)

## Challenge

Write a function that converts a lowercase letter to uppercase using character arithmetic (without using library functions).

## Related

- [[014-character-type-char]] — Char variable type
- [[035-escape-sequences]] — Special character escapes
- [[047-format-specifier-c]] — Printing characters
