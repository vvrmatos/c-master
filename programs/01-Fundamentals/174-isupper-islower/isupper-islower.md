# isupper and islower - Case Tests

## Overview
`isupper` tests for uppercase letters (A-Z) and `islower` tests for lowercase letters (a-z). Essential for case-sensitive validation and text analysis.

## Function Signatures
```c
int isupper(int c);  // Returns non-zero if uppercase letter
int islower(int c);  // Returns non-zero if lowercase letter
```

## What They Match

### isupper
- Matches: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
- ASCII codes: 65-90
- Does NOT match: lowercase, digits, punctuation

### islower
- Matches: a b c d e f g h i j k l m n o p q r s t u v w x y z
- ASCII codes: 97-122
- Does NOT match: uppercase, digits, punctuation

## Relationships
- `isalpha(c)` is true ⟺ `isupper(c) || islower(c)` is true
- `isupper(c)` is true ⟹ `isalpha(c)` is true
- `islower(c)` is true ⟹ `isalpha(c)` is true

## Common Case Patterns

### ALL UPPERCASE
```c
int is_all_upper(const char *s) {
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i]) && !isupper(s[i])) return 0;
    }
    return 1;
}
```

### all lowercase
```c
int is_all_lower(const char *s) {
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i]) && !islower(s[i])) return 0;
    }
    return 1;
}
```

### Title Case
```c
// Each word starts with uppercase, rest lowercase
int is_title_case(const char *s);
```

### camelCase
```c
// Starts lowercase, each new word capitalized
int is_camel_case(const char *s);
```

### PascalCase
```c
// Like camelCase but starts uppercase
int is_pascal_case(const char *s);
```

## Compilation
```bash
gcc -o isupper-islower isupper-islower.c
./isupper-islower
```

---

# Kata Challenge: Case Style Detector and Converter

## Objective
Create a tool that detects and converts between different case styles.

## Requirements
1. Detect case style (UPPER, lower, Title, camelCase, PascalCase, snake_case)
2. Convert between case styles
3. Handle edge cases (single letter, all numbers)
4. Preserve non-letter characters appropriately

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum {
    CASE_UNKNOWN,
    CASE_UPPER,      // ALL UPPERCASE
    CASE_LOWER,      // all lowercase
    CASE_TITLE,      // Title Case
    CASE_CAMEL,      // camelCase
    CASE_PASCAL,     // PascalCase
    CASE_SNAKE       // snake_case
} CaseStyle;

const char *style_name(CaseStyle style) {
    const char *names[] = {
        "Unknown", "UPPER", "lower", "Title", "camelCase", "PascalCase", "snake_case"
    };
    return names[style];
}

CaseStyle detect_case(const char *str) {
    // TODO: Analyze string and determine case style
    return CASE_UNKNOWN;
}

// Convert to all uppercase
void to_upper_case(char *dest, const char *src) {
    // TODO: Implement
}

// Convert to all lowercase
void to_lower_case(char *dest, const char *src) {
    // TODO: Implement
}

// Convert to Title Case
void to_title_case(char *dest, const char *src) {
    // TODO: Implement
}

// Convert to camelCase
void to_camel_case(char *dest, const char *src) {
    // TODO: Remove spaces/underscores, capitalize following letters
}

// Convert to snake_case
void to_snake_case(char *dest, const char *src) {
    // TODO: Insert underscores before capitals, lowercase all
}

int main(void) {
    const char *samples[] = {
        "HELLO WORLD",
        "hello world",
        "Hello World",
        "helloWorld",
        "HelloWorld",
        "hello_world",
        NULL
    };
    
    printf("Case Detection:\n");
    for (int i = 0; samples[i]; i++) {
        CaseStyle style = detect_case(samples[i]);
        printf("  \"%s\" -> %s\n", samples[i], style_name(style));
    }
    
    printf("\nConversions of \"Hello World\":\n");
    char result[100];
    const char *test = "Hello World";
    
    to_upper_case(result, test);
    printf("  UPPER: %s\n", result);
    
    to_lower_case(result, test);
    printf("  lower: %s\n", result);
    
    to_camel_case(result, test);
    printf("  camelCase: %s\n", result);
    
    to_snake_case(result, test);
    printf("  snake_case: %s\n", result);
    
    return 0;
}
```

## Expected Output
```
Case Detection:
  "HELLO WORLD" -> UPPER
  "hello world" -> lower
  "Hello World" -> Title
  "helloWorld" -> camelCase
  "HelloWorld" -> PascalCase
  "hello_world" -> snake_case

Conversions of "Hello World":
  UPPER: HELLO WORLD
  lower: hello world
  camelCase: helloWorld
  snake_case: hello_world
```

## Bonus Challenges
1. Handle mixed case intelligently
2. Support kebab-case (hello-world)
3. Preserve acronyms (XMLParser → xmlParser)
4. Handle Unicode letters (beyond ASCII)

## Test Cases
- Empty string → UNKNOWN
- "123" → UNKNOWN (no letters)
- "a" → could be LOWER or CAMEL
- "A" → could be UPPER or PASCAL
