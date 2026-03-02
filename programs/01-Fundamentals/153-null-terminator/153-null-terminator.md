# 153 - Null Terminator: The `'\0'` Character

## Overview
The **null terminator** (`'\0'`) is a character with ASCII value 0 that marks the end of a string in C. It's what distinguishes a string from a regular character array.

## The Null Character

```c
'\0'  // Null character (escape sequence)
0     // Integer zero
NULL  // Null pointer (different concept!)

// These are equivalent:
if (str[i] == '\0')
if (str[i] == 0)
if (!str[i])
```

## Properties

```c
printf("%d\n", '\0');      // Prints: 0
printf("%d\n", 'A');       // Prints: 65
sizeof('\0')               // 4 in C (int), 1 in C++
```

## How String Functions Use '\0'

```c
// strlen implementation
size_t strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// printf %s scans until '\0'
char str[] = "Hello\0World";
printf("%s", str);  // Prints: Hello (stops at '\0')
```

## Embedded Null Characters

```c
char str[] = "AB\0CD";
// Memory: ['A']['B']['\0']['C']['D']['\0']
// strlen(str) = 2
// sizeof(str) = 6

// The "CD" part is inaccessible via string functions
printf("%s", str);      // "AB"
printf("%s", str + 3);  // "CD"
```

## Common Operations

### Truncating Strings
```c
char str[] = "Hello World";
str[5] = '\0';
// str is now "Hello"
```

### Checking for Empty String
```c
if (str[0] == '\0')  // String is empty
if (*str == '\0')    // Same thing
if (!*str)           // Idiomatic C
```

### Finding String End
```c
char *end = str;
while (*end) end++;
// end now points to '\0'
```

## Dangers

```c
// 1. Missing null terminator
char bad[5] = {'H', 'e', 'l', 'l', 'o'};
strlen(bad);  // Undefined! Reads past array

// 2. Overwriting null terminator
char str[6] = "Hello";
str[5] = '!';  // Now there's no '\0'!

// 3. Buffer overflow
char small[3];
strcpy(small, "Hello");  // Overwrites memory!
```

---

# Kata Challenge

## Challenge: Null Terminator Detective
Write a program that:
1. Creates strings with embedded null characters
2. Shows the difference between sizeof and strlen
3. Implements a function to find ALL null characters in a buffer
4. Demonstrates string truncation and restoration

## Requirements
- Create `char str[] = "Hello\0Hidden\0Data"`
- Display all parts of the string
- Print total bytes vs "visible" length
- Show how to access hidden parts

## Expected Output
```
=== Null Terminator Detective ===

Original buffer: "Hello\0Hidden\0Data"
Total buffer size: 18 bytes
Visible length (strlen): 5

Scanning all bytes:
  [0-4]  "Hello"   (5 chars)
  [5]    '\0'      <- null terminator #1
  [6-11] "Hidden"  (6 chars)
  [12]   '\0'      <- null terminator #2
  [13-16] "Data"   (4 chars)
  [17]   '\0'      <- final null terminator

Found 3 strings in buffer:
  String 1: "Hello" (starts at 0)
  String 2: "Hidden" (starts at 6)
  String 3: "Data" (starts at 13)

=== Truncation Demo ===
Before: "Programming"
After str[4] = '\0': "Prog"
Restoring str[4] = 'r': "Programming"
```

## Function to Implement
```c
int count_strings(const char *buffer, size_t size);
void print_all_strings(const char *buffer, size_t size);
```

## Bonus
- Handle binary data with multiple null bytes
- Implement a safe print that shows \0 explicitly
