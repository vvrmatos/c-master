---
id: "069"
title: "sprintf() - Format to String"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - sprintf
  - formatting
  - strings
  - conversion
difficulty: intermediate
source: "C11 Standard 7.21.6.6"
---

# 069 — sprintf() - Format to String

## Concept

`sprintf()` writes formatted output to a **string buffer** instead of stdout. It's like printf, but captures the output in a string.

**Syntax:**
```c
int sprintf(char *str, const char *format, ...);
```

**Returns:** Number of characters written (excluding null terminator), or negative on error.

**Use cases:**
- Building strings dynamically
- Converting numbers to strings
- Creating formatted messages for logging
- Constructing file paths
- Building SQL queries or commands
- Creating formatted identifiers

**Warning: NO buffer overflow protection!**
```c
char small[10];
sprintf(small, "This is way too long!");  // BUFFER OVERFLOW!
```

**Always use snprintf() for safety (next lesson).**

**Common patterns:**
```c
// Number to string
sprintf(str, "%d", number);

// Build path
sprintf(path, "%s/%s", dir, file);

// Format decimal
sprintf(price, "$%.2f", amount);
```

## Code

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("=== sprintf() - Format to String ===\n\n");
    
    char buffer[100];
    
    sprintf(buffer, "Hello, World!");
    printf("Basic: %s\n\n", buffer);
    
    int age = 25;
    char name[] = "Alice";
    sprintf(buffer, "Name: %s, Age: %d", name, age);
    printf("Formatted: %s\n\n", buffer);
    
    int year = 2024, month = 3, day = 15;
    sprintf(buffer, "%04d-%02d-%02d", year, month, day);
    printf("Date string: %s\n\n", buffer);
    
    int hour = 9, minute = 5, second = 3;
    sprintf(buffer, "%02d:%02d:%02d", hour, minute, second);
    printf("Time string: %s\n\n", buffer);
    
    char path[200];
    char dir[] = "/home/user";
    char file[] = "document.txt";
    sprintf(path, "%s/%s", dir, file);
    printf("Path: %s\n\n", path);
    
    char sql[200];
    char table[] = "users";
    int id = 42;
    sprintf(sql, "SELECT * FROM %s WHERE id = %d", table, id);
    printf("SQL: %s\n\n", sql);
    
    char message[100];
    int count = 5;
    double price = 19.99;
    sprintf(message, "You ordered %d items for $%.2f each", count, price);
    printf("Message: %s\n\n", message);
    
    printf("Return value (chars written):\n");
    int len = sprintf(buffer, "Hello!");
    printf("  \"%s\" is %d characters\n\n", buffer, len);
    
    char hex[20];
    unsigned int color = 0xFF8800;
    sprintf(hex, "#%06X", color);
    printf("Hex color: %s\n\n", hex);
    
    char ipaddr[20];
    unsigned char ip[] = {192, 168, 1, 1};
    sprintf(ipaddr, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    printf("IP address: %s\n\n", ipaddr);
    
    char large[50];
    char *result = sprintf(large, "Number: %d", 12345) > 0 ? large : "error";
    printf("Chained: %s\n\n", result);
    
    printf("Building strings incrementally:\n");
    char report[200];
    char *ptr = report;
    ptr += sprintf(ptr, "Report:\n");
    ptr += sprintf(ptr, "  Items: %d\n", 10);
    ptr += sprintf(ptr, "  Total: $%.2f\n", 99.99);
    ptr += sprintf(ptr, "  Status: %s\n", "Complete");
    printf("%s\n", report);
    
    printf("WARNING: sprintf() has NO buffer protection!\n");
    printf("  If formatted string exceeds buffer: BUFFER OVERFLOW\n");
    printf("  Use snprintf() for safety (see next lesson)\n\n");
    
    printf("sprintf() vs printf():\n");
    printf("  printf(): writes to stdout\n");
    printf("  sprintf(): writes to string buffer\n");
    printf("  Both use same format specifiers\n");
    
    return 0;
}
```

## Output

```
=== sprintf() - Format to String ===

Basic: Hello, World!

Formatted: Name: Alice, Age: 25

Date string: 2024-03-15

Time string: 09:05:03

Path: /home/user/document.txt

SQL: SELECT * FROM users WHERE id = 42

Message: You ordered 5 items for $19.99 each

Return value (chars written):
  "Hello!" is 6 characters

Hex color: #FF8800

IP address: 192.168.1.1

Chained: Number: 12345

Building strings incrementally:
Report:
  Items: 10
  Total: $99.99
  Status: Complete

WARNING: sprintf() has NO buffer protection!
  If formatted string exceeds buffer: BUFFER OVERFLOW
  Use snprintf() for safety (see next lesson)

sprintf() vs printf():
  printf(): writes to stdout
  sprintf(): writes to string buffer
  Both use same format specifiers
```

## Compilation

```bash
gcc 069-sprintf.c -o 069-sprintf
./069-sprintf
```

## Key Takeaways

- `sprintf()` writes formatted output to a string
- Same format specifiers as printf
- Returns number of characters written
- **Danger:** No buffer overflow protection
- Use snprintf() in production code
- Useful for building strings, paths, messages

## Challenge

Write a function that formats a timestamp from components (year, month, day, hour, minute, second) into ISO 8601 format.

## Related

- [[070-snprintf]] — Safe version with size limit
- [[068-sscanf]] — Parse strings (inverse operation)
