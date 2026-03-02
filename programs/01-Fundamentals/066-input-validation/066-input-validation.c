#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int validate_int(const char *str, int *result) {
    char *endptr;
    errno = 0;
    long val = strtol(str, &endptr, 10);
    if (errno != 0 || endptr == str || *endptr != '\0')
        return 0;
    *result = (int)val;
    return 1;
}

int main(void) {
    char input1[] = "42";
    char input2[] = "abc";
    char input3[] = "123abc";
    int num;

    if (validate_int(input1, &num))
        printf("Valid: %d\n", num);
    else
        printf("Invalid\n");

    if (validate_int(input2, &num))
        printf("Valid: %d\n", num);
    else
        printf("Invalid\n");

    char *endptr;
    long val = strtol(input3, &endptr, 10);
    printf("Parsed: %ld, remaining: '%s'\n", val, endptr);

    return 0;
}

