#include <stdio.h>   // Include standard I/O functions
#include <stdlib.h>  // Include standard library functions (though not used here)
#include <string.h>  // Include string manipulation functions

int main(int argc, char *argv[]) {  // Main function with command-line arguments
    // Initialize integer arrays
    int arr_1[] = { 1, 2 };
    int arr_2[] = { 1, 2 };
    int arr_3[] = { 1, 1 };

    // Initialize strings
    char str_1[50] = "Arrays are the same";
    char str_2[50] = "Arrays are not the same";
    
    // Uncomment the following line to print the size of an integer in bytes
    // printf("%lu", sizeof(int));
    
    // Comparing arr_1 and arr_2 (similar arrays)
    if (memcmp(arr_1, arr_2, 2 * sizeof(int)) == 0) {  // memcmp compares byte by byte
        printf("%s\n", str_1);  // Print if arrays are the same
    } else {
        printf("%s\n", str_2);  // Print if arrays are not the same
    }
    
    // Comparing arr_1 and arr_3 (different arrays)
    if (memcmp(arr_1, arr_3, 2 * sizeof(int)) == 0) {  // memcmp compares byte by byte
        printf("%s\n", str_1);  // Print if arrays are the same
    } else {
        printf("%s\n", str_2);  // Print if arrays are not the same
    }
    
    return 0;  // Return 0 indicating successful execution
}
