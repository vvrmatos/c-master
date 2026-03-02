#include <stdio.h>

int main(void) {
    char data[] = "42 3.14 Hello";
    int num;
    float f;
    char word[20];

    sscanf(data, "%d %f %s", &num, &f, word);
    printf("%d %.2f %s\n", num, f, word);

    char date[] = "2024-03-15";
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    printf("%04d-%02d-%02d\n", year, month, day);

    char csv[] = "Alice,25,Engineer";
    char name[30], job[30];
    int age;
    sscanf(csv, "%[^,],%d,%s", name, &age, job);
    printf("%s %d %s\n", name, age, job);

    char hex[] = "#FF8800";
    unsigned int color;
    sscanf(hex, "#%x", &color);
    printf("0x%06X\n", color);

    return 0;
}

