// Short-circuit evaluation

#include <stdio.h>

int check_a(void) {
    printf("  Checking A...\n");
    return 0;  // false
}

int check_b(void) {
    printf("  Checking B...\n");
    return 1;  // true
}

int main(void) {
    printf("AND short-circuit (false && ?):\n");
    if (check_a() && check_b()) {
        printf("Both true\n");
    } else {
        printf("  B was NOT checked!\n\n");
    }
    
    printf("OR short-circuit (true || ?):\n");
    if (check_b() || check_a()) {
        printf("  A was NOT checked!\n\n");
    }
    
    // Practical use: safe pointer dereference
    int *ptr = NULL;
    if (ptr != NULL && *ptr > 0) {
        printf("Value is positive\n");
    } else {
        printf("Safe: didn't dereference NULL\n");
    }
    
    // Practical use: bounds check before access
    int arr[] = {10, 20, 30};
    int index = 5;
    if (index >= 0 && index < 3 && arr[index] > 0) {
        printf("arr[%d] = %d\n", index, arr[index]);
    } else {
        printf("Safe: didn't access out of bounds\n");
    }
    
    return 0;
}
