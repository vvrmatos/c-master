# 138 - C99 Designated Initializers

## Overview
**Designated initializers** (C99) allow specifying array indices in initialization lists with `[index] = value` syntax. This enables sparse initialization and self-documenting code.

## Syntax
```c
type arr[size] = {
    [index1] = value1,
    [index2] = value2,
    ...
};
```

## Basic Examples

### Specific Indices
```c
int arr[5] = {[2] = 20, [4] = 40};
/* Result: {0, 0, 20, 0, 40} */
```

### Out of Order
```c
int arr[4] = {[3] = 3, [1] = 1, [0] = 0, [2] = 2};
/* Result: {0, 1, 2, 3} */
```

### Single Element
```c
int arr[100] = {[50] = 500};
/* arr[50] = 500, all others = 0 */
```

## Mixed Initialization

### Designated + Sequential
```c
int arr[6] = {1, 2, [4] = 40, 50};
/* arr[0] = 1 */
/* arr[1] = 2 */
/* arr[2] = 0 (skipped) */
/* arr[3] = 0 (skipped) */
/* arr[4] = 40 (designated) */
/* arr[5] = 50 (continues from [4]) */
```

After a designated initializer, subsequent values continue from that index.

### Multiple Designations
```c
int arr[10] = {
    [0] = 100,
    [3] = 300,
    [7] = 700
};
/* {100, 0, 0, 300, 0, 0, 0, 700, 0, 0} */
```

## Size Inference

The compiler can infer array size from the largest index:

```c
int arr[] = {[5] = 50, [2] = 20};
/* Size is 6 (indices 0-5) */
/* {0, 0, 20, 0, 0, 50} */
```

```c
int arr[] = {[99] = 99};
/* Size is 100! */
```

## Using Enums as Indices

Perfect for creating lookup tables:

```c
enum Color { RED, GREEN, BLUE, NUM_COLORS };

int rgb_values[NUM_COLORS] = {
    [RED]   = 0xFF0000,
    [GREEN] = 0x00FF00,
    [BLUE]  = 0x0000FF
};
```

```c
enum Weekday { SUN, MON, TUE, WED, THU, FRI, SAT };

const char *day_names[] = {
    [SUN] = "Sunday",
    [MON] = "Monday",
    [TUE] = "Tuesday",
    [WED] = "Wednesday",
    [THU] = "Thursday",
    [FRI] = "Friday",
    [SAT] = "Saturday"
};
```

## Sparse Arrays

Initialize only needed elements:

```c
/* Character conversion table */
int digit_value[128] = {
    ['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3, ['4'] = 4,
    ['5'] = 5, ['6'] = 6, ['7'] = 7, ['8'] = 8, ['9'] = 9,
    ['a'] = 10, ['b'] = 11, ['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15,
    ['A'] = 10, ['B'] = 11, ['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15
};

int hex_val = digit_value['A'];  /* 10 */
```

## Range Designation (GCC Extension)

GCC allows range designation (not standard C):

```c
/* GCC only */
int arr[100] = {[0 ... 9] = 1, [10 ... 19] = 2};
```

For standard C, use individual designators or loops.

## Override Behavior

Later initializers override earlier ones:

```c
int arr[3] = {[0] = 10, [0] = 20};
/* arr[0] = 20 (last wins) */
```

```c
int arr[5] = {1, 2, 3, [0] = 100};
/* {100, 2, 3, 0, 0} - [0] overrides the first 1 */
```

## Practical Applications

### Error Messages Table
```c
enum ErrorCode { OK = 0, FILE_NOT_FOUND = 1, PERMISSION_DENIED = 2 };

const char *error_msgs[] = {
    [OK] = "Success",
    [FILE_NOT_FOUND] = "File not found",
    [PERMISSION_DENIED] = "Permission denied"
};
```

### State Machine Actions
```c
enum State { IDLE, RUNNING, PAUSED, STOPPED };

void (*actions[])(void) = {
    [IDLE] = idle_handler,
    [RUNNING] = run_handler,
    [PAUSED] = pause_handler,
    [STOPPED] = stop_handler
};
```

### Character Properties
```c
int is_vowel[128] = {
    ['a'] = 1, ['e'] = 1, ['i'] = 1, ['o'] = 1, ['u'] = 1,
    ['A'] = 1, ['E'] = 1, ['I'] = 1, ['O'] = 1, ['U'] = 1
};

if (is_vowel[(int)c]) { /* it's a vowel */ }
```

### Days in Month
```c
enum Month { JAN=1, FEB, MAR, APR, MAY, JUN, 
             JUL, AUG, SEP, OCT, NOV, DEC };

int days[13] = {
    [JAN] = 31, [FEB] = 28, [MAR] = 31, [APR] = 30,
    [MAY] = 31, [JUN] = 30, [JUL] = 31, [AUG] = 31,
    [SEP] = 30, [OCT] = 31, [NOV] = 30, [DEC] = 31
};
/* days[0] unused, days[1-12] have values */
```

## Benefits

1. **Self-documenting**: Index meaning is clear
2. **Order-independent**: Initialize in logical order
3. **Sparse-friendly**: Skip unused indices
4. **Maintainable**: Adding enums doesn't break initialization
5. **Safe**: Compiler catches out-of-bounds indices

## Limitations

1. **Index must be constant expression**
   ```c
   int i = 5;
   int arr[10] = {[i] = 50};  /* Error! */
   ```

2. **Cannot use variables**
   ```c
   int arr[] = {[rand()] = 1};  /* Error! */
   ```

3. **C99 or later required**
   - Not available in C89/C90

---

## Kata Challenge

### Challenge: Lookup Table with Designated Initializers

**Task**: Create a character classification system using designated initializers.

**Requirements**:
1. Create an enum for character types (UNKNOWN, DIGIT, UPPER, LOWER, SPACE, PUNCT)
2. Initialize a lookup table `char_type[128]` using designated initializers
3. Test the table with various characters
4. Count each type in a test string

**Expected Output**:
```
Character types:
  'A' = UPPER
  'a' = LOWER
  '5' = DIGIT
  ' ' = SPACE
  '.' = PUNCT
  '@' = UNKNOWN

Analyzing "Hello, World! 123":
  UPPER: 2
  LOWER: 8
  DIGIT: 3
  SPACE: 2
  PUNCT: 2
  UNKNOWN: 0
```

**Starter Code**:
```c
#include <stdio.h>

enum CharType { UNKNOWN, DIGIT, UPPER, LOWER, SPACE, PUNCT };

const char *type_names[] = {
    [UNKNOWN] = "UNKNOWN",
    [DIGIT] = "DIGIT",
    /* Add rest */
};

int char_type[128] = {
    /* Use designated initializers for each character class */
};

int main(void) {
    const char *test = "Hello, World! 123";
    
    /* Classify and count */
    
    return 0;
}
```

---
**Difficulty**: ⭐⭐ (Easy)  
**Time**: 20 minutes  
**Topics**: Arrays, Designated Initializers, Enums
