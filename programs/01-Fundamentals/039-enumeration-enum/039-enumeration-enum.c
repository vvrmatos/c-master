#include <stdio.h>

enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum Color {
    RED,
    GREEN,
    BLUE
};

enum Status {
    STATUS_OK,
    STATUS_ERROR,
    STATUS_PENDING,
    STATUS_TIMEOUT
};

enum Boolean {
    FALSE = 0,
    TRUE = 1
};

int main(void) {
    printf("=== Enumeration (enum) Basics ===\n\n");
    
    printf("1. Basic enum - Days of week:\n");
    printf("   SUNDAY    = %d\n", SUNDAY);
    printf("   MONDAY    = %d\n", MONDAY);
    printf("   TUESDAY   = %d\n", TUESDAY);
    printf("   WEDNESDAY = %d\n", WEDNESDAY);
    printf("   THURSDAY  = %d\n", THURSDAY);
    printf("   FRIDAY    = %d\n", FRIDAY);
    printf("   SATURDAY  = %d\n", SATURDAY);
    
    printf("\n2. Using enum variables:\n");
    enum Day today = WEDNESDAY;
    enum Day weekend = SATURDAY;
    printf("   enum Day today = WEDNESDAY; // %d\n", today);
    printf("   enum Day weekend = SATURDAY; // %d\n", weekend);
    
    printf("\n3. Enum comparison:\n");
    if (today == WEDNESDAY) {
        printf("   today == WEDNESDAY: true\n");
    }
    if (today < weekend) {
        printf("   today < weekend: true (WEDNESDAY < SATURDAY)\n");
    }
    
    printf("\n4. Enum in switch:\n");
    enum Status status = STATUS_ERROR;
    switch (status) {
        case STATUS_OK:
            printf("   Status: OK\n");
            break;
        case STATUS_ERROR:
            printf("   Status: ERROR\n");
            break;
        case STATUS_PENDING:
            printf("   Status: PENDING\n");
            break;
        case STATUS_TIMEOUT:
            printf("   Status: TIMEOUT\n");
            break;
    }
    
    printf("\n5. Enum size:\n");
    printf("   sizeof(enum Day) = %zu bytes\n", sizeof(enum Day));
    printf("   sizeof(enum Color) = %zu bytes\n", sizeof(enum Color));
    printf("   sizeof(enum Status) = %zu bytes\n", sizeof(enum Status));
    
    printf("\n6. Enum is integer type:\n");
    enum Color c = RED;
    int color_as_int = c;
    printf("   enum Color c = RED;\n");
    printf("   int color_as_int = c; // %d\n", color_as_int);
    
    c = 1;
    printf("   c = 1; // Valid but not recommended\n");
    printf("   c is now: %d (GREEN)\n", c);
    
    printf("\n7. Enumerator scope:\n");
    printf("   Enumerators are in the same scope as the enum\n");
    printf("   They can conflict with other names!\n");
    
    printf("\n8. Anonymous enum:\n");
    enum { MAX_SIZE = 100, MIN_SIZE = 10 };
    printf("   enum { MAX_SIZE = 100, MIN_SIZE = 10 };\n");
    printf("   MAX_SIZE = %d, MIN_SIZE = %d\n", MAX_SIZE, MIN_SIZE);
    
    printf("\n9. Typedef with enum:\n");
    printf("   typedef enum { OFF, ON } Switch;\n");
    printf("   Switch light = ON; // Cleaner syntax\n");
    
    return 0;
}
