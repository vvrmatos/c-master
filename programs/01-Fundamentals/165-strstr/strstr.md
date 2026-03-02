# strstr - Find Substring in String

## Overview
`strstr` (string string) searches for the first occurrence of a substring within another string. It's the fundamental text search function in C.

## Function Signature
```c
char *strstr(const char *haystack, const char *needle);
```

## Parameters
- **haystack**: String to search in
- **needle**: Substring to find

## Return Value
- Pointer to first occurrence of needle
- NULL if needle not found
- Returns haystack if needle is empty

## Key Concepts

### Case Sensitivity
strstr is case-sensitive. "Hello" won't match "hello".

### Finding All Occurrences
```c
const char *p = text;
while ((p = strstr(p, pattern)) != NULL) {
    // Process match
    p += strlen(pattern);  // Or p++ for overlapping matches
}
```

### Overlapping Matches
- "ana" in "banana": with p++, finds 2 matches
- "ana" in "banana": with p += 3, finds 1 match

## Common Use Cases

### Check if String Contains Substring
```c
if (strstr(text, "error") != NULL) {
    // Text contains "error"
}
```

### Simple Search and Replace
```c
char *pos = strstr(text, old);
if (pos) {
    // Calculate lengths and rebuild string
}
```

### Parsing Key-Value
```c
char *eq = strstr(line, "=");
if (eq) {
    // Split at equals sign
}
```

## Compilation
```bash
gcc -o strstr strstr.c
./strstr
```

---

# Kata Challenge: Text Search Engine

## Objective
Build a simple text search engine using strstr.

## Requirements
1. Search for words in a text
2. Count occurrences
3. Implement case-insensitive search
4. Highlight matches in output

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Case-insensitive strstr
char *strcasestr(const char *haystack, const char *needle) {
    // TODO: Implement case-insensitive search
    return NULL;
}

// Count occurrences of substring
int count_occurrences(const char *text, const char *pattern) {
    // TODO: Count how many times pattern appears
    return 0;
}

// Find and highlight all matches
void highlight_matches(const char *text, const char *pattern) {
    // TODO: Print text with matches highlighted using [brackets]
}

// Find word (not substring of another word)
char *find_word(const char *text, const char *word) {
    // TODO: Find word with word boundaries
    return NULL;
}

int main(void) {
    const char *text = "The quick brown fox jumps over the lazy dog. "
                       "The fox is quick and the dog is lazy.";
    
    char pattern[64];
    printf("Text: %s\n\n", text);
    
    while (1) {
        printf("Search for (or 'quit'): ");
        if (scanf("%63s", pattern) != 1) break;
        if (strcmp(pattern, "quit") == 0) break;
        
        int count = count_occurrences(text, pattern);
        printf("Found %d occurrence(s)\n", count);
        
        printf("Highlighted: ");
        highlight_matches(text, pattern);
        printf("\n\n");
    }
    
    return 0;
}
```

## Expected Output
```
Search for: the
Found 3 occurrence(s)
Highlighted: [The] quick brown fox jumps over [the] lazy dog. [The] fox...

Search for: fox
Found 2 occurrence(s)
Highlighted: The quick brown [fox] jumps over the lazy dog. The [fox]...
```

## Bonus Challenges
1. Implement wildcard search (f?x matches fox, fix)
2. Add regular expression support
3. Create an index for faster repeated searches
4. Search multiple patterns at once

## Test Cases
- "aa" in "aaa" → 2 occurrences (non-overlapping) or 2 (overlapping)
- "" in "abc" → found at position 0
- "xyz" in "abc" → not found
