# String Literals vs Character Arrays

## Overview
C has two fundamentally different ways to work with strings, with very different behaviors and constraints.

## The Two Types

### String Literal (Pointer to Read-Only)
```c
const char *str = "Hello";
```
- Points to string in read-only memory
- Cannot modify characters
- Pointer can be reassigned
- sizeof gives pointer size (4 or 8 bytes)

### Character Array (Modifiable Copy)
```c
char str[] = "Hello";
```
- Creates a copy on stack
- Characters can be modified
- Array name cannot be reassigned
- sizeof gives array size (6 bytes for "Hello")

## Comparison Table

| Feature | `const char *s = "X"` | `char s[] = "X"` |
|---------|----------------------|------------------|
| Storage | Read-only section | Stack/heap |
| Modifiable | NO (undefined behavior) | YES |
| Reassignable | YES (pointer) | NO (array) |
| sizeof | Pointer size | Array size |
| Identical literals | May share memory | Always separate |

## Visual Memory Layout

```
String Literal:                   Character Array:
                                  
  Stack:                           Stack:
  ┌───────────┐                    ┌───────────┐
  │ ptr ──────┼────────┐           │ 'H' │ 'e' │
  └───────────┘        │           │ 'l' │ 'l' │
                       ▼           │ 'o' │ '\0'│
  Read-only:           │           └───────────┘
  ┌───────────────┐    │
  │ H e l l o \0  │◄───┘
  └───────────────┘
```

## Common Mistakes

### 1. Modifying String Literal
```c
char *s = "Hello";  // Missing const!
s[0] = 'J';         // CRASH! Undefined behavior
```

### 2. Returning Local Array
```c
char *bad_func(void) {
    char local[] = "Hello";
    return local;  // DANGER! Dangling pointer
}
```

### 3. Comparing with ==
```c
char *a = "test";
char *b = "test";
if (a == b) ...  // May work by accident (string pooling)
```

## Compilation
```bash
gcc -o string-literals-vs-arrays string-literals-vs-arrays.c
./string-literals-vs-arrays
```

---

# Kata Challenge: Safe String Library

## Objective
Create string functions that properly handle both literals and arrays.

## Requirements
1. Determine if a string is modifiable
2. Create safe string duplication
3. Build a string type that tracks its nature
4. Implement safe modification functions

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    STR_LITERAL,     // Read-only
    STR_STACK,       // Stack array
    STR_HEAP         // Dynamically allocated
} StringType;

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
    StringType type;
} SafeString;

// Create from literal (read-only)
SafeString ss_from_literal(const char *str) {
    SafeString ss = {
        .data = (char*)str,
        .length = strlen(str),
        .capacity = 0,  // Not modifiable
        .type = STR_LITERAL
    };
    return ss;
}

// Create modifiable copy
SafeString ss_copy(const char *str) {
    // TODO: Create heap-allocated copy
    SafeString ss = {0};
    return ss;
}

// Create with capacity
SafeString ss_create(size_t capacity) {
    // TODO: Allocate buffer with capacity
    SafeString ss = {0};
    return ss;
}

// Safe modification (copies if needed)
bool ss_set_char(SafeString *ss, size_t index, char c) {
    // TODO: If literal, convert to heap copy first
    // TODO: Then modify
    return false;
}

// Append (grows if needed)
bool ss_append(SafeString *ss, const char *str) {
    // TODO: Implement with reallocation
    return false;
}

// Free resources
void ss_free(SafeString *ss) {
    if (ss->type == STR_HEAP && ss->data) {
        free(ss->data);
    }
    ss->data = NULL;
    ss->length = 0;
    ss->capacity = 0;
}

int main(void) {
    // Test literal
    SafeString s1 = ss_from_literal("Hello");
    printf("Literal: \"%s\", modifiable: %s\n", 
           s1.data, s1.type != STR_LITERAL ? "yes" : "no");
    
    // Test copy
    SafeString s2 = ss_copy("World");
    printf("Copy: \"%s\", modifiable: %s\n",
           s2.data, s2.type != STR_LITERAL ? "yes" : "no");
    
    // Test modification
    if (ss_set_char(&s1, 0, 'J')) {
        printf("Modified s1: \"%s\"\n", s1.data);
    }
    
    ss_free(&s1);
    ss_free(&s2);
    
    return 0;
}
```

## Expected Output
```
Literal: "Hello", modifiable: no
Copy: "World", modifiable: yes
Modified s1: "Jello"
```

## Bonus Challenges
1. Implement copy-on-write semantics
2. Add reference counting for shared strings
3. Implement small string optimization
4. Add string interning for deduplication

## Test Cases
- Literal → not modifiable
- Copy → modifiable
- Modify literal → automatically copies
- Append beyond capacity → grows
