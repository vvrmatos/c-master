#include <stdio.h>

int main(void) {
    puts("Hello, World!");
    puts("Automatic newline added");

    char message[] = "From a variable";
    puts(message);

    char lines[][20] = {"Line 1", "Line 2", "Line 3"};
    for (int i = 0; i < 3; i++) {
        puts(lines[i]);
    }

    fputs("No newline", stdout);
    fputs(" added\n", stdout);

    return 0;
}

