---
id: "032"
title: "Octal, Hexadecimal, and Binary Literals"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - literals
  - hexadecimal
  - octal
  - binary
difficulty: beginner
source: "C11 Standard Section 6.4.4.1"
---

# 032 — Octal, Hexadecimal, and Binary Literals

## Concept

C supports multiple numeral bases for integer literals. Each base has a specific prefix that tells the compiler how to interpret the digits:

- **Decimal** — no prefix, digits 0-9
- **Octal** — prefix `0`, digits 0-7 (base 8)
- **Hexadecimal** — prefix `0x` or `0X`, digits 0-9 and A-F (base 16)
- **Binary** — prefix `0b` or `0B`, digits 0-1 (C23 standard, earlier as GNU extension)

Common uses:
- **Octal** — Unix file permissions (0755, 0644)
- **Hexadecimal** — memory addresses, byte values, bit patterns, color codes
- **Binary** — bit flags, hardware registers, network protocols

> **Security Note**: Hexadecimal is ubiquitous in security work. Memory dumps, shellcode, magic numbers (0xDEADBEEF), and network protocols all use hex. Being fluent in hex ↔ decimal ↔ binary conversion is essential.

## Code

```c
#include <stdio.h>

int main(void) {
    int decimal = 255;
    int octal = 0377;
    int hex_lower = 0xff;
    int hex_upper = 0xFF;
    int binary = 0b11111111;
    
    printf("=== Octal, Hexadecimal, and Binary Literals ===\n\n");
    
    printf("Same value in different bases:\n");
    printf("  Decimal:     255   = %d\n", decimal);
    printf("  Octal:       0377  = %d\n", octal);
    printf("  Hexadecimal: 0xFF  = %d\n", hex_upper);
    printf("  Binary:      0b11111111 = %d\n", binary);
    
    printf("\nOctal literals (prefix 0):\n");
    printf("  010 = %d (not 10!)\n", 010);
    printf("  0777 = %d (Unix permissions)\n", 0777);
    printf("  0644 = %d (file permissions)\n", 0644);
    
    printf("\nHexadecimal literals (prefix 0x or 0X):\n");
    printf("  0xDEADBEEF = %u\n", 0xDEADBEEF);
    printf("  0xCAFEBABE = %u\n", 0xCAFEBABE);
    printf("  0x7F = %d (max signed byte)\n", 0x7F);
    printf("  0xFF = %d (max unsigned byte)\n", 0xFF);
    
    printf("\nBinary literals (C23/GNU extension, prefix 0b):\n");
    printf("  0b1010 = %d\n", 0b1010);
    printf("  0b11110000 = %d\n", 0b11110000);
    printf("  0b00001111 = %d\n", 0b00001111);
    
    printf("\nCommon patterns in security:\n");
    printf("  0x41414141 = %u ('AAAA')\n", 0x41414141);
    printf("  0x90909090 = %u (NOP sled)\n", 0x90909090);
    printf("  0xCCCCCCCC = %u (INT3 breakpoints)\n", 0xCCCCCCCC);
    
    printf("\nWith type suffixes:\n");
    printf("  0xFFFFFFFFUL = %lu\n", 0xFFFFFFFFUL);
    printf("  0xFFFFFFFFFFFFFFFFULL = %llu\n", 0xFFFFFFFFFFFFFFFFULL);
    
    return 0;
}
```

## Output

```
=== Octal, Hexadecimal, and Binary Literals ===

Same value in different bases:
  Decimal:     255   = 255
  Octal:       0377  = 255
  Hexadecimal: 0xFF  = 255
  Binary:      0b11111111 = 255

Octal literals (prefix 0):
  010 = 8 (not 10!)
  0777 = 511 (Unix permissions)
  0644 = 420 (file permissions)

Hexadecimal literals (prefix 0x or 0X):
  0xDEADBEEF = 3735928559
  0xCAFEBABE = 3405691582
  0x7F = 127 (max signed byte)
  0xFF = 255 (max unsigned byte)

Binary literals (C23/GNU extension, prefix 0b):
  0b1010 = 10
  0b11110000 = 240
  0b00001111 = 15

Common patterns in security:
  0x41414141 = 1094795585 ('AAAA')
  0x90909090 = 2425393296 (NOP sled)
  0xCCCCCCCC = 3435973836 (INT3 breakpoints)

With type suffixes:
  0xFFFFFFFFUL = 4294967295
  0xFFFFFFFFFFFFFFFFULL = 18446744073709551615
```

## Key Takeaways

- Octal prefix is `0` — beware `010` means 8, not 10!
- Hexadecimal prefix is `0x` or `0X`
- Binary prefix is `0b` or `0B` (C23 or GNU extension)
- Hex is case-insensitive: `0xff` = `0xFF` = `0XFF`
- Type suffixes work with all bases: `0xFFUL`
- Hex is essential for security: memory, shellcode, protocols

## Challenge

Write a program that displays the same value (like 255) in all four bases. Then create common Unix permission patterns (rwx) in octal.

## Related

- [[031-integer-literals]] — Decimal integer literals
- [[049-format-specifier-x-X-o]] — Printing in hex/octal
- [[035-escape-sequences]] — Hex escape sequences
