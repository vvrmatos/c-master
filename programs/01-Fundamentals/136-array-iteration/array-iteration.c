#include <stdio.h>

int main(void) {
    int arr[] = {5, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Forward iteration:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nBackward iteration:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nSum of elements: ");
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    
    return 0;
}
