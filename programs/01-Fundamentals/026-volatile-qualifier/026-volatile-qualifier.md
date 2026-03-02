---
id: "026"
title: "The volatile Qualifier"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - volatile
  - qualifiers
  - optimization
  - signals
  - embedded
difficulty: beginner
source: "C11 Standard 6.7.3"
---

# 026 — The volatile Qualifier

## Concept

The `volatile` qualifier tells the compiler: **"This variable can change unexpectedly — don't optimize reads/writes to it."**

Without `volatile`, compilers may:
- Cache variable values in registers
- Eliminate "redundant" reads
- Reorder memory accesses

This breaks code when variables change outside normal program flow.

**When to use volatile:**

| Scenario | Why needed |
|----------|------------|
| Signal handlers | Value modified asynchronously |
| Memory-mapped I/O | Hardware changes the value |
| Interrupt service routines | ISR modifies variables |
| Shared memory | External process writes |

**Signal handler example:**
```c
volatile sig_atomic_t flag = 0;

void handler(int sig) {
    flag = 1;  // Modified by signal
}

int main(void) {
    signal(SIGINT, handler);
    while (!flag) {  // Without volatile, might become infinite loop
        // wait
    }
}
```

**Memory-mapped I/O (embedded):**
```c
// Status register at hardware address
volatile uint32_t *STATUS = (volatile uint32_t *)0x40001000;

// Must re-read each iteration — hardware changes it
while (*STATUS & BUSY_BIT) {
    // wait for hardware
}
```

**volatile does NOT provide:**
- Thread safety (use `_Atomic` or mutexes)
- Memory ordering guarantees
- Atomic operations

**Combining with const:**
```c
volatile const uint32_t *sensor;  // Read-only hardware register
// We can read it, but not write; hardware can update it
```

## Code

```c
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

volatile sig_atomic_t shutdown_requested = 0;

void signal_handler(int signum) {
    (void)signum;
    shutdown_requested = 1;
}

int main(void) {
    printf("=== The volatile Qualifier ===\n\n");
    
    printf("--- What volatile Does ---\n");
    printf("volatile tells the compiler:\n");
    printf("  1. Don't optimize away reads/writes to this variable\n");
    printf("  2. Always read from memory, never use cached value\n");
    printf("  3. Value may change unexpectedly (hardware, signals, etc.)\n");
    
    printf("\n--- Example: Signal Handler ---\n");
    signal(SIGINT, signal_handler);
    printf("volatile sig_atomic_t shutdown_requested = 0;\n");
    printf("Press Ctrl+C to set shutdown_requested = 1\n");
    printf("(We'll simulate this for the demo)\n\n");
    
    shutdown_requested = 1;
    
    printf("Without volatile, this loop might never exit:\n");
    printf("  while (!shutdown_requested) { /* wait */ }\n");
    printf("Compiler might optimize to: while(1) {} if it caches the value!\n");
    
    printf("\n--- Common Use Cases ---\n");
    printf("1. Signal handlers (sig_atomic_t)\n");
    printf("2. Memory-mapped hardware registers\n");
    printf("3. Variables shared between threads*\n");
    printf("   (*but prefer atomics or mutexes for threads)\n");
    printf("4. Variables modified by interrupts (embedded systems)\n");
    
    printf("\n--- Syntax Examples ---\n");
    printf("volatile int sensor_value;\n");
    printf("volatile uint32_t *hardware_register;\n");
    printf("volatile const int *read_only_register;\n");
    
    printf("\n--- volatile Does NOT Mean ---\n");
    printf("- Thread-safe (use atomics for that)\n");
    printf("- Memory barriers (use proper synchronization)\n");
    printf("- Atomic operations (use _Atomic or stdatomic.h)\n");
    
    printf("\n--- Demonstration ---\n");
    volatile int counter = 0;
    
    printf("volatile int counter = 0;\n");
    printf("Initial value: %d\n", counter);
    
    counter = 42;
    printf("After assignment: %d\n", counter);
    
    printf("\nKey point: Each read goes to memory, not a register.\n");
    printf("Without volatile, compiler might skip repeated reads.\n");
    
    printf("\n--- Memory-Mapped I/O Example (Embedded) ---\n");
    printf("// Hardware status register at address 0x40000000\n");
    printf("volatile uint32_t *STATUS = (volatile uint32_t *)0x40000000;\n");
    printf("while (*STATUS & BUSY_FLAG) { /* wait for hardware */ }\n");
    printf("// Without volatile, compiler might read STATUS only once!\n");
    
    return 0;
}
```

## Output

```
=== The volatile Qualifier ===

--- What volatile Does ---
volatile tells the compiler:
  1. Don't optimize away reads/writes to this variable
  2. Always read from memory, never use cached value
  3. Value may change unexpectedly (hardware, signals, etc.)

--- Example: Signal Handler ---
volatile sig_atomic_t shutdown_requested = 0;
Press Ctrl+C to set shutdown_requested = 1
(We'll simulate this for the demo)

Without volatile, this loop might never exit:
  while (!shutdown_requested) { /* wait */ }
Compiler might optimize to: while(1) {} if it caches the value!

--- Common Use Cases ---
1. Signal handlers (sig_atomic_t)
2. Memory-mapped hardware registers
3. Variables shared between threads*
   (*but prefer atomics or mutexes for threads)
4. Variables modified by interrupts (embedded systems)

--- Syntax Examples ---
volatile int sensor_value;
volatile uint32_t *hardware_register;
volatile const int *read_only_register;

--- volatile Does NOT Mean ---
- Thread-safe (use atomics for that)
- Memory barriers (use proper synchronization)
- Atomic operations (use _Atomic or stdatomic.h)

--- Demonstration ---
volatile int counter = 0;
Initial value: 0
After assignment: 42

Key point: Each read goes to memory, not a register.
Without volatile, compiler might skip repeated reads.

--- Memory-Mapped I/O Example (Embedded) ---
// Hardware status register at address 0x40000000
volatile uint32_t *STATUS = (volatile uint32_t *)0x40000000;
while (*STATUS & BUSY_FLAG) { /* wait for hardware */ }
// Without volatile, compiler might read STATUS only once!
```

## Key Takeaways

- `volatile` prevents compiler optimizations on variable access
- Essential for signal handlers, hardware registers, and ISRs
- Always use with `sig_atomic_t` for signal-safe flag variables
- Does NOT provide thread safety — use atomics or mutexes
- Can combine with `const`: `volatile const` for read-only hardware
- Without `volatile`, loops checking external values may never exit
- Overusing `volatile` hurts performance; use only when needed

## Challenge

Write a program that uses `setitimer()` to set up a periodic timer signal. Use a volatile variable to count the number of signals received. Print the count in main's loop. See how removing `volatile` affects behavior with `-O2` optimization.

## Related

- [[025-const-qualifier]] — const qualifier
- [[028-static-variables]] — static variables
- [[027-auto-storage-class]] — auto storage class
