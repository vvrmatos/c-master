#include <stdio.h>

int main(void) {
    int count = 1;
    
    while (count <= 5) {
        printf("Count: %d\n", count);
        count++;
    }
    
    int sum = 0, n = 1;
    while (n <= 100) {
        sum += n;
        n++;
    }
    printf("Sum 1-100: %d\n", sum);
    
    return 0;
}
