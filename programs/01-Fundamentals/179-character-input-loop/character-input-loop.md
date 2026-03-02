# Character Input Loop - Processing Characters in Loop

## Overview
Processing characters one at a time in a loop is fundamental to text processing in C. Using `getchar()` with a while loop allows efficient character-by-character input handling until end-of-file (EOF).

## The Classic Pattern
```c
int ch;
while ((ch = getchar()) != EOF) {
    // Process character
}
```

## Key Points

### Why `int` for Character?
- `getchar()` returns `int`, not `char`
- EOF is typically -1, outside char range
- Using `char` can cause infinite loops

### EOF (End of File)
- Signals no more input available
- Keyboard: Ctrl+D (Unix) or Ctrl+Z (Windows)
- Files: End of file reached

## Input Methods Comparison

| Function | Returns | Reads |
|----------|---------|-------|
| getchar() | int | Single character |
| fgetc(file) | int | Character from file |
| scanf("%c", &c) | int | Single character |
| fgets(buf, n, stdin) | char* | Line into buffer |

## Common Patterns

### Count characters
```c
int count = 0;
while (getchar() != EOF) count++;
```

### Copy input to output
```c
int ch;
while ((ch = getchar()) != EOF) putchar(ch);
```

### Process until newline
```c
while ((ch = getchar()) != '\n' && ch != EOF) {
    // Process line
}
```

## Loop Termination
- EOF from input
- Specific character (newline, sentinel)
- Counter limit
- Condition met

---

# Kata Challenge: Character Statistics

## Objective
Write a program that reads text and produces comprehensive character statistics.

## Requirements
1. Read characters until EOF
2. Count:
   - Total characters
   - Uppercase letters
   - Lowercase letters
   - Digits
   - Whitespace (space, tab, newline separately)
   - Punctuation
3. Track line count
4. Find most frequent character

## Example
```
Input:
Hello World!
123 Test.
[Ctrl+D]

Output:
=== Character Statistics ===
Total characters: 23
Lines: 2

Letters: 13
  Uppercase: 3
  Lowercase: 10

Digits: 3
Whitespace: 3
  Spaces: 2
  Newlines: 2
Punctuation: 2

Most frequent: 'l' (3 times)
```

## Hints
- Use an array to count frequency of each character (256 slots)
- Increment line count on '\n'
- Use ctype.h functions for classification

## Bonus
- Show character frequency histogram
- Calculate average word length
- Detect and count words
- Support reading from file argument
