---
id: "047"
title: "Format Specifier: %c"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - char
  - ascii
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 047 — Format Specifier: %c (Character)

## Concept

`%c` is the format specifier for printing a **single character**. In C, characters are integers representing ASCII (or Unicode) code points.

**Key facts:**
- Prints exactly one character
- Argument is converted to `unsigned char`
- Can print any ASCII value (including non-printable)
- Integer values are interpreted as character codes

**Character representations:**
```c
char c = 'A';     // Character literal
char c = 65;      // ASCII code (same as 'A')
char c = 0x41;    // Hex code (same as 'A')
```

**Important ASCII ranges:**
| Range | Characters |
|-------|------------|
| 48-57 | '0' to '9' |
| 65-90 | 'A' to 'Z' |
| 97-122 | 'a' to 'z' |
| 32 | Space |
| 0 | Null terminator |

**Character arithmetic:**
- `'A' + 1` gives `'B'`
- `'a' - 'A'` = 32 (difference between cases)
- `ch - '0'` converts digit char to int value

**Width with %c:**
```c
printf("%5c", 'X');   // Right-aligned in 5-width field
printf("%-5c", 'X');  // Left-aligned
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Format Specifier: %%c (Character) ===\n\n");
    
    char letter = 'A';
    char digit = '7';
    char symbol = '@';
    
    printf("Basic character output:\n");
    printf("  Letter: %c\n", letter);
    printf("  Digit: %c\n", digit);
    printf("  Symbol: %c\n", symbol);
    
    printf("\nCharacter literals:\n");
    printf("  Single quote: %c\n", '\'');
    printf("  Backslash: %c\n", '\\');
    printf("  Percent: %c\n", '%');
    
    printf("\nASCII values as characters:\n");
    printf("  65 = '%c'\n", 65);
    printf("  97 = '%c'\n", 97);
    printf("  48 = '%c'\n", 48);
    printf("  33 = '%c'\n", 33);
    
    printf("\nPrinting alphabet:\n  ");
    for (char c = 'A'; c <= 'Z'; c++) {
        printf("%c ", c);
    }
    printf("\n  ");
    for (char c = 'a'; c <= 'z'; c++) {
        printf("%c ", c);
    }
    printf("\n");
    
    printf("\nPrinting digits:\n  ");
    for (char c = '0'; c <= '9'; c++) {
        printf("%c ", c);
    }
    printf("\n");
    
    printf("\nSpecial characters via escape:\n");
    printf("  Tab: [%c]\n", '\t');
    printf("  Newline: [\\n]\n");
    printf("  Null: [%c] (invisible)\n", '\0');
    
    printf("\nCharacter arithmetic:\n");
    char base = 'A';
    printf("  '%c' + 1 = '%c'\n", base, base + 1);
    printf("  '%c' + 25 = '%c'\n", base, base + 25);
    printf("  'a' - 'A' = %d (case difference)\n", 'a' - 'A');
    
    printf("\nCase conversion:\n");
    char upper = 'G';
    char lower = 'g';
    printf("  '%c' to lowercase: '%c'\n", upper, upper + 32);
    printf("  '%c' to uppercase: '%c'\n", lower, lower - 32);
    
    printf("\nPrinting a simple box:\n");
    printf("  +---+\n");
    printf("  | %c |\n", 'X');
    printf("  +---+\n");
    
    return 0;
}
```

## Output

```
=== Format Specifier: %c (Character) ===

Basic character output:
  Letter: A
  Digit: 7
  Symbol: @

Character literals:
  Single quote: '
  Backslash: \
  Percent: %

ASCII values as characters:
  65 = 'A'
  97 = 'a'
  48 = '0'
  33 = '!'

Printing alphabet:
  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
  a b c d e f g h i j k l m n o p q r s t u v w x y z 

Printing digits:
  0 1 2 3 4 5 6 7 8 9 

Special characters via escape:
  Tab: [	]
  Newline: [\n]
  Null: [] (invisible)

Character arithmetic:
  'A' + 1 = 'B'
  'A' + 25 = 'Z'
  'a' - 'A' = 32 (case difference)

Case conversion:
  'G' to lowercase: 'g'
  'g' to uppercase: 'G'

Printing a simple box:
  +---+
  | X |
  +---+
```

## Compilation

```bash
gcc 047-format-specifier-c.c -o 047-format-specifier-c
./047-format-specifier-c
```

## Key Takeaways

- `%c` prints a single character from its ASCII/Unicode value
- Characters are integers — arithmetic works on them
- Case conversion: +32 for lowercase, -32 for uppercase
- Character literals use single quotes: `'A'`
- String literals use double quotes: `"ABC"`
- `%c` can print any byte value, including control characters

## Challenge

Write a program that prints an ASCII table showing characters 32-127 with their decimal and hex codes.

## Related

- [[048-format-specifier-s]] — String format specifier
- [[061-getchar]] — Reading single characters
