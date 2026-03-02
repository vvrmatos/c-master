# strncmp - Bounded String Comparison

## Overview
`strncmp` compares at most `n` characters of two strings. It's safer than `strcmp` when dealing with buffers that may not be null-terminated.

## Function Signature
```c
int strncmp(const char *s1, const char *s2, size_t n);
```

## Parameters
- **s1, s2**: Strings to compare
- **n**: Maximum number of characters to compare

## Return Values
- **0**: First n characters are equal (or strings end before n)
- **< 0**: s1 is less than s2 within first n characters
- **> 0**: s1 is greater than s2 within first n characters

## Key Concepts

### Bounded Comparison
- Stops after comparing n characters
- Also stops if null terminator is reached before n
- Useful for prefix matching and buffer safety

### vs strcmp
| Feature | strcmp | strncmp |
|---------|--------|---------|
| Length limit | None | Yes (n) |
| Buffer safety | Requires null terminator | Can work without |
| Use case | Full comparison | Prefix/partial |

## Common Use Cases

### Prefix Checking
```c
if (strncmp(filename, "test_", 5) == 0) {
    // filename starts with "test_"
}
```

### Protocol/Command Parsing
```c
if (strncmp(input, "GET ", 4) == 0) {
    // HTTP GET request
}
```

### Safe Buffer Comparison
```c
char buffer[10];  // May not be null-terminated
if (strncmp(buffer, "MAGIC", 5) == 0) {
    // Safe even without null terminator
}
```

## Compilation
```bash
gcc -o strncmp strncmp.c
./strncmp
```

---

# Kata Challenge: Command Parser

## Objective
Create a command-line parser using strncmp for prefix matching.

## Requirements
1. Parse commands with prefixes: "get", "set", "del", "list"
2. Extract arguments after the command
3. Handle case variations
4. Handle abbreviated commands (e.g., "g" for "get")

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    CMD_GET,
    CMD_SET,
    CMD_DEL,
    CMD_LIST,
    CMD_UNKNOWN
} CommandType;

CommandType parse_command(const char *input) {
    // TODO: Use strncmp to identify command
    return CMD_UNKNOWN;
}

const char *get_argument(const char *input) {
    // TODO: Return pointer to argument after command
    return NULL;
}

int main(void) {
    char input[256];
    
    printf("Commands: get <key>, set <key> <value>, del <key>, list\n");
    
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        
        // Remove newline
        input[strcspn(input, "\n")] = '\0';
        
        if (strncmp(input, "quit", 4) == 0) break;
        
        // TODO: Parse and execute command
    }
    
    return 0;
}
```

## Expected Output
```
Commands: get <key>, set <key> <value>, del <key>, list
> get username
GET: key = "username"
> set username john
SET: key = "username", value = "john"
> list
LIST: showing all entries
> quit
```

## Bonus Challenges
1. Support command abbreviations (g, ge, get all work)
2. Add case-insensitive matching
3. Implement command history with up/down navigation
4. Add tab completion for commands

## Test Cases
- "get key" → CMD_GET, arg="key"
- "GET KEY" → CMD_GET, arg="KEY"
- "g key" → CMD_GET (abbreviation)
- "unknown" → CMD_UNKNOWN
