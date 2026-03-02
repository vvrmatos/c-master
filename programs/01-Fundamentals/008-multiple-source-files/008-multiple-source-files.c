#include <stdio.h>

extern int shared_value;
void helper_function(void);

int shared_value = 100;

void helper_function(void) {
    shared_value += 10;
}

int main(void) {
    printf("%d\n", shared_value);
    helper_function();
    printf("%d\n", shared_value);
    return 0;
}
