# isalnum and isspace - Alphanumeric and Whitespace Tests

## Overview
`isalnum` tests for letters OR digits, while `isspace` tests for whitespace characters. These are essential for parsing and text processing.

## Function Signatures
```c
int isalnum(int c);  // Returns non-zero if letter or digit
int isspace(int c);  // Returns non-zero if whitespace
```

## What They Match

### isalnum
Equivalent to `isalpha(c) || isdigit(c)`:
- All letters: A-Z, a-z
- All digits: 0-9
- Does NOT match: underscore, punctuation, whitespace

### isspace
Standard whitespace characters:
| Character | Code | Name |
|-----------|------|------|
| ' ' | 0x20 | Space |
| '\t' | 0x09 | Horizontal tab |
| '\n' | 0x0A | Newline |
| '\v' | 0x0B | Vertical tab |
| '\f' | 0x0C | Form feed |
| '\r' | 0x0D | Carriage return |

### Related: isblank (C99)
Only matches space and horizontal tab (not newline, etc.)

## Common Patterns

### Skip Whitespace
```c
while (*str && isspace(*str)) str++;
```

### Trim String
```c
// Trim leading
while (isspace(*str)) str++;

// Trim trailing
int len = strlen(str);
while (len > 0 && isspace(str[len-1])) {
    str[--len] = '\0';
}
```

### Word Count
```c
int count = 0, in_word = 0;
for (int i = 0; str[i]; i++) {
    if (isspace(str[i])) {
        in_word = 0;
    } else if (!in_word) {
        in_word = 1;
        count++;
    }
}
```

### Valid C Identifier
```c
int valid = (isalpha(s[0]) || s[0] == '_');
for (int i = 1; valid && s[i]; i++) {
    valid = isalnum(s[i]) || s[i] == '_';
}
```

## Compilation
```bash
gcc -o isalnum-isspace isalnum-isspace.c
./isalnum-isspace
```

---

# Kata Challenge: Text Tokenizer

## Objective
Build a text tokenizer using isalnum and isspace.

## Requirements
1. Split text into tokens (words)
2. Handle various whitespace types
3. Extract alphanumeric tokens only
4. Support custom delimiters

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKEN_LEN 64
#define MAX_TOKENS 100

typedef struct {
    char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
    int count;
} TokenList;

// Trim whitespace from both ends (modifies in place)
char *trim(char *str) {
    // TODO: Skip leading whitespace
    // TODO: Remove trailing whitespace
    return str;
}

// Split by whitespace
TokenList tokenize_whitespace(const char *text) {
    TokenList list = {0};
    // TODO: Extract words separated by any whitespace
    return list;
}

// Split by custom delimiter
TokenList tokenize_delim(const char *text, char delim) {
    TokenList list = {0};
    // TODO: Extract tokens separated by delimiter
    return list;
}

// Extract only alphanumeric words
TokenList tokenize_alnum(const char *text) {
    TokenList list = {0};
    // TODO: Extract sequences of alphanumeric characters
    return list;
}

// Collapse multiple spaces to single space
void collapse_spaces(char *dest, const char *src) {
    // TODO: Implement
}

// Check if string is single word (no spaces, alphanumeric)
bool is_single_word(const char *str) {
    // TODO: Implement
    return false;
}

void print_tokens(const TokenList *list) {
    printf("Tokens (%d):", list->count);
    for (int i = 0; i < list->count; i++) {
        printf(" [%s]", list->tokens[i]);
    }
    printf("\n");
}

int main(void) {
    // Test trim
    char test1[] = "   hello world   ";
    printf("Trim: \"%s\" -> \"%s\"\n", test1, trim(test1));
    
    // Test whitespace tokenize
    const char *text = "The  quick\tbrown\n\nfox";
    printf("\nTokenize: \"%s\"\n", text);
    TokenList tokens = tokenize_whitespace(text);
    print_tokens(&tokens);
    
    // Test alnum tokenize
    const char *mixed = "Hello, World! How's it going? #123";
    printf("\nAlnum only: \"%s\"\n", mixed);
    tokens = tokenize_alnum(mixed);
    print_tokens(&tokens);
    
    // Test collapse
    char collapsed[100];
    collapse_spaces(collapsed, "too    many   spaces");
    printf("\nCollapsed: \"%s\"\n", collapsed);
    
    return 0;
}
```

## Expected Output
```
Trim: "   hello world   " -> "hello world"

Tokenize: "The  quick	brown

fox"
Tokens (4): [The] [quick] [brown] [fox]

Alnum only: "Hello, World! How's it going? #123"
Tokens (6): [Hello] [World] [How] [s] [it] [going] [123]

Collapsed: "too many spaces"
```

## Bonus Challenges
1. Preserve quoted strings as single tokens
2. Implement command-line argument parser
3. Support escape sequences in tokens
4. Build a simple lexer for a mini-language

## Test Cases
- Empty string → 0 tokens
- All whitespace → 0 tokens
- Single word → 1 token
- Multiple spaces → collapsed correctly
