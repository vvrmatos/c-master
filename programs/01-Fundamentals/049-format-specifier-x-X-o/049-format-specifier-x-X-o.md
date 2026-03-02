---
id: "049"
title: "Format Specifiers: %x, %X, %o"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - printf
  - format-specifiers
  - hexadecimal
  - octal
  - binary
difficulty: beginner
source: "C11 Standard 7.21.6.1"
---

# 049 — Format Specifiers: %x, %X, %o (Hex/Octal)

## Concept

`%x`, `%X`, and `%o` display **unsigned integers** in hexadecimal (base 16) and octal (base 8) formats. These are essential for low-level programming, memory inspection, and bitwise operations.

**Format specifiers:**
| Specifier | Base | Digits Used |
|-----------|------|-------------|
| `%x` | 16 (hex) | 0-9, a-f |
| `%X` | 16 (hex) | 0-9, A-F |
| `%o` | 8 (octal) | 0-7 |

**Length modifiers:**
| Specifier | Type |
|-----------|------|
| `%hx` | unsigned short |
| `%x` | unsigned int |
| `%lx` | unsigned long |
| `%llx` | unsigned long long |

**The # flag adds prefix:**
```c
printf("%#x", 255);   // 0xff
printf("%#X", 255);   // 0XFF
printf("%#o", 255);   // 0377
```

**Common patterns:**
```c
printf("%02x", byte);      // 2-digit hex, zero-padded
printf("%08x", word);      // 8-digit hex, zero-padded  
printf("%#010x", word);    // 10 chars total: 0x + 8 digits
```

**Use cases:**
- Memory addresses and pointers
- Binary data inspection (hex dumps)
- Bit manipulation debugging
- Color codes (RGB)
- File permissions (octal)

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Format Specifiers: %%x, %%X, %%o (Hex/Octal) ===\n\n");
    
    unsigned int value = 255;
    
    printf("Same value in different bases:\n");
    printf("  Decimal (%%u): %u\n", value);
    printf("  Hex lower (%%x): %x\n", value);
    printf("  Hex upper (%%X): %X\n", value);
    printf("  Octal (%%o): %o\n", value);
    
    printf("\nCommon hex values:\n");
    printf("  16 = 0x%x\n", 16);
    printf("  256 = 0x%x\n", 256);
    printf("  65535 = 0x%x\n", 65535);
    printf("  255 = 0x%02x\n", 255);
    
    printf("\nWith # flag (prefix):\n");
    printf("  %%#x: %#x\n", value);
    printf("  %%#X: %#X\n", value);
    printf("  %%#o: %#o\n", value);
    printf("  Zero: %#x (no prefix for 0)\n", 0);
    
    printf("\nPadding hex values:\n");
    printf("  %%08x: %08x\n", 0xABCD);
    printf("  %%8x: %8x\n", 0xABCD);
    printf("  %%#010x: %#010x\n", 0xABCD);
    
    printf("\nByte representation:\n");
    unsigned char bytes[] = {0xDE, 0xAD, 0xBE, 0xEF};
    printf("  Bytes: ");
    for (int i = 0; i < 4; i++) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");
    
    printf("\nMemory addresses typically use hex:\n");
    int var = 42;
    printf("  Address of var: %p\n", (void*)&var);
    
    printf("\nBitwise operations in hex:\n");
    unsigned int a = 0xFF00;
    unsigned int b = 0x00FF;
    printf("  a = 0x%04X\n", a);
    printf("  b = 0x%04X\n", b);
    printf("  a | b = 0x%04X\n", a | b);
    printf("  a & b = 0x%04X\n", a & b);
    printf("  a ^ b = 0x%04X\n", a ^ b);
    printf("  ~a = 0x%08X\n", ~a);
    
    printf("\nOctal (base 8) - less common:\n");
    printf("  File permissions: %o (rwxr-xr-x)\n", 0755);
    printf("  Read/Write: %o (rw-r--r--)\n", 0644);
    
    printf("\nDifferent integer sizes:\n");
    unsigned long long big = 0xDEADBEEFCAFEBABEULL;
    printf("  %%llx: %llx\n", big);
    printf("  %%016llX: %016llX\n", big);
    
    return 0;
}
```

## Output

```
=== Format Specifiers: %x, %X, %o (Hex/Octal) ===

Same value in different bases:
  Decimal (%u): 255
  Hex lower (%x): ff
  Hex upper (%X): FF
  Octal (%o): 377

Common hex values:
  16 = 0x10
  256 = 0x100
  65535 = 0xffff
  255 = 0xff

With # flag (prefix):
  %#x: 0xff
  %#X: 0XFF
  %#o: 0377
  Zero: 0 (no prefix for 0)

Padding hex values:
  %08x: 0000abcd
  %8x:     abcd
  %#010x: 0x0000abcd

Byte representation:
  Bytes: DE AD BE EF 

Memory addresses typically use hex:
  Address of var: 0x7ff7b...

Bitwise operations in hex:
  a = 0xFF00
  b = 0x00FF
  a | b = 0xFFFF
  a & b = 0x0000
  a ^ b = 0xFFFF
  ~a = 0xFFFF00FF

Octal (base 8) - less common:
  File permissions: 755 (rwxr-xr-x)
  Read/Write: 644 (rw-r--r--)

Different integer sizes:
  %llx: deadbeefcafebabe
  %016llX: DEADBEEFCAFEBABE
```

## Compilation

```bash
gcc 049-format-specifier-x-X-o.c -o 049-format-specifier-x-X-o
./049-format-specifier-x-X-o
```

## Key Takeaways

- `%x`/`%X` print hexadecimal (lowercase/uppercase)
- `%o` prints octal (base 8)
- Use `#` flag to add 0x/0X/0 prefix
- Zero-pad with `%08x` for consistent width
- Hex is essential for memory/binary work
- Octal mainly used for Unix file permissions

## Challenge

Write a program that takes an integer and displays it in decimal, hexadecimal, octal, and binary (you'll need to implement binary yourself).

## Related

- [[043-format-specifier-u]] — Unsigned decimal format
- [[050-format-specifier-p]] — Pointer format
