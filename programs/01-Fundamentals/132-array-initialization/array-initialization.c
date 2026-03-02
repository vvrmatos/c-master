#include <stdio.h>

int main(void) {
    int arr[] = {1, 2, 3};
    int nums[5] = {10, 20, 30, 40, 50};
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    
    printf("arr: %d, %d, %d\n", arr[0], arr[1], arr[2]);
    printf("nums: %d, %d, %d, %d, %d\n", 
           nums[0], nums[1], nums[2], nums[3], nums[4]);
    printf("vowels: %c, %c, %c, %c, %c\n", 
           vowels[0], vowels[1], vowels[2], vowels[3], vowels[4]);
    
    return 0;
}
