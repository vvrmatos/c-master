# strchr - Find Character in String

## Overview
`strchr` searches for the first occurrence of a character in a string. It returns a pointer to that position or NULL if not found.

## Function Signature
```c
char *strchr(const char *s, int c);
```

## Parameters
- **s**: String to search
- **c**: Character to find (passed as int, converted to char)

## Return Value
- Pointer to first occurrence of character
- NULL if character not found
- Can find null terminator '\0'

## Key Concepts

### Pointer Arithmetic
```c
const char *str = "Hello";
char *p = strchr(str, 'l');
int position = p - str;  // Index of found character
```

### Finding All Occurrences
```c
const char *p = str;
while ((p = strchr(p, 'l')) != NULL) {
    // Process each 'l'
    p++;
}
```

### Extracting Substrings
```c
char *at = strchr(email, '@');
if (at) {
    char domain[100];
    strcpy(domain, at + 1);  // Copy from after @
}
```

## Common Use Cases

### Path Parsing
```c
char *dot = strchr(filename, '.');
if (dot) {
    // dot points to extension
}
```

### Delimiter Finding
```c
char *colon = strchr(line, ':');
if (colon) {
    *colon = '\0';  // Split string
    char *key = line;
    char *value = colon + 1;
}
```

## Compilation
```bash
gcc -o strchr strchr.c
./strchr
```

---

# Kata Challenge: Email Parser

## Objective
Create an email address parser using strchr.

## Requirements
1. Validate email has exactly one '@'
2. Extract username and domain parts
3. Find and validate TLD (top-level domain)
4. Check for common invalid patterns

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char username[64];
    char domain[128];
    char tld[16];
    bool valid;
} EmailParts;

EmailParts parse_email(const char *email) {
    EmailParts parts = {0};
    
    // TODO: Find '@' using strchr
    // TODO: Validate only one '@' exists
    // TODO: Extract username (before @)
    // TODO: Extract domain (after @)
    // TODO: Find TLD (after last '.')
    
    return parts;
}

int main(void) {
    const char *emails[] = {
        "user@example.com",
        "john.doe@company.co.uk",
        "invalid@@email.com",
        "no-at-sign.com",
        "missing@domain",
        NULL
    };
    
    for (int i = 0; emails[i]; i++) {
        EmailParts p = parse_email(emails[i]);
        printf("\nEmail: %s\n", emails[i]);
        if (p.valid) {
            printf("  Username: %s\n", p.username);
            printf("  Domain: %s\n", p.domain);
            printf("  TLD: %s\n", p.tld);
        } else {
            printf("  Invalid email!\n");
        }
    }
    
    return 0;
}
```

## Expected Output
```
Email: user@example.com
  Username: user
  Domain: example.com
  TLD: com

Email: invalid@@email.com
  Invalid email!
```

## Bonus Challenges
1. Handle quoted local parts ("john doe"@example.com)
2. Validate according to RFC 5321
3. Extract subdomain from domain
4. Build an email normalization function

## Test Cases
- "a@b.c" → valid
- "@domain.com" → invalid (no username)
- "user@" → invalid (no domain)
- "user@domain" → invalid (no TLD)
