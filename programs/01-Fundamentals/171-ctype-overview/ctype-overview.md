# ctype.h Overview - Character Classification

## Overview
The `<ctype.h>` header provides functions for testing characters (is*) and converting case (to*). All functions work on int values representing unsigned char or EOF.

## Classification Functions

| Function | Tests for |
|----------|-----------|
| isalpha(c) | Letter (a-z, A-Z) |
| isdigit(c) | Digit (0-9) |
| isalnum(c) | Letter or digit |
| isspace(c) | Whitespace (space, tab, newline, etc.) |
| isupper(c) | Uppercase letter |
| islower(c) | Lowercase letter |
| ispunct(c) | Punctuation |
| isprint(c) | Printable (including space) |
| isgraph(c) | Printable (excluding space) |
| iscntrl(c) | Control character |
| isxdigit(c) | Hexadecimal digit (0-9, a-f, A-F) |
| isblank(c) | Space or tab only (C99) |

## Conversion Functions

| Function | Action |
|----------|--------|
| toupper(c) | Convert to uppercase |
| tolower(c) | Convert to lowercase |

## Important Notes

### Return Values
- is* functions return **non-zero** (true) or **zero** (false)
- Don't assume return value is 1 for true!

### Parameter Type
```c
// Correct (int from unsigned char)
char c = 'a';
if (isalpha((unsigned char)c)) { ... }

// Dangerous with signed char and negative values
char c = -1;  // Could be EOF or valid char depending on platform
isalpha(c);   // Undefined behavior if c < 0 and != EOF
```

### Locale Dependency
- These functions can be locale-dependent
- In "C" locale, only ASCII characters are classified
- Other locales may classify accented characters differently

## ASCII Reference

| Range | Characters |
|-------|------------|
| 0-31 | Control characters |
| 32 | Space |
| 33-47 | Punctuation (!\"#$%&'()*+,-./) |
| 48-57 | Digits (0-9) |
| 58-64 | Punctuation (:;<=>?@) |
| 65-90 | Uppercase (A-Z) |
| 91-96 | Punctuation ([\\]^_`) |
| 97-122 | Lowercase (a-z) |
| 123-126 | Punctuation ({|}~) |
| 127 | DEL (control) |

## Compilation
```bash
gcc -o ctype-overview ctype-overview.c
./ctype-overview
```

---

# Kata Challenge: Text Analyzer

## Objective
Build a comprehensive text analysis tool using ctype functions.

## Requirements
1. Count different character types
2. Generate character frequency statistics
3. Validate strings against patterns
4. Clean and normalize text

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int total;
    int letters;
    int uppercase;
    int lowercase;
    int digits;
    int spaces;
    int punctuation;
    int control;
    int printable;
} TextStats;

TextStats analyze_text(const char *text) {
    TextStats stats = {0};
    
    for (int i = 0; text[i]; i++) {
        unsigned char c = text[i];
        stats.total++;
        
        // TODO: Classify each character
    }
    
    return stats;
}

void print_stats(const TextStats *s) {
    printf("Total characters: %d\n", s->total);
    printf("  Letters: %d (upper: %d, lower: %d)\n",
           s->letters, s->uppercase, s->lowercase);
    printf("  Digits: %d\n", s->digits);
    printf("  Spaces: %d\n", s->spaces);
    printf("  Punctuation: %d\n", s->punctuation);
}

// Check if string is valid identifier (letter/underscore start, alnum after)
int is_valid_identifier(const char *str) {
    // TODO: Implement
    return 0;
}

// Check if string is valid integer
int is_valid_integer(const char *str) {
    // TODO: Implement
    return 0;
}

// Normalize: trim, lowercase, collapse spaces
void normalize_text(char *dest, const char *src, size_t size) {
    // TODO: Implement
}

int main(void) {
    const char *text = "Hello, World! 123\n\tTest";
    
    printf("Analyzing: \"%s\"\n\n", text);
    TextStats stats = analyze_text(text);
    print_stats(&stats);
    
    printf("\nIdentifier tests:\n");
    const char *ids[] = {"valid_name", "123invalid", "_ok", "has space", NULL};
    for (int i = 0; ids[i]; i++) {
        printf("  \"%s\": %s\n", ids[i], 
               is_valid_identifier(ids[i]) ? "valid" : "invalid");
    }
    
    return 0;
}
```

## Expected Output
```
Analyzing: "Hello, World! 123
	Test"

Total characters: 22
  Letters: 14 (upper: 3, lower: 11)
  Digits: 3
  Spaces: 3
  Punctuation: 2

Identifier tests:
  "valid_name": valid
  "123invalid": invalid
  "_ok": valid
  "has space": invalid
```

## Bonus Challenges
1. Build a password strength checker
2. Create a slug generator (URL-friendly strings)
3. Implement camelCase/snake_case converters
4. Add Unicode support (beyond ASCII)

## Test Cases
- Empty string → all zeros
- All letters → letters = total
- Mixed content → correct counts
