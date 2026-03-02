#include <stdio.h>

int main(void) {
    char valid[] = "42 3.14";
    char invalid[] = "abc 123";
    int num;
    float f;
    int count;

    count = sscanf(valid, "%d %f", &num, &f);
    printf("Matched: %d\n", count);
    printf("%d %.2f\n", num, f);

    count = sscanf(invalid, "%d", &num);
    printf("Matched: %d\n", count);

    char partial[] = "10 abc 20";
    int a, b;
    count = sscanf(partial, "%d %d", &a, &b);
    printf("Matched: %d\n", count);

    return 0;
}
    
    return 0;
}
