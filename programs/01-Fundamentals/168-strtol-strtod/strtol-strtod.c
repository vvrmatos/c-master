/*
 * strtol, strtod - safer string to number conversions
 * Provides error detection and overflow handling
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(void) {
    char *endptr;
    long val;
    double dval;

    // Basic strtol usage
    printf("strtol examples:\n");
    val = strtol("42", &endptr, 10);
    printf("  \"42\" -> %ld (endptr: '%s')\n", val, endptr);

    val = strtol("  -17abc", &endptr, 10);
    printf("  \"  -17abc\" -> %ld (endptr: '%s')\n", val, endptr);

    // Error detection
    printf("\nError detection:\n");
    
    // Case 1: No digits
    errno = 0;
    val = strtol("abc", &endptr, 10);
    if (endptr == "abc") {  // No conversion performed
        printf("  \"abc\" -> No digits found\n");
    }

    // Case 2: Partial conversion
    val = strtol("123xyz", &endptr, 10);
    if (*endptr != '\0') {
        printf("  \"123xyz\" -> Partial: %ld, remaining: '%s'\n", val, endptr);
    }

    // Case 3: Overflow detection
    errno = 0;
    val = strtol("99999999999999999999", &endptr, 10);
    if (errno == ERANGE) {
        printf("  Overflow detected! Result clamped to %ld\n", val);
    }

    // Different bases
    printf("\nDifferent bases:\n");
    printf("  \"FF\" base 16 -> %ld\n", strtol("FF", NULL, 16));
    printf("  \"0xFF\" base 0 -> %ld\n", strtol("0xFF", NULL, 0));  // Auto-detect
    printf("  \"0777\" base 0 -> %ld\n", strtol("0777", NULL, 0));  // Octal
    printf("  \"1010\" base 2 -> %ld\n", strtol("1010", NULL, 2));  // Binary

    // strtod for floating-point
    printf("\nstrtod examples:\n");
    dval = strtod("3.14159", &endptr);
    printf("  \"3.14159\" -> %f\n", dval);
    
    dval = strtod("1.5e10", &endptr);
    printf("  \"1.5e10\" -> %e\n", dval);

    return 0;
}
