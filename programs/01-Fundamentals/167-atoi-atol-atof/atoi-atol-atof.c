/*
 * atoi, atol, atof - string to number conversion
 * Simple conversion functions (no error checking)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // atoi - ASCII to integer
    printf("atoi examples:\n");
    printf("  atoi(\"42\") = %d\n", atoi("42"));
    printf("  atoi(\"-17\") = %d\n", atoi("-17"));
    printf("  atoi(\"  123\") = %d\n", atoi("  123"));      // Skips whitespace
    printf("  atoi(\"456abc\") = %d\n", atoi("456abc"));    // Stops at non-digit
    printf("  atoi(\"abc\") = %d\n", atoi("abc"));          // Returns 0
    printf("  atoi(\"\") = %d\n", atoi(""));                // Returns 0

    // atol - ASCII to long
    printf("\natol examples:\n");
    printf("  atol(\"2147483647\") = %ld\n", atol("2147483647"));
    printf("  atol(\"9999999999\") = %ld\n", atol("9999999999"));

    // atof - ASCII to float (actually double)
    printf("\natof examples:\n");
    printf("  atof(\"3.14159\") = %f\n", atof("3.14159"));
    printf("  atof(\"-2.5\") = %f\n", atof("-2.5"));
    printf("  atof(\"1.5e10\") = %e\n", atof("1.5e10"));    // Scientific notation
    printf("  atof(\".5\") = %f\n", atof(".5"));            // Leading decimal
    printf("  atof(\"1.\") = %f\n", atof("1."));            // Trailing decimal

    // Demonstration of no error checking
    printf("\nDanger - no error detection:\n");
    printf("  atoi(\"99999999999999\") = %d\n", atoi("99999999999999"));  // Overflow!
    printf("  atoi(\"not a number\") = %d\n", atoi("not a number"));      // Silent 0

    return 0;
}
