---
id: "067"
title: "EOF and Sentinel Input"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - input
  - eof
  - sentinel
  - loops
difficulty: intermediate
source: "K&R The C Programming Language, Chapter 1"
---

# 067 — EOF and Sentinel Input

## Concept

When reading variable amounts of input, you need a way to signal "end of input." Two main approaches: **EOF** (end of file) and **sentinel values**.

**EOF (End Of File):**
- Special value indicating no more input
- Defined in `<stdio.h>`, typically -1
- Keyboard: Ctrl+D (Unix/Mac) or Ctrl+Z (Windows)
- All input functions can detect it

**Detecting EOF:**
| Function | EOF indication |
|----------|----------------|
| `getchar()` | Returns EOF |
| `scanf()` | Returns EOF (or less than expected) |
| `fgets()` | Returns NULL |
| `feof(fp)` | Returns non-zero after EOF |

**Sentinel values:**
- Special data value that means "stop"
- Chosen from invalid data range
- Examples: -1 for positive counts, empty string, "quit"

**Choosing termination method:**
| Use case | Method |
|----------|--------|
| File processing | EOF |
| Interactive menus | Sentinel ("q", 0) |
| Piped input | EOF |
| Known data range | Sentinel (value outside range) |

**Common EOF patterns:**
```c
while ((ch = getchar()) != EOF)      // Character by character
while (scanf("%d", &n) == 1)         // Until scanf fails
while (fgets(line, size, fp))        // Until NULL
```

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== EOF and Sentinel Input ===\n\n");
    
    printf("EOF (End Of File):\n");
    printf("  - Defined in <stdio.h>, typically -1\n");
    printf("  - Keyboard: Ctrl+D (Unix) or Ctrl+Z (Windows)\n");
    printf("  - Indicates end of input stream\n\n");
    
    printf("Example 1: Reading until EOF with getchar()\n");
    printf("  Enter characters (Ctrl+D/Z to end):\n  ");
    
    int ch;
    int count = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            printf("\n  ");
        }
        count++;
    }
    printf("\n  Read %d characters total\n\n", count);
    
    clearerr(stdin);
    
    printf("Example 2: Reading numbers until EOF\n");
    printf("  Enter numbers (Ctrl+D/Z to end):\n");
    
    int num;
    int sum = 0;
    int n = 0;
    
    printf("  > ");
    while (scanf("%d", &num) == 1) {
        sum += num;
        n++;
        printf("  Running sum: %d\n  > ", sum);
    }
    printf("\n  Final sum of %d numbers: %d\n\n", n, sum);
    
    clearerr(stdin);
    while (getchar() != '\n' && !feof(stdin));
    
    printf("Example 3: Sentinel value (non-EOF termination)\n");
    printf("  Enter numbers (-1 to stop):\n");
    
    int value;
    int total = 0;
    int items = 0;
    
    printf("  > ");
    while (scanf("%d", &value) == 1 && value != -1) {
        total += value;
        items++;
        printf("  > ");
    }
    printf("\n  Sum of %d items: %d\n\n", items, total);
    
    while (getchar() != '\n' && !feof(stdin));
    
    printf("Example 4: Empty line as sentinel\n");
    printf("  Enter lines (empty line to stop):\n");
    
    char line[100];
    int lines = 0;
    
    while (1) {
        printf("  [%d] ", lines + 1);
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        if (line[0] == '\n') break;
        lines++;
    }
    printf("  Read %d non-empty lines\n\n", lines);
    
    printf("Common patterns:\n");
    printf("  1. while ((ch = getchar()) != EOF)\n");
    printf("  2. while (scanf(\"%%d\", &n) == 1)\n");
    printf("  3. while (fgets(line, size, stdin) != NULL)\n");
    printf("  4. while (value != SENTINEL)\n\n");
    
    printf("Detecting EOF:\n");
    printf("  - getchar() returns EOF\n");
    printf("  - scanf() returns EOF\n");
    printf("  - fgets() returns NULL\n");
    printf("  - feof(stdin) returns true after EOF\n\n");
    
    printf("Sentinel vs EOF:\n");
    printf("  Sentinel: Special value in data (-1, 0, empty)\n");
    printf("  EOF: End of input stream itself\n");
    printf("  Use sentinel for interactive input\n");
    printf("  Use EOF for file processing\n");
    
    return 0;
}
```

## Output

```
=== EOF and Sentinel Input ===

EOF (End Of File):
  - Defined in <stdio.h>, typically -1
  - Keyboard: Ctrl+D (Unix) or Ctrl+Z (Windows)
  - Indicates end of input stream

Example 1: Reading until EOF with getchar()
  Enter characters (Ctrl+D/Z to end):
  Hello World
  
  Read 12 characters total

Example 2: Reading numbers until EOF
  Enter numbers (Ctrl+D/Z to end):
  > 10
  Running sum: 10
  > 20
  Running sum: 30
  > 30
  Running sum: 60
  > ^D
  Final sum of 3 numbers: 60

Example 3: Sentinel value (non-EOF termination)
  Enter numbers (-1 to stop):
  > 5
  > 10
  > 15
  > -1
  Sum of 3 items: 30

Example 4: Empty line as sentinel
  Enter lines (empty line to stop):
  [1] First line
  [2] Second line
  [3] 
  Read 2 non-empty lines

Common patterns:
  1. while ((ch = getchar()) != EOF)
  2. while (scanf("%d", &n) == 1)
  3. while (fgets(line, size, stdin) != NULL)
  4. while (value != SENTINEL)

Detecting EOF:
  - getchar() returns EOF
  - scanf() returns EOF
  - fgets() returns NULL
  - feof(stdin) returns true after EOF

Sentinel vs EOF:
  Sentinel: Special value in data (-1, 0, empty)
  EOF: End of input stream itself
  Use sentinel for interactive input
  Use EOF for file processing
```

## Compilation

```bash
gcc 067-eof-sentinel-input.c -o 067-eof-sentinel-input
./067-eof-sentinel-input
```

## Key Takeaways

- EOF signals end of input stream (Ctrl+D/Z)
- Sentinel is a special value meaning "stop"
- Use EOF for file processing and piped input
- Use sentinel for interactive user input
- `clearerr(stdin)` can reset EOF state
- Check function return values to detect EOF

## Challenge

Write a program that reads lines from stdin until EOF and outputs them numbered, like `cat -n`.

## Related

- [[061-getchar]] — Character input with EOF
- [[060-scanf-return-value]] — Detecting EOF with scanf
