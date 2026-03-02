#include <stdio.h>

int main(void) {
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    printf("Max of %d and %d is %d\n", a, b, max);
    
    int x = 5;
    printf("%d is %s\n", x, (x % 2 == 0) ? "even" : "odd");
    
    int score = 85;
    char *result = (score >= 60) ? "Pass" : "Fail";
    printf("Result: %s\n", result);
    
    return 0;
}
