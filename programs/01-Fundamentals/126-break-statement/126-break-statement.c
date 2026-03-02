#include <stdio.h>

int main(void) {
    int numbers[] = {4, 2, 7, 1, 9, 3, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 9;
    int found = 0;
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {
            printf("Found %d at index %d\n", target, i);
            found = 1;
            break;
        }
        printf("Checked index %d\n", i);
    }
    
    if (!found) {
        printf("Not found\n");
    }
    
    return 0;
}
