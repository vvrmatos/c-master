/*
 * Command Line Arguments (argc/argv)
 * Accessing arguments passed to the program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // argc = argument count (includes program name)
    // argv = argument vector (array of strings)
    
    printf("Program name: %s\n", argv[0]);
    printf("Argument count: %d\n\n", argc);
    
    // Print all arguments
    printf("All arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("  argv[%d] = \"%s\"\n", i, argv[i]);
    }
    
    // Example: simple calculator
    if (argc == 4) {
        int a = atoi(argv[1]);
        char op = argv[2][0];
        int b = atoi(argv[3]);
        int result;
        
        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case 'x': result = a * b; break;  // Use 'x' for multiply
            case '/': result = (b != 0) ? a / b : 0; break;
            default:
                printf("\nUnknown operator: %c\n", op);
                return 1;
        }
        
        printf("\nCalculation: %d %c %d = %d\n", a, op, b, result);
    } else if (argc > 1) {
        printf("\nUsage: %s <num1> <op> <num2>\n", argv[0]);
        printf("Example: %s 10 + 5\n", argv[0]);
    }
    
    return 0;
}
