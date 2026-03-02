# sprintf - Number to String Conversion

## Overview
`sprintf` writes formatted output to a string buffer. It's the standard way to convert numbers to strings in C.

## Function Signatures
```c
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);  // Safe version
```

## Return Value
- Number of characters written (excluding null terminator)
- For snprintf: number that WOULD be written if buffer was large enough

## Common Format Specifiers

### Integers
| Format | Result for 42 |
|--------|---------------|
| %d | "42" |
| %5d | "   42" |
| %-5d | "42   " |
| %05d | "00042" |
| %+d | "+42" |
| %x | "2a" |
| %X | "2A" |
| %o | "52" |

### Floating-Point
| Format | Result for 3.14159 |
|--------|-------------------|
| %f | "3.141590" |
| %.2f | "3.14" |
| %8.2f | "    3.14" |
| %e | "3.141590e+00" |
| %g | "3.14159" |

## Safety: sprintf vs snprintf

### ⚠️ sprintf - Dangerous
```c
char buf[10];
sprintf(buf, "A very long string");  // BUFFER OVERFLOW!
```

### ✅ snprintf - Safe
```c
char buf[10];
snprintf(buf, sizeof(buf), "A very long string");  // Truncated safely
// buf = "A very lo" (9 chars + null)
```

## Building Strings Incrementally
```c
char buf[256];
int pos = 0;
pos += snprintf(buf + pos, sizeof(buf) - pos, "Part 1, ");
pos += snprintf(buf + pos, sizeof(buf) - pos, "Part 2, ");
pos += snprintf(buf + pos, sizeof(buf) - pos, "Part 3");
```

## Compilation
```bash
gcc -o sprintf-strings sprintf-strings.c
./sprintf-strings
```

---

# Kata Challenge: String Builder

## Objective
Create a safe string builder library using snprintf.

## Requirements
1. Append various types to a buffer
2. Track remaining space
3. Prevent buffer overflow
4. Support format strings

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct {
    char *buffer;
    size_t capacity;
    size_t length;
    bool overflow;
} StringBuilder;

void sb_init(StringBuilder *sb, char *buffer, size_t capacity) {
    sb->buffer = buffer;
    sb->capacity = capacity;
    sb->length = 0;
    sb->overflow = false;
    if (capacity > 0) {
        buffer[0] = '\0';
    }
}

bool sb_append(StringBuilder *sb, const char *str) {
    // TODO: Append string, track overflow
    return true;
}

bool sb_append_int(StringBuilder *sb, int value) {
    // TODO: Append integer
    return true;
}

bool sb_append_double(StringBuilder *sb, double value, int decimals) {
    // TODO: Append double with specified precision
    return true;
}

bool sb_appendf(StringBuilder *sb, const char *format, ...) {
    // TODO: Append formatted string (like sprintf)
    return true;
}

void sb_clear(StringBuilder *sb) {
    sb->length = 0;
    sb->overflow = false;
    if (sb->capacity > 0) {
        sb->buffer[0] = '\0';
    }
}

int main(void) {
    char buffer[100];
    StringBuilder sb;
    
    sb_init(&sb, buffer, sizeof(buffer));
    
    sb_append(&sb, "Name: ");
    sb_append(&sb, "Alice");
    sb_append(&sb, ", Age: ");
    sb_append_int(&sb, 30);
    sb_append(&sb, ", Score: ");
    sb_append_double(&sb, 95.5, 1);
    
    printf("Result: %s\n", sb.buffer);
    printf("Length: %zu\n", sb.length);
    printf("Overflow: %s\n", sb.overflow ? "yes" : "no");
    
    // Test overflow
    char small[20];
    sb_init(&sb, small, sizeof(small));
    sb_append(&sb, "This is a very long string that will overflow");
    printf("\nSmall buffer: \"%s\"\n", sb.buffer);
    printf("Overflow: %s\n", sb.overflow ? "yes" : "no");
    
    return 0;
}
```

## Expected Output
```
Result: Name: Alice, Age: 30, Score: 95.5
Length: 32
Overflow: no

Small buffer: "This is a very lo"
Overflow: yes
```

## Bonus Challenges
1. Add sb_prepend() for prepending content
2. Implement sb_insert() at position
3. Add JSON building helpers
4. Create HTML escaping function

## Test Cases
- Normal append → success
- Append to full buffer → overflow flag set
- Empty string append → no change
- Printf-style formatting → correct output
