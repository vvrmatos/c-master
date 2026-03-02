# Pass by Pointer

## Overview
C passes all arguments by value, meaning functions receive copies. To modify the original variable, pass its address (a pointer) and dereference it inside the function.

## Key Concepts

### Pass by Value vs Pass by Pointer

**Pass by Value (copy):**
```c
void increment(int x) {
    x++;  // Only modifies the copy
}

int num = 5;
increment(num);  // num is still 5
```

**Pass by Pointer (reference):**
```c
void increment(int *x) {
    (*x)++;  // Modifies original via pointer
}

int num = 5;
increment(&num);  // num is now 6
```

### Why Use Pass by Pointer?

1. **Modify caller's variables**
2. **Return multiple values**
3. **Avoid copying large structures**
4. **Dynamic memory allocation**

### Classic Swap Function
```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int x = 10, y = 20;
swap(&x, &y);  // x=20, y=10
```

### Multiple Return Values
```c
void divide(int dividend, int divisor, int *quotient, int *remainder) {
    *quotient = dividend / divisor;
    *remainder = dividend % divisor;
}

int q, r;
divide(17, 5, &q, &r);  // q=3, r=2
```

### Error Pattern
```c
int parse_int(const char *str, int *result) {
    // Parse string into result
    // Return 0 on success, -1 on error
    if (valid) {
        *result = parsed_value;
        return 0;
    }
    return -1;
}
```

## Common Mistakes
1. Forgetting to dereference: `x = 10` instead of `*x = 10`
2. Forgetting address-of: `func(num)` instead of `func(&num)`
3. Dereferencing NULL pointers

---

# Kata Challenge

## Challenge: Statistics Calculator

Write a function that calculates multiple statistics of an array in a single pass.

### Requirements
1. Function signature: 
   ```c
   void calculate_stats(int *arr, int size, int *sum, double *avg, int *min, int *max);
   ```
2. Calculate all statistics in a single iteration through the array
3. All results returned via pointer parameters
4. Handle edge case of size 0 appropriately

### Example
```c
int data[] = {4, 8, 15, 16, 23, 42};
int sum, min, max;
double avg;

calculate_stats(data, 6, &sum, &avg, &min, &max);
printf("Sum: %d\n", sum);     // 108
printf("Avg: %.2f\n", avg);   // 18.00
printf("Min: %d\n", min);     // 4
printf("Max: %d\n", max);     // 42
```

### Bonus Challenge
Add a function `void normalize_array(int *arr, int size, int *min_out, int *max_out)` that:
- Finds min and max (returns via pointers)
- Normalizes all values to 0-100 range in-place

### Starter Code
```c
#include <stdio.h>

void calculate_stats(int *arr, int size, int *sum, double *avg, int *min, int *max) {
    if (size == 0) {
        *sum = 0;
        *avg = 0.0;
        *min = 0;
        *max = 0;
        return;
    }
    
    // Your code here
}

int main(void) {
    int data[] = {4, 8, 15, 16, 23, 42};
    int sum, min, max;
    double avg;
    
    calculate_stats(data, 6, &sum, &avg, &min, &max);
    
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    
    return 0;
}
```

### Expected Output
```
Sum: 108
Average: 18.00
Min: 4
Max: 42
```
