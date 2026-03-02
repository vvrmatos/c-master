# Void Pointer - Generic void*

## Overview
A `void*` (void pointer) is a generic pointer that can hold the address of any data type. It provides flexibility but requires explicit casting before dereferencing.

## Declaration
```c
void *ptr;  // Can point to anything
```

## Key Properties

### 1. Universal Assignment
```c
int i = 10;
float f = 3.14;
char c = 'A';

void *vp;
vp = &i;  // OK - no cast needed
vp = &f;  // OK
vp = &c;  // OK
```

### 2. Requires Cast to Dereference
```c
void *vp = &i;
// printf("%d", *vp);     // ERROR: can't dereference void*
printf("%d", *(int*)vp);  // OK: cast then dereference
```

### 3. No Pointer Arithmetic
```c
void *vp;
// vp + 1;  // ERROR: size unknown, can't do arithmetic
```

## Common Uses

### Generic Functions
```c
void *memcpy(void *dest, const void *src, size_t n);
void *malloc(size_t size);
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
```

### Callback Data
```c
void register_callback(void (*fn)(void*), void *user_data);
```

### Type-Agnostic Storage
```c
struct Any {
    void *data;
    char type;  // Track actual type
};
```

## Casting Patterns
```c
void *vp = malloc(sizeof(int));

// Cast to appropriate pointer type
int *ip = (int*)vp;
*ip = 42;

// Or cast when dereferencing
*(int*)vp = 42;
```

## Safety Considerations
- Compiler can't check type correctness
- Programmer responsible for correct casting
- Easy to make mistakes (no type safety)

---

# Kata Challenge: Generic Container

## Objective
Create a simple generic container using void pointers that can store values of any type.

## Requirements
1. Create a `Container` struct with:
   - `void *data` - the stored value
   - `size_t size` - size of the stored data
   - `char type` - type identifier
2. Implement functions:
   - `container_create(void *value, size_t size, char type)`
   - `container_get(Container *c, void *out)`
   - `container_print(Container *c)`
   - `container_destroy(Container *c)`
3. Support at least: int, float, double, char, string

## Example Output
```
=== Generic Container Demo ===

Storing int 42...
Container[int]: 42

Storing float 3.14...
Container[float]: 3.140000

Storing string "Hello"...
Container[string]: Hello

=== Array of Mixed Types ===
containers[0]: int = 100
containers[1]: float = 2.718
containers[2]: char = 'X'
containers[3]: string = "World"
```

## Hints
- Use `malloc` to copy data into container
- Store size for proper memory operations
- Use type identifier for correct casting when printing

## Bonus
- Add comparison function for containers
- Implement container array operations
- Add serialization to/from bytes
- Create a simple type-safe wrapper macro
