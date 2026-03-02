# 155 - String Input: `fgets` vs `scanf %s`

## Overview
Getting string input safely in C requires understanding the pitfalls of different functions. `fgets` is generally preferred over `scanf %s` for security and flexibility.

## scanf %s - The Dangerous Way

```c
char buffer[20];
scanf("%s", buffer);  // DANGEROUS!
```

### Problems with scanf %s
1. **No bounds checking** - buffer overflow risk
2. **Stops at whitespace** - can't read "Hello World"
3. **No newline handling** - leaves `\n` in input stream
4. **No length limit by default**

### Safer scanf
```c
char buffer[20];
scanf("%19s", buffer);  // Limit to 19 chars (leave room for '\0')
```

## fgets - The Safe Way

```c
char buffer[100];
fgets(buffer, sizeof(buffer), stdin);
```

### fgets Properties
- Reads up to `n-1` characters
- Stops at newline OR buffer full
- **Includes the newline** in buffer
- Always null-terminates
- Returns NULL on error/EOF

### Removing the Newline
```c
char buffer[100];
fgets(buffer, sizeof(buffer), stdin);

// Method 1: strlen
size_t len = strlen(buffer);
if (len > 0 && buffer[len-1] == '\n') {
    buffer[len-1] = '\0';
}

// Method 2: strcspn (elegant)
buffer[strcspn(buffer, "\n")] = '\0';
```

## Comparison

| Feature | `scanf %s` | `fgets` |
|---------|-----------|---------|
| Buffer overflow | Risk | Safe |
| Reads spaces | No | Yes |
| Includes newline | No | Yes |
| Returns | Count | String/NULL |
| EOF handling | Returns EOF | Returns NULL |

## Other Input Functions

### getchar
```c
int c = getchar();  // Single character (returns int for EOF)
```

### gets (NEVER USE!)
```c
gets(buffer);  // Removed in C11 - NO bounds checking!
```

### getline (POSIX)
```c
char *line = NULL;
size_t len = 0;
getline(&line, &len, stdin);  // Allocates memory automatically
free(line);
```

## Clearing Input Buffer
```c
// After scanf, clear remaining input:
int c;
while ((c = getchar()) != '\n' && c != EOF);
```

---

# Kata Challenge

## Challenge: Robust Input Handler
Create a program with safe input functions that handle edge cases.

## Requirements
Implement:
1. `int get_line(char *buf, int size)` - safe line input, returns length
2. `int get_word(char *buf, int size)` - single word, no spaces
3. `int get_int(int *value)` - integer with validation
4. Handle empty input, too-long input, and invalid data

## Expected Output
```
=== Robust Input Demo ===

get_line test:
  Enter text: Hello World
  Got: "Hello World" (length: 11)

  Enter text: [empty - just Enter]
  Got: "" (length: 0, empty line)

  Enter text: [very long input...]
  Got: "This is a very long " (truncated, length: 20)
  Warning: Input was truncated

get_word test:
  Enter word: Hello World
  Got: "Hello" (stopped at space)
  Remaining input cleared

get_int test:
  Enter number: 42
  Got: 42

  Enter number: abc
  Error: Invalid number, try again
  Enter number: 123
  Got: 123
```

## Function Signatures
```c
int get_line(char *buffer, int max_size);   // Returns length or -1
int get_word(char *buffer, int max_size);   // Returns length or -1  
int get_int(int *value);                     // Returns 1 success, 0 fail
```

## Bonus
- Add `get_float` with validation
- Implement timeout for input
- Add input history/recall
