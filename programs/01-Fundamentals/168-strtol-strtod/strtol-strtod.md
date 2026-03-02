# strtol and strtod - Safer String to Number Conversions

## Overview
`strtol` (string to long) and `strtod` (string to double) are the safe alternatives to atoi/atof. They provide error detection, overflow handling, and support for different number bases.

## Function Signatures
```c
long strtol(const char *str, char **endptr, int base);
long long strtoll(const char *str, char **endptr, int base);
unsigned long strtoul(const char *str, char **endptr, int base);
double strtod(const char *str, char **endptr);
float strtof(const char *str, char **endptr);
```

## Parameters
- **str**: String to convert
- **endptr**: Pointer to first invalid character (or NULL)
- **base**: Number base (2-36, or 0 for auto-detect)

## Error Detection

### Using endptr
```c
char *end;
long val = strtol(str, &end, 10);

if (end == str) {
    // No digits found at all
}
if (*end != '\0') {
    // Extra characters after number
}
```

### Using errno for Overflow
```c
#include <errno.h>
#include <limits.h>

errno = 0;
long val = strtol(str, &end, 10);

if (errno == ERANGE) {
    if (val == LONG_MAX) // Overflow
    if (val == LONG_MIN) // Underflow
}
```

## Base Options
| Base | Format | Example |
|------|--------|---------|
| 10 | Decimal | "123" |
| 16 | Hex | "FF" or "0xFF" |
| 8 | Octal | "777" or "0777" |
| 2 | Binary | "1010" |
| 0 | Auto-detect | 0x→hex, 0→octal, else decimal |

## Complete Validation Pattern
```c
bool safe_strtol(const char *str, long *result) {
    char *end;
    errno = 0;
    
    *result = strtol(str, &end, 10);
    
    if (end == str) return false;      // No digits
    if (*end != '\0') return false;    // Trailing garbage
    if (errno == ERANGE) return false; // Overflow
    
    return true;
}
```

## Compilation
```bash
gcc -o strtol-strtod strtol-strtod.c
./strtol-strtod
```

---

# Kata Challenge: Robust Number Parser

## Objective
Create a robust number parsing library with complete validation.

## Requirements
1. Parse integers with full error detection
2. Support hex, octal, binary, and decimal
3. Parse floating-point with validation
4. Report specific error types

## Starter Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

typedef enum {
    PARSE_OK,
    PARSE_EMPTY,
    PARSE_NO_DIGITS,
    PARSE_OVERFLOW,
    PARSE_UNDERFLOW,
    PARSE_TRAILING_CHARS
} ParseResult;

const char *parse_result_str(ParseResult r) {
    const char *msgs[] = {
        "OK", "Empty string", "No digits found",
        "Overflow", "Underflow", "Trailing characters"
    };
    return msgs[r];
}

ParseResult parse_long(const char *str, long *result) {
    // TODO: Implement complete validation
    if (str == NULL || *str == '\0') {
        return PARSE_EMPTY;
    }
    
    char *end;
    errno = 0;
    *result = strtol(str, &end, 0);  // base 0 = auto-detect
    
    // TODO: Check for all error conditions
    
    return PARSE_OK;
}

ParseResult parse_double(const char *str, double *result) {
    // TODO: Implement for doubles
    return PARSE_OK;
}

// Parse with range checking
ParseResult parse_int_range(const char *str, int *result, int min, int max) {
    // TODO: Parse and validate within range
    return PARSE_OK;
}

int main(void) {
    const char *test_cases[] = {
        "42",
        "-17",
        "0xFF",
        "0777",
        "",
        "abc",
        "12abc",
        "99999999999999999999",
        "3.14159",
        NULL
    };
    
    for (int i = 0; test_cases[i]; i++) {
        long val;
        ParseResult r = parse_long(test_cases[i], &val);
        printf("\"%s\" -> ", test_cases[i]);
        if (r == PARSE_OK) {
            printf("%ld\n", val);
        } else {
            printf("Error: %s\n", parse_result_str(r));
        }
    }
    
    return 0;
}
```

## Expected Output
```
"42" -> 42
"-17" -> -17
"0xFF" -> 255
"0777" -> 511
"" -> Error: Empty string
"abc" -> Error: No digits found
"12abc" -> Error: Trailing characters
"99999999999999999999" -> Error: Overflow
"3.14159" -> Error: Trailing characters
```

## Bonus Challenges
1. Support thousands separators (1,000,000)
2. Parse currency strings ($1.50)
3. Support SI prefixes (1K, 1M, 1G)
4. Create scanf-like format parsing

## Test Cases
- "42" → 42, OK
- "" → Empty
- "0x" → No digits (just prefix)
- "9223372036854775808" → Overflow for long
