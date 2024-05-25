#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    // Declaring and initializing an integer array
    int arr[4] = {1, 2, 3, 4};
    
    printf("arr[0] = %d\n", arr[0]); // Printing the content of the array at zeroeth index
    printf("memory address of arr[0] = %p\n", (void *)&arr[0]);
        
    return EXIT_SUCCESS;
}
