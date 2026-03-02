---
id: "066"
title: "Input Validation"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - input
  - validation
  - security
  - error-handling
difficulty: intermediate
source: "Practical C Programming, CERT C Coding Standard"
---

# 066 — Input Validation

## Concept

Input validation ensures user input meets expected criteria before use. Invalid input can cause crashes, incorrect results, or security vulnerabilities.

**Types of validation:**
1. **Type validation** — Is it the right type (int, float)?
2. **Range validation** — Is it within acceptable bounds?
3. **Format validation** — Does it match expected pattern?
4. **Length validation** — Is it the right size?

**Validation strategies:**

**1. Check scanf return value:**
```c
while (scanf("%d", &num) != 1) {
    printf("Invalid! ");
    clear_buffer();
}
```

**2. Use fgets + sscanf:**
```c
fgets(line, sizeof(line), stdin);
if (sscanf(line, "%d", &num) != 1) {
    // handle error
}
```

**3. Use strtol for robust parsing:**
```c
char *endptr;
long val = strtol(input, &endptr, 10);
if (endptr == input) // no digits
if (*endptr != '\0') // trailing garbage
```

**Security implications:**
- Buffer overflow from unchecked input
- Integer overflow from out-of-range values
- Format string attacks from unvalidated strings
- Injection attacks from special characters

## Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_int_in_range(const char *prompt, int min, int max) {
    int value;
    int valid = 0;
    
    while (!valid) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            if (value >= min && value <= max) {
                valid = 1;
            } else {
                printf("  Error: Must be between %d and %d\n", min, max);
            }
        } else {
            printf("  Error: Invalid number\n");
        }
        clear_input_buffer();
    }
    return value;
}

int main(void) {
    printf("=== Input Validation ===\n\n");
    
    printf("1. Basic type validation:\n");
    int num;
    printf("   Enter an integer: ");
    while (scanf("%d", &num) != 1) {
        printf("   Invalid! Enter an integer: ");
        clear_input_buffer();
    }
    printf("   Valid integer: %d\n\n", num);
    clear_input_buffer();
    
    printf("2. Range validation:\n");
    int age = get_int_in_range("   Enter age (0-150): ", 0, 150);
    printf("   Valid age: %d\n\n", age);
    
    printf("3. Character validation:\n");
    char choice;
    printf("   Enter Y or N: ");
    while (1) {
        scanf(" %c", &choice);
        choice = toupper(choice);
        if (choice == 'Y' || choice == 'N') break;
        printf("   Invalid! Enter Y or N: ");
    }
    printf("   Choice: %c\n\n", choice);
    clear_input_buffer();
    
    printf("4. String length validation:\n");
    char name[20];
    printf("   Enter name (max 19 chars): ");
    while (1) {
        if (fgets(name, sizeof(name), stdin) != NULL) {
            size_t len = strlen(name);
            if (len > 0 && name[len-1] == '\n') {
                name[len-1] = '\0';
                len--;
            }
            if (len > 0 && len < sizeof(name) - 1) {
                break;
            }
        }
        printf("   Invalid length! Try again: ");
    }
    printf("   Name: '%s' (%zu chars)\n\n", name, strlen(name));
    
    printf("5. Numeric string validation:\n");
    char numstr[20];
    printf("   Enter a positive integer: ");
    while (1) {
        if (fgets(numstr, sizeof(numstr), stdin) != NULL) {
            numstr[strcspn(numstr, "\n")] = '\0';
            int valid = 1;
            for (int i = 0; numstr[i]; i++) {
                if (!isdigit(numstr[i])) {
                    valid = 0;
                    break;
                }
            }
            if (valid && strlen(numstr) > 0) break;
        }
        printf("   Invalid! Enter digits only: ");
    }
    printf("   Number string: '%s'\n\n", numstr);
    
    printf("6. Using strtol for robust integer parsing:\n");
    char input[50];
    printf("   Enter an integer: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    char *endptr;
    errno = 0;
    long val = strtol(input, &endptr, 10);
    
    if (errno == ERANGE) {
        printf("   Error: Number out of range\n");
    } else if (endptr == input) {
        printf("   Error: No digits found\n");
    } else if (*endptr != '\0') {
        printf("   Warning: Extra characters ignored\n");
        printf("   Parsed value: %ld\n", val);
    } else {
        printf("   Valid: %ld\n", val);
    }
    
    printf("\nValidation best practices:\n");
    printf("  1. Always check return values\n");
    printf("  2. Clear buffer after failed input\n");
    printf("  3. Use fgets + parsing for robustness\n");
    printf("  4. Validate ranges, not just types\n");
    printf("  5. Give clear error messages\n");
    printf("  6. Use strtol/strtod for numeric conversion\n");
    
    return 0;
}
```

## Output

```
=== Input Validation ===

1. Basic type validation:
   Enter an integer: abc
   Invalid! Enter an integer: 42
   Valid integer: 42

2. Range validation:
   Enter age (0-150): 200
   Error: Must be between 0 and 150
   Enter age (0-150): 25
   Valid age: 25

3. Character validation:
   Enter Y or N: X
   Invalid! Enter Y or N: Y
   Choice: Y

4. String length validation:
   Enter name (max 19 chars): John
   Name: 'John' (4 chars)

5. Numeric string validation:
   Enter a positive integer: 12a34
   Invalid! Enter digits only: 1234
   Number string: '1234'

6. Using strtol for robust integer parsing:
   Enter an integer: 42abc
   Warning: Extra characters ignored
   Parsed value: 42

Validation best practices:
  1. Always check return values
  2. Clear buffer after failed input
  3. Use fgets + parsing for robustness
  4. Validate ranges, not just types
  5. Give clear error messages
  6. Use strtol/strtod for numeric conversion
```

## Compilation

```bash
gcc 066-input-validation.c -o 066-input-validation
./066-input-validation
```

## Key Takeaways

- Always validate user input before use
- Check both type and range
- Use fgets + parsing for robust string input
- strtol/strtod provide detailed error information
- Clear buffer after invalid input
- Give users clear feedback on errors

## Challenge

Write a function that validates an email address format (contains @, has domain, etc.).

## Related

- [[060-scanf-return-value]] — scanf return values
- [[065-input-buffer-issues]] — Buffer management
