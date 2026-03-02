# toupper and tolower - Case Conversion

## Overview
`toupper` converts lowercase to uppercase, and `tolower` converts uppercase to lowercase. Non-letter characters pass through unchanged.

## Function Signatures
```c
int toupper(int c);  // Convert to uppercase if lowercase
int tolower(int c);  // Convert to lowercase if uppercase
```

## Return Values
- Returns converted character if applicable
- Returns original character if not a convertible letter
- Returns int (cast to char if needed)

## Behavior

### toupper
| Input | Output |
|-------|--------|
| 'a'-'z' | 'A'-'Z' |
| 'A'-'Z' | unchanged |
| digits | unchanged |
| punctuation | unchanged |

### tolower
| Input | Output |
|-------|--------|
| 'A'-'Z' | 'a'-'z' |
| 'a'-'z' | unchanged |
| digits | unchanged |
| punctuation | unchanged |

## Common Patterns

### Convert Entire String to Uppercase
```c
void str_to_upper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}
```

### Convert Entire String to Lowercase
```c
void str_to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}
```

### Case-Insensitive Comparison
```c
int strcasecmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int diff = tolower(*s1) - tolower(*s2);
        if (diff != 0) return diff;
        s1++; s2++;
    }
    return tolower(*s1) - tolower(*s2);
}
```

### Toggle Case
```c
char toggle_case(char c) {
    if (isupper(c)) return tolower(c);
    if (islower(c)) return toupper(c);
    return c;
}
```

### Capitalize First Letter
```c
void capitalize(char *str) {
    if (str[0]) {
        str[0] = toupper((unsigned char)str[0]);
    }
}
```

## Compilation
```bash
gcc -o toupper-tolower toupper-tolower.c
./toupper-tolower
```

---

# Kata Challenge: Text Case Transformer

## Objective
Build a comprehensive text case transformation utility.

## Requirements
1. Convert to UPPERCASE, lowercase, Title Case
2. Implement sentence case (capitalize after periods)
3. Create toggle case
4. Handle special rules (preserve acronyms, handle apostrophes)

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Convert to uppercase
void to_uppercase(char *dest, const char *src) {
    while (*src) {
        *dest++ = toupper((unsigned char)*src++);
    }
    *dest = '\0';
}

// Convert to lowercase
void to_lowercase(char *dest, const char *src) {
    while (*src) {
        *dest++ = tolower((unsigned char)*src++);
    }
    *dest = '\0';
}

// Convert to Title Case (capitalize first letter of each word)
void to_titlecase(char *dest, const char *src) {
    bool new_word = true;
    
    while (*src) {
        if (isspace(*src)) {
            new_word = true;
            *dest++ = *src++;
        } else if (new_word) {
            *dest++ = toupper((unsigned char)*src++);
            new_word = false;
        } else {
            *dest++ = tolower((unsigned char)*src++);
        }
    }
    *dest = '\0';
}

// Convert to Sentence Case (capitalize after . ! ?)
void to_sentencecase(char *dest, const char *src) {
    // TODO: Implement
}

// Toggle case (A→a, a→A)
void toggle_case(char *dest, const char *src) {
    // TODO: Implement
}

// Alternating case (hElLo)
void alternating_case(char *dest, const char *src) {
    // TODO: Implement
}

// Smart Title Case (don't capitalize small words like "the", "a", "of")
void smart_titlecase(char *dest, const char *src) {
    // TODO: Implement with list of exceptions
}

// Case-insensitive string comparison
int str_iequals(const char *s1, const char *s2) {
    // TODO: Implement
    return 0;
}

// Find substring case-insensitive
char *str_ifind(const char *haystack, const char *needle) {
    // TODO: Implement
    return NULL;
}

int main(void) {
    const char *original = "hello WORLD, how ARE you?";
    char result[100];
    
    printf("Original: \"%s\"\n\n", original);
    
    to_uppercase(result, original);
    printf("UPPERCASE: %s\n", result);
    
    to_lowercase(result, original);
    printf("lowercase: %s\n", result);
    
    to_titlecase(result, original);
    printf("Title Case: %s\n", result);
    
    // Test case-insensitive comparison
    printf("\n\"Hello\" equals \"HELLO\": %s\n",
           str_iequals("Hello", "HELLO") ? "yes" : "no");
    
    // Test sentence case
    const char *sentences = "hello. how are you? i am fine!";
    to_sentencecase(result, sentences);
    printf("\nSentence case: %s\n", result);
    
    return 0;
}
```

## Expected Output
```
Original: "hello WORLD, how ARE you?"

UPPERCASE: HELLO WORLD, HOW ARE YOU?
lowercase: hello world, how are you?
Title Case: Hello World, How Are You?

"Hello" equals "HELLO": yes

Sentence case: Hello. How are you? I am fine!
```

## Bonus Challenges
1. Implement ROT13 cipher using case-preserving conversion
2. Create a camelCase to snake_case converter
3. Handle Unicode case conversion (beyond ASCII)
4. Create a title case that properly handles names like "McDonald"

## Test Cases
- Empty string → empty output
- All spaces → unchanged
- Already correct case → unchanged
- Mixed punctuation → preserved
