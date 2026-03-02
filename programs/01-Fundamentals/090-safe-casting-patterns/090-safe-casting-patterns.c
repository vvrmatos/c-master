// Safe casting patterns

#include <stdio.h>
#include <limits.h>

// Safe int to short conversion
int int_to_short(int value, short *result) {
    if (value < SHRT_MIN || value > SHRT_MAX) {
        return -1;  // Overflow
    }
    *result = (short)value;
    return 0;
}

// Safe double to int conversion
int double_to_int(double value, int *result) {
    if (value < INT_MIN || value > INT_MAX) {
        return -1;  // Overflow
    }
    *result = (int)value;
    return 0;
}

int main(void) {
    // Safe narrowing conversion
    int big = 1000000;
    short small;
    if (int_to_short(big, &small) == 0) {
        printf("Converted: %d -> %d\n", big, small);
    } else {
        printf("Cannot convert %d to short (overflow)\n", big);
    }
    
    int safe_val = 100;
    if (int_to_short(safe_val, &small) == 0) {
        printf("Converted: %d -> %d\n", safe_val, small);
    }
    
    // Safe float to int
    double d = 1e15;
    int i;
    if (double_to_int(d, &i) == 0) {
        printf("Converted: %.0f -> %d\n", d, i);
    } else {
        printf("Cannot convert %.0e to int (overflow)\n", d);
    }
    
    return 0;
}
