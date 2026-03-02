# 136 - Array Iteration: Looping Through Arrays

## Overview
**Array iteration** is the process of accessing each element in sequence. Loops combined with array indexing form the basis of most array operations.

## Basic Patterns

### Forward Iteration (For Loop)
```c
int arr[5] = {10, 20, 30, 40, 50};
size_t size = sizeof(arr) / sizeof(arr[0]);

for (size_t i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
}
```

### Backward Iteration
```c
/* Method 1: Careful with unsigned */
for (size_t i = size; i > 0; i--) {
    printf("%d\n", arr[i - 1]);
}

/* Method 2: Using signed int */
for (int i = (int)size - 1; i >= 0; i--) {
    printf("%d\n", arr[i]);
}
```

### While Loop
```c
size_t i = 0;
while (i < size) {
    printf("%d\n", arr[i]);
    i++;
}
```

### Do-While Loop
```c
size_t i = 0;
do {
    printf("%d\n", arr[i]);
    i++;
} while (i < size);  /* Be careful: executes at least once */
```

## Common Iteration Operations

### Calculate Sum
```c
int sum = 0;
for (size_t i = 0; i < size; i++) {
    sum += arr[i];
}
```

### Calculate Average
```c
double avg = 0.0;
for (size_t i = 0; i < size; i++) {
    avg += arr[i];
}
avg /= size;
```

### Find Maximum
```c
int max = arr[0];
for (size_t i = 1; i < size; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}
```

### Find Minimum
```c
int min = arr[0];
for (size_t i = 1; i < size; i++) {
    if (arr[i] < min) {
        min = arr[i];
    }
}
```

### Search for Element
```c
int target = 30;
int found_index = -1;
for (size_t i = 0; i < size; i++) {
    if (arr[i] == target) {
        found_index = (int)i;
        break;
    }
}
```

### Count Occurrences
```c
int target = 5;
int count = 0;
for (size_t i = 0; i < size; i++) {
    if (arr[i] == target) {
        count++;
    }
}
```

## Iteration with Modification

### Double All Elements
```c
for (size_t i = 0; i < size; i++) {
    arr[i] *= 2;
}
```

### Add Index to Element
```c
for (size_t i = 0; i < size; i++) {
    arr[i] += (int)i;
}
```

### Reset to Zero
```c
for (size_t i = 0; i < size; i++) {
    arr[i] = 0;
}
```

### Initialize with Pattern
```c
for (size_t i = 0; i < size; i++) {
    arr[i] = (int)(i * i);  /* Squares */
}
```

## Iteration Over Part of Array

### Starting Mid-Array
```c
for (size_t i = 5; i < size; i++) {
    printf("%d\n", arr[i]);
}
```

### Stopping Early
```c
for (size_t i = 0; i < size / 2; i++) {
    printf("%d\n", arr[i]);
}
```

### Every Other Element
```c
for (size_t i = 0; i < size; i += 2) {
    printf("%d\n", arr[i]);  /* Even indices */
}

for (size_t i = 1; i < size; i += 2) {
    printf("%d\n", arr[i]);  /* Odd indices */
}
```

## Parallel Iteration

### Two Arrays
```c
int a[5] = {1, 2, 3, 4, 5};
int b[5] = {5, 4, 3, 2, 1};

for (size_t i = 0; i < 5; i++) {
    printf("a[%zu] + b[%zu] = %d\n", i, i, a[i] + b[i]);
}
```

### Copy Array
```c
int src[5] = {10, 20, 30, 40, 50};
int dst[5];

for (size_t i = 0; i < 5; i++) {
    dst[i] = src[i];
}
```

## Common Mistakes

### 1. Off-by-One (Overshooting)
```c
/* Bug: accesses arr[5] which is out of bounds */
for (int i = 0; i <= 5; i++) {
    arr[i] = 0;
}

/* Fix */
for (int i = 0; i < 5; i++) {
    arr[i] = 0;
}
```

### 2. Wrong Size
```c
/* Bug: hardcoded wrong size */
int arr[10];
for (int i = 0; i < 5; i++) {  /* Only half */
    arr[i] = 0;
}

/* Fix: use sizeof idiom */
for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    arr[i] = 0;
}
```

### 3. Unsigned Underflow in Backward Loop
```c
/* Bug: i wraps to huge value when going below 0 */
for (size_t i = size - 1; i >= 0; i--) {  /* Always true! */
    printf("%d\n", arr[i]);
}

/* Fix */
for (size_t i = size; i > 0; i--) {
    printf("%d\n", arr[i - 1]);
}
```

## Performance Considerations

### Cache-Friendly Iteration
```c
/* Good: Sequential access */
for (size_t i = 0; i < size; i++) {
    sum += arr[i];
}

/* Less efficient: Random access */
for (size_t i = 0; i < size; i++) {
    sum += arr[random_indices[i]];
}
```

### Loop Unrolling (Manual)
```c
/* Process 4 elements at a time */
for (size_t i = 0; i + 3 < size; i += 4) {
    sum += arr[i] + arr[i+1] + arr[i+2] + arr[i+3];
}
/* Handle remaining elements */
for (size_t i = size - (size % 4); i < size; i++) {
    sum += arr[i];
}
```

---

## Kata Challenge

### Challenge: Array Analysis

**Task**: Write a program that performs complete analysis of an integer array:

**Requirements**:
1. Create an array of at least 10 integers
2. Using iteration, calculate:
   - Sum of all elements
   - Average
   - Maximum value and its index
   - Minimum value and its index
   - Count of positive, negative, and zero elements
3. Reverse the array in place

**Expected Output**:
```
Array: 5 -3 0 8 2 -1 7 0 4 -2
Sum: 20
Average: 2.00
Maximum: 8 at index 3
Minimum: -3 at index 1
Positive: 5, Negative: 3, Zero: 2
Reversed: -2 4 0 7 -1 2 8 0 -3 5
```

**Starter Code**:
```c
#include <stdio.h>

int main(void) {
    int arr[] = {5, -3, 0, 8, 2, -1, 7, 0, 4, -2};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    /* Implement analysis using iteration */
    
    return 0;
}
```

---
**Difficulty**: ⭐⭐ (Easy)  
**Time**: 20 minutes  
**Topics**: Arrays, Loops, Control Flow
