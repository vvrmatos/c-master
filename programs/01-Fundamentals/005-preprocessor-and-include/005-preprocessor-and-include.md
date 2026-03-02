---
id: "005"
title: "Preprocessor & #include"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - preprocessor
  - include
  - headers
  - define
difficulty: beginner
source: "C11 Standard Section 6.10"
---

# 005 — Preprocessor & #include

## Concept

The **preprocessor** runs before actual compilation, transforming your source code based on special directives that start with `#`. It's a text-processing step — it doesn't understand C syntax, just text manipulation.

**Key Preprocessor Directives:**

| Directive | Purpose |
|-----------|---------|
| `#include` | Insert contents of another file |
| `#define` | Define macros (text replacement) |
| `#ifdef` / `#ifndef` | Conditional compilation |
| `#pragma` | Compiler-specific instructions |
| `#error` | Generate compilation error |

**#include Syntax:**

```c
#include <stdio.h>     // Search system include paths
#include "myheader.h"  // Search current directory first, then system paths
```

- **Angle brackets `< >`**: For standard library and system headers
- **Double quotes `" "`**: For your own project headers

**Common Standard Headers:**

| Header | Provides |
|--------|----------|
| `<stdio.h>` | printf, scanf, FILE operations |
| `<stdlib.h>` | malloc, free, exit, atoi |
| `<string.h>` | strcpy, strlen, memset |
| `<math.h>` | sin, cos, sqrt, pow |
| `<limits.h>` | INT_MAX, INT_MIN, etc. |
| `<stdbool.h>` | bool, true, false (C99) |
| `<stdint.h>` | int32_t, uint64_t, etc. (C99) |

**Note:** When using `<math.h>`, link with `-lm`: `gcc file.c -lm`

## Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265359
#define SQUARE(x) ((x) * (x))

int main(void) {
    printf("=== Preprocessor & #include Demo ===\n\n");
    
    printf("Standard headers included:\n");
    printf("  <stdio.h>  - printf, scanf, FILE\n");
    printf("  <stdlib.h> - malloc, free, exit\n");
    printf("  <string.h> - strcpy, strlen, memset\n");
    printf("  <math.h>   - sin, cos, sqrt\n\n");
    
    printf("Macro PI = %f\n", PI);
    printf("SQUARE(5) = %d\n", SQUARE(5));
    
    double x = 2.0;
    printf("sqrt(%.1f) = %f\n", x, sqrt(x));
    
    return 0;
}
```

## Compilation

```bash
gcc 005-preprocessor-and-include.c -o 005-preprocessor-and-include -lm
```

## Output

```
=== Preprocessor & #include Demo ===

Standard headers included:
  <stdio.h>  - printf, scanf, FILE
  <stdlib.h> - malloc, free, exit
  <string.h> - strcpy, strlen, memset
  <math.h>   - sin, cos, sqrt

Macro PI = 3.141593
SQUARE(5) = 25
sqrt(2.0) = 1.414214
```

## Key Takeaways

- Preprocessor runs before compilation (text processing)
- `#include <file>` — system headers
- `#include "file"` — your headers (searches locally first)
- Headers contain declarations (function prototypes, types, macros)
- `#define` creates macros (text substitution)
- Use `gcc -E` to see preprocessor output
- `<math.h>` requires `-lm` linker flag

## Challenge

1. Create a simple `myheader.h` with a `#define` and `#include "myheader.h"` in your program
2. Use `gcc -E` to see how `#include <stdio.h>` expands (it's massive!)

## Related

- [[004-compilation-process]] — Where preprocessing fits
- [[037-define-macros]] — Detailed macro coverage
- [[009-header-files-basics]] — Creating your own headers
- [[198-conditional-compilation]] — #ifdef and friends
