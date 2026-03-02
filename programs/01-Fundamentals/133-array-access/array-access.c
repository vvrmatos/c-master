#include <stdio.h>

int main(void) {
    int arr[] = {100, 200, 300, 400, 500};
    
    printf("First element:  arr[0] = %d\n", arr[0]);
    printf("Second element: arr[1] = %d\n", arr[1]);
    printf("Last element:   arr[4] = %d\n", arr[4]);
    
    arr[2] = 999;
    printf("\nAfter arr[2] = 999:\n");
    printf("Third element:  arr[2] = %d\n", arr[2]);
    
    int index = 3;
    printf("\nUsing variable index=%d: arr[%d] = %d\n", 
           index, index, arr[index]);
    
    return 0;
}
