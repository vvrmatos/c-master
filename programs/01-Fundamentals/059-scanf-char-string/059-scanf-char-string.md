---
id: "059"
title: "scanf() Character and String Input"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - scanf
  - input
  - strings
  - characters
difficulty: beginner
source: "C11 Standard 7.21.6.2"
---

# 059 — scanf() Character and String Input

## Concept

Character and string input with scanf requires special attention to whitespace handling and buffer overflow prevention.

**Character input (`%c`):**
```c
scanf("%c", &ch);   // Reads NEXT char (including whitespace!)
scanf(" %c", &ch);  // Space skips whitespace first
```

**String input (`%s`):**
```c
scanf("%s", str);     // DANGER: No buffer limit
scanf("%49s", str);   // Safe: reads max 49 chars + null
```

**%s behavior:**
- Skips leading whitespace
- Stops at first whitespace character
- Cannot read strings with spaces
- Does NOT need `&` (array name is address)

**Character class `%[...]`:**
```c
scanf("%[a-z]", str);     // Only lowercase letters
scanf("%[0-9]", str);     // Only digits
scanf("%[^\n]", str);     // Everything except newline
scanf("%[^,]", str);      // Until comma
```

**Security considerations:**
| Input | Risk |
|-------|------|
| `scanf("%s", buf)` | Buffer overflow → crash/exploit |
| `scanf("%99s", buf)` | Safe with 100-byte buffer |
| `fgets()` | Preferred for lines |

> **Security Warning:** Never use `%s` without width limit. Attacker can overflow buffer with long input.

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== scanf() Character and String Input ===\n\n");
    
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    printf("  Character: '%c' (ASCII: %d)\n\n", ch, ch);
    
    printf("Why space before %%c?\n");
    printf("  Without space: reads leftover newline from previous input\n");
    printf("  With space: skips whitespace first\n\n");
    
    char c1, c2, c3;
    printf("Enter three characters (no spaces): ");
    scanf(" %c%c%c", &c1, &c2, &c3);
    printf("  Got: '%c' '%c' '%c'\n\n", c1, c2, c3);
    
    char word[50];
    printf("Enter a single word: ");
    scanf("%49s", word);
    printf("  Word: '%s'\n\n", word);
    
    printf("%%s behavior:\n");
    printf("  - Skips leading whitespace\n");
    printf("  - Stops at whitespace (space, tab, newline)\n");
    printf("  - Can't read phrases with spaces\n\n");
    
    char first[20], last[20];
    printf("Enter first and last name: ");
    scanf("%19s %19s", first, last);
    printf("  Full name: %s %s\n\n", first, last);
    
    char limited[10];
    printf("Enter a long word (will be truncated to 9 chars): ");
    scanf("%9s", limited);
    printf("  Limited: '%s'\n\n", limited);
    
    char name[30];
    int age;
    printf("Enter 'name age' (e.g., Alice 25): ");
    scanf("%29s %d", name, &age);
    printf("  Name: %s, Age: %d\n\n", name, age);
    
    printf("Character class with []: \n");
    char alpha[50];
    printf("Enter letters only (stops at non-letter): ");
    scanf(" %49[a-zA-Z]", alpha);
    printf("  Letters: '%s'\n\n", alpha);
    
    while (getchar() != '\n');
    
    char digits[20];
    printf("Enter digits only: ");
    scanf("%19[0-9]", digits);
    printf("  Digits: '%s'\n\n", digits);
    
    while (getchar() != '\n');
    
    char line[100];
    printf("Enter text until newline: ");
    scanf(" %99[^\n]", line);
    printf("  Line: '%s'\n\n", line);
    
    printf("scanf string security:\n");
    printf("  DANGEROUS: scanf(\"%%s\", buffer);\n");
    printf("  SAFE: scanf(\"%%49s\", buffer);  // limit width\n");
    printf("  BETTER: Use fgets() for line input\n");
    
    return 0;
}
```

## Output

```
=== scanf() Character and String Input ===

Enter a character: A
  Character: 'A' (ASCII: 65)

Why space before %c?
  Without space: reads leftover newline from previous input
  With space: skips whitespace first

Enter three characters (no spaces): XYZ
  Got: 'X' 'Y' 'Z'

Enter a single word: Hello
  Word: 'Hello'

%s behavior:
  - Skips leading whitespace
  - Stops at whitespace (space, tab, newline)
  - Can't read phrases with spaces

Enter first and last name: John Doe
  Full name: John Doe

Enter a long word (will be truncated to 9 chars): Supercalifragilistic
  Limited: 'Supercali'

Enter 'name age' (e.g., Alice 25): Alice 25
  Name: Alice, Age: 25

Character class with []: 
Enter letters only (stops at non-letter): Hello123
  Letters: 'Hello'

Enter digits only: 12345
  Digits: '12345'

Enter text until newline: This is a full line with spaces
  Line: 'This is a full line with spaces'

scanf string security:
  DANGEROUS: scanf("%s", buffer);
  SAFE: scanf("%49s", buffer);  // limit width
  BETTER: Use fgets() for line input
```

## Compilation

```bash
gcc 059-scanf-char-string.c -o 059-scanf-char-string
./059-scanf-char-string
```

## Key Takeaways

- Use `" %c"` (with space) to skip whitespace before character
- Always limit `%s` width: `%49s` not `%s`
- `%s` stops at whitespace — can't read phrases
- Use `%[^\n]` to read until newline (like a line)
- Character classes `%[...]` for controlled input
- Consider `fgets()` for safer line input

## Challenge

Write a program that reads a CSV line with name, age, and city, handling the commas as delimiters using scanf character classes.

## Related

- [[056-scanf-basics]] — scanf fundamentals  
- [[063-fgets]] — Safe line input with fgets
