#include <stdio.h>

int main(void) {
    char input1[] = " A B C";
    char input2[] = "Hello World";
    char ch1, ch2, ch3;
    char word[20];

    sscanf(input1, " %c %c %c", &ch1, &ch2, &ch3);
    printf("%c %c %c\n", ch1, ch2, ch3);

    sscanf(input2, "%19s", word);
    printf("%s\n", word);

    char line[] = "The quick brown fox";
    char full[50];
    sscanf(line, "%49[^\n]", full);
    printf("%s\n", full);

    return 0;
}

