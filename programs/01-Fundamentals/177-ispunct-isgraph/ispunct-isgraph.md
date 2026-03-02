# ispunct and isgraph - Punctuation and Graphical Characters

## Overview
The `ispunct()` function tests if a character is punctuation, while `isgraph()` tests if a character is graphical (has visible representation). Both are part of `<ctype.h>` and help classify printable characters.

## Function Signatures
```c
#include <ctype.h>

int ispunct(int c);  // Returns non-zero if punctuation
int isgraph(int c);  // Returns non-zero if graphical (printable, non-space)
```

## Character Classification

| Function | What it matches | Excludes |
|----------|-----------------|----------|
| ispunct() | !\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ | letters, digits, space |
| isgraph() | All printable except space | space, control chars |

## Key Differences

### ispunct()
- Printable characters that are NOT:
  - Letters (A-Z, a-z)
  - Digits (0-9)
  - Space
- Includes: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~

### isgraph()
- All characters with visible representation
- Same as `isprint()` but excludes space
- Includes letters, digits, AND punctuation

## Relationship to Other Functions
```
isgraph() = isalnum() OR ispunct()
isprint() = isgraph() OR space
```

## Use Cases
- **ispunct()**: Counting punctuation, text analysis, parsing
- **isgraph()**: Checking for visible characters, trimming whitespace

## ASCII Punctuation Characters
```
! " # $ % & ' ( ) * + , - . /
: ; < = > ? @
[ \ ] ^ _ `
{ | } ~
```

---

# Kata Challenge: Text Analyzer

## Objective
Write a program that analyzes text and provides statistics about character types.

## Requirements
1. Read a line of text from the user
2. Count and display:
   - Total graphical characters
   - Punctuation marks
   - Letters
   - Digits
   - Spaces
3. Calculate percentage of each type

## Example
```
Input: Hello, World! 123
Output:
Total characters: 17
Graphical: 14 (82.4%)
Punctuation: 2 (11.8%)
Letters: 10 (58.8%)
Digits: 3 (17.6%)
Spaces: 3 (17.6%)
```

## Hints
- Use `isgraph()` for visible chars
- Use `ispunct()` for punctuation
- Use `isalpha()` and `isdigit()` for letters/digits
- Cast to float for percentage

## Bonus
- List each unique punctuation mark found
- Show frequency distribution
- Handle multi-line input
