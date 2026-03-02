#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    /* Off-by-one: accessing arr[5] is undefined */
    printf("Correct (0 to size-1):\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    /* Wrong: <= causes one extra iteration */
    /* for (int i = 0; i <= size; i++) - BUG! */
    
    /* Wrong: starting at 1 misses first element */
    /* for (int i = 1; i < size; i++) - BUG! */
    
    printf("\nFence post: %d items, %d separators\n", size, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
    
    return 0;
}
