#include <stdio.h>

int main(void) {
    char op = '%';
    int a = 10, b = 3;
    
    switch (op) {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            printf("%d / %d = %d\n", a, b, a / b);
            break;
        default:
            printf("Unknown operator: %c\n", op);
    }
    
    return 0;
}
