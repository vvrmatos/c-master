#include <stdio.h>

int main(void) {
    unsigned int u = 42;
    unsigned short us = 65535;
    unsigned long ul = 4294967295UL;
    unsigned long long ull = 18446744073709551615ULL;

    printf("%u\n", u);
    printf("%hu\n", us);
    printf("%lu\n", ul);
    printf("%llu\n", ull);
    printf("%zu\n", sizeof(int));

    return 0;
}
