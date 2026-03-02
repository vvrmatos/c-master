---
id: "068"
title: "sscanf() - Parse Strings"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - sscanf
  - parsing
  - strings
  - conversion
difficulty: intermediate
source: "C11 Standard 7.21.6.7"
---

# 068 — sscanf() - Parse Strings

## Concept

`sscanf()` reads formatted data from a **string** instead of stdin. It's like scanf but parses an existing string buffer.

**Syntax:**
```c
int sscanf(const char *str, const char *format, ...);
```

**Returns:** Number of items successfully matched, or EOF on error.

**Use cases:**
- Parsing configuration files
- Processing CSV data
- Converting strings to numbers (alternative to atoi)
- Extracting structured data from strings
- Safe input: fgets + sscanf pattern

**Common patterns:**
```c
// Parse date
sscanf("2024-03-15", "%d-%d-%d", &year, &month, &day);

// Parse key=value
sscanf("port=8080", "port=%d", &port);

// Parse CSV with %[^,] (until comma)
sscanf("Alice,25", "%[^,],%d", name, &age);
```

**Character class tricks:**
```c
%[^,]   // Read until comma
%[^\n]  // Read until newline  
%[^;]   // Read until semicolon
%[a-zA-Z] // Read only letters
```

**fgets + sscanf pattern (recommended):**
```c
char line[100];
fgets(line, sizeof(line), stdin);  // Safe read
if (sscanf(line, "%d", &num) != 1) {
    // Handle error
}
```

## Code

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("=== sscanf() - Parse Strings ===\n\n");
    
    char data[] = "42 3.14 Hello";
    int num;
    float fnum;
    char word[20];
    
    int matched = sscanf(data, "%d %f %s", &num, &fnum, word);
    
    printf("Parsing \"%s\":\n", data);
    printf("  Matched: %d items\n", matched);
    printf("  Integer: %d\n", num);
    printf("  Float: %.2f\n", fnum);
    printf("  String: %s\n\n", word);
    
    char date[] = "2024-03-15";
    int year, month, day;
    
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    printf("Parsing date \"%s\":\n", date);
    printf("  Year: %d, Month: %d, Day: %d\n\n", year, month, day);
    
    char time[] = "14:30:45";
    int hour, minute, second;
    
    sscanf(time, "%d:%d:%d", &hour, &minute, &second);
    printf("Parsing time \"%s\":\n", time);
    printf("  %02d:%02d:%02d\n\n", hour, minute, second);
    
    char config[] = "port=8080;host=localhost;timeout=30";
    int port, timeout;
    char host[50];
    
    sscanf(config, "port=%d;host=%[^;];timeout=%d", &port, host, &timeout);
    printf("Parsing config \"%s\":\n", config);
    printf("  Port: %d\n", port);
    printf("  Host: %s\n", host);
    printf("  Timeout: %d\n\n", timeout);
    
    char coordinates[] = "(10.5, 20.3)";
    float x, y;
    
    sscanf(coordinates, "(%f, %f)", &x, &y);
    printf("Parsing coordinates \"%s\":\n", coordinates);
    printf("  X: %.1f, Y: %.1f\n\n", x, y);
    
    char hex_data[] = "Color: #FF8800";
    unsigned int color;
    char label[20];
    
    sscanf(hex_data, "%s #%x", label, &color);
    printf("Parsing \"%s\":\n", hex_data);
    printf("  Label: %s\n", label);
    printf("  Color: 0x%06X (R=%d, G=%d, B=%d)\n\n", 
           color, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
    
    char csv[] = "Alice,25,Engineer";
    char name[30], job[30];
    int age;
    
    sscanf(csv, "%[^,],%d,%s", name, &age, job);
    printf("Parsing CSV \"%s\":\n", csv);
    printf("  Name: %s, Age: %d, Job: %s\n\n", name, age, job);
    
    printf("sscanf() vs scanf():\n");
    printf("  scanf(): reads from stdin\n");
    printf("  sscanf(): reads from a string\n");
    printf("  Same format specifiers work for both\n\n");
    
    printf("Using with fgets() for safe input:\n");
    char line[100];
    int value;
    
    printf("  Enter a number: ");
    if (fgets(line, sizeof(line), stdin) != NULL) {
        if (sscanf(line, "%d", &value) == 1) {
            printf("  Parsed: %d\n", value);
        } else {
            printf("  Parse error!\n");
        }
    }
    
    printf("\nAdvantages of fgets + sscanf:\n");
    printf("  1. Buffer overflow protection from fgets\n");
    printf("  2. Can re-parse the same line\n");
    printf("  3. Easier error recovery\n");
    printf("  4. No buffer issues between inputs\n");
    
    return 0;
}
```

## Output

```
=== sscanf() - Parse Strings ===

Parsing "42 3.14 Hello":
  Matched: 3 items
  Integer: 42
  Float: 3.14
  String: Hello

Parsing date "2024-03-15":
  Year: 2024, Month: 3, Day: 15

Parsing time "14:30:45":
  14:30:45

Parsing config "port=8080;host=localhost;timeout=30":
  Port: 8080
  Host: localhost
  Timeout: 30

Parsing coordinates "(10.5, 20.3)":
  X: 10.5, Y: 20.3

Parsing "Color: #FF8800":
  Label: Color:
  Color: 0xFF8800 (R=255, G=136, B=0)

Parsing CSV "Alice,25,Engineer":
  Name: Alice, Age: 25, Job: Engineer

sscanf() vs scanf():
  scanf(): reads from stdin
  sscanf(): reads from a string
  Same format specifiers work for both

Using with fgets() for safe input:
  Enter a number: 42
  Parsed: 42

Advantages of fgets + sscanf:
  1. Buffer overflow protection from fgets
  2. Can re-parse the same line
  3. Easier error recovery
  4. No buffer issues between inputs
```

## Compilation

```bash
gcc 068-sscanf.c -o 068-sscanf
./068-sscanf
```

## Key Takeaways

- `sscanf()` parses formatted data from strings
- Same format specifiers as scanf
- Returns count of matched items
- Use `%[^X]` to read until character X
- fgets + sscanf is safer than scanf alone
- Great for parsing config files and structured data

## Challenge

Write a program that parses a log file format like "2024-03-15 14:30:45 ERROR: Connection failed" extracting timestamp, level, and message.

## Related

- [[069-sprintf]] — Format to string
- [[066-input-validation]] — Validating parsed input
