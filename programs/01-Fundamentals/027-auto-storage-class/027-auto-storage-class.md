---
id: "027"
title: "The auto Storage Class"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - auto
  - storage-class
  - scope
  - lifetime
difficulty: beginner
source: "C11 Standard 6.2.4, 6.7.1"
---

# 027 — The auto Storage Class

## Concept

`auto` declares **automatic storage duration** — the variable is created when its block is entered and destroyed when the block exits.

**Key insight: `auto` is the default for local variables.** You almost never need to write it explicitly.

```c
void func(void) {
    auto int x = 10;  // Explicit auto (rare)
    int y = 20;       // Implicit auto (same thing)
}
```

**Characteristics of auto variables:**

| Property | Value |
|----------|-------|
| Scope | Block where declared |
| Lifetime | Block execution |
| Default value | Undefined (garbage) |
| Storage | Stack |
| Linkage | None |

**Automatic storage duration means:**
1. Variable created when entering the block
2. Variable destroyed when exiting the block
3. Value is lost between function calls

```c
void count(void) {
    auto int counter = 0;  // Created fresh each call
    counter++;
    printf("%d\n", counter);  // Always prints 1
}
```

**Why `auto` is rarely used:**
- It's the default — writing it is redundant
- C++ repurposed `auto` for type inference (C++11)
- Modern style prefers implicit auto

**Storage class keywords in C:**
- `auto` — automatic duration (default for locals)
- `static` — static duration
- `extern` — external linkage
- `register` — optimization hint

You can only use one storage class specifier per declaration.

## Code

```c
#include <stdio.h>

void demonstrate_auto(void) {
    auto int x = 10;
    int y = 20;
    
    printf("  auto int x = %d\n", x);
    printf("  int y = %d (implicitly auto)\n", y);
    printf("  Both are identical - auto is the default!\n");
}

void show_lifetime(void) {
    for (int i = 0; i < 3; i++) {
        auto int counter = 0;
        counter++;
        printf("  Iteration %d: counter = %d (always 1, recreated each time)\n", 
               i + 1, counter);
    }
}

void nested_scope(void) {
    auto int x = 100;
    printf("  Outer x = %d\n", x);
    
    {
        auto int x = 200;
        printf("  Inner x = %d (shadows outer)\n", x);
    }
    
    printf("  Back to outer x = %d\n", x);
}

int main(void) {
    printf("=== The auto Storage Class ===\n\n");
    
    printf("--- What is auto? ---\n");
    printf("auto declares automatic storage duration.\n");
    printf("It's the DEFAULT for local variables - rarely written explicitly.\n\n");
    
    printf("--- Explicit vs Implicit auto ---\n");
    demonstrate_auto();
    
    printf("\n--- auto Variable Characteristics ---\n");
    printf("1. Created when block is entered\n");
    printf("2. Destroyed when block exits\n");
    printf("3. Not initialized by default (contains garbage)\n");
    printf("4. Stored on the stack\n");
    printf("5. Scope limited to declaring block\n");
    
    printf("\n--- Lifetime Demonstration ---\n");
    show_lifetime();
    
    printf("\n--- Scope Demonstration ---\n");
    nested_scope();
    
    printf("\n--- Uninitialized auto Variables ---\n");
    auto int uninitialized;
    printf("  Uninitialized auto int may contain: %d (garbage!)\n", uninitialized);
    printf("  ALWAYS initialize your variables!\n");
    
    printf("\n--- Why auto is Rarely Used ---\n");
    printf("1. It's the default - explicit auto is redundant\n");
    printf("2. C++ repurposed 'auto' for type inference\n");
    printf("3. Modern style: just write 'int x' not 'auto int x'\n");
    
    printf("\n--- Storage Classes Summary ---\n");
    printf("| Keyword  | Scope    | Lifetime    | Default Init |\n");
    printf("|----------|----------|-------------|-------------|\n");
    printf("| auto     | Block    | Block       | Garbage     |\n");
    printf("| static   | Block    | Program     | Zero        |\n");
    printf("| extern   | Global   | Program     | Zero        |\n");
    printf("| register | Block    | Block       | Garbage     |\n");
    
    return 0;
}
```

## Output

```
=== The auto Storage Class ===

--- What is auto? ---
auto declares automatic storage duration.
It's the DEFAULT for local variables - rarely written explicitly.

--- Explicit vs Implicit auto ---
  auto int x = 10
  int y = 20 (implicitly auto)
  Both are identical - auto is the default!

--- auto Variable Characteristics ---
1. Created when block is entered
2. Destroyed when block exits
3. Not initialized by default (contains garbage)
4. Stored on the stack
5. Scope limited to declaring block

--- Lifetime Demonstration ---
  Iteration 1: counter = 1 (always 1, recreated each time)
  Iteration 2: counter = 1 (always 1, recreated each time)
  Iteration 3: counter = 1 (always 1, recreated each time)

--- Scope Demonstration ---
  Outer x = 100
  Inner x = 200 (shadows outer)
  Back to outer x = 100

--- Uninitialized auto Variables ---
  Uninitialized auto int may contain: 0 (garbage!)
  ALWAYS initialize your variables!

--- Why auto is Rarely Used ---
1. It's the default - explicit auto is redundant
2. C++ repurposed 'auto' for type inference
3. Modern style: just write 'int x' not 'auto int x'

--- Storage Classes Summary ---
| Keyword  | Scope    | Lifetime    | Default Init |
|----------|----------|-------------|-------------|
| auto     | Block    | Block       | Garbage     |
| static   | Block    | Program     | Zero        |
| extern   | Global   | Program     | Zero        |
| register | Block    | Block       | Garbage     |
```

## Key Takeaways

- `auto` is the default storage class for local variables
- You almost never need to write `auto` explicitly
- Auto variables are created/destroyed with their block
- Auto variables are NOT initialized by default
- Auto variables are stored on the stack
- C++ has a different `auto` (type inference) — don't confuse them
- Each storage class declaration can have only one specifier

## Challenge

Compare the assembly generated for a function with `auto int x = 0` vs just `int x = 0` using `gcc -S`. Are they identical? Now try with `-O2` optimization.

## Related

- [[028-static-variables]] — static storage class
- [[029-register-hint]] — register hint
- [[030-extern-declaration]] — extern linkage
