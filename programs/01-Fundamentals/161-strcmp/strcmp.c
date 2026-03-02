/*
 * strcmp - string comparison
 * Compares two strings lexicographically
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s1 = "apple";
    const char *s2 = "apple";
    const char *s3 = "banana";
    const char *s4 = "Apple";

    // strcmp returns 0 if equal, <0 if s1<s2, >0 if s1>s2
    printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s2, strcmp(s1, s2));
    printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s3, strcmp(s1, s3));
    printf("strcmp(\"%s\", \"%s\") = %d\n", s3, s1, strcmp(s3, s1));
    printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s4, strcmp(s1, s4));

    // Practical comparison
    if (strcmp(s1, s2) == 0) {
        printf("\n\"%s\" equals \"%s\"\n", s1, s2);
    }

    if (strcmp(s1, s3) < 0) {
        printf("\"%s\" comes before \"%s\"\n", s1, s3);
    }

    return 0;
}
