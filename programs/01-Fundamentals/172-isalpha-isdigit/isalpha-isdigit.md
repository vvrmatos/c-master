# isalpha and isdigit - Letter and Digit Tests

## Overview
`isalpha` tests if a character is a letter (A-Z, a-z), and `isdigit` tests if it's a decimal digit (0-9). These are the most commonly used ctype functions.

## Function Signatures
```c
int isalpha(int c);  // Returns non-zero if letter
int isdigit(int c);  // Returns non-zero if digit
```

## Return Values
- **Non-zero (true)**: Character matches the category
- **Zero (false)**: Character does not match

## What They Match

### isalpha
- Uppercase: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
- Lowercase: a b c d e f g h i j k l m n o p q r s t u v w x y z
- Does NOT match: digits, punctuation, whitespace, accented letters (in C locale)

### isdigit
- Digits: 0 1 2 3 4 5 6 7 8 9
- Does NOT match: letters, decimal point, signs (+/-), hex letters

## Common Patterns

### Check if All Letters
```c
int is_all_letters(const char *s) {
    for (int i = 0; s[i]; i++) {
        if (!isalpha((unsigned char)s[i])) return 0;
    }
    return 1;
}
```

### Check if Valid Number
```c
int is_all_digits(const char *s) {
    if (*s == '\0') return 0;  // Empty string
    for (int i = 0; s[i]; i++) {
        if (!isdigit((unsigned char)s[i])) return 0;
    }
    return 1;
}
```

### Convert Digit Character to Integer
```c
if (isdigit(c)) {
    int value = c - '0';  // '5' - '0' = 5
}
```

## Compilation
```bash
gcc -o isalpha-isdigit isalpha-isdigit.c
./isalpha-isdigit
```

---

# Kata Challenge: Input Validator

## Objective
Create input validation functions using isalpha and isdigit.

## Requirements
1. Validate names (letters and spaces only)
2. Validate phone numbers (digits and optional formatting)
3. Validate postal codes (various formats)
4. Validate usernames (letters, digits, underscores)

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Validate name: letters and spaces, at least 2 chars
bool is_valid_name(const char *name) {
    if (name == NULL || strlen(name) < 2) return false;
    
    for (int i = 0; name[i]; i++) {
        // TODO: Allow letters and spaces only
    }
    return true;
}

// Validate phone: digits only, 10-15 length
// Optional: allow spaces, dashes, parentheses
bool is_valid_phone(const char *phone) {
    // TODO: Implement
    return false;
}

// Validate US ZIP: 5 digits or 5+4 format (12345 or 12345-6789)
bool is_valid_zip(const char *zip) {
    // TODO: Implement
    return false;
}

// Validate username: starts with letter, contains alnum and underscore
bool is_valid_username(const char *username) {
    // TODO: Implement
    return false;
}

// Validate password strength
typedef struct {
    bool has_upper;
    bool has_lower;
    bool has_digit;
    bool has_special;
    int length;
} PasswordStrength;

PasswordStrength check_password(const char *password) {
    PasswordStrength ps = {0};
    // TODO: Analyze password
    return ps;
}

int main(void) {
    // Test names
    const char *names[] = {"John Doe", "123", "J", "Mary Jane", NULL};
    printf("Name validation:\n");
    for (int i = 0; names[i]; i++) {
        printf("  \"%s\": %s\n", names[i],
               is_valid_name(names[i]) ? "valid" : "invalid");
    }
    
    // Test phones
    const char *phones[] = {"1234567890", "123-456-7890", "123", NULL};
    printf("\nPhone validation:\n");
    for (int i = 0; phones[i]; i++) {
        printf("  \"%s\": %s\n", phones[i],
               is_valid_phone(phones[i]) ? "valid" : "invalid");
    }
    
    // Test usernames
    const char *usernames[] = {"user_123", "123user", "_test", "valid", NULL};
    printf("\nUsername validation:\n");
    for (int i = 0; usernames[i]; i++) {
        printf("  \"%s\": %s\n", usernames[i],
               is_valid_username(usernames[i]) ? "valid" : "invalid");
    }
    
    return 0;
}
```

## Expected Output
```
Name validation:
  "John Doe": valid
  "123": invalid
  "J": invalid
  "Mary Jane": valid

Phone validation:
  "1234567890": valid
  "123-456-7890": valid
  "123": invalid

Username validation:
  "user_123": valid
  "123user": invalid
  "_test": invalid
  "valid": valid
```

## Bonus Challenges
1. Add international phone format support
2. Validate email addresses
3. Create a credit card number validator (Luhn algorithm)
4. Build a date format validator

## Test Cases
- Empty string → invalid for all
- Single character → depends on type
- Unicode characters → not matched by isalpha in C locale
