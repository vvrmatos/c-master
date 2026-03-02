# isprint and iscntrl - Printable and Control Characters

## Overview
The `isprint()` function tests if a character is printable (including space), while `iscntrl()` tests if a character is a control character. These functions from `<ctype.h>` help classify characters by their visibility and function.

## Function Signatures
```c
#include <ctype.h>

int isprint(int c);  // Returns non-zero if printable (32-126)
int iscntrl(int c);  // Returns non-zero if control char (0-31, 127)
```

## Character Classification

| Category | ASCII Range | Examples |
|----------|-------------|----------|
| Printable | 32-126 | A-Z, a-z, 0-9, space, punctuation |
| Control | 0-31, 127 | \n, \t, \r, \0, DEL |

## Key Concepts

### Printable Characters
- Include letters, digits, punctuation, and space
- Visible when output to terminal
- ASCII codes 32 (space) through 126 (~)

### Control Characters
- Non-printable characters that control devices
- Include newline, tab, carriage return
- ASCII codes 0-31 and 127 (DEL)

## Common Control Characters
| Char | ASCII | Name | Escape |
|------|-------|------|--------|
| NUL | 0 | Null | \0 |
| TAB | 9 | Horizontal Tab | \t |
| LF | 10 | Line Feed | \n |
| CR | 13 | Carriage Return | \r |
| ESC | 27 | Escape | \e |
| DEL | 127 | Delete | - |

## Use Cases
- Filtering user input to printable only
- Detecting hidden control characters
- Sanitizing strings for display
- Terminal/text processing

---

# Kata Challenge: Character Filter

## Objective
Write a program that filters a string to show only printable characters and counts control characters.

## Requirements
1. Read a string that may contain control characters
2. Print only the printable characters
3. Count and report the number of control characters found
4. Show the ASCII value of each control character found

## Example
```
Input: "Hello\tWorld\n"
Output:
Printable: HelloWorld
Control characters found: 2
  - ASCII 9 (TAB)
  - ASCII 10 (LF)
```

## Hints
- Use `isprint()` to filter printable chars
- Use `iscntrl()` to detect control chars
- Store control chars in an array for reporting

## Bonus
- Handle extended ASCII (128-255)
- Create escape sequence representation for known control chars
