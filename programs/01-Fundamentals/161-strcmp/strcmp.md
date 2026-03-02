# strcmp - String Comparison

## Overview
`strcmp` compares two null-terminated strings lexicographically (character by character based on ASCII values).

## Function Signature
```c
int strcmp(const char *s1, const char *s2);
```

## Return Values
- **0**: Strings are equal
- **< 0**: First string is less than second (comes before alphabetically)
- **> 0**: First string is greater than second (comes after alphabetically)

## Key Concepts

### Lexicographic Comparison
- Compares character by character using ASCII values
- Stops at first difference or null terminator
- Case-sensitive ('A' ≠ 'a')

### ASCII Order
- Uppercase letters (65-90) come before lowercase (97-122)
- Digits (48-57) come before letters
- "Apple" < "apple" because 'A' (65) < 'a' (97)

## Common Patterns
```c
// Equality check
if (strcmp(str1, str2) == 0) { /* equal */ }

// Less than
if (strcmp(str1, str2) < 0) { /* str1 comes first */ }

// Greater than
if (strcmp(str1, str2) > 0) { /* str2 comes first */ }
```

## Common Mistakes
1. Using `==` instead of `strcmp()` for string comparison
2. Forgetting that comparison is case-sensitive
3. Not checking for NULL pointers before calling

## Compilation
```bash
gcc -o strcmp strcmp.c
./strcmp
```

---

# Kata Challenge: String Comparison Utility

## Objective
Create a program that compares strings and determines their ordering.

## Requirements
1. Compare two user-provided strings
2. Report if they are equal, or which comes first
3. Handle case-sensitive and case-insensitive comparisons
4. Sort an array of strings alphabetically

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Case-insensitive comparison
int strcasecmp_custom(const char *s1, const char *s2) {
    // TODO: Implement
    return 0;
}

// Sort array of strings
void sort_strings(char *arr[], int n) {
    // TODO: Implement bubble sort using strcmp
}

int main(void) {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    scanf("%99s", str1);
    printf("Enter second string: ");
    scanf("%99s", str2);
    
    // TODO: Compare and report results
    
    return 0;
}
```

## Expected Output
```
Enter first string: Hello
Enter second string: hello
Case-sensitive: "Hello" < "hello"
Case-insensitive: "Hello" == "hello"
```

## Bonus Challenges
1. Implement natural sorting (file1, file2, file10 instead of file1, file10, file2)
2. Create a string dictionary that maintains sorted order
3. Implement a binary search on sorted strings

## Test Cases
- "abc" vs "abc" → equal
- "abc" vs "abd" → abc < abd
- "ABC" vs "abc" → ABC < abc
- "" vs "a" → "" < "a"
