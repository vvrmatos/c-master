---
id: "062"
title: "putchar() - Single Character Output"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - output
  - putchar
  - characters
  - stdio
difficulty: beginner
source: "C11 Standard 7.21.7.8"
---

# 062 — putchar() - Single Character Output

## Concept

`putchar()` writes a single character to stdout. It's the complement to `getchar()` and is efficient for character-by-character output.

**Syntax:**
```c
int putchar(int character);
```

**Key characteristics:**
- Outputs one character to stdout
- Returns the character written on success
- Returns EOF on error
- Argument is `int` but only lowest byte used

**Return value:**
- Success: Character written (as unsigned char cast to int)
- Error: EOF

**putchar() vs printf("%c", c):**
- `putchar()` is typically faster (less overhead)
- `printf()` offers formatting options
- Use `putchar()` for simple character output
- Use `printf()` when formatting is needed

**Common uses:**
- Character-by-character output
- Building strings manually
- Drawing ASCII art
- Simple text transformations

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== putchar() - Single Character Output ===\n\n");
    
    printf("Basic putchar() usage:\n");
    putchar('H');
    putchar('e');
    putchar('l');
    putchar('l');
    putchar('o');
    putchar('\n');
    
    printf("\nOutputting with ASCII values:\n");
    putchar(65);
    putchar(66);
    putchar(67);
    putchar('\n');
    
    printf("\nPrinting alphabet:\n");
    for (char c = 'A'; c <= 'Z'; c++) {
        putchar(c);
    }
    putchar('\n');
    for (char c = 'a'; c <= 'z'; c++) {
        putchar(c);
    }
    putchar('\n');
    
    printf("\nPrinting digits:\n");
    for (char c = '0'; c <= '9'; c++) {
        putchar(c);
        putchar(' ');
    }
    putchar('\n');
    
    printf("\nCreating patterns:\n");
    for (int row = 1; row <= 5; row++) {
        for (int col = 0; col < row; col++) {
            putchar('*');
        }
        putchar('\n');
    }
    
    printf("\nputchar() return value:\n");
    int result = putchar('X');
    putchar('\n');
    printf("  putchar('X') returned: %d (ASCII of 'X')\n", result);
    printf("  On error, returns EOF (%d)\n\n", EOF);
    
    printf("Drawing a box:\n");
    int width = 20;
    
    putchar('+');
    for (int i = 0; i < width - 2; i++) putchar('-');
    putchar('+');
    putchar('\n');
    
    for (int row = 0; row < 3; row++) {
        putchar('|');
        for (int i = 0; i < width - 2; i++) putchar(' ');
        putchar('|');
        putchar('\n');
    }
    
    putchar('+');
    for (int i = 0; i < width - 2; i++) putchar('-');
    putchar('+');
    putchar('\n');
    
    printf("\nputchar() vs printf():\n");
    printf("  putchar(): outputs single character\n");
    printf("  printf(\"%%c\", ch): same but more overhead\n");
    printf("  putchar(): faster for character-by-character output\n");
    printf("  Use putchar() in tight loops for performance\n");
    
    printf("\nCopy input to output (type, press Enter):\n");
    printf("  Enter text: ");
    int ch;
    printf("  Echo: ");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        putchar(ch);
    }
    putchar('\n');
    
    return 0;
}
```

## Output

```
=== putchar() - Single Character Output ===

Basic putchar() usage:
Hello

Outputting with ASCII values:
ABC

Printing alphabet:
ABCDEFGHIJKLMNOPQRSTUVWXYZ
abcdefghijklmnopqrstuvwxyz

Printing digits:
0 1 2 3 4 5 6 7 8 9 

Creating patterns:
*
**
***
****
*****

putchar() return value:
X
  putchar('X') returned: 88 (ASCII of 'X')
  On error, returns EOF (-1)

Drawing a box:
+------------------+
|                  |
|                  |
|                  |
+------------------+

putchar() vs printf():
  putchar(): outputs single character
  printf("%c", ch): same but more overhead
  putchar(): faster for character-by-character output
  Use putchar() in tight loops for performance

Copy input to output (type, press Enter):
  Enter text: Hello World
  Echo: Hello World
```

## Compilation

```bash
gcc 062-putchar.c -o 062-putchar
./062-putchar
```

## Key Takeaways

- `putchar()` outputs a single character to stdout
- Returns the character on success, EOF on error
- Faster than printf for single characters
- Can use ASCII codes directly: `putchar(65)` outputs 'A'
- Use with getchar() for character-by-character I/O
- Don't forget newlines: `putchar('\n')`

## Challenge

Write a program that reads text and outputs it with each character's ASCII code, like: `A(65) B(66) C(67)`.

## Related

- [[061-getchar]] — Single character input
- [[064-puts]] — String output
