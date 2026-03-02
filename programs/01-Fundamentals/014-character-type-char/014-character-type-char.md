---
id: "014"
title: "Character Type (char)"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - char
  - data-types
  - ascii
  - characters
difficulty: beginner
source: "C11 Standard 6.2.5, ASCII Table"
---

# 014 — Character Type (char)

## Concept

`char` stores a single character. In C, characters are actually **small integers** — each character maps to a number via ASCII (or other encoding).

**Key facts:**
- Size: exactly 1 byte (8 bits)
- Stores values 0-255 (or -128 to 127 if signed)
- Character literals use **single quotes**: `'A'`
- String literals use **double quotes**: `"ABC"`

**ASCII Ranges:**
| Characters | ASCII Range |
|------------|-------------|
| `'0'` - `'9'` | 48 - 57 |
| `'A'` - `'Z'` | 65 - 90 |
| `'a'` - `'z'` | 97 - 122 |
| space | 32 |

**Escape sequences:**
| Sequence | Meaning |
|----------|---------|
| `\n` | Newline |
| `\t` | Tab |
| `\\` | Backslash |
| `\'` | Single quote |
| `\"` | Double quote |
| `\0` | Null character (string terminator) |
| `\r` | Carriage return |

**signed vs unsigned char:**
- Plain `char` may be signed or unsigned (implementation-defined)
- Use `signed char` or `unsigned char` to be explicit
- `unsigned char` is often used for binary data (bytes)

**Format specifier:** `%c`

## Code

```c
#include <stdio.h>

int main(void) {
    char letter = 'A';
    char digit = '7';
    char newline = '\n';
    char tab = '\t';
    
    printf("=== Character Type (char) ===\n\n");
    
    printf("char letter = '%c'\n", letter);
    printf("char digit = '%c'\n", digit);
    
    printf("\nCharacters are stored as numbers (ASCII):\n");
    printf("  '%c' = %d\n", letter, letter);
    printf("  '%c' = %d\n", digit, digit);
    printf("  'a' = %d\n", 'a');
    printf("  'z' = %d\n", 'z');
    printf("  '0' = %d\n", '0');
    printf("  '9' = %d\n", '9');
    
    printf("\nSize of char: %zu byte\n", sizeof(char));
    
    printf("\nSpecial characters (escape sequences):\n");
    printf("  \\n = newline%c", newline);
    printf("  \\t = tab%clike this\n", tab);
    printf("  \\\\ = backslash: \\\n");
    printf("  \\' = single quote: \'\n");
    printf("  \\\" = double quote: \"\n");
    
    return 0;
}
```

## Output

```
=== Character Type (char) ===

char letter = 'A'
char digit = '7'

Characters are stored as numbers (ASCII):
  'A' = 65
  '7' = 55
  'a' = 97
  'z' = 122
  '0' = 48
  '9' = 57

Size of char: 1 byte

Special characters (escape sequences):
  \n = newline
  \t = tab	like this
  \\ = backslash: \
  \' = single quote: '
  \" = double quote: "
```

## Key Takeaways

- `char` is 1 byte, stores single characters
- Characters are numbers (ASCII codes)
- Use single quotes for chars: `'A'`
- Use double quotes for strings: `"ABC"`
- Digits `'0'`-`'9'` are ASCII 48-57 (not 0-9!)
- Escape sequences start with backslash
- `sizeof(char)` is always 1

## Challenge

Write a program that prints the entire printable ASCII table (characters 32-126) with their decimal values.

## Related

- [[015-character-as-integer]] — Math with characters
- [[035-escape-sequences]] — All escape sequences
- [[151-strings-in-c]] — Character arrays
- [[171-ctype-h-overview]] — Character classification
