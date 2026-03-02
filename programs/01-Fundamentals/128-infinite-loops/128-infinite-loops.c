#include <stdio.h>

int main(void) {
    int count = 0;
    
    /* for(;;) style */
    for (;;) {
        printf("Loop %d\n", ++count);
        if (count >= 3) break;
    }
    
    /* while(1) style */
    count = 0;
    while (1) {
        printf("While %d\n", ++count);
        if (count >= 3) break;
    }
    
    /* Event loop pattern */
    int running = 1;
    int events = 0;
    while (running) {
        events++;
        if (events >= 3) {
            running = 0;
        }
    }
    printf("Processed %d events\n", events);
    
    return 0;
}
