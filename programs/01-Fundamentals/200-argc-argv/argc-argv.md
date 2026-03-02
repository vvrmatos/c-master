# Command Line Arguments (argc/argv)

## Overview
Command line arguments allow users to pass data to a program when launching it. The `main` function receives these through `argc` (argument count) and `argv` (argument vector).

## Key Concepts

### Function Signature
```c
int main(int argc, char *argv[])
// or equivalently:
int main(int argc, char **argv)
```

### argc and argv
- **argc**: Number of arguments (always ≥ 1)
- **argv**: Array of C strings (null-terminated)
- **argv[0]**: Program name
- **argv[argc]**: Always NULL

### Example
```bash
./myprogram hello world 123
```
```
argc = 4
argv[0] = "./myprogram"
argv[1] = "hello"
argv[2] = "world"
argv[3] = "123"
argv[4] = NULL
```

### Converting Arguments
Arguments are always strings. Convert as needed:
```c
int num = atoi(argv[1]);       // String to int
long big = atol(argv[1]);      // String to long
double d = atof(argv[1]);      // String to double
int n = strtol(argv[1], NULL, 10);  // Better: with error checking
```

### Common Patterns

**Checking argument count:**
```c
if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
}
```

**Iterating arguments:**
```c
for (int i = 1; i < argc; i++) {
    printf("Arg %d: %s\n", i, argv[i]);
}
```

**Flag detection:**
```c
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0) {
        verbose = 1;
    } else if (strcmp(argv[i], "-h") == 0) {
        print_help();
    }
}
```

### Memory Layout
```
argv: [ptr0][ptr1][ptr2][NULL]
        |     |     |
        v     v     v
      "prog" "arg1" "arg2"
```

---

# Kata Challenge

## Challenge: Mini Grep Tool

Create a simple grep-like tool that searches for a pattern in provided text arguments.

### Requirements
1. Program name: `minigrep`
2. Usage: `./minigrep <pattern> <text1> [text2] [text3] ...`
3. Print each text argument that contains the pattern
4. Case-insensitive search (bonus)
5. Return 0 if found, 1 if not found

### Example
```bash
./minigrep cat "The cat sat" "Dogs bark" "Cats meow"
```
Output:
```
Match: "The cat sat"
Match: "Cats meow"
Found 2 matches
```

### Hints
- Use `strstr()` for substring search
- For case-insensitive: convert both strings to lowercase first

### Bonus Challenges
1. Add `-i` flag for case-insensitive search
2. Add `-c` flag to just count matches
3. Add `-n` flag to show argument index

### Starter Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void to_lower(char *str, char *dest) {
    while (*str) {
        *dest++ = tolower(*str++);
    }
    *dest = '\0';
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pattern> <text1> [text2] ...\n", argv[0]);
        return 1;
    }
    
    char *pattern = argv[1];
    int matches = 0;
    
    // Your code here
    
    return (matches > 0) ? 0 : 1;
}
```

### Expected Output
```bash
$ ./minigrep hello "hello world" "goodbye" "Hello there"
Match in arg 2: "hello world"
Match in arg 4: "Hello there"
Found 2 matches

$ ./minigrep xyz "abc" "def"
No matches found
```

### Extended Challenge
Create a more advanced version with these features:
- Read from files if filenames are provided
- Support regex patterns
- Count occurrences within each match
- Highlight the matched portion
