#include <stdio.h>

int main(void) {
    char input[] = "42 3.14 A hello";
    int num;
    float f;
    char ch;
    char word[20];

    sscanf(input, "%d %f %c %s", &num, &f, &ch, word);

    printf("%d\n", num);
    printf("%f\n", f);
    printf("%c\n", ch);
    printf("%s\n", word);

    return 0;
}

