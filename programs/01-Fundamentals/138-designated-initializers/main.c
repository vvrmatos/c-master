/*
 * 138-designated-initializers
 * C99 Designated Initializers
 */

#include <stdio.h>

int main(void) {
    /* Initialize specific indices */
    int arr1[10] = {[0] = 100, [5] = 500, [9] = 900};
    
    /* Mix with regular initializers */
    int arr2[5] = {10, [3] = 30, 40};  /* {10, 0, 0, 30, 40} */
    
    /* Out of order initialization */
    int arr3[5] = {[4] = 4, [2] = 2, [0] = 0};
    
    /* Size from largest index */
    int arr4[] = {[9] = 90, [0] = 0};  /* Size is 10 */
    
    /* Enum as indices */
    enum { MON, TUE, WED, THU, FRI, SAT, SUN };
    int hours[7] = {
        [MON] = 8, [TUE] = 8, [WED] = 8,
        [THU] = 8, [FRI] = 6, [SAT] = 0, [SUN] = 0
    };
    
    printf("arr1 (sparse): ");
    for (int i = 0; i < 10; i++) printf("%d ", arr1[i]);
    
    printf("\narr2 (mixed): ");
    for (int i = 0; i < 5; i++) printf("%d ", arr2[i]);
    
    printf("\narr3 (out of order): ");
    for (int i = 0; i < 5; i++) printf("%d ", arr3[i]);
    
    printf("\narr4 (size from index): %zu elements\n",
           sizeof(arr4)/sizeof(arr4[0]));
    
    printf("Work hours: M=%d T=%d W=%d Th=%d F=%d Sa=%d Su=%d\n",
           hours[MON], hours[TUE], hours[WED], hours[THU],
           hours[FRI], hours[SAT], hours[SUN]);
    
    return 0;
}
