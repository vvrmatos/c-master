---
id: "028"
title: "Static Variables"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - static
  - storage-class
  - linkage
  - persistence
difficulty: beginner
source: "C11 Standard 6.2.2, 6.2.4"
---

# 028 — Static Variables

## Concept

`static` has two distinct meanings in C:

**1. Inside a function: Persistent local variable**
```c
void count(void) {
    static int n = 0;  // Initialized once, persists between calls
    n++;
    printf("%d\n", n);  // Prints 1, 2, 3, 4...
}
```

**2. At file scope: Internal linkage (private to file)**
```c
static int private_var = 42;     // Not visible to other files
static void helper(void) { }     // Not visible to other files
```

**Static local variable properties:**

| Property | Value |
|----------|-------|
| Scope | Block where declared |
| Lifetime | Entire program |
| Default value | Zero (for numerics) |
| Storage | Data segment (not stack) |
| Initialization | Once, before first use |

**Comparison:**
```c
void func(void) {
    int a = 0;         // Created/destroyed each call, garbage if uninitialized
    static int b = 0;  // Created once, persists, initialized to 0
}
```

**Common uses for static:**
1. **Counters** that persist across calls
2. **Caches** within functions
3. **One-time initialization** patterns
4. **Encapsulation** (hiding functions/variables from other files)
5. **ID generators**

**Internal linkage (file scope static):**
```c
// file1.c
static int count = 0;       // Private to file1.c

// file2.c
static int count = 0;       // Different variable! Private to file2.c
extern int count;           // ERROR: can't link to static
```

## Code

```c
#include <stdio.h>

void counter_without_static(void) {
    int count = 0;
    count++;
    printf("  Without static: count = %d\n", count);
}

void counter_with_static(void) {
    static int count = 0;
    count++;
    printf("  With static:    count = %d\n", count);
}

static int module_private = 42;

static void helper_function(void) {
    printf("  I'm a static function - only visible in this file!\n");
}

int get_unique_id(void) {
    static int next_id = 1000;
    return next_id++;
}

void demonstrate_initialization(void) {
    static int initialized_once = 0;
    static int call_count = 0;
    
    call_count++;
    
    if (initialized_once == 0) {
        printf("  First call - initializing...\n");
        initialized_once = 1;
    } else {
        printf("  Already initialized (call #%d)\n", call_count);
    }
}

int main(void) {
    printf("=== Static Variables ===\n\n");
    
    printf("--- Static vs Auto in Functions ---\n");
    printf("Calling each function 3 times:\n\n");
    
    for (int i = 0; i < 3; i++) {
        counter_without_static();
        counter_with_static();
        printf("\n");
    }
    
    printf("--- Static Preserves Value Between Calls ---\n");
    printf("Unique IDs generated: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", get_unique_id());
    }
    printf("\n");
    
    printf("\n--- Static for Internal Linkage ---\n");
    printf("module_private = %d (only accessible in this file)\n", module_private);
    helper_function();
    
    printf("\n--- Default Initialization ---\n");
    static int default_init;
    printf("Static variables default to zero: %d\n", default_init);
    printf("(Auto variables would have garbage!)\n");
    
    printf("\n--- One-Time Initialization Pattern ---\n");
    for (int i = 0; i < 3; i++) {
        demonstrate_initialization();
    }
    
    printf("\n--- Static Variable Properties ---\n");
    printf("1. Lifetime: entire program execution\n");
    printf("2. Scope: block where declared (for local static)\n");
    printf("3. Initialized once (before main for global static)\n");
    printf("4. Default value: zero (not garbage)\n");
    printf("5. Stored in data segment (not stack)\n");
    
    printf("\n--- Two Meanings of 'static' ---\n");
    printf("1. Inside function: persistent local variable\n");
    printf("2. At file scope: internal linkage (private to file)\n");
    
    return 0;
}
```

## Output

```
=== Static Variables ===

--- Static vs Auto in Functions ---
Calling each function 3 times:

  Without static: count = 1
  With static:    count = 1

  Without static: count = 1
  With static:    count = 2

  Without static: count = 1
  With static:    count = 3

--- Static Preserves Value Between Calls ---
Unique IDs generated: 1000 1001 1002 1003 1004 

--- Static for Internal Linkage ---
module_private = 42 (only accessible in this file)
  I'm a static function - only visible in this file!

--- Default Initialization ---
Static variables default to zero: 0
(Auto variables would have garbage!)

--- One-Time Initialization Pattern ---
  First call - initializing...
  Already initialized (call #2)
  Already initialized (call #3)

--- Static Variable Properties ---
1. Lifetime: entire program execution
2. Scope: block where declared (for local static)
3. Initialized once (before main for global static)
4. Default value: zero (not garbage)
5. Stored in data segment (not stack)

--- Two Meanings of 'static' ---
1. Inside function: persistent local variable
2. At file scope: internal linkage (private to file)
```

## Key Takeaways

- Static local variables persist between function calls
- Static variables are initialized only once
- Static variables default to zero (unlike auto)
- File-scope `static` creates private (internal linkage) symbols
- Use static for encapsulation and hiding implementation details
- Static variables live in data segment, not stack
- Be careful: static in multithreaded code needs synchronization!

## Challenge

Create a simple "object" using static: a `stack` module with `push()`, `pop()`, and `peek()` functions. Use a static array and static index to store state. The array and index should not be visible outside the module.

## Related

- [[027-auto-storage-class]] — auto storage class
- [[029-register-hint]] — register hint
- [[030-extern-declaration]] — extern linkage
