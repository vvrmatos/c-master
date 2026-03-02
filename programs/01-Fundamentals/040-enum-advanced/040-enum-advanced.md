---
id: "040"
title: "Advanced Enum Usage"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - enum
  - bit-flags
  - patterns
difficulty: intermediate
source: "C11 Standard Section 6.7.2.2"
---

# 040 — Advanced Enum Usage

## Concept

Enums can be customized with explicit values, used as bit flags, and combined with typedef for cleaner code. These patterns are essential for system programming and API design.

**Explicit values:**
```c
enum HttpStatus { OK = 200, NOT_FOUND = 404 };
```

**Bit flags pattern:**
```c
enum Flags {
    FLAG_A = 1 << 0,  // 1
    FLAG_B = 1 << 1,  // 2
    FLAG_C = 1 << 2   // 4
};
int flags = FLAG_A | FLAG_C;  // Combine with OR
```

**Operations with bit flags:**
- Set flag: `flags |= FLAG_A`
- Clear flag: `flags &= ~FLAG_A`
- Toggle flag: `flags ^= FLAG_A`
- Check flag: `if (flags & FLAG_A)`

> **Security Application**: Bit flags are ubiquitous in system programming — file permissions (rwx), socket options, process flags, capability bits. Understanding this pattern is crucial for security tools.

## Code

```c
#include <stdio.h>

enum HttpStatus {
    HTTP_OK = 200,
    HTTP_CREATED = 201,
    HTTP_ACCEPTED = 202,
    HTTP_NO_CONTENT = 204,
    HTTP_MOVED = 301,
    HTTP_FOUND = 302,
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_FORBIDDEN = 403,
    HTTP_NOT_FOUND = 404,
    HTTP_INTERNAL_ERROR = 500,
    HTTP_NOT_IMPLEMENTED = 501,
    HTTP_BAD_GATEWAY = 502
};

enum Permission {
    PERM_NONE    = 0,
    PERM_READ    = 1 << 0,
    PERM_WRITE   = 1 << 1,
    PERM_EXECUTE = 1 << 2,
    PERM_DELETE  = 1 << 3,
    PERM_ADMIN   = 1 << 4,
    
    PERM_RW      = PERM_READ | PERM_WRITE,
    PERM_RWX     = PERM_READ | PERM_WRITE | PERM_EXECUTE,
    PERM_ALL     = PERM_READ | PERM_WRITE | PERM_EXECUTE | PERM_DELETE | PERM_ADMIN
};

enum MixedValues {
    ZERO,
    ONE,
    TEN = 10,
    ELEVEN,
    TWELVE,
    HUNDRED = 100,
    HUNDRED_ONE
};

typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_CRITICAL
} LogLevel;

void print_permissions(int perms) {
    printf("   Permissions: ");
    if (perms == PERM_NONE) {
        printf("NONE");
    } else {
        if (perms & PERM_READ) printf("READ ");
        if (perms & PERM_WRITE) printf("WRITE ");
        if (perms & PERM_EXECUTE) printf("EXECUTE ");
        if (perms & PERM_DELETE) printf("DELETE ");
        if (perms & PERM_ADMIN) printf("ADMIN ");
    }
    printf("\n");
}

int main(void) {
    printf("=== Advanced Enum Usage ===\n\n");
    
    printf("1. Explicit values (HTTP status codes):\n");
    printf("   HTTP_OK = %d\n", HTTP_OK);
    printf("   HTTP_NOT_FOUND = %d\n", HTTP_NOT_FOUND);
    printf("   HTTP_INTERNAL_ERROR = %d\n", HTTP_INTERNAL_ERROR);
    
    enum HttpStatus response = HTTP_OK;
    printf("\n   Response handling:\n");
    if (response >= 200 && response < 300) {
        printf("   Status %d: Success!\n", response);
    } else if (response >= 400) {
        printf("   Status %d: Error!\n", response);
    }
    
    printf("\n2. Bit flags pattern:\n");
    printf("   PERM_NONE    = %d (0b%05b)\n", PERM_NONE, PERM_NONE);
    printf("   PERM_READ    = %d (0b%05b)\n", PERM_READ, PERM_READ);
    printf("   PERM_WRITE   = %d (0b%05b)\n", PERM_WRITE, PERM_WRITE);
    printf("   PERM_EXECUTE = %d (0b%05b)\n", PERM_EXECUTE, PERM_EXECUTE);
    printf("   PERM_DELETE  = %d (0b%05b)\n", PERM_DELETE, PERM_DELETE);
    printf("   PERM_ADMIN   = %d (0b%05b)\n", PERM_ADMIN, PERM_ADMIN);
    
    printf("\n   Combined flags:\n");
    printf("   PERM_RW  = %d (0b%05b)\n", PERM_RW, PERM_RW);
    printf("   PERM_RWX = %d (0b%05b)\n", PERM_RWX, PERM_RWX);
    printf("   PERM_ALL = %d (0b%05b)\n", PERM_ALL, PERM_ALL);
    
    printf("\n3. Using bit flags:\n");
    int user_perms = PERM_READ | PERM_WRITE;
    print_permissions(user_perms);
    
    printf("\n   Adding EXECUTE permission:\n");
    user_perms |= PERM_EXECUTE;
    print_permissions(user_perms);
    
    printf("\n   Removing WRITE permission:\n");
    user_perms &= ~PERM_WRITE;
    print_permissions(user_perms);
    
    printf("\n   Checking permissions:\n");
    printf("   Has READ? %s\n", (user_perms & PERM_READ) ? "Yes" : "No");
    printf("   Has WRITE? %s\n", (user_perms & PERM_WRITE) ? "Yes" : "No");
    printf("   Has ADMIN? %s\n", (user_perms & PERM_ADMIN) ? "Yes" : "No");
    
    printf("\n4. Mixed explicit and auto values:\n");
    printf("   ZERO        = %d (auto)\n", ZERO);
    printf("   ONE         = %d (auto)\n", ONE);
    printf("   TEN         = %d (explicit)\n", TEN);
    printf("   ELEVEN      = %d (auto from TEN)\n", ELEVEN);
    printf("   TWELVE      = %d (auto)\n", TWELVE);
    printf("   HUNDRED     = %d (explicit)\n", HUNDRED);
    printf("   HUNDRED_ONE = %d (auto from HUNDRED)\n", HUNDRED_ONE);
    
    printf("\n5. Typedef enum pattern:\n");
    LogLevel level = LOG_WARNING;
    printf("   typedef enum { ... } LogLevel;\n");
    printf("   LogLevel level = LOG_WARNING; // %d\n", level);
    
    const char *level_names[] = {
        "DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"
    };
    printf("   Level name: %s\n", level_names[level]);
    
    printf("\n6. Enum array indexing:\n");
    int level_counts[5] = {0};
    level_counts[LOG_DEBUG] = 100;
    level_counts[LOG_INFO] = 50;
    level_counts[LOG_ERROR] = 5;
    printf("   level_counts[LOG_DEBUG] = %d\n", level_counts[LOG_DEBUG]);
    printf("   level_counts[LOG_INFO] = %d\n", level_counts[LOG_INFO]);
    printf("   level_counts[LOG_ERROR] = %d\n", level_counts[LOG_ERROR]);
    
    return 0;
}
```

