---
id: "035"
title: "Escape Sequences"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - escape-sequences
  - strings
  - characters
difficulty: beginner
source: "C11 Standard Section 6.4.4.4"
---

# 035 — Escape Sequences

## Concept

Escape sequences are special character combinations starting with a backslash (`\`) that represent characters which cannot be typed directly or have special meaning. They work in both character literals and string literals.

Common escape sequences:
| Escape | Name | ASCII | Description |
|--------|------|-------|-------------|
| `\n` | Newline | 10 | Line feed |
| `\t` | Tab | 9 | Horizontal tab |
| `\r` | Return | 13 | Carriage return |
| `\\` | Backslash | 92 | Literal backslash |
| `\'` | Single quote | 39 | In char literals |
| `\"` | Double quote | 34 | In strings |
| `\0` | Null | 0 | String terminator |
| `\a` | Alert | 7 | Bell/beep |
| `\b` | Backspace | 8 | Back one char |

Numeric escapes:
- **Octal**: `\nnn` (1-3 octal digits) — `\101` = 'A'
- **Hex**: `\xNN` (any hex digits) — `\x41` = 'A'

> **Security Critical**: The null terminator `\0` is fundamental to C strings and a source of many vulnerabilities. Hex escapes `\xNN` are essential for shellcode and binary data manipulation.

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Escape Sequences ===\n\n");
    
    printf("Common escape sequences:\n");
    printf("  \\n  = newline\n");
    printf("  \\t  = horizontal tab\t<- after tab\n");
    printf("  \\r  = carriage return (moves cursor to line start)\n");
    printf("  \\\\  = backslash: \\\n");
    printf("  \\'  = single quote: \'\n");
    printf("  \\\"  = double quote: \"\n");
    printf("  \\0  = null character (string terminator)\n");
    
    printf("\nLess common escapes:\n");
    printf("  \\a  = alert (bell)");
    printf("\a");
    printf(" <- bell rang\n");
    printf("  \\b  = backspace: ABC\\b\\b = AB\bC\n");
    printf("  \\f  = form feed (new page)\n");
    printf("  \\v  = vertical tab\n");
    printf("  \\?  = question mark: \\? = \?\n");
    
    printf("\nOctal escape sequences (\\nnn):\n");
    printf("  \\101 = %c (octal 101 = 'A')\n", '\101');
    printf("  \\141 = %c (octal 141 = 'a')\n", '\141');
    printf("  \\060 = %c (octal 60 = '0')\n", '\060');
    printf("  \\012 = newline (octal 12 = 10)\n");
    
    printf("\nHexadecimal escape sequences (\\xNN):\n");
    printf("  \\x41 = %c (hex 41 = 'A')\n", '\x41');
    printf("  \\x61 = %c (hex 61 = 'a')\n", '\x61');
    printf("  \\x30 = %c (hex 30 = '0')\n", '\x30');
    printf("  \\x0A = newline (hex 0A = 10)\n");
    
    printf("\nPractical examples:\n");
    printf("  Tab-separated:\tvalue1\tvalue2\tvalue3\n");
    printf("  Quoted string: \"Hello, World!\"\n");
    printf("  File path: C:\\\\Users\\\\Admin\\\\file.txt\n");
    printf("  Progress: [####      ] 40%%\r");
    printf("  Progress: [######    ] 60%%\n");
    
    printf("\nNull terminator demonstration:\n");
    char str[] = "Hello\0World";
    printf("  char str[] = \"Hello\\0World\";\n");
    printf("  printf(str) = \"%s\"\n", str);
    printf("  Only 'Hello' prints - \\0 terminates the string\n");
    
    printf("\nSecurity-relevant escapes:\n");
    printf("  Shellcode byte: \\x90 (NOP = %d)\n", '\x90');
    printf("  Null byte: \\x00 (terminates strings)\n");
    printf("  Return: \\x0d\\x0a (CRLF = Windows newline)\n");
    
    return 0;
}
```

## Output

```
=== Escape Sequences ===

Common escape sequences:
  \n  = newline
  \t  = horizontal tab	<- after tab
  \r  = carriage return (moves cursor to line start)
  \\  = backslash: \
  \'  = single quote: '
  \"  = double quote: "
  \0  = null character (string terminator)

Less common escapes:
  \a  = alert (bell) <- bell rang
  \b  = backspace: ABC\b\b = AC
  \f  = form feed (new page)
  \v  = vertical tab
  \?  = question mark: \? = ?

Octal escape sequences (\nnn):
  \101 = A (octal 101 = 'A')
  \141 = a (octal 141 = 'a')
  \060 = 0 (octal 60 = '0')
  \012 = newline (octal 12 = 10)

Hexadecimal escape sequences (\xNN):
  \x41 = A (hex 41 = 'A')
  \x61 = a (hex 61 = 'a')
  \x30 = 0 (hex 30 = '0')
  \x0A = newline (hex 0A = 10)

Practical examples:
  Tab-separated:	value1	value2	value3
  Quoted string: "Hello, World!"
  File path: C:\\Users\\Admin\\file.txt
  Progress: [######    ] 60%

Null terminator demonstration:
  char str[] = "Hello\0World";
  printf(str) = "Hello"
  Only 'Hello' prints - \0 terminates the string

Security-relevant escapes:
  Shellcode byte: \x90 (NOP = 144)
  Null byte: \x00 (terminates strings)
  Return: \x0d\x0a (CRLF = Windows newline)
```

## Key Takeaways

- Escape sequences start with backslash `\`
- `\n` (newline) and `\t` (tab) are most common
- `\0` is the null terminator — critical for C strings
- Octal: `\nnn`, Hex: `\xNN` for any byte value
- Use `\\` to print a literal backslash
- `\r` returns cursor to line start without newline

## Challenge

Create a program that prints a formatted table using tabs, with proper column alignment. Then create a "typing" animation using `\r` to overwrite the same line.

## Related

- [[034-character-literals]] — Character constants
- [[036-string-literals]] — String constants
- [[048-format-specifier-s]] — Printing strings
