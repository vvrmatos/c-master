# strrchr - Find Last Character in String

## Overview
`strrchr` (string reverse character) searches for the last occurrence of a character in a string. Essential for path and filename manipulation.

## Function Signature
```c
char *strrchr(const char *s, int c);
```

## Parameters
- **s**: String to search
- **c**: Character to find (passed as int, converted to char)

## Return Value
- Pointer to last occurrence of character
- NULL if character not found

## Comparison: strchr vs strrchr

| Function | Direction | Use Case |
|----------|-----------|----------|
| strchr | First occurrence | Find delimiter start |
| strrchr | Last occurrence | Extract filename, extension |

## Common Use Cases

### Extract Filename from Path
```c
const char *path = "/home/user/file.txt";
char *filename = strrchr(path, '/');
if (filename) {
    filename++;  // Skip the '/'
    printf("Filename: %s\n", filename);
}
```

### Extract File Extension
```c
char *ext = strrchr(filename, '.');
if (ext) {
    printf("Extension: %s\n", ext + 1);
}
```

### Get Directory Path
```c
char path_copy[256];
strcpy(path_copy, path);
char *last_slash = strrchr(path_copy, '/');
if (last_slash) {
    *last_slash = '\0';  // Truncate at last slash
    printf("Directory: %s\n", path_copy);
}
```

## Edge Cases
- No slash in path → strrchr returns NULL
- Hidden files (.bashrc) → extension is whole name after dot
- Multiple extensions (.tar.gz) → only gets last extension

## Compilation
```bash
gcc -o strrchr strrchr.c
./strrchr
```

---

# Kata Challenge: Path Manipulation Library

## Objective
Create a comprehensive path manipulation library using strrchr.

## Requirements
1. Extract filename from full path
2. Extract directory from full path
3. Extract and validate file extension
4. Handle both Unix (/) and Windows (\) paths

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char directory[256];
    char filename[128];
    char basename[128];  // filename without extension
    char extension[32];
} PathParts;

PathParts parse_path(const char *path) {
    PathParts parts = {0};
    
    // TODO: Find last path separator (/ or \)
    // TODO: Extract directory
    // TODO: Extract filename
    // TODO: Find extension using strrchr
    // TODO: Extract basename
    
    return parts;
}

char *get_extension(const char *path) {
    // TODO: Return extension or empty string
    return NULL;
}

bool has_extension(const char *path, const char *ext) {
    // TODO: Check if path has given extension (case-insensitive)
    return false;
}

int main(void) {
    const char *paths[] = {
        "/home/user/documents/report.pdf",
        "C:\\Users\\John\\file.txt",
        "README",
        ".gitignore",
        "archive.tar.gz",
        NULL
    };
    
    for (int i = 0; paths[i]; i++) {
        PathParts p = parse_path(paths[i]);
        printf("\nPath: %s\n", paths[i]);
        printf("  Directory: %s\n", p.directory);
        printf("  Filename: %s\n", p.filename);
        printf("  Basename: %s\n", p.basename);
        printf("  Extension: %s\n", p.extension);
    }
    
    return 0;
}
```

## Expected Output
```
Path: /home/user/documents/report.pdf
  Directory: /home/user/documents
  Filename: report.pdf
  Basename: report
  Extension: pdf
```

## Bonus Challenges
1. Normalize paths (convert \ to /, remove double slashes)
2. Resolve relative paths (handle . and ..)
3. Join paths safely
4. Check if path is absolute or relative

## Test Cases
- "/path/to/file.txt" → dir="/path/to", file="file.txt", ext="txt"
- "file" → dir="", file="file", ext=""
- ".hidden" → dir="", file=".hidden", ext="hidden" or ""?
