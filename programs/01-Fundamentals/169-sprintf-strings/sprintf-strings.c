/*
 * sprintf - number to string conversion
 * Format numbers into string buffers
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char buffer[100];
    int len;

    // Integer to string
    int num = 42;
    len = sprintf(buffer, "%d", num);
    printf("Integer: \"%s\" (length: %d)\n", buffer, len);

    // With formatting
    sprintf(buffer, "%08d", num);
    printf("Padded: \"%s\"\n", buffer);

    // Floating-point to string
    double pi = 3.14159265359;
    sprintf(buffer, "%f", pi);
    printf("Float default: \"%s\"\n", buffer);

    sprintf(buffer, "%.2f", pi);
    printf("Float 2 decimals: \"%s\"\n", buffer);

    sprintf(buffer, "%e", pi);
    printf("Scientific: \"%s\"\n", buffer);

    // Hexadecimal
    int hex = 255;
    sprintf(buffer, "0x%X", hex);
    printf("Hex: \"%s\"\n", buffer);

    // Building complex strings
    char name[] = "Alice";
    int age = 30;
    double salary = 75000.50;
    
    sprintf(buffer, "Name: %s, Age: %d, Salary: $%.2f", name, age, salary);
    printf("\nComplex: %s\n", buffer);

    // snprintf for safety (prevents buffer overflow)
    char small[10];
    int written = snprintf(small, sizeof(small), "Hello, World!");
    printf("\nsnprintf: \"%s\" (would need %d chars)\n", small, written);

    // Building strings incrementally
    char result[200];
    int offset = 0;
    offset += sprintf(result + offset, "Line 1\n");
    offset += sprintf(result + offset, "Line 2\n");
    offset += sprintf(result + offset, "Line 3\n");
    printf("\nIncremental:\n%s", result);

    return 0;
}