## Output

```
=== Advanced Enum Usage ===

1. Explicit values (HTTP status codes):
   HTTP_OK = 200
   HTTP_NOT_FOUND = 404
   HTTP_INTERNAL_ERROR = 500

   Response handling:
   Status 200: Success!

2. Bit flags pattern:
   PERM_NONE    = 0 (0b00000)
   PERM_READ    = 1 (0b00001)
   PERM_WRITE   = 2 (0b00010)
   PERM_EXECUTE = 4 (0b00100)
   PERM_DELETE  = 8 (0b01000)
   PERM_ADMIN   = 16 (0b10000)

   Combined flags:
   PERM_RW  = 3 (0b00011)
   PERM_RWX = 7 (0b00111)
   PERM_ALL = 31 (0b11111)

3. Using bit flags:
   Permissions: READ WRITE 

   Adding EXECUTE permission:
   Permissions: READ WRITE EXECUTE 

   Removing WRITE permission:
   Permissions: READ EXECUTE 

   Checking permissions:
   Has READ? Yes
   Has WRITE? No
   Has ADMIN? No

4. Mixed explicit and auto values:
   ZERO        = 0 (auto)
   ONE         = 1 (auto)
   TEN         = 10 (explicit)
   ELEVEN      = 11 (auto from TEN)
   TWELVE      = 12 (auto)
   HUNDRED     = 100 (explicit)
   HUNDRED_ONE = 101 (auto from HUNDRED)

5. Typedef enum pattern:
   typedef enum { ... } LogLevel;
   LogLevel level = LOG_WARNING; // 2
   Level name: WARNING

6. Enum array indexing:
   level_counts[LOG_DEBUG] = 100
   level_counts[LOG_INFO] = 50
   level_counts[LOG_ERROR] = 5
```

## Key Takeaways

- Assign explicit values with `= value`
- Auto-increment continues from last explicit value
- Bit flags: use `1 << n` for powers of 2
- Set: `|=`, Clear: `&= ~`, Check: `& flag`
- Combine values in enum definition with `|`
- Use typedef for cleaner syntax
- Enums work well as array indices

## Challenge

Create a file permissions system using enum bit flags (similar to Unix). Implement functions to check if a user has required permissions, and display permissions in rwx format.

## Related

- [[039-enumeration-enum]] — Enum basics
- [[037-define-macros]] — Alternative with #define
- [[032-octal-hex-binary-literals]] — Binary representation
