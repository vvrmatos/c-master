---
id: "039"
title: "Enumeration (enum)"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - enum
  - constants
  - types
difficulty: beginner
source: "C11 Standard Section 6.7.2.2"
---

# 039 — Enumeration (enum)

## Concept

Enumerations (`enum`) define a set of named integer constants. They provide more readable code than magic numbers and limited type safety. Each enumerator is assigned an integer value, starting from 0 by default.

Basic syntax:
```c
enum Day { SUNDAY, MONDAY, TUESDAY };  // 0, 1, 2
enum Day today = MONDAY;
```

Key characteristics:
- **Auto-numbering** — starts at 0, increments by 1
- **Integer type** — enums are integers, can use in arithmetic
- **Scope** — enumerators are in surrounding scope (not enum scope)
- **Size** — typically `sizeof(int)`, implementation-defined

Common uses:
- State machines (STATE_IDLE, STATE_RUNNING, STATE_DONE)
- Error codes (ERROR_NONE, ERROR_FILE, ERROR_MEMORY)
- Options (OPT_READ, OPT_WRITE, OPT_APPEND)
- Days, months, colors, directions

> **Why enum over #define**: Enums provide grouped constants with debugger visibility. The compiler can warn about unhandled enum values in switch statements.

## Code

```c
#include <stdio.h>

enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum Color {
    RED,
    GREEN,
    BLUE
};

enum Status {
    STATUS_OK,
    STATUS_ERROR,
    STATUS_PENDING,
    STATUS_TIMEOUT
};

enum Boolean {
    FALSE = 0,
    TRUE = 1
};

int main(void) {
    printf("=== Enumeration (enum) Basics ===\n\n");
    
    printf("1. Basic enum - Days of week:\n");
    printf("   SUNDAY    = %d\n", SUNDAY);
    printf("   MONDAY    = %d\n", MONDAY);
    printf("   TUESDAY   = %d\n", TUESDAY);
    printf("   WEDNESDAY = %d\n", WEDNESDAY);
    printf("   THURSDAY  = %d\n", THURSDAY);
    printf("   FRIDAY    = %d\n", FRIDAY);
    printf("   SATURDAY  = %d\n", SATURDAY);
    
    printf("\n2. Using enum variables:\n");
    enum Day today = WEDNESDAY;
    enum Day weekend = SATURDAY;
    printf("   enum Day today = WEDNESDAY; // %d\n", today);
    printf("   enum Day weekend = SATURDAY; // %d\n", weekend);
    
    printf("\n3. Enum comparison:\n");
    if (today == WEDNESDAY) {
        printf("   today == WEDNESDAY: true\n");
    }
    if (today < weekend) {
        printf("   today < weekend: true (WEDNESDAY < SATURDAY)\n");
    }
    
    printf("\n4. Enum in switch:\n");
    enum Status status = STATUS_ERROR;
    switch (status) {
        case STATUS_OK:
            printf("   Status: OK\n");
            break;
        case STATUS_ERROR:
            printf("   Status: ERROR\n");
            break;
        case STATUS_PENDING:
            printf("   Status: PENDING\n");
            break;
        case STATUS_TIMEOUT:
            printf("   Status: TIMEOUT\n");
            break;
    }
    
    printf("\n5. Enum size:\n");
    printf("   sizeof(enum Day) = %zu bytes\n", sizeof(enum Day));
    printf("   sizeof(enum Color) = %zu bytes\n", sizeof(enum Color));
    printf("   sizeof(enum Status) = %zu bytes\n", sizeof(enum Status));
    
    printf("\n6. Enum is integer type:\n");
    enum Color c = RED;
    int color_as_int = c;
    printf("   enum Color c = RED;\n");
    printf("   int color_as_int = c; // %d\n", color_as_int);
    
    c = 1;
    printf("   c = 1; // Valid but not recommended\n");
    printf("   c is now: %d (GREEN)\n", c);
    
    printf("\n7. Enumerator scope:\n");
    printf("   Enumerators are in the same scope as the enum\n");
    printf("   They can conflict with other names!\n");
    
    printf("\n8. Anonymous enum:\n");
    enum { MAX_SIZE = 100, MIN_SIZE = 10 };
    printf("   enum { MAX_SIZE = 100, MIN_SIZE = 10 };\n");
    printf("   MAX_SIZE = %d, MIN_SIZE = %d\n", MAX_SIZE, MIN_SIZE);
    
    printf("\n9. Typedef with enum:\n");
    printf("   typedef enum { OFF, ON } Switch;\n");
    printf("   Switch light = ON; // Cleaner syntax\n");
    
    return 0;
}
```

## Output

```
=== Enumeration (enum) Basics ===

1. Basic enum - Days of week:
   SUNDAY    = 0
   MONDAY    = 1
   TUESDAY   = 2
   WEDNESDAY = 3
   THURSDAY  = 4
   FRIDAY    = 5
   SATURDAY  = 6

2. Using enum variables:
   enum Day today = WEDNESDAY; // 3
   enum Day weekend = SATURDAY; // 6

3. Enum comparison:
   today == WEDNESDAY: true
   today < weekend: true (WEDNESDAY < SATURDAY)

4. Enum in switch:
   Status: ERROR

5. Enum size:
   sizeof(enum Day) = 4 bytes
   sizeof(enum Color) = 4 bytes
   sizeof(enum Status) = 4 bytes

6. Enum is integer type:
   enum Color c = RED;
   int color_as_int = c; // 0
   c = 1; // Valid but not recommended
   c is now: 1 (GREEN)

7. Enumerator scope:
   Enumerators are in the same scope as the enum
   They can conflict with other names!

8. Anonymous enum:
   enum { MAX_SIZE = 100, MIN_SIZE = 10 };
   MAX_SIZE = 100, MIN_SIZE = 10

9. Typedef with enum:
   typedef enum { OFF, ON } Switch;
   Switch light = ON; // Cleaner syntax
```

## Key Takeaways

- Enums define named integer constants starting at 0
- Use `enum TypeName { A, B, C };` syntax
- Enumerators are in surrounding scope, not enum scope
- Enums are integer types — can compare and assign integers
- Anonymous enums work as grouped constants
- Use typedef for cleaner variable declarations

## Challenge

Create a state machine using enum: IDLE, CONNECTING, CONNECTED, DISCONNECTING, ERROR. Write a function that transitions between states and validates transitions.

## Related

- [[040-enum-advanced]] — Explicit values and flags
- [[037-define-macros]] — Alternative for constants
- [[038-const-vs-define]] — Constant comparison
