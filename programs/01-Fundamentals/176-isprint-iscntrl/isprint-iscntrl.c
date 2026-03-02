/*
 * isprint and iscntrl - Testing printable and control characters
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char test_chars[] = {'A', ' ', '\n', '\t', '5', 127, 0};
    
    printf("Testing isprint() and iscntrl():\n\n");
    
    for (int i = 0; i < sizeof(test_chars); i++) {
        unsigned char c = test_chars[i];
        printf("Character %3d: isprint=%d, iscntrl=%d\n",
               c, isprint(c) != 0, iscntrl(c) != 0);
    }
    
    printf("\nPrintable characters (32-126):\n");
    for (int c = 32; c <= 126; c++) {
        if (isprint(c)) {
            printf("%c", c);
        }
    }
    printf("\n");
    
    return 0;
}
