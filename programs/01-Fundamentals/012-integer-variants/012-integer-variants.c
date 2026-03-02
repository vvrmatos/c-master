#include <stdio.h>

int main(void) {
    short s = 32767;
    long l = 2147483647L;
    long long ll = 9223372036854775807LL;
    
    printf("=== Integer Variants ===\n\n");
    
    printf("short s = %hd\n", s);
    printf("long l = %ld\n", l);
    printf("long long ll = %lld\n", ll);
    
    printf("\nSizes:\n");
    printf("  sizeof(short)     = %zu bytes\n", sizeof(short));
    printf("  sizeof(int)       = %zu bytes\n", sizeof(int));
    printf("  sizeof(long)      = %zu bytes\n", sizeof(long));
    printf("  sizeof(long long) = %zu bytes\n", sizeof(long long));
    
    printf("\nMinimum guaranteed sizes:\n");
    printf("  short:     >= 16 bits (2 bytes)\n");
    printf("  int:       >= 16 bits (2 bytes)\n");
    printf("  long:      >= 32 bits (4 bytes)\n");
    printf("  long long: >= 64 bits (8 bytes)\n");
    
    return 0;
}
