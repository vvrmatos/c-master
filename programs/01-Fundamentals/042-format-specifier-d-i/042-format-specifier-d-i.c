#include <stdio.h>

int main(void) {
    int num = 42;
    short s = 32767;
    long l = 2147483647L;
    long long ll = 9223372036854775807LL;

    printf("%d\n", num);
    printf("%i\n", num);
    printf("%d\n", -17);
    printf("%hd\n", s);
    printf("%ld\n", l);
    printf("%lld\n", ll);

    return 0;
}
