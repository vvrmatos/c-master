#include <stdio.h>

int main(void) {
    char grade = 'B';
    
    switch (grade) {
        case 'A':
            printf("Excellent!\n");
            break;
        case 'B':
            printf("Good job!\n");
            break;
        case 'C':
            printf("Satisfactory\n");
            break;
        case 'F':
            printf("Failed\n");
            break;
        default:
            printf("Invalid grade\n");
            break;
    }
    
    printf("Grade processed\n");
    
    return 0;
}
