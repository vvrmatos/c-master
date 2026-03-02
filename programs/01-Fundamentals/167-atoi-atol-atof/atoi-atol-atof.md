# atoi, atol, atof - String to Number Conversion

## Overview
These functions convert strings to numbers. They're simple to use but provide NO error checking - invalid input silently returns 0, and overflow is undefined behavior.

## Function Signatures
```c
int atoi(const char *str);      // ASCII to int
long atol(const char *str);     // ASCII to long
double atof(const char *str);   // ASCII to float (returns double!)
```

## Behavior

### Conversion Rules
1. Skip leading whitespace
2. Optional sign (+ or -)
3. Convert digits until non-digit encountered
4. Return 0 if no valid digits

### Examples
| Input | atoi Result |
|-------|-------------|
| "42" | 42 |
| "  -17" | -17 |
| "123abc" | 123 |
| "abc" | 0 |
| "" | 0 |

## ⚠️ Dangers

### No Error Detection
```c
int x = atoi("not a number");  // x = 0, but was that intentional?
int y = atoi("0");             // y = 0, same result, different meaning
```

### Overflow is Undefined Behavior
```c
int x = atoi("99999999999999");  // Undefined! May crash, wrap, etc.
```

### Cannot Distinguish Failure
```c
// These all return 0:
atoi("0");      // Valid zero
atoi("");       // Empty string
atoi("abc");    // Invalid input
```

## When to Use
- Quick prototypes
- Trusted input (hardcoded values)
- Simple scripts

## When NOT to Use
- User input
- File parsing
- Any production code requiring validation

## Better Alternatives
- `strtol()`, `strtod()` - safer, with error detection
- `sscanf()` - returns count of successful conversions

## Compilation
```bash
gcc -o atoi-atol-atof atoi-atol-atof.c
./atoi-atol-atof
```

---

# Kata Challenge: Command-Line Calculator

## Objective
Build a simple calculator that takes numbers as command-line arguments.

## Requirements
1. Parse numbers from command-line arguments
2. Support basic operations (+, -, *, /)
3. Detect and handle invalid input
4. Support both integers and decimals

## Starter Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_number(const char *str) {
    // TODO: Check if string represents a valid number
    // Handle: integers, decimals, negative numbers
    return false;
}

double safe_atof(const char *str, bool *success) {
    // TODO: Convert with validation
    *success = false;
    return 0.0;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <num1> <op> <num2>\n", argv[0]);
        printf("Operations: + - * /\n");
        return 1;
    }
    
    // TODO: Parse num1
    // TODO: Parse operator
    // TODO: Parse num2
    // TODO: Calculate and print result
    
    double num1 = atof(argv[1]);  // Replace with safe version
    char op = argv[2][0];
    double num2 = atof(argv[3]);  // Replace with safe version
    
    double result;
    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Unknown operator: %c\n", op);
            return 1;
    }
    
    printf("%g %c %g = %g\n", num1, op, num2, result);
    return 0;
}
```

## Expected Output
```bash
$ ./calc 10 + 5
10 + 5 = 15

$ ./calc 3.14 "*" 2
3.14 * 2 = 6.28

$ ./calc abc + 5
Error: 'abc' is not a valid number
```

## Bonus Challenges
1. Support expression chains: 1 + 2 + 3
2. Add parentheses support
3. Implement operator precedence
4. Add scientific notation support

## Test Cases
- "10 + 5" → 15
- "10 / 0" → error
- "abc + 5" → error
- "3.14 * 2" → 6.28
