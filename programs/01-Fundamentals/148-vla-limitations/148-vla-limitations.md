# 148 - VLA Limitations: Stack Allocation and No Initialization

## Overview
While VLAs are convenient, they have significant limitations that make them unsuitable for many use cases. Understanding these limitations is crucial for writing safe C code.

## Limitation 1: No Initializer Lists

```c
int n = 5;
int arr[n];              // OK - VLA declared
int arr[n] = {1,2,3};    // ERROR! Cannot initialize VLA

// Must initialize manually:
for (int i = 0; i < n; i++) {
    arr[i] = 0;
}
// Or use memset:
memset(arr, 0, n * sizeof(int));
```

## Limitation 2: Stack Allocation

```c
void risky_function(int n) {
    int huge[n];  // Allocated on stack!
    // If n is large, STACK OVERFLOW
}

// Stack is typically 1-8 MB
// int arr[1000000] uses ~4 MB - dangerous!
```

### Safe Alternatives
```c
// Use heap for large/unknown sizes
int *arr = malloc(n * sizeof(int));
if (arr == NULL) {
    // Handle allocation failure
}
// ... use arr ...
free(arr);
```

## Limitation 3: No Static Storage

```c
int n = 10;
static int arr[n];   // ERROR: VLA cannot be static
extern int arr2[n];  // ERROR: VLA cannot be extern
```

## Limitation 4: Optional in C11

```c
#ifdef __STDC_NO_VLA__
    #error "VLAs not supported"
#endif
```

## Limitation 5: No Allocation Failure Detection

```c
int arr[n];  // If stack overflow, program crashes
             // No way to check if allocation succeeded
             
// Contrast with malloc:
int *ptr = malloc(n * sizeof(int));
if (ptr == NULL) {
    // Handle gracefully
}
```

## Comparison: VLA vs malloc

| Feature | VLA | malloc |
|---------|-----|--------|
| Size limit | Stack (~1-8MB) | Heap (GBs) |
| Failure handling | Crash | Returns NULL |
| Initialization | Manual | Can use calloc |
| Cleanup | Automatic | Manual free() |
| Speed | Faster | Slower |
| Portability | C99/C11 optional | Always available |

---

# Kata Challenge

## Challenge: Safe Array Allocator
Write a program that:
1. Asks user for array size
2. If size <= 1000, use VLA
3. If size > 1000, use malloc
4. Demonstrates both paths work correctly
5. Properly handles malloc failure

## Requirements
- Implement `safe_allocate()` function
- Zero-initialize all elements
- Print which allocation method was used
- Free heap memory if used

## Expected Output
```
Enter array size: 500
Using VLA (stack allocation)
Array initialized with 500 zeros
Sum: 0

Enter array size: 10000
Using malloc (heap allocation)
Array initialized with 10000 zeros
Sum: 0
Memory freed
```

## Starter Code
```c
#define VLA_THRESHOLD 1000

void process_data(int n) {
    int use_heap = (n > VLA_THRESHOLD);
    
    if (use_heap) {
        // malloc path
    } else {
        // VLA path
    }
}
```

## Bonus
- Add timing comparison between VLA and malloc
- Implement a custom stack size checker
