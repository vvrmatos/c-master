# isxdigit - Hexadecimal Digit Test

## Overview
The `isxdigit()` function tests if a character is a valid hexadecimal digit. This includes decimal digits (0-9) and letters A-F (both uppercase and lowercase). Essential for parsing hex values.

## Function Signature
```c
#include <ctype.h>

int isxdigit(int c);  // Returns non-zero if hex digit
```

## Valid Hexadecimal Digits

| Characters | Description |
|------------|-------------|
| 0-9 | Decimal digits (values 0-9) |
| A-F | Uppercase hex (values 10-15) |
| a-f | Lowercase hex (values 10-15) |

## Hexadecimal System
- Base-16 number system
- Uses 16 symbols: 0-9 and A-F
- Common in programming (colors, memory addresses, byte values)

## Common Hex Uses
| Format | Example | Usage |
|--------|---------|-------|
| 0x prefix | 0xFF | C hex literal |
| # prefix | #FFFFFF | HTML colors |
| \x escape | \x0A | Hex in strings |
| % encoding | %20 | URL encoding |

## Character to Value Conversion
```c
int hex_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;  // Invalid
}
```

## Use Cases
- Validating hex color codes
- Parsing memory addresses
- Processing URL-encoded strings
- Reading binary data as hex

---

# Kata Challenge: Hex String Validator

## Objective
Write a program that validates and converts hexadecimal strings to decimal values.

## Requirements
1. Read a hex string from user (with or without 0x prefix)
2. Validate that all characters are valid hex digits
3. Convert valid hex strings to decimal
4. Handle both uppercase and lowercase
5. Report invalid characters if found

## Example
```
Input: 1A3F
Output:
Valid hex string: 1A3F
Decimal value: 6719

Input: GHIJ
Output:
Invalid hex string!
Invalid characters at positions: 0, 1, 2, 3
```

## Algorithm
```
value = 0
for each char in string:
    value = value * 16 + hex_digit_value(char)
```

## Hints
- Skip "0x" or "0X" prefix if present
- Use `isxdigit()` for validation
- Build value by multiplying by 16 for each digit
- Handle overflow for large hex numbers

## Bonus
- Support negative hex (two's complement)
- Convert decimal back to hex
- Parse multiple hex values separated by spaces
- Validate specific formats (color codes, MAC addresses)
